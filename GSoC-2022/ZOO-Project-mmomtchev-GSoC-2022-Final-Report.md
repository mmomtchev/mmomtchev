# ZOO-Project GSoC 2022 Proposal by @mmomtchev

### Adding Node.js support for service implementation to be run from the ZOO-Kernel

## Abstract

The ZOO-Project is a solid WPS server able to handle services implemented in various different programming languages. The existing `ZOO-Kernel` supports C, C++, and JS implementations with the SpiderMonkey engine. With this project, the objective was to add support for NodeJS implementation in the `ZOO-Kernel`.

Mentors: Gérald Fenoy, Aditi Sawant, Rajat Shinde

## State of the art

SpiderMonkey, the original JavaScript engine, has a very mature support for being integrated in C++ projects as a shared library.

Node.js already supports being built as a shared library instead of an executable. The main user and current maintainer of this feature is the Electron project (https://www.electronjs.org/). Electron wraps around Node.js in a rather complex manner, reimplementing some its features. It does so by directly accessing the Node.js internals and the raw V8 API, by directly linking to it.

Ubuntu and Debian already provide Node.js and libnode packages. These are however built according to those distributions' guidelines and are not updated once the distribution is released. As Node.js is a very fast moving project, most users use the binaries provided by NodeSource, which are maintained by developers directly linked to the Node.js team. These are widely considered to be the reference binaries for each platform. The notion of a reference binary exists because Node.js supports native add-ons which are not always compatible between different Node.js builds. The libnode packages in those distributions do not allow access to the Node.js internals so these are in fact next to useless. NodeSource, on the other hand, does not provide prebuilt libnode packages.

![Current libnode](https://raw.githubusercontent.com/mmomtchev/mmomtchev/master/GSoC-2022/libnode-before.png)

*(The current state of libnode)*

An issue, with 14 hearts, on the Node.js tracker, proposes an alternative libnode API, built upon the binary stable N-API used for native addons: <https://github.com/nodejs/node/issues/23265>.

![Current N-API](https://raw.githubusercontent.com/mmomtchev/mmomtchev/master/GSoC-2022/native-addon.png)

*(An overview of the excellent and very successful `N-API` and `node-addon-api`)*

Very early in this project, it became clear that instead of developing the ZOO-Project support around a very specific Node.js/V8 version, that was to be included in the source distribution, it was much more future proof to develop an abstraction layer, and then, in the spirit of the GSoC program, to contribute it back to the open source community.

## N-API Embedding

Node.js provides an excellent stable ABI for creating native addons. It is a second-generation API - replacing the previous NAN (*Native Abstractions for Node.js*) - and it is the result of the very significant experience of the Node.js developers in the field of distributing binary addons for a JavaScript runtime. It allows a third party to compile and then to distribute a single binary per supported platform that will be compatible with all future Node.js versions. This magic takes place behind the scenes and allows the average user to simply type `npm install pkg` and to retrieve binary code, in addition to the JS library, that will simply work on its platform. The ABI has even full C++ support that avoids any compiler runtime conflicts by being entirely implemented as C++ templates to be built with the addon. These templates reduce the C++ API to plain C calls using N-API across the linking border of the shared library for maximum compatibility. This C++ API is called `node-addon-api` and it is a separate project from Node.js itself.

This ABI provides stable abstractions for calling and being called from JS code, decoding JS objects and interacting with the garbage collector and the different worker threads (V8 isolates) which are not transparent from the viewpoint of the C++ code. V8 isolates are represented by an opaque reference, called a Node.js environment, that is passed to every N-API method. It is this reference to a Node.js environment that is used to provide an alternative implementation that allows speaking to an embedded Node.js instance instead of the calling Node.js instance.

![New libnode](https://raw.githubusercontent.com/mmomtchev/mmomtchev/master/GSoC-2022/libnode-after.png)

*(Turning `N-API` and `node-addon-api` inside-out)*

### The Platform Environment

The first major element of this libnode implementation is a new environment type compatible with all the existing methods. This includes N-API primitives for creation of a new environment that take care of loading Node.js and V8 and initializing it:

```c
napi_status napi_create_platform(int argc,
                                    char** argv,
                                    int exec_argc,
                                    char** exec_argv,
                                    char*** errors,
                                    int thread_pool_size,
                                    napi_platform* result);

napi_status napi_create_environment(napi_platform platform,
                                    char*** errors,
                                    const char* main_script,
                                    napi_env* result);

napi_status napi_destroy_platform(napi_platform platform, int *exit_code);

napi_status napi_destroy_environment(napi_env env);
```

These methods allow the creation of a `napi_env` object - the same type of object used by Node.js to interact with a native C/C++ addon. It describes a running V8 isolate with Node.js builtins.

The C++ classes `Napi::Platform` and `Napi::PlatformEnv`, implemented in `node-addon-api` allow for a cleaner interface when using only C++.

### The Asynchronous Execution Model

Node.js has a very peculiar asynchronous execution model that comes from the Web legacy of JavaScript. This is something that must be taken into account when embedding JavaScript code - as it expects its functions to be run as callbacks from the event loop.

In order to provide clean and simple interface for calling C/C++ programs, that event loop has been completely abstracted.

For example, consider this simple JS function:
```js
function fn() {
    const r = { result: 'pending' };
    setImmediate(() => {
        r.result = 'result';
    });
    return r;
}
```
It returns an object with an attribute and then schedules a coroutine to modify this object that will run at some later point. When this function is called from C++, the calling program will need a method to trigger the execution of this coroutine which will still be pending at the moment the function returns.

Two methods allow flushing of the pending callbacks:
```c
napi_status napi_run_environment(napi_env env);

napi_status napi_await_promise(napi_env env,
                            napi_value promise,
                            napi_value *result);
```

The first one spins the event loop until all pending callbacks have been executed, the second one spins it until the passed `Promise` object has been resolved (or rejected) and retrieves its value (or error). These functions allow the execution of the pending JavaScript code in the context of the currently running C++ thread.

### `require`/`import`

At the time when SpiderMonkey was still the leading JS engine, JS did not really had the notion of packages or code splitting. It is Node.js that introduced the `require` method for loading of external JS code.

In order to provide a true sense of *linking* the JS code from C/C++, it was decided to support directly calling `require` and `import` methods from C/C++ - as this would be the way that JS code would load a package. These methods - the traditional Node.js `require` and the new dynamic function-like `import` (the static `import` is part of the language) are in fact implemented as Node.js builtins and are loaded during the boostrapping of the JS code.

In order to render them accessible, a new bootstrapping was implemented - one that exported these methods in the `global` object so that they can easily be accessed from C/C++.

### PPA Packages

In order for the `libnode` to be an (almost) drop-in replacement for the SpiderMonkey, Ubuntu PPA packages are provided as this is the way that ZOO-Project used to retrieve and include SpiderMonkey - by using the now obsolete packages `libmoz`.

These packages are currently provided only for Ubuntu LTS versions - Bionic (18.04), Focal (20.04) and Jammy (22.04) and they exist both for the Node.js 16.x (LTS) and 18.x (Current) branches:

https://launchpad.net/~mmomtchev

* `ppa:mmomtchev/libnode`
* `ppa:mmomtchev/libnode-18.x`


### Multi-threading

In order to simplify the API and to avoid any V8 locking issues, there is one very simple rule that is to be followed:

**After creating a new platform environment, only the thread that created it is allowed to access it.**

This greatly simplifies the code and does not seem to impose any significant additional restrictions.

## Future of N-API Embedding

Embedding JS plugins in C/C++ software is a very common need. JS is currently the fastest growing general purpose language in the world and it is the first language for many young developers. C/C++ on the other hand still has the largest installed base and it is not going away for at least several more generations. Even if it is likely to be challenged in this role during the coming decade, it is still the first language for implementing complex system software such as operating systems, database engines, network processing or interpreting higher-level languages such as JS or Python.

N-API embedding `libnode` has a very great potential because it allows for very easy support of Node.js plugins.

### Short-term Plans

* Provide Debian packages

* Provide macOS and Windows binaries

### Long-term Plans

* Push forward with the merging of the PR https://github.com/nodejs/node/pull/43542 in the main Node.js tree

    The whole point of N-API embedding, besides being easier for the end-user, is that it is binary compatible with future Node.js versions. In order for `libnode` to be truly future-proof, it has to be merged at some point with the main Node.js tree.

    Besides the sheer amount of work and testing required for merging a large PR in a project of Node.js' stature, there is one particularly problematic point - `libnode` currently carries a monkey-patch for `libuv` that fixes a complex issue that never happens with the use that Node.js makes of it: https://github.com/libuv/libuv/issues/3686. This means that merging `libnode` will require simultaneous pushes to both Node.js and libuv and an upgrade of the libuv version in Node.js.

    In order to mitigate risks when it comes to ZOO-Project, Node.js support in ZOO-Project has been implemented without using the very practical shortcut `napi_await_promise` which requires modifying `libuv`.


## Documentation

![illustration](https://raw.githubusercontent.com/mmomtchev/mmomtchev/master/GSoC-2022/gsoc-2022.png)

*(An example for calling `axios.get` from C++)*

**The program resulting from compiling this code will be a very small binary executable, that will be dynamically linked with the 80Mb (on Linux) `libnode.so` shared library and it will require the presence of a `node_modules/axios` and all of its dependencies in the same directory as the executable.**

### Using `libnode` to implement support of JS plugins in C++ code

The full documentation for using N-API embedding `libnode` has been integrated in the Node.js documentation in the `napi-libnode` branch:

https://github.com/mmomtchev/node/blob/napi-libnode/doc/api/embedding.md
https://github.com/mmomtchev/node/blob/napi-libnode/doc/api/n-api.md

Also, the `libnode` repository contains some examples allowing to quick-start a new project:

https://github.com/mmomtchev/libnode/tree/main/examples

One should probably start by the ***Calling `axios` from C++*** example:

https://github.com/mmomtchev/libnode/blob/main/examples/axios-example.cc

### Using Node.js JavaScript to implement a WPS service in ZOO-Project

The documentation geared towards WPS service authors has been integrated in the ZOO-Project documentation and it is available in `nodejs` branch:

https://github.com/mmomtchev/ZOO-Project/blob/nodejs/docs/services/howtos.rst#javascript-node-js

An example Node.js service is available as PR for the examples repository of ZOO-Project:

https://github.com/ZOO-Project/examples/pull/1

## The Code

All the work done in Node.js is available in my Node.js forks:

* v16.x branch https://github.com/mmomtchev/node/tree/napi-libnode-v16.x
* v18.x branch https://github.com/mmomtchev/node/tree/napi-libnode-v18.x
* main branch https://github.com/mmomtchev/node/tree/napi-libnode

The PR for merging N-API embedding to the main branch of Node.js:
https://github.com/nodejs/node/pull/43542

(currently unmergeable until libuv is modified accordingly)

The Ubuntu PPA packages build system, along with instructions for installing and using `libnode` are available in a dedicated repo:

https://github.com/mmomtchev/libnode

All the work done in ZOO-Project itself is available in the `nodejs` branch:

https://github.com/mmomtchev/ZOO-Project/tree/nodejs

The currently pending PR is available here:

https://github.com/ZOO-Project/ZOO-Project/pull/30

The slides from the `libnode` presentation at [FOSS4G 2022](https://2022.foss4g.org/) can be found here: 

* (sources) https://github.com/mmomtchev/zoo-slides/blob/gsoc2022-nodejs/FOSS4G-2022/GSoC/Node.js/index.html
* (preview) https://htmlpreview.github.io/?https://github.com/mmomtchev/zoo-slides/blob/gsoc2022-nodejs/FOSS4G-2022/GSoC/Node.js/index.html#/
