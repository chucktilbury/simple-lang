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

    #pp(tokens)
    #pp(rules)
    print("%d tokens and %d rules loaded"%(len(tokens), len(rules)))

    return (tokens, rules)

def mk_backup_file(fname):

    bak = fname+".bak"
    if os.path.exists(fname):
        if os.path.exists(bak):
            os.remove(bak)
        os.rename(fname, bak)

def gen_token_header(data):

    mk_backup_file('token_types.h')
    with open('token_types.h', 'w') as fp:
        fp.write("/* generated file. DO NOT EDIT */\n")
        fp.write("#ifndef _TOKENS_H\n")
        fp.write("#define _TOKENS_H\n\n")
        fp.write("typedef enum {\n")
        s = " = 1000,"
        for item in data[0]:
            fp.write("    %s%s\n"%(item, s))
            s = ","
        fp.write("} token_t;\n\n")
        fp.write("typedef struct {\n")
        fp.write("    token_t type;\n")
        fp.write("    const char* str;\n")
        fp.write("    const char* name;\n")
        fp.write("} token_value_t = {\n")
        for item in data[0]:
            fp.write("    {%s, \"\", \"\"},\n"%(item))
        fp.write("};\n\n")
        fp.write("#endif /* _TOKENS_H */\n\n")

def gen_parser_header(data):

    (tokens, rules) = data

    mk_backup_file('parser.h')
    with open('parser.h', 'w') as fp:
        fp.write("/* generated file. DO NOT EDIT */\n")
        fp.write("#ifndef _PARSER_H\n")
        fp.write("#define _PARSER_H\n\n")

        fp.write("#include <stdio.h>\n")
        fp.write("#include <stdlib.h>\n")
        fp.write("#include <stdint.h>\n")
        fp.write("#include <stdbool.h>\n\n")

        fp.write("#include \"ast.h\"\n\n")

        fp.write("typedef struct _parser_state_t_ {\n")
        fp.write("    bool error; /* set if handling an error */\n")
        fp.write("    const char* emsg;\n")
        fp.write("    int errors;\n")
        fp.write("    int warnings;\n")
        fp.write("} parser_state_t;\n\n")

        fp.write("/* parse function headers */\n")
        fp.write("parser_state_t* create_parser_state();\n")
        fp.write("void destroy_parser_state(parser_state_t* state);\n\n")

        for item in rules:
            fp.write("ast_%s_t* parse_%s(parser_state_t* state);\n"%(item, item))
        fp.write("\n")

        fp.write("#endif /* _PARSER_H */\n\n")

def gen_ast_struct(fp, data):
    """
    """

def gen_ast_header(data):

    (tokens, rules) = data

    mk_backup_file('ast.h')
    with open('ast.h', 'w') as fp:
        fp.write("/* generated file. DO NOT EDIT */\n")
        fp.write("#ifndef _AST_H\n")
        fp.write("#define _AST_H\n\n")

        fp.write("typedef enum {\n")
        s = " = 1100,"
        for item in rules:
            fp.write("    AST_%s_T%s\n"%(item, s))
            s = ","
        fp.write("} AST_TYPE_T;\n\n")

        fp.write("/* this exists so that we can find out what the type is, even\n")
        fp.write("   if the pointer of of type void */\n")
        fp.write("#define TYPEOF(p) ((ast_type_t*)(p))->type;\n")
        fp.write("typedef struct _ast_type_t_ {\n")
        fp.write("    AST_TYPE_T type;\n")
        fp.write("} ast_type_t;\n\n")

        fp.write("/* ast data structures and create function protos. */\n")
        for item in rules:
            fp.write("/*\n")
            fp.write(" *    %s\n"%(item))
            for line in rules[item]:
                fp.write(" *        | %s\n"%(line))
            fp.write(" */\n")
            fp.write("typedef struct _ast_%s_t_ {\n"%(item))
            fp.write("    ast_type_t type;\n")
            fp.write("} ast_%s_t;\n"%(item))
            fp.write("ast_%s_t* create_%s();\n\n"%(item, item))
        fp.write("#endif /* _AST_H */\n\n")

def gen_ast_src(data):

    (tokens, rules) = data
    mk_backup_file('ast.c')
    with open("ast.c", "w") as fp:
        fp.write("/* generated file. DO NOT EDIT */\n")
        fp.write("#include <stdio.h>\n")
        fp.write("#include <stdlib.h>\n")
        fp.write("#include <stdint.h>\n")
        fp.write("#include <stdbool.h>\n\n")

        fp.write("#include \"ast.h\"\n")
        fp.write("#include \"mem.h\"\n\n")

        for item in rules:
            fp.write("/*\n")
            fp.write(" *    %s\n"%(item))
            for line in rules[item]:
                fp.write(" *        | %s\n"%(line))
            fp.write(" */\n")
            fp.write("ast_%s_t* create_%s() {\n"%(item, item))
            fp.write("    ast_%s_t* ptr = _alloc_ds(ast_%s_t);\n"%(item, item))
            fp.write("    return ptr;\n")
            fp.write("}\n\n")

def gen_parse_func(fp, name, data):
    '''
    '''

def gen_parser_src(data):

    (tokens, rules) = data
    mk_backup_file('parser.c')
    with open("parser.c", "w") as fp:
        fp.write("/* generated file. DO NOT EDIT */\n")
        fp.write("#include <stdio.h>\n")
        fp.write("#include <stdlib.h>\n")
        fp.write("#include <stdint.h>\n")
        fp.write("#include <stdbool.h>\n\n")

        fp.write("#include \"ast.h\"\n")
        fp.write("#include \"tokens.h\"\n")
        fp.write("#include \"scanner.h\"\n")
        fp.write("#include \"parser.h\"\n")
        fp.write("#include \"mem.h\"\n\n")

        for item in rules:
            fp.write("/*\n")
            fp.write(" *    %s\n"%(item))
            for line in rules[item]:
                fp.write(" *        | %s\n"%(line))
            fp.write(" */\n")
            fp.write("ast_%s_t* parse_%s(parser_state_t* state) {\n"%(item, item))
            fp.write("    ast_%s_t* ptr = create_%s();\n"%(item, item))
            fp.write("    return ptr;\n")
            fp.write("}\n\n")

if __name__ == '__main__':

    data = load_all('grammar.txt')

    gen_token_header(data)
    gen_ast_header(data)
    gen_ast_src(data)
    gen_parser_header(data)
    gen_parser_src(data)
