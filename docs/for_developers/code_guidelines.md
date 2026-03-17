# Coding Guidelines

## Hard Rules
These rules are derived from "The Power of Ten", most of them are just a copy paste with maybe some annotations, in case of doubt refer to the original document.

1. The code must be verifiable by static analyzers and the compiler, most rules are based on this.
2. Simple flow control constructs. No gotos or recursion, be it direct or indirect.
3. All loops must have a fixed upper-bound.
4. Only stack memory, all memory should be allocated at initialization.
5. No function should be longer than what can be easily be tracked on a single screen. This usually means no more than about 60 lines, with a hard cap on 100.
6. There sould be an average of two asserts per function, which must be used to check for anomalous conditions that should **never** hapen in real-life. When an assertion fails an explicit recovery action must be taken, like returning an error condition to the function. Any assertion that can never fail or hold breaks this rule.
7. Objects must be declared at the smalles possible level of scope.
8. The return of a non-void function must be checked by each calling function and the validity of parameters must be checked inside each function. If the return value is non important it must be casted to *void* to explicitly state reflect it.
9. Keep macro usage at a minumum. Only use it when it's necesary. Don't use compile time dependant variables or "magic". The preprocessor is very powerful and obscure tool, making it a time bomb, (it's magic until everything breaks and no one can fix the macro and a whole bunch of code needs to be rewritten without or around it).
10. No more than one level of dereferencing. (This generally means no pointers to pointers). Function pointers are not allowed.
11. All code must be compiled with the most pedantic and unsufferable flags. All code must be checked with a static source code analyzer. No warning must be present, if you see a "wrong" or "out of place" warning refactor the code, if the code is fine but confusing the analyzer or the compiler, the code is not right and should be written in a more trivial way.
12. Ansi C.
13. No non-ascii characters on the code. (This only applies to the code itself, so feel free to use emojis while commenting or making commits)

## "Soft" Rules
This rules are derived from personal preference, mostly encompassing stylistic choices and recommendations. The main idea behind them is to make the code homogeneus, but they can be taken more as a recommendation than a strict rule. Just make sure that the "incorrect" code is encapsuled on it's own file or structure.

This doesn't mean you don't have to follow them, it just means that they can be changed down the line and, in case you break some of them, just keep it contained in a single file. For example, if you are going to use a different naming convention or capitalization, just make sure that the interaction with files that *do* follow these rules does, in fact follow the rules too.
For instance, if you want to make a feature which takes one value and returns another, make sure that when it returns a value it follows the conventions, even if the rest of the code doesn't. Which ensures that although your code doesn't follow the guidelines, the interactions with the rest of the project do. This means that if someone else needs your code they won't need to bother with *how* you've written your code to interface with it.

1. Indenting: 2 blanks TAB.
2. Use a color column, at least at 70. (I personally use 80).
3. Be as civil as possible while commenting and making commits, this isn't gamedev.
4. KISS. Don't be smart, for example, unless it's crucial (which in 99% of times isn't) don't save 10 cpu cycles while sacrificing the readibility of a whole process.
5. In case a variable has a dimension, write it. (ie. oxidizer_g and oxidizer_mol)
6. Names should clearly state what everying is, if you can't get what a line of code does only by reading it in context then the naming isn't clear enough. (Context means the function or loop as an isolated world).
7. Capitalization rules:

| Thing/Concept | Style      |
|---------------|------------|
| variables     | snake_case |
| types         | snake_case |
| constants     | UPPER_CASE |
| functions     | camelCase  |
