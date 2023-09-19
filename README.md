[![Stand With Ukraine](https://raw.githubusercontent.com/vshymanskyy/StandWithUkraine/main/badges/StandWithUkraine.svg)](https://stand-with-ukraine.pp.ua)

![Blue Anarchist flag](https://garga.net/blue_anarchist.png)
***I AM CURRENTLY UNEMPLOYED AND IN A VERY DIRE FINANCIAL SITUATION, SEE BELOW***

*I am maintaining a large number of binary Node.js projects - if you use any of them, you should know that I am ready to provide pre-built binaries for Macbooks with Apple Silicon if someone provides me a remote access to such hardware. If paying by the hour, expect about an hour of average daily usage.*

![](https://garga.net/blue_anarchist.png)

* C / C++ / JavaScript / TypeScript
* Node.js / V8 internals
* GIS, Spatial Algorithms, HPC, Scientific and Parallel Computing, Numerical Weather Prediction
* React / React Native
* Linux, FreeBSD and OpenBSD kernel experience, especially the TCP/IP stacks and device drivers

I am the world's first unemployed IT engineer who is living on social welfare in a legal *no-man's-land* and works for free.

I am currently in the middle of a huge judicial scandal in France since several previous employers took part in a very shocking affair of sexual nature motivated by the intimate problem of one person with political connections. By now the affair has spiraled out ouf control and it involves a very large number of French judicial officials, the French police, politically exposed persons, and many big IT companies such as Google, Twitter, Amazon AWS, OSGeo, the OpenJS Foundation, StackOverflow, some YCombinator companies and even Steam and Cloud Imperium Games.

Currently I am living with a few bucks per day and I am offered a job if I am to accept to stop telling people about what happened - and to submit myself to sexual harassment - which is impossible to organize unless I shut up.

![Eunuch Programmers](https://orel.garga.net/image-3175739551.jpg)

I have started maintaining a list of the companies where this kind of deal is possible - there are some very large French and US companies in it - you can find it [here](https://github.com/mmomtchev/mmomtchev/blob/master/BUSINESS-AS-USUAL.md).

My projects:

# General Purpose Software

* [pymport](https://github.com/mmomtchev/pymport) - My current major project, full native compatibility of existing Python libraries with Node.js code
* [libnode](https://github.com/mmomtchev/libnode) - Node.js-as-a-shared-library allowing easy calling of JS code from compiled C and C++ applications through the Node-API (C) and `node-addon-api` (C++) interfaces with Ubuntu/Debian packages, created as part of GSoC 2022
* [node-magickwand](https://github.com/mmomtchev/node-magickwand) - Full ImageMagick-7 bindings for Node.js - meant both as a full-featured general-purpose image processing library for Node.js and as testing grounds for SWIG NAPI (of which I am the author), includes a tutorial for porting C++ libraries to Node.js
* [sqlite-wasm-http](https://github.com/mmomtchev/sqlite-wasm-http) - the so-called _SQL over HTTP_ middleware, an alternative implementation of [`@phiresky/sql.js-httpvfs`](https://github.com/phiresky/sql.js-httpvfs) based on the new official SQLite WASM distribution
* [ExprTk.js](https://github.com/mmomtchev/exprtk.js) - asynchronous Node.js bindings for [ExprTk](http://www.partow.net/programming/exprtk/index.html) - a mathematical expression engine - allowing for an effortless multithreading of computationally heavy tasks by supporting asynchronous execution of thunks precompiled from strings - it will eventually be supported by both `gdal-async` and `scijs`
* [jeetah](https://github.com/mmomtchev/jeetah) - an optimizing compiler for mathematical expressions in JavaScript
* [documentation-polyglot](https://github.com/mmomtchev/documentation-polyglot) - a plugin that adds *C++* support to `documentation.js` via the new plugin framework that I am currently making
* [documentation-hipster](https://github.com/mmomtchev/documentation-hipster) - is a beautiful `documentation.js` Bootstrap-based theme with support for TypeScript and React components - one of its goals is to provide an almost drop-in replacement for the seemingly dying [react-styleguidist](https://react-styleguidist.js.org/) project
* [react-native-settings](https://github.com/mmomtchev/react-native-settings) - an all-in-one component for creating cross-platform settings (preferences) screens with React Native
* [react-edit-list](https://github.com/mmomtchev/react-edit-list) - an universal editable ListView React component that can interact with an external API
* [@mmomtchev/expo-android-localized-app-name](https://github.com/mmomtchev/expo-android-localized-app-name) - an [expo](https://expo.dev) plugin for having a localized app name in managed React Native workflows
* [yatag](https://github.com/mmomtchev/yatag) - is a tool that I use to generate the TypeScript type definitions in most of my projects, it is slowly reaching maturity
* [Queue](https://github.com/mmomtchev/Queue) - is a rather simple but useful package for rate-limiting access to external APIs
* [@mmomtchev/node-pre-gyp-github](https://github.com/mmomtchev/node-pre-gyp-github) - an almost complete rewrite of the popular [node-pre-gyp-github](https://github.com/bchr02/node-pre-gyp-github) abandoned by its author, compatible with the current version of the GitHub API
* [SharedMap](https://github.com/mmomtchev/SharedMap) - is a `Map` that can be accessed by multiple `worker_threads`

# Geospatial Software

* [node-gdal-async](https://github.com/mmomtchev/node-gdal-async) - I am actively developing the GDAL bindings for Node.js which used to be abandoned by its creator
  - [ndarray-gdal](https://github.com/mmomtchev/ndarray-gdal) is the [scijs](https://github.com/scijs/ndarray) plugin
  - [gdal-exprtk](https://github.com/mmomtchev/gdal-exprtk) is the [ExprTk.js](https://github.com/mmomtchev/exprtk.js) plugin
* [rlayers](https://github.com/mmomtchev/rlayers) - a set of React components for creating online maps with OpenLayers
* [ol-mbtiles](https://github.com/mmomtchev/ol-mbtiles) - an Openlayers plugin adding `MBTiles` support
* [intercity.js](https://github.com/mmomtchev/intercity) - a still unreleased Work-In-Progress for a dynamic data WMTS/WMS/WCS/WFS server for Node.js
* [query-mvt](https://github.com/mmomtchev/query-mvt) - a simple CLI tool and a Node.js/browser library for retrieving geographical data directly from public map services without the need for an API, special server software or any keys, works with Qwant Maps and all other map services that serve MVT/PBF tiles (Google Maps uses a proprietary format)
* [geosub](https://github.com/mmomtchev/geosub) - A tool for partial downloading of bands and subwindows from geospatial raster datasets from cloud storage, it is an Amazon AWS-compatible replacement for NOAA's own [g2sub](https://nomads.ncep.noaa.gov/cgi-bin/filter_gfs_0p25.pl)
* [geoapi](https://github.com/mmomtchev/geoapi) - is an open-source server that can translate lat:long coordinates to postal codes (a free GeoNames API), it is based on the proprietary `geodata` in velivole
* [europe-geodata](https://github.com/mmomtchev/europe-geodata) - a collection of freely available geographical information for Europe

# Paragliding Software

* [igc-xc-score](https://github.com/mmomtchev/igc-xc-score) - an open-source solution for scoring paragliding XC competitions - which is a very interesting linear optimization problem with a *O(n^5)* worst case complexity
* [XC-DB](https://github.com/mmomtchev/xc-db) - an open-source interactive browser for paragliding flight tracks implemented in React, Redux and rlayers for the front-end and Node.js, Express, gdal-async and ndarray for the back-end
* [velitherm](https://github.com/mmomtchev/velitherm) - an open-source library of basic thermodynamics equations used in soaring weather
  - [velitherm-visu](https://github.com/mmomtchev/velitherm-visu) - is an online air parcel calculator in React that uses the library
* [igc-admin-analyze](https://github.com/mmomtchev/igc-admin-analyze) - a tool for analyzing IGC flight logs giving a percentage of time spent above given administrative divisions defined by their GeoJSON borders

# Websites

I am mostly a C++/JavaScript integration expert with a focus on V8/Node.js internals, but I also do lots of browser JS / web development:
* [velivole.fr / meteo.guru](https://www.velivole.fr) - is a free soaring weather site for paragliding, hang-gliding and sail-plane pilots. It is complex application which includes a **vanilla JS / OpenLayers 6 / custom webpack** front-end, an **Express.js/Node.js** backend and a **Node.js/C++** computational engine for specialized numerical weather prediction that consists of a secondary model running on top of the French and German national weather models. You can see an overview of velivole/meteo.guru [here](https://raw.githubusercontent.com/mmomtchev/mmomtchev/master/velivole.fr-Architecture-Overview.svg) and explore its API [here](https://www.velivole.fr/apidoc/). The website includes a number of GIS innovations, including the remote querying of MVT data using [query-mvt](https://github.com/mmomtchev/query-mvt). It is also the very first site in the world to support the displaying of remote MBTiles maps using [ol-mbtiles](https://github.com/mmomtchev/ol-mbtiles). Almost all of my GIS software listed above is used in some way on this site.
* [xc-db.velivole.fr](https://xcdb.velivole.fr) - an [open-sourced](https://github.com/mmomtchev/xc-db) navigator/explorer that can uses basic machine-learning (an algorithm loosely based on K-means clustering) to deduce the typical routes pilots will take depending on the prevailing winds by classifying all paragliding flights of the French Federal Distance Cup of the French Paragliding Association. **Node.js/Express.js/gdal-async** backend with a **React/Redux/rlayers** front-end. *No mobile version available at the moment.* The sites is a demonstration of the capabilities of `gdal-async` used with Express.js and `rlayers` as it includes a dynamically computed particle visualization entirely in React/rlayers that uses an SQL database with 700M lines.
* [isitplausible.com](https://isitplausible.com) - a StackOverflow-inspired website for analyzing the scientific accuracy of Sci-Fi movies, books and video games. **Node.js/Express.js** backend with **React/Next.js**, this was my first foray in the world of server-side rendering with React.
* [scodex.garga.net](https://scodex.garga.net) - the first attempt of creating an universal Codex website for the (forever) upcoming Star Citizen by CIG with information extracted from the game files using [`scdatatools`](https://gitlab.com/scmodding/frameworks/scdatatools) in Node.js / TypeScript environment with `pymport`. The site also makes heavy use of `gdal-async`, `rlayers`, `node-magickwand` and `scijs` through `ndarray-gdal` because it includes detailed 2D/3D maps of the planets and some basic extrasolar astronomy. Backend-less design with server-rendered **React** using **Next.js 13**.
* [aircalc.velivole.fr](https://aircalc.velivole.fr/) - a thermodynamics air parcel calculator for weather, online version of [velitherm-visu](https://github.com/mmomtchev/velitherm-visu), raw **React**.
* [xc-score](https://www.velivole.fr/xc-score/) - online version of * [igc-xc-score](https://github.com/mmomtchev/igc-xc-score) - **vanilla JS** with a **custom webpack**.

# Mobile applications

* [velivole-mobile](https://github.com/mmomtchev/velivole-mobile) - the open-sourced mobile counterpart to velivole.fr, in its current iteration it is based on React Native / expo.

# Timewasters

* [EDCarnage](https://github.com/mmomtchev/EDCarnage) - an [Electron](https://www.electronjs.org/) tool for tracking stacked massacre missions in [Elite: Dangerous](https://www.elitedangerous.com/)

---

You can also check my Medium articles here: <https://mmomtchev.medium.com/>

Besides writing software, I have been trying, for almost 10 years now, to create a video as stunningly beautiful as [this one](https://www.youtube.com/watch?v=a71bZ1YG68U) that I saw when I started [paragliding](https://github.com/mmomtchev/mmomtchev/blob/master/AERIAL_SPORTS.md). I have come [a long way](https://www.youtube.com/user/momtchev) since I started in [2012](https://www.youtube.com/watch?v=fzTU611kfrw).

I also used to spent lots of time doing blue water sailing before my affair spiraled out of control.

I am an active member of the French Paragliding and Hang-gliding Federation <https://www.ffvl.fr> and (currently) an inactive member of the French Sailing Federation <https://www.ffvoile.fr>.

*Vous pouvez également lire mon introduction rapide à la thermodynamique appliquée au vol libre et le vol à voile ici: [THERMODYNAMIQUE.md](https://github.com/mmomtchev/velivole/blob/main/THERMODYNAMIQUE.md).*

*There is also an English version of my introduction to the basic concepts of Thermodynamics for Soaring Flight here: [THERMODYNAMICS.md](https://github.com/mmomtchev/velivole/blob/main/THERMODYNAMICS.md).*
