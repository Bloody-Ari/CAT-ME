# CAT-ME (Carpinchos Aid Tools, Melissa Edition)

This project aims to aid the development of the CP-1 proyect. Which, for now, encompasses *Melissa*, our first experimental rocket engine.

## Disclamer ⚠

Most of this documentation, apart from code guidelines, should be taken with a grain of salt. This project is in development and the documentation is being "templated" first.
For instance, the file structure is layed out but not fully in use, so you may spot some things. Compilation instructions are not really there, there's no usage and some other details are still rough.

# Current Scope 🔍

- [x] Stoichiometric calculation of a chemical reaction involving 2 reactants and 2 products.
- [x] Recalculation of said reaction with a specific OF ratio.
- [x] Recalulation of the reaction based on *any* value as input with real-time updates.
- [ ] Basic Throat Calculations with CEA.
- [ ] Calculation of the same reaction multiple times (mostly for tests).
- [ ] CSV output.
- [ ] GUI

# Future Features 🚀
These are features which I want to include but need some pre-arrangements. Mostly real world tests. Some others just have less priority right now and will be developed after the current scope ones.
- Aproximate Chamber Temperature
- Aproximate Chamber Pressure
- General Calculations (Ae, Me, etc)
- Throat design hints (ie. A/A&#42;)

## Plausible Features 🌠
Some of this features I'd love to have, some we need, but may be made on another program, some may be too ambitious, or may be too hard to code to justify not using a pre-existing tool.
- Generalization of the reaction structure and functions. This could easily be achived using arrays but, at least for now, the scope is 1 fuel and 1 oxidizer.
- Throat design (I'd love to be able to automate this, not sure if it's too ambitious, openscad or freecad should do tho)
- Aproximation of Specific Characteristics (L&#42;, C&#42;)

# Documentation 📖

## Basic install

DISCLAIMER: I use Linux (x86-64), I haven't tested this anywhere else. I *may* do it in Windows or Raspberry Pi in the future. BUT it's plain C for now, so it should run in a potato as long as you can get a C compiler for it.

For now there are no external depencies or stuff needed, so you can just clone the repo and use make. The binary will be in bin/cat-me.

```bash
git clone https://github.com/Bloody-Ari/CAT-ME.git
cd CAT-ME
make
bin/cat-me
```

## Usage

`bin/cat-me`

Will prompt you a "table" with your current data and several numbered options to choose from. You enter the number of what you want to change (ie. 1 for fuel mass) and then the new value. You don't need to input the dimensions and there is no sanitization so, if you input a negative number or a letter instead of one, it's undefined behaviour.

If you are a bit unsure about how to use it, try this: To calculate how much aluminum you would need to react 54 ml of HCl you would choose 2 and input 54. That will give you the inforation but... you use 6.4 Mol HCl not the default, so you can choose 7 and input 6.4 which will recalculate everything! And while you are at it, why don't you change the OF ratio from 3 (stoichiometric) to 1.2 and, BAM! everything is recalculated again.
It may feel a bit unnatural but *for now* it's a CLI tool...

## Technical

For technical documentation please refer to [Documentation for developers](https://github.com/Bloody-Ari/CAT-ME/blob/main/docs/for_developers/introduction.md "Documentation for developers"), here are some basic things for orientation but you should refer to that if you are interested in the behind the scenes (no documentation about the inner working itself for now tho, the project is still in diapers).

There are a few options for compiling:

    make              # compilation
    make clean        # removes object and binary files
    make debug        # runs make clean and then compiles with debug symbols
    make run          # runs make clean, make and then runs the main binary
    make run-no-clean # runs make and then the main binary
    make directories  # creates the build/ and bin/ directories if they don't exist
    
If you want some topic in specific there's documentation for [file structure](https://github.com/Bloody-Ari/CAT-ME/blob/main/docs/for_developers/file_structure.md), [code guidelines](https://github.com/Bloody-Ari/CAT-ME/blob/main/docs/for_developers/code_guidelines.md) and a [general introduction](https://github.com/Bloody-Ari/CAT-ME/blob/main/docs/for_developers/introduction.md)
