# File Structure 📂
The file structure it's based around some modularity and ease of use. It's not meant to be perfect, but to be the most usable and understandable for everyone.

## Source Directory
The main idea is to have an src directory which contains all the source code written for the project. This code would be split, at least for now, into source .c files (with the expansion of the projects this files would have to split into several sub directories), and the header files .h, which include (in separate files) declarations of types and functions.

Basic example of the source directory:

└── src

│	└── include

 │ 	   │ ├── reaction_functions.h
 
│    │   └── reaction_types.h

 │   ├── main.c
 
  │  └── reaction_functions.c

## Bin and Build Directories  🛠
Both of these directories are to be used for compilation, the bin directory should be used to store the needed binaries to run the tool and, the build directory, to store temporary files like object files. This means that if you just want the binary, it should be in the /bin directory.

These directories should be cleaned by *make clean*, here's a simple example:

└── build

│   └── reaction_types.o

│   ├── bin

│   │  └── main_executable.out


## Lib Directory

This directory is destined to store external libraries. It's empty for now tho.

## Documentation Directory 📖
The documentation directory is split between two main subdirectories, a user oriented one, and a development focused one.

### User Documentation 

This directory *will* have information about the general usage of the tool, how to make a basic install and maybe some other information like tips and tricks. For now it's pretty empty and don't expect more than a simple page.

### Technical Documentation

This directory contains information targeted to developers and collegues. Here you will find information like the code guidelines, (in the future) a detailed guide about building, some in-depth details and an introduction.
