# Technical Introduction to the Project
This file includes an introduction to the project aimed at developers and those who want some in depth information.
It should be enough for those who just want a little peek at the backstage, but don't want to fully inmerse themselves in the code.

# General Idea 🔭
In the technical side of things the main idea behind te inner workings of this project is an object oriented programming paradigm, using a class to define the properties of a reaction. The core loop defines the stoichiometric relationship and then applies it to the variable inputs of the user. After making the first calculation it gets recalculated using an introduced Oxidizier to Fuel ratio and, finally, it computes not only the moles but also the mass and volume needed along with the mass and volume of the products.

This features don't represent the full planed extent of the program, being the next most important features the capability of doing the calculations on a range of inputs and outputting them not only to the screen but also to a CSV file.

Once this gets fully developed the next objectives would be to predict general characteristics like chamber pressure and, if deemed possible, an estimation of thrust and even design variables like throat and exit area.

# Why C? 🧙‍♂️

Are you wondering why are we using C over Python, C++, Matlab or Rust? Well, this section covers just that!

I am writting this as the, at least for now, main developer of the team, so maybe it's not shared by everyone. But in any case, it could be migrated to another language pretty easily (let's rewrite it in rust?).

## Industry Compliance 🏭
The main languages in the aerospace engineering scene are C/C++ (mainly microcontrollers, space computers, etc), Ada and Fortran (yes, I am serious), and python (data science and some not so critical code). So, by definition, this project should use one of them. Ideally if we use another language it will be on another repository unless it's just a snippet or interface.

##  Familiarity 👩‍👩‍👦
I have a C background and I am comfortable with it, it's a static typed language, fast, clean, small and works everywhere. I personally think it works *with* you and *with* the machine, something that it's sometimes hard to get.

## KISS 💋
C is high level enough to be simple in every way without obscuring the technical side. It doesn't have a ton of features, I think every C programmer can understand a snippet of code down to machine level just by looking and thinking about it for a while. And, also thanks to this simplicity, it can be fairly understood by everyone who speaks a bit of english and some basic programming.

It forces you to be a bit more diligent with your code, but it's not like C++ which forces you to be a proper adult or you get you leg blown out of the window.

## Cleanness 🧹
Following with the previous section, having a "small" language allows you to write easy to read code, the most "magical" and hard to read things are macros, and they get better with time. The general syntax is simple and consistant, it makes it hard to write code that's hard to understand (as long as you are not doing quick inverse square root type of things).
It may have a steeper learning curve or not be as clear, but in my opinion is more transparent than Python, which shares some of this advantages, but can get too messy too fast.

## What about MATLAB? 📊 ❓
This project could easily be done in matlab, even with graphs! I could do them with gnuplot or maybe some lightweight library but, honestly, not one of us knows MATLAB and it's a bit different from other languages. Also, we kinda need this tool, so it was prefered to use a familiar language in which the tool could be easily and quickly developed without risking quality.

## Afterword 🖋️

As it has been said before, writing the project in C allows it to be easily portable to another language, so the "need" for plots or a GUI may be the main contributor to a rewrite, be it MATLAB, python or another language. This could even allow the implementation of figures or some other graphics.

It may not be wisest idea to write something with the "it will get rewritten later" mentality (I know this from experience), but I also think it's important to not forget that this project probably won't get to that scale either and if it does the requirements and time scale will change too. So, in turn, it's not like this **will** get rewritten, but it *may* get rewritten and, if it does, I want to be a dwm to dwl, a clean adaptation to new needs.

# Basic File Structure 📂
 proyect folder

├── bin	

│   └── target files, basically the main binary directory.

├── build

│   └── object files, temporary build files.

├── docs

│   ├── for_developers

│   │   └── Documentation aimed at fellow devs who want to get involved or check the code.

│   └── for_users

│   │   └── More thorow information about the usage of the tool.

├── lib

│       └── External libraries.

└── src

│    ├── include

│    │   └── Header files, definitions.

│    └── Source code files.

├── Makefile

└── README.md

# Some Code Style Details 🔍
The code follows the "Power of Ten" rules along some other specific anotations or recommendations
The code follows a set of rules derived from "The Power of Ten" along some anotations and recomendations. 

The code should be as simple and readable as possible, following the KISS principle and not being overly complicated unless necessary.

If you want to take a quick look at the code take into account the following information:
1. Indentations are made with tab stops of 2 blanks.
2. The code is written in ansi C.
3. Types, function declarations and function definitions are placed on different files.
4. Variables names include the dimentions of their values.
5.  Capitalization style:

| Thing/Concept | Style      |
|---------------|------------|
| variables     | snake_case |
| types         | snake_case |
| constants     | UPPER_CASE |
| functions     | camelCase  |
