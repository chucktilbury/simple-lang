# NOTES
This file contains random notes and a TODO list.

* todo: Fix filebuf so that it never actually frees the file stack. When an error is returned after the last file is closed, then the name of that file, the line and column numbers should be returned instead of "no file" and -1.
* todo: Fix the scanner so that a copy of the token can be returned so that it can be stored in the AST data structure for future reference, especially for error generation. For a quick patch, just make a function that does a deep copy.
* todo: Finish scanner to fill in the token value completely when a token is recognized.
* problem: How to tell what to put in the AST struct. It looks like I want to create the ast struct in the python data structure so that I can refer to it as the parse happens.

## Parse function error detection
The execution of the parse functions calls non-terminal functions until a terminal symbol is found. If that symbol is the one that is expected, then the AST struct is created and next token is read and execution proceeds from that point until there are no more tokens in that production rule. If there are no more rule elements and none have failed to match at this point, then the rule succeeds. If at some point a match fails, then the non-terminal function returns without searching for more tokens and the tokens that have been read are returned to the token stream to be read again for the next alternative line in the rule.

**Problem:** When the execution recurses into a non-terminal, it is not known if it can be considered an error until all of the options are exhausted. If, in that case, there were no matching rules, then the production fails and an error can be published and recovery entered. Otherwise the production succeeds and the AST data structure is returned.
**Solution:** Pass a flag in the parser state. If a match succeeds, then the flag is set and no more options are tried. If the flag is not set when the rule runs out of options, then the production fails and an error is produced. Note that the grammer should be set up so that the most likely match is first in the list of alternatives for efficiency.

When the execution reaches a terminal symbol, but the production fails, then that symbol is added to a list. If an error is created, then the list is used to create the error in the form of ```Error: expected x, y, or z, but got X```.

## AST data structure.
Some of the data structures are for a list and so they have a first and last entry. Things that can go in a list have to have a next pointer in them, no matter what the rest of the struct looks like.

In some cases the terminals or non-terminals are redundant and only one of them needs to be kept.

Some of the keywords are significant to keep and others are not. All operators are significant (by definition) but none of the punctuation is (by definition). Also, all of the constructed items have their own type that must be respected in the AST data structure.

Knowing what is in the AST data structure is required when parsing, so we can store the elements as they are created. Pointers to the data should be in the function preamble so that they can be assigned when this object's ast entry is created.