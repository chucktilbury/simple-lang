# NOTES
This file contains random notes and a TODO list.

## TODO
* Read up on Graphiz dot notation so that a map of the parsed syntax can be generated for verification.
* Tighten up the names of things. For example, operators are always call ``op``. Rules need to be factored such that there is one operator in an alternative.
* Think about expressions and how those will be implemented.

## Token management while parsing
The problem is that if a particular alternative failes to parse, those tokens might be needed to parse another alternative. So the tokens are stored into a queue until they are consumed by either a successful rule recognition or by an error. If an alternative fails, then the scanner returns the tokens from the queue instead of reading fresh tokens. Since the rules are recursive, then the current rule must only consume the tokens that were read to try and complete it. There will certainly be other tokens that must not be consumed. So the problem is how to know how many tokens....

Maybe each parse function has its own queue instead of putting that in the global parser status. Maybe the parser status is created when a parse function is entered instead of passing it around. Or the elements in the status are simply locals.

## Parse function error detection
The execution of the parse functions calls non-terminal functions until a terminal symbol is found. If that symbol is the one that is expected, then the AST struct is created and next token is read and execution proceeds from that point until there are no more tokens in that production rule. If there are no more rule elements and none have failed to match at this point, then the rule succeeds. If at some point a match fails, then the non-terminal function returns without searching for more tokens and the tokens that have been read are returned to the token stream to be read again for the next alternative line in the rule.

**Problem:** When the execution recurses into a non-terminal, it is not known if it can be considered an error until all of the options are exhausted. If, in that case, there were no matching rules, then the production fails and an error can be published and recovery entered. Otherwise the production succeeds and the AST data structure is returned.
**Solution:** Pass a flag in the parser state. If a match succeeds, then the flag is set and no more options are tried. If the flag is not set when the rule runs out of options, then the production fails and an error is produced. Note that the grammer should be set up so that the most likely match is first in the list of alternatives for efficiency.

When the execution reaches a terminal symbol, but the production fails, then that symbol is added to a list. If an error is created, then the list is used to create the error in the form of ```Error: expected x, y, or z, but got X```.

## Parse errors (more)
When a parse error is detected, the function that found it returns NULL signifying that it did not succeed. The function clears the ``found`` local variable to handle flow in a generic way. The problem is that it is hard to know how many functions this backs out. Does it naturally end? Or is there more information required?

## AST data structure.
Some of the data structures are for a list and so they have a first and last entry. Things that can go in a list have to have a next pointer in them, no matter what the rest of the struct looks like.

In some cases the terminals or non-terminals are redundant and only one of them needs to be kept.

Some of the keywords are significant to keep and others are not. All operators are significant (by definition) but none of the punctuation is (by definition). Also, all of the constructed items have their own type that must be respected in the AST data structure.

In the case where one of a selection of non-terminals is the object of the AST node, then it is a void* instead of the actual type.

Knowing what is in the AST data structure is required when parsing, so we can store the elements as they are created. Pointers to the data should be in the function preamble so that they can be assigned when this object's ast entry is created.

Probably going to have to add some kind of a hint to the rules so the generator can tell how to generate the data structures and the code.
