Bpep
====

[![Build Status](https://travis-ci.org/Ventto/bpep.svg?branch=master)](https://travis-ci.org/Ventto/bpep) 
[![License](https://img.shields.io/badge/license-GPLv2-blue.svg?style=flat)](https://github.com/Ventto/bpep/blob/master/COPYING) 
[![Version](https://img.shields.io/badge/version-v0.1.0-blue.svg?style=flat)](https://github.com/Ventto/bpep/releases) 
[![Status](https://img.shields.io/badge/status-experimental-orange.svg?style=flat)](https://github.com/Ventto/bpep/) 

*Bpep is an Ethernet protocol Wireshark plugin.*

**This plugin is under construction.**

## Requirements

* *cmake*
* *wireshark*

## Build

```
$ git clone https://github.com/venthom/bpep.git
$ cd bpep
$ mkdir build
$ cmake ..
$ make
```

## Install

* Install the plugin in `~/.config/wireshark/plugins/`

```
$ make install
```
