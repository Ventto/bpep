Bpep
====

[![Build Status](https://travis-ci.org/Ventto/bpep.svg?branch=master)](https://travis-ci.org/Ventto/bpep) 
[![License](https://img.shields.io/badge/license-GPLv2-blue.svg?style=flat)](https://github.com/Ventto/bpep/blob/master/COPYING) 
[![Version](https://img.shields.io/badge/version-v0.1.0-blue.svg?style=flat)](https://github.com/Ventto/bpep/releases) 
[![Status](https://img.shields.io/badge/status-experimental-orange.svg?style=flat)](https://github.com/Ventto/bpep/) 

*Bpep is a base for Ethernet protocol Wireshark standalone plugin.*

**Under construction, currently it is just a model base.**

## Dependencies

### Packages

* *glib2*
* *wireshark-common*

### Ubuntu

```
 $ sudo add-apt-repository -y ppa:wireshark-dev/stable
 $ sudo apt-get update
 $ sudo apt-get install libglib2.0-dev libwireshark-dev
```

### Arch

```
$ sudo pacman -S glib2 wireshark-common
```

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
