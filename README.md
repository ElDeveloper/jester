jester
======

A tool to view and edit [biom-format](http://biom-format.org/) files (.biom).

Jester is currently under development.

To build and run:

```
qmake
make
./jester
```

Jester requires that you have Qt installed, as well as the amalgamated version
of [JsonCpp](http://jsoncpp.sourceforge.net/) in the same directory as this
README.md file.

TODO:

- BIOM file parser (dense and sparse)
- BIOM file writer (dense and sparse)
- display BIOM files
- allow editing of BIOM files
- saving BIOM files
- converting BIOM files (classic -> BIOM -> classic)
- sorting
- filtering
- validation
- more operations (domain specific)?
