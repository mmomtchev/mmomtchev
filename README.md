[![Stand With Ukraine](https://raw.githubusercontent.com/vshymanskyy/StandWithUkraine/main/badges/StandWithUkraine.svg)](https://stand-with-ukraine.pp.ua)

***I AM CURRENTLY UNEMPLOYED AND IN A VERY DIRE FINANCIAL SITUATION, SEE BELOW***

![](https://garga.net/blue_anarchist.png)

* C / C++ / JavaScript / TypeScript
* Node.js / V8 internals
* GIS, Spatial Algorithms, HPC, Scientific and Parallel Computing, Numerical Weather Prediction
* React / React Native
* Linux, FreeBSD and OpenBSD kernel experience, especially the TCP/IP stacks and device drivers

I am an unemployed engineer that has been living on social welfare for the last 3 years. I am writing open-source software both as a pass-time and also to raise awareness about my situation - an employer organized false rape charges against me, used the French Judiciary to cover it up, then was able to drag my next employers into an absolutely shocking sexual harassment affair. The affair is sexually-motivated and involves a number of very high-profile persons in the EU business and politics. I am currently being extorted, with the help of the French state, to accept a job with a company that will continue the sexual harassment - which is the main motivation behind this affair. I have been somewhat involved in the past in the OSGeo and Node.js communities, but alas, they have both accepted to back the extortion because of the involvement of some of their sponsors. These have been joined by telecom operators, bank, the security of my residence, the social welfare services, Google and Twitter and pretty much everyone as the scandal would be extremely embarrassing for all involved parties. The French Paragliding Association is also backing the extortion - because of a number symbolic sponsorships - that they will be too embarrassed to admit. During the last few months, even Steam and Cloud Imperium Games have joined the extortion.

Currently I am living with a few bucks per day in order to force me to accept this job.

My projects:

# General Purpose Software

* [pymport](https://github.com/mmomtchev/pymport) - My current major project, full native compatibility of existing Python libraries with Node.js code
* [libnode](https://github.com/mmomtchev/libnode) - Node.js-as-a-shared-library allowing easy calling of JS code from compiled C and C++ applications through the Node-API (C) and `node-addon-api` (C++) interfaces with Ubuntu/Debian packages, created as part of GSoC 2022
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
* [intercity.js](https://github.com/mmomtchev/intercity) - a still unreleased Work-In-Progress for a dynamic data WMTS/WMS/WCS/WFS server for Node.js
* [geosub](https://github.com/mmomtchev/geosub) - A tool for partial downloading of bands and subwindows from geospatial raster datasets from cloud storage, it is an Amazon AWS-compatible replacement for NOAA's own [g2sub](https://nomads.ncep.noaa.gov/cgi-bin/filter_gfs_0p25.pl)
* [geoapi](https://github.com/mmomtchev/geoapi) - is an open-source server that can translate lat:long coordinates to postal codes (a free GeoNames API), it is based on the proprietary `geodata` in velivole
* [europe-geodata](https://github.com/mmomtchev/europe-geodata) - a collection of freely available geographical information for Europe

# Paragliding Software

* [igc-xc-score](https://github.com/mmomtchev/igc-xc-score) - an open-source solution for scoring paragliding XC competitions - which is a very interesting linear optimization problem with a *O(n^5)* worst case complexity
* [XC-DB](https://github.com/mmomtchev/xc-db) - an open-source interactive browser for paragliding flight tracks implemented in React, Redux and rlayers for the front-end and Node.js, Express, gdal-async and ndarray for the back-end
* [velitherm](https://github.com/mmomtchev/velitherm) - an open-source library of basic thermodynamics equations used in soaring weather
  - [velitherm-visu](https://github.com/mmomtchev/velitherm-visu) - is an online air parcel calculator in React that uses the library
* [igc-admin-analyze](https://github.com/mmomtchev/igc-admin-analyze) - a tool for analyzing IGC flight logs giving a percentage of time spent above given administrative divisions defined by their GeoJSON borders

# Timewasters

* [EDCarnage](https://github.com/mmomtchev/EDCarnage) - an [Electron](https://www.electronjs.org/) tool for tracking stacked massacre missions in [Elite: Dangerous](https://www.elitedangerous.com/)

---

You can also check my Medium articles here: <https://mmomtchev.medium.com/>

Besides writing software, I have been trying, for almost 10 years now, to create a video as stunningly beautiful as [this one](https://www.youtube.com/watch?v=a71bZ1YG68U) that I saw when I started [paragliding](https://github.com/mmomtchev/mmomtchev/blob/master/AERIAL_SPORTS.md). I have come [a long way](https://www.youtube.com/user/momtchev) since I started in [2012](https://www.youtube.com/watch?v=fzTU611kfrw).

I am also the creator and the maintainer of <https://www.velivole.fr> (French) and <https://www.meteo.guru> (English), the leading free soaring weather site in Europe and the author and maintainer of <https://isitplausible.com>. You can see an overview of velivole/meteo.guru [here](https://raw.githubusercontent.com/mmomtchev/mmomtchev/master/velivole.fr-Architecture-Overview.svg) and explore its API [here](https://www.velivole.fr/apidoc/).

I also used to spent lots of time doing blue water sailing before my affair spiraled out of control.

I am an active member of the French Paragliding and Hang-gliding Federation <https://www.ffvl.fr> and (currently) an inactive member of the French Sailing Federation <https://www.ffvoile.fr>.

*Vous pouvez également lire mon introduction rapide à la thermodynamique appliquée au vol libre et le vol à voile ici: [THERMODYNAMIQUE.md](https://github.com/mmomtchev/velivole/blob/main/THERMODYNAMIQUE.md).*

*There is also an English version of my introduction to the basic concepts of Thermodynamics for Soaring Flight here: [THERMODYNAMICS.md](https://github.com/mmomtchev/velivole/blob/main/THERMODYNAMICS.md).*
