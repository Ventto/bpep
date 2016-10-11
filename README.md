Bpep
====

*Bpep is an Ethernet protocol Wireshark plugin.*

**This plugin is currently experimental.**

## Requirements

  1. *cmake*
  2. *wireshark-qt* (fix potential dependencies for the clone version)

## Wireshark installation

### Download and Build

```
$ git clone https://github.com/wireshark/wireshark.git
$ cd wireshark/
$ mkdir build && cd build && cmake ..
$ make
```

### Run

```
$ pwd
<path>/wireshark/build
$ cd run/
$ WIRESHARK_RUN_FROM_BUILD_DIRECTORY=1 ./wireshark
```

## Plugin Installation

### Download

* Clone the plugin repository where it suits you:

```
$ git clone https://github.com/venthom/bpep.git
```

* For purpose of ergonomy, you could create a symbolic link of the main
top-level plugin source directory:

```
$ ln -s bpep <path>/wireshark/plugins/bpep
```

### Before Building

Source: [wireshark/doc/README.plugins](https://code.wireshark.org/review/gitweb?p=wireshark.git;a=blob_plain;f=doc/README.plugins)

* Go to the plugins directory:

```
cd ~/wireshark/plugins
```

* Copy the `Custom.m4.example` and `Custom.make.example` files to files of the
same name but without the ".example" suffix:

```
$ cp Custom.m4.example Custom.m4
$ cp Custom.make.example Custom.make
```

* Edit  `Custom.m4` and `Custom.make` and replace *foo* by the plugin name
*bpep*


### Build

* In the main top-level Wireshark source directory:

```
$ cd build/
$ cmake .. -DCUSTOM_PLUGIN_SRC_DIR="plugins/bpep"
$ make
```

* After compiling the plugin, you could find the shared library `bpep.so`
in `./run/plugin/`.

* To add the plugin to Wireshark if the latter is installed on the system,
there's nothing for it but to copy the .so file into
`/usr/lib/wireshark/plugins/<version>/`.

## TODO

* Compile the plugin without the whole Wireshark sources
