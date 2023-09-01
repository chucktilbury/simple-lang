import os
from pprint import pprint as pp

def load_tokens(fp):
    '''
    Load the tokens into a list.
    '''
    tokens = []
    for line in fp:
        if line.strip() == "%tokens":
            for line in fp:
                if line.strip() == "%tokens":
                    return tokens
                else:
                    s = line.strip()
                    if len(s) > 0 and s[0] != '#':
                        s = s.split()
                        tokens = tokens + s
    return ['none found']

def load_rules(fp):
    '''
    Load the rules into a dictionary where the rule name is the index and the
    rules are in a list of strings.
    '''
    rules = {}
    for line in fp:
        if line.strip() == "%rules":
            for name in fp:
                if name.strip() == "%rules":
                    return rules
                else:
                    name = name.strip()
                    if len(name) > 0 and name[0] != '#':
                        rules[name] = []
                        for line in fp:
                            if len(line.strip()) == 0:
                                break;
                            else:
                                # If there is a comment embedded in the rule,
                                # then don't stop reading lines, but don't
                                # output it either.
                                if line.strip()[0] != '#':
                                    x = line.split('#') # strip trailing comment
                                    rules[name].append(x[0].strip()[2:])

def load_all(fname):
    '''
    Load the rules and the tokens and return a tuple.
    '''
    with open(fname, 'r') as fp:
        tokens = load_tokens(fp)
        rules = load_rules(fp)

    return (tokens, rules)

if __name__ == '__main__':

    (tokens, rules) = load_all('grammar.txt')
    #pp(tokens)
    #pp(rules)
    print("tokens: %d and rules: %d"%(len(tokens), len(rules)))

    with open('grammar.y', 'w') as fp:
        fp.write("\n%{\n%}\n\n")
        for item in tokens:
            fp.write("%%token %s\n"%(item))

        fp.write("%%\n")
        for name in rules:
            s = ':'
            fp.write("%s\n"%(name))
            for item in rules[name]:
                fp.write("    %s %s\n"%(s, item))
                s = '|'
            fp.write("    ;\n\n")
        fp.write("%%\n")
