# Simple
The simple language compiler. Simple is a computer programming language that attempts to take the best parts of C and Python and combine them into a single language. The idea is to have a language that is as simple as possible, but can still represent any construct that is used for application development. (i.e. Python) The Simple language attempts to be very self-consistent for syntax and semantics, but also attempts to elimiate unnessessary or redundant syntax and boilerplate.

## Features
* Object oriented.
* Strong type system.
* Managed memory.
* Whitespace insensitive. (jab at Python)
* Uses semicolons for comments. (jab at C)
* String, dict, and list native data types.
* Formatted strings.
* Uses C as intermediate representation.
* Robust interface to external libraries.
* Exceptions.
* Iterators.

## Missing
* Pointers.
* Bitwise operations.
* 64 bit numbers only.

## Implementation
Simple is implemented as a generated recursive decent parser that has its own parser generator. The parser generator is written in Python, but it emits C code. There is no attempt to use the latest advances in technology to implement the compiler unless it make the implementation more simple, obvious, and easy to read. For example, the parser generator does not generate a single GOTO statement. It generates a parser that looks like one that I might create without the use of a generator. The grammer specification is as simple as possible.
