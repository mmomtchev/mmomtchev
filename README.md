[![Stand With Ukraine](https://raw.githubusercontent.com/vshymanskyy/StandWithUkraine/main/badges/StandWithUkraine.svg)](https://stand-with-ukraine.pp.ua)
[![Stand With Palestine](https://raw.githubusercontent.com/Safouene1/support-palestine-banner/master/StandWithPalestine.svg)](https://github.com/Safouene1/support-palestine-banner)

![Blue Anarchist flag](https://garga.net/blue_anarchist.png)

# You saw me at dotJS 2024?

Here are my guerilla slides:

* [Markdown version](guerilla-slides-2024-dotjs.md)
  
* GIF version

![GIF](https://orel.garga.net/guerilla-slides-2024-dotjs.gif)

* [HTML version](https://orel.garga.net/guerilla-slides-2024-dotjs/)


# My work

I am an unemployed IT engineer living on social welfare in a legal *no-man's-land* and working full-time on open-source software.

You can find a brief summary of my situation at the end.

My current main area of expertise is linking C++ and JavaScript.

My main projects are:
 * [SWIG JavaScript Evolution](https://github.com/mmomtchev/swig)  - An automatic bindings generator/compiler for C/C++ libraries, produces dual-environment bindings - Node.js native addon and a WASM bundle
 * The [`hadron`](https://github.com/mmomtchev/hadron) build system for JavaScript - A `meson`-based alternative to `node-gyp` that supports dual-environment C/C++ projects, `conan` integration and can use *xPacks* for a completely self-contained build that does not assume anything about the user host
 * [`libnode`](https://github.com/mmomtchev/libnode) - a GSoC-sponsored project that allows to easily call JavaScript subroutines from C++ using Node-API - alas, this project is currently frozen at Node.js 18.x since I have been banned from interacting with the Node.js' projects on github (see my story at the end for more details on this *incident*)
 * [`nobind17`](https://github.com/mmomtchev/nobind) - an experiment in developing the next generation automatic bindings for C++ and JavaScript - inspired by `pybind11` but with a focus on C++17

Additionally, I have authored and maintain a number of bindings of C/C++ libraries for JavaScript:

 * [`node-gdal-async`](https://github.com/mmomtchev/node-gdal-async)
    
    fork of the unmaintained `gdal`/`gdal-next`
    GDAL bindings for Node.js
    An early generation Node.js addon using NAN, I transformed the sync bindings in async bindings

   - [`ndarray-gdal`](https://github.com/mmomtchev/ndarray-gdal) is the [`scijs`](https://github.com/scijs/ndarray) plugin
   - [`gdal-exprtk`](https://github.com/mmomtchev/gdal-exprtk) is the [`ExprTk.js`](https://github.com/mmomtchev/exprtk.js) plugin

 * [`ExprTk.js`](https://github.com/mmomtchev/exprtk.js) / [`jeetah`](https://github.com/mmomtchev/jeetah)

    Node-API manual bindings for ExprTk for Node.js including an experimental JIT compiler that allows to run parallel vector calculations on `TypedArray`s without being constrained by the V8 monothreaded model

 * [`everything-json`](https://github.com/mmomtchev/everything-json)

    Node-API manual bindings for `simdjson`, the fastest JSON parser in the world, the everything JSON parser for Node.js - asynchronous, very high performance, yieldable and with partial decoding support - check it to see why JSON parsing is such a problem in Node.js (it is synchronous!)

 * [`sqlite-wasm-http`](https://github.com/mmomtchev/sqlite-wasm-http)

    `embind` semi-automatic bindings for `sqlite3` for WASM with a transparent SQL over plain HTTP support, inspired by phiresky's original implementation for `sqlite.js`

 * [`magickwand.js`](https://github.com/mmomtchev/magickwand.js)

    The SWIG JSE showcase project, fully automatic SWIG JSE-generated bindings for ImageMagick for JavaScript - 400k of C++ code generated with 600 lines of SWIG code, native addon in Node.js, WASM bundle in the browser, web-bundler friendly, async support and TypeScript support
 * [`@mmomtchev/ffmpeg`](https://github.com/mmomtchev/ffmpeg)

    The `nobind17` showcase project, semi-automatic `nobind17` bindings for ffmpeg for Node.js - complete with a native streams API, async support and Typescript support

 * [`proj.js`](https://github.com/mmomtchev/proj.js)
 
    Another SWIG JSE project, still under development, fully automatic SWIG JSE-generated bindings for a project with advanced C++17 features

My other projects:

# General Purpose Software

* [documentation-polyglot](https://github.com/mmomtchev/documentation-polyglot) - a plugin that adds *C++* support to `documentation.js` via the new plugin framework that I am currently making
* [documentation-hipster](https://github.com/mmomtchev/documentation-hipster) - is a beautiful `documentation.js` Bootstrap-based theme with support for TypeScript and React components - one of its goals is to provide an almost drop-in replacement for the seemingly dying [react-styleguidist](https://react-styleguidist.js.org/) project
* [yatag](https://github.com/mmomtchev/yatag) - is a tool that I use to generate the TypeScript type definitions in most of my projects, it is slowly reaching maturity
* [Queue](https://github.com/mmomtchev/Queue) - is a rather simple but useful package for rate-limiting access to external APIs
* [@mmomtchev/node-pre-gyp-github](https://github.com/mmomtchev/node-pre-gyp-github) - an almost complete rewrite of the popular [node-pre-gyp-github](https://github.com/bchr02/node-pre-gyp-github) abandoned by its author, compatible with the current version of the GitHub API
* [SharedMap](https://github.com/mmomtchev/SharedMap) - is a `Map` that can be accessed by multiple `worker_threads`

# Geospatial Software

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

# Space

* [orbitron](https://github.com/mmomtchev/orbitron) - a tool for making `.gif` and `.mp4` animations of orbiting bodies out of the NASA/JPL Horizons data

# No longer maintained

* [react-native-settings](https://github.com/mmomtchev/react-native-settings) - an all-in-one component for creating cross-platform settings (preferences) screens with React Native
* [react-edit-list](https://github.com/mmomtchev/react-edit-list) - an universal editable ListView React component that can interact with an external API
* [@mmomtchev/expo-android-localized-app-name](https://github.com/mmomtchev/expo-android-localized-app-name) - an [expo](https://expo.dev) plugin for having a localized app name in managed React Native workflows

# Websites

I also do lots of browser JS / web development:
* [velivole.fr / meteo.guru](https://www.velivole.fr) - is a free soaring weather site for paragliding, hang-gliding and sail-plane pilots. It is complex application which includes a **vanilla JS / OpenLayers 6 / custom webpack** front-end, an **Express.js/Node.js** backend and a **Node.js/C++** computational engine for specialized numerical weather prediction that consists of a secondary model running on top of the French and German national weather models. You can see an overview of velivole/meteo.guru [here](https://raw.githubusercontent.com/mmomtchev/mmomtchev/master/velivole.fr-Architecture-Overview.svg) and explore its API [here](https://www.velivole.fr/apidoc/). The website includes a number of GIS innovations, including the remote querying of MVT data using [query-mvt](https://github.com/mmomtchev/query-mvt). It is also the very first site in the world to support the displaying of remote MBTiles maps using [ol-mbtiles](https://github.com/mmomtchev/ol-mbtiles). Almost all of my GIS software listed above is used in some way on this site.
* [xc-db.velivole.fr](https://xcdb.velivole.fr) - an [open-sourced](https://github.com/mmomtchev/xc-db) navigator/explorer that can uses basic machine-learning (an algorithm loosely based on K-means clustering) to deduce the typical routes pilots will take depending on the prevailing winds by classifying all paragliding flights of the French Federal Distance Cup of the French Paragliding Association. **Node.js/Express.js/gdal-async** backend with a **React/Redux/rlayers** front-end. *No mobile version available at the moment.* The sites is a demonstration of the capabilities of `gdal-async` used with Express.js and `rlayers` as it includes a dynamically computed particle visualization entirely in React/rlayers that uses an SQL database with 700M lines.
* [isitplausible.com](https://isitplausible.com) - a StackOverflow-inspired website for analyzing the scientific accuracy of Sci-Fi movies, books and video games. **Node.js/Express.js** backend with **React/Next.js**, this was my first foray in the world of server-side rendering with React.
* [scodex.garga.net](https://scodex.garga.net) - the first attempt of creating an universal Codex website for the (forever) upcoming Star Citizen by CIG with information extracted from the game files using [`scdatatools`](https://gitlab.com/scmodding/frameworks/scdatatools) in Node.js / TypeScript environment with `pymport`. The site also makes heavy use of `gdal-async`, `rlayers`, `node-magickwand` and `scijs` through `ndarray-gdal` because it includes detailed 2D/3D maps of the planets and some basic extrasolar astronomy. Backend-less design with server-rendered **React** using **Next.js 13**.
* [aircalc.velivole.fr](https://aircalc.velivole.fr/) - a thermodynamics air parcel calculator for weather, online version of [velitherm-visu](https://github.com/mmomtchev/velitherm-visu), raw **React**.
* [xc-score](https://www.velivole.fr/xc-score/) - online version of * [igc-xc-score](https://github.com/mmomtchev/igc-xc-score) - **vanilla JS** with a **custom webpack**.

# Mobile applications

* [velivole-mobile](https://github.com/mmomtchev/velivole-mobile) - the open-sourced mobile counterpart to velivole.fr, in its current iteration it is based on React Native / expo.

# Timewasters

* [r/dataisbeautiful](https://github.com/mmomtchev/data-is-beautiful) - a collection of data visualizations produced with [magickwand.js](https://github.com/mmomtchev/magickwand.js) and [node-ffmpeg](https://github.com/mmomtchev/node-ffmpeg)
* [EDCarnage](https://github.com/mmomtchev/EDCarnage) - an [Electron](https://www.electronjs.org/) tool for tracking stacked massacre missions in [Elite: Dangerous](https://www.elitedangerous.com/)

---

You can also check my Medium articles here: <https://mmomtchev.medium.com/>

Besides writing software, I have been trying, for almost 10 years now, to create a video as stunningly beautiful as [this one](https://www.youtube.com/watch?v=a71bZ1YG68U) that I saw when I started [paragliding](https://github.com/mmomtchev/mmomtchev/blob/master/AERIAL_SPORTS.md). I have come [a long way](https://www.youtube.com/user/momtchev) since I started in [2012](https://www.youtube.com/watch?v=fzTU611kfrw).

I also used to spent lots of time doing blue water sailing before my affair spiraled out of control.

I am an active member of the French Paragliding and Hang-gliding Federation <https://www.ffvl.fr> and (currently) an inactive member of the French Sailing Federation <https://www.ffvoile.fr>.

*Vous pouvez également lire mon introduction rapide à la thermodynamique appliquée au vol libre et le vol à voile ici: [THERMODYNAMIQUE.md](https://github.com/mmomtchev/velivole/blob/main/THERMODYNAMIQUE.md).*

*There is also an English version of my introduction to the basic concepts of Thermodynamics for Soaring Flight here: [THERMODYNAMICS.md](https://github.com/mmomtchev/velivole/blob/main/THERMODYNAMICS.md).*

# My current situation

![Eunuch Programmers](https://orel.garga.net/image-3175739551.jpg)

I am an unemployed IT engineer living on social welfare in a legal *no-man's-land* and working full-time on open-source software.

An ex-employer of mine who needed to prove something of sexual nature to his immediate entourage (all of this happened after I left his company):

 * Tried buying people in my entourage - I was in my late 20s - in order to play games of intimate nature with people I knew
 * Bought someone in my extended family in Bulgaria (I am a Bulgarian national who has spent most of his adult life in France) to serve as a cover story - in fact this person had little to do with most of this affair
 * Ended organizing false rape charges - on three different occasions - investigated twice by the French "police" - once going through a criminal courts - where the affair was covered up by the judges and a lawyer with a Wikipedia page who is the current president of the French ADL - as the affair had far reaching consequences for several politically exposed names in French IT business and politics - and involved Parisian night-life, various legal and illegal drugs, ED enhancers and unusual sexual practices - it was covered up without any proceedings or written documents
 * Normally, at this point, I should have received a huge severance package and everything should have stopped here - however as the guy who started it all was unable to admit the very reason that motivated the whole affair, everything did continue
 * My extended family in Bulgaria - who hardly knew me - fell easily to the promise that everything could be "fixed" - without going public with the sexual details - and by the time they realized their error, they had already committed numerous felonies - it should also be noted that the generation of my parents grew up during the Brezhnev era - when an affair involving sexual deviation by a man in position of power - and backed the by police - would have been absolutely impossible to win - fact that was ruthlessly exploited by elements having a political police background who were recruited by political means through the Council of Europe
 * At this point they tried extorting me with all the sexual elements of the affair - without any success - from this point on the French police started taking active part in the affair
 * In order to stop me from talking, my next employer took part in an absolutely shocking sexual harassment - including references to penises and viagra - all while pretending that it was all a coincidence and I was being psychotic
 * Absolutely the same game started in the paragliding world - by buying off people and offering sponsorships - most of them official - as at this point, the involvement of the police and courts offered total immunity
 * After a few years, I started developing a psychosomatic response linked to the pronunciation of certain words - those that were used to make me react in order to say that I was seeing things - at this point the affair passed through the official French work-illness commission - and it was once again covered up
 * When it became impossible to pretend that nothing happened, I was fired from my job - a psychiatrist appointed by my employer declared me psychotic - and then another round of lawsuits were covered up - adding many new lawyers and judges to the affair - including at the EU level - where I sued the French state for denying me the right to a fair trial
 * From this point on, I have been working on open source software while living on social welfare with a few bucks per day - and much of what happened earlier is being repeated in the open source projects I have worked in
 * My phone company, my bank and my insurance company have all been involved - frequently showing it clearly as an intimidation tactic
 * Last year, I was banned from the Node.js project after the French police came - illegally - to my home - with their guns drawn - to try to intimidate me - during the next few days all projects I had worked in posted simultaneous messages - and Node.js banned me because I said what had happened
 * By now, the affair has included companies such as Google, Facebook, X (Twitter), Microsoft and Amazon - many of them - especially Google - being involved in the penis games - and the extortion - for example recently my insurance company stole part of my food money from me by falsifying documents - and then they went to simultaneously send me an SMS along with a message in a Google-backed opensource project to show me that it was part of the extortion
 * It also includes all my online accounts - even things like my Discord, Steam, Spotify, Sonetel, CIG (producers of Star Citizen - this affair is very active there at the moment) - or for example even my [`uptimerobot.com`](https://uptimerobot.com) - where recently they did take part in a DoS against my website by Google, Facebook, Microsoft and Amazon

I am being offered a job - if I accept to never talk about this affair again - and accept that the penis game continues - because the organizer of the affair needs to be able to explain it.
 
I have started maintaining a list of the companies where the kind of deal I am offered is possible - there are some very large French and US companies in it - you can find it [here](https://github.com/mmomtchev/mmomtchev/blob/master/BUSINESS-AS-USUAL.md).

*I am maintaining a large number of binary Node.js projects - if you use any of them, you should know that I am ready to provide pre-built binaries for Macbooks with Apple Silicon if someone provides me a remote access to such hardware. If paying by the hour, expect about an hour of average daily usage. If you care only about the software and do not want be involved with the criminal affair, there are various options for anonymous sponsorship.*
