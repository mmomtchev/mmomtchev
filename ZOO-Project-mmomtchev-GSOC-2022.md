# ZOO-Project GSOC 2022 Proposal by @mmomtchev

## Adding Node.js support for service implementation to be run from the ZOO-kernel

# Abstract

The ZOO-Project is a solid WPS server able to handle services implemented in various different programming languages. The existing `ZOO-Kernel` supports C, C++, and JS implementations with the SpiderMonkey engine. With this project, the objective is to add support for NodeJS implementation of the `ZOO-Kernel`.

Mentors: Gérald Fenoy, Aditi Sawant, Rajat Shinde

# Proposed Solution

The current latest LTS version of Node.js, Node.js 16.x, is to be embedded in the `ZOO-Kernel` executable following the same architecture as SpiderMonkey.

It is worth noting that the next LTS version of Node.js, Node.js 18 is scheduled to be released during the GSOC timeline. As this version is not expected to replace the 16.x as recommended version until October 2022, it is believed that Node.js 16.x remains the safer choice.

Node.js supports being built as a shared library since version 12.x. This feature is used by the Electron project which is its main maintainer. It allows the JS runtime to be loaded inside the address space of the calling program and to both call JS functions from the native code and expose native functions to the JS code.

There are several different interfaces available for interacting with the Node.js runtime:
* By calling raw internal V8 and Node.js methods which are usually not stable across different versions
* By using the [NAN C++ API](https://github.com/nodejs/nan) C++ which is stable at the source level across different versions
* By using the [Node C N-API](https://nodejs.org/api/n-api.html) which is stable at the binary level across different versions
* By using the [Node Addon C++ API](https://github.com/nodejs/node-addon-api) which is stable at the binary level across different versions

Of these methods, the Node C N-API seems to be the best suited for ZOO-Project as it is binary stable across different Node.js versions and it does not require C++.

It should be noted that while these APIs/ABIs are usually meant to be used by native addons that are loaded by the main Node.js process as a shared library, they are also perfectly usable in the opposite direction - ie when Node.js is loaded as a shared library by a 3rd party process.

Node.js supports running multiple V8 isolates, each with a separate main thread, offering a completely separate execution environment to each JS instance.

These separate instances have separate event loops but can share the same worker thread pool.

This mode of embedding Node.js matches most closely the existing JS architecture based on SpiderMonkey. It is also the preferred mode for embedding Node.js.

The following alternatives have also been considered:
* Run every instance of a service in a separate, external, Node.js process
    This mode will have a more expensive startup and will present unique challenges when implementing the various ZOO-Project routines which will have to communicate with the `ZOO-Kernel` by some external mechanism - such as RabbitMQ.
* Run all instances of a service in a single shared environment
    This mode offers the potentially best performance but it imposes upon the end-user to use very correctly the Node.js asynchronous mechanisms - failing to do so will result in latency spikes and possibly dropped connections.

Rebuilding `libnode` as part of the `ZOO-Project` build system is considered to be out of the scope of the current project - just as the current SpiderMonkey shared library is expected to be provided by the end-user, so will be `libnode` which is already carried by some major Linux distributions - Ubuntu being one of them.

# Proposal Timeline

## Before June 13

* To familiarize myself completely with ZOO-Project functionality and architecture.
* To experiment with using `libnode`, the embedded version of NodeJS and test the compatibility between the packaged `libnode` by the Linux distributions and the existing Node.js native addons

## June 13 - July 25

* Implement the loading of the Node.js shared library in the `ZOO-Kernel` and reimplement the existing SpiderMonkey methods using Node N-API. Expose those methods to the JS world.

## July 25 - July 29

* Phase 1 evaluation

## July 29 - September 4

Stretch goals:
* Add builtin Node.js GDAL support
 - Allow JS services to use `gdal-async` out of the box
 - Reimplement the GDAL profile C++ service in JS as an example

* Allow services to request to be executed in a single-instance mode by providing an `async` function as entry point

* Add snapshot support to `libnode`
 - Should the time permit, `libnode` could benefit from having the same V8 snapshot support as the Node.js main executable. V8 supports creating and restoring snapshots of a JS heap - this feature is used by Node.js to speed-up the initial loading of the JS class library - instead of compiling it at every process startup, it is compiled and initialized once during the build of the Node.js executable and then the JS heap is saved in a snapshot to be reused when launching Node.js. Currently, this feature is not readily available when using `libnode`. Electron re-implements it on its own. This is to be submitted for merging back in Node.js.

After September 4

* Phase 2 evaluation
