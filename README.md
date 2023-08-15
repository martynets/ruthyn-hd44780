Copyright (C) 2017 Andriy Martynets [martynets@volia.ua](mailto:martynets@volia.ua)<br>
See end of this file for license conditions.

-------------------------------------------------------------------------------

#### Introduction
Usual constraint of a localized embedded application is the character set support by the output devices used by the implementation. As the periphery used in this domain normally is limited in resources and doesn't provide means for localization the application has to combine available means with custom character generators and non-standard coding.

Real example is Cyrillic charset implementation by Epson's dot-matrix LCD controller based on HD44780 chip. It partially implements Russian alphabet which in turn is a subset of Ruthyn alphabet that covers Cyrillic based Slavic languages. This forces an application to convert string literals to character codes above 127 for Cyrillic symbols which patterns are implemented by the ROM character generator, to codes below 127 for symbols which look similar to some ASCII symbols and the rest to codes which correspond to patterns in the user defined character generator. Certainly, this leads to a non-standard code page.

To have the application to operate with string literals coded with the non-standard code page we need the compiler to translate source code from its code page to the non-standard code page. Fortunately `gcc` offers such a functionality. The code page for the binary output can be selected by its `exec-charset` option (`-fexec-charset=<codepage>`). It employs `iconv` function for the conversion to be done. The GNU implementation of the function (it is part of the GNU C Library) uses external modules for conversion functions (`gconv`) for each particular code page. Normally systems come with wide range of modules for most standard code pages. Additionally the `iconv` function provides facilities to specify locations for custom modules. To solve our problem what we need is to develop a module for the non-standard code page, request the compiler to generate output string literals using our custom code page and inform the `iconv` function about the location of the module.

The intention of this project is to provide an example of the solution which can be used as a template for a particular case. It is based on framework example taken from [GNU C Library documentation](https://www.gnu.org/software/libc/manual/html_node/glibc-iconv-Implementation.html) and the latest `skeleton.c` file. As we are interested only in output coded in non-standard way the conversion function implements unidirectional conversion: from the compiler's internal representation (UCS-4 encoded ISO 10646) to the target non-standard code page. It is expected that embedded applications operate with 8 bit character sets. Thus the conversion function is the case of non-stateful conversion from wide character to character types. The `iconv` concept was developed to cover cases of any complexity and much of its functionality isn't involved in our solution and wasn't ever tested.

This example implementation solves the case described above and implements `gconv` module for conversion function to support Ruthyn alphabet on Epson HD44780 dot-matrix LCD controller.

#### Software Requirements
The source code of the `ruthyn-hd44780` module contains calls to standard C library functions only, is specific for the GNU C Library implementation and expects ISO 10646 encoding is used for wide character type. Thus it most likely can be compiled for any POSIX compliant system with GNU C Library installed but the author tested it in GNU/Linux environment only.

To compile the module from the source code the following packages must be installed on a GNU/Linux system:

- gcc
- make
- libc-dev
- sed

#### Downloading
The latest released version of the `ruthyn-hd44780` module can be checked by the link below:

https://github.com/martynets/ruthyn-hd44780/releases/latest

Current development version can be downloaded using the following link:

https://github.com/martynets/ruthyn-hd44780/archive/master.zip

The `ruthyn-hd44780` project is also available via Git access from the GitHub server:

https://github.com/martynets/ruthyn-hd44780.git

#### Installation
To compile and install the module issue the following commands from the directory containing the source:
```
make
make install
```
By default the module gets installed to `../gconv` directory. If this is not the preferred destination either the `Makefile` needs to be altered to modify the `TARGETDIR` variable or the destination must be specified in the command line in format:
```
make TARGETDIR=../test install
```
where `../test` should be replaced with the desired value.
> Note: it is advised not to install custom modules to the system default `gconv` directory (e.g. `/usr/lib/x86_64-linux-gnu/gconv`). But if it is selected the last command requires root privileges and must be followed by the `iconvconfig` command.

To uninstall the module issue the following command from the same directory (the same note and `TARGETDIR` guidance are applicable here):
```
make uninstall
```
For more customizations see the `Makefile` internal variables and comments.

#### Usage
To get the source compiled with desired custom code page used for string literals coding the following command line can be used as an example:
```
GCONV_PATH=../gconv gcc -fexec-charset=ruthyn -c -o main.o main.c
```
where `../gconv` is the directory the custom module is installed in
and `ruthyn` is the name or alias of the custom code page implemented
by the module.

Note that the gconv files are not needed at run-time, only compilation.

#### Example source code

Please see the file [ruthyn-example.c](ruthyn-example.c) for a program
with literal strings encoded in UTF-8 that output as the custom code
page when compiled as described above. You may use `make test` to
compile the example and run it.

#### Bug Reporting
You can send `ruthyn-hd44780` bug reports and/or any compatibility issues directly to the author [martynets@volia.ua](mailto:martynets@volia.ua).

You can also use the online bug tracking system in the GitHub `ruthyn-hd44780` project to submit new problem reports or search for existing ones:

  https://github.com/martynets/ruthyn-hd44780/issues

#### Change Log
|Publication Date| Version | Changes |
|----------------|---------|---------|
|Jan 25, 2017 |1.0|Initial release|

#### License
Copyright (C) 2017 Andriy Martynets [martynets@volia.ua](mailto:martynets@volia.ua)<br>
This file is part of `ruthyn-hd44780`.

`ruthyn-hd44780` is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.

`ruthyn-hd44780` is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
`ruthyn-hd44780`.  If not, see <http://www.gnu.org/licenses/>.
