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

Jester requires that you have Qt installed (tested on 4.8.3).

Jester includes the amalgamated version of the
[JsonCpp](http://jsoncpp.sourceforge.net/) library, which is used to read and
write JSON files. All credit goes to Baptiste Lepilleur, the author of JsonCpp,
for this excellent tool. I am including this dependency as part of the Jester
project because it is lightweight and I had to make a couple of fixes to the
header files to get the amalgamated version to work correctly. Please see the
copyright and license disclaimer in the JsonCpp files included in this
repository for more details.

TODO:

- add exception handling
- fix segfault when hitting the exit button
- ~~BIOM file parser (dense and sparse)~~
- BIOM file writer (dense and sparse)
- ~~display BIOM files~~
- ~~allow editing of BIOM files~~
- opening BIOM files (command line and GUI)
- saving BIOM files
- converting BIOM files (classic -> BIOM -> classic)
- sorting
- filtering
- validation
- more operations (domain specific)?
