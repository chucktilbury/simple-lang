import os
from pprint import pprint as pp

def load_tokens(fp):
    '''
    Load the tokens into a list.
    '''
    tokens = {}
    for line in fp:
        line = line.strip()
        if line == "%tokens":
            for line in fp:
                line = line.strip()
                if line == "%tokens":
                    tokens['keywords'].sort()
                    return tokens
                else:
                    if line == "%keywords":
                        tokens['keywords'] = []
                        for line in fp:
                            line = line.strip()
                            if line == "%keywords":
                                break
                            else:
                                tokens['keywords'].append(line.split(','))
                    elif line == "%operators":
                        tokens['operators'] = []
                        for line in fp:
                            line = line.strip()
                            if line == "%operators":
                                break
                            else:
                                s = line.split(',')
                                # special cases....
                                if s[0].strip() != "NOT":
                                    if s[0].strip() == "COMMA":
                                        tokens['operators'].append(["COMMA", ' ","', ' ","'])
                                    else:
                                        tokens['operators'].append(s)
                    elif line == "%constructs":
                        tokens['constructs'] = []
                        for line in fp:
                            line = line.strip()
                            if line == "%constructs":
                                break
                            else:
                                tokens['constructs'].append(line.split(','))
                    elif line == "%overhead":
                        tokens['overhead'] = []
                        for line in fp:
                            line = line.strip()
                            if line == "%overhead":
                                break
                            else:
                                tokens['overhead'].append(line.split(','))

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
    print("%d tokens and %d rules loaded"%(
        len(tokens['keywords'])+
        len(tokens['operators'])+
        len(tokens['overhead'])+
        len(tokens['constructs']), len(rules)))

    return {'tokens': tokens, 'rules':rules}

def mk_backup_file(fname):

    bak = fname+".bak"
    if os.path.exists(fname):
        if os.path.exists(bak):
            os.remove(bak)
        os.rename(fname, bak)

def gen_token_header(data):

    mk_backup_file('token_types.h')
    with open('token_types.h', 'w') as fp:
        fp.write("/*\n  this file is generated.\n  --- DO NOT EDIT ---\n */\n")
        fp.write("#ifndef _TOKEN_TYPES_H\n")
        fp.write("#define _TOKEN_TYPES_H\n\n")
        fp.write("#define TOK_BEGIN 1000\n\n")
        fp.write("typedef enum {\n")
        s = " = TOK_BEGIN,"
        for item in data:
            fp.write("\n    /* %s */\n"%(item))
            for name in data[item]:
                fp.write("    %s%s\n"%(name[0], s))
                s = ","
        fp.write("} token_type_t;\n\n")
        fp.write("const char* tok_to_str(token_type_t type);\n")
        fp.write("token_type_t search_keyword(const char* str);\n\n")
        fp.write("#endif /* _TOKEN_TYPES_H */\n\n")

def gen_token_src(data):

    mk_backup_file('token_types.c')
    with open('token_types.c', 'w') as fp:
        fp.write("/*\n  this file is generated.\n  --- DO NOT EDIT ---\n */\n")
        fp.write("#include <stdio.h>\n")
        fp.write("#include <stdlib.h>\n")
        fp.write("#include <stdint.h>\n")
        fp.write("#include <string.h>\n")
        fp.write("#include <stdbool.h>\n\n")
        fp.write("#include \"token_types.h\"\n\n")

        fp.write("typedef struct {\n")
        fp.write("    token_type_t type;\n")
        fp.write("    const char* str;\n")
        fp.write("    const char* name;\n")
        fp.write("} token_value_t;\n\n")
        for item in data:
            fp.write("/* %s */\n"%(item))
            fp.write("token_value_t %s[] = {\n"%(item))
            for name in data[item]:
                fp.write("    {%s,%s,%s},\n"%(name[0], name[1], name[2]))
            fp.write("};\n\n")
        fp.write("#define MAX_TOKENS ((sizeof(keywords)+ \\\n")
        fp.write("                     sizeof(operators)+ \\\n")
        fp.write("                     sizeof(overhead)+ \\\n")
        fp.write("                     sizeof(constructs))/sizeof(token_value_t))\n\n")
        fp.write("#define TOK_IDX(t) ((t)-TOK_BEGIN)\n\n")

        fp.write("static token_type_t search(token_value_t* lst, const char* str, int start, int end) {\n\n")
        fp.write("    if(start >= end)\n")
        fp.write("        return SYMBOL;\n")
        fp.write("    else {\n")
        fp.write("        int mid = (start + end) / 2;\n")
        fp.write("        int val = strcmp(str, lst[mid].str);\n")
        fp.write("        if(val == 0)\n")
        fp.write("            return lst[mid].type;\n")
        fp.write("        else if(val > 0)\n")
        fp.write("            return search(lst, str, mid + 1, end);\n")
        fp.write("        else\n")
        fp.write("            return search(lst, str, start, end - 1);\n")
        fp.write("    }\n")
        fp.write("}\n\n")

        fp.write("token_type_t search_keyword(const char* str) {\n")
        fp.write("    return search(keywords, str, 0, (sizeof(keywords)/sizeof(token_value_t)));\n")
        fp.write("}\n\n")

        fp.write("const char* tok_to_str(token_type_t type) {\n")
        fp.write("    return\n")
        for item in data:
            for name in data[item]:
                fp.write("        (type == %s)? %s:\n"%(name[0], name[2]))
        fp.write("        \"UNKNOWN\";\n")
        fp.write("}\n\n")

def gen_parser_header(data):

    rules = data['rules']

    mk_backup_file('parser.h')
    with open('parser.h', 'w') as fp:
        fp.write("/*\n  this file is generated.\n  --- DO NOT EDIT ---\n */\n")
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

    rules = data['rules']

    mk_backup_file('ast.h')
    with open('ast.h', 'w') as fp:
        fp.write("/*\n  this file is generated.\n  --- DO NOT EDIT ---\n */\n")
        fp.write("#ifndef _AST_H\n")
        fp.write("#define _AST_H\n\n")
        fp.write("#include \"scanner.h\"\n")
        fp.write("#include \"token_types.h\"\n\n")
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
            fp.write("    Token* tok;\n")
            fp.write("} ast_%s_t;\n"%(item))
            fp.write("ast_%s_t* create_%s();\n\n"%(item, item))
        fp.write("#endif /* _AST_H */\n\n")

def gen_ast_src(data):

    rules = data['rules']

    mk_backup_file('ast.c')
    with open("ast.c", "w") as fp:
        fp.write("/*\n  this file is generated.\n  --- DO NOT EDIT ---\n */\n")
        fp.write("#include <stdio.h>\n")
        fp.write("#include <stdlib.h>\n")
        fp.write("#include <stdint.h>\n")
        fp.write("#include <stdbool.h>\n\n")

        fp.write("#include \"ast.h\"\n")
        fp.write("#include \"mem.h\"\n")

        for item in rules:
            fp.write("/*\n")
            fp.write(" *    %s\n"%(item))
            for line in rules[item]:
                fp.write(" *        | %s\n"%(line))
            fp.write(" */\n")
            fp.write("ast_%s_t* create_%s() {\n"%(item, item))
            fp.write("    ast_%s_t* ptr = _alloc_ds(ast_%s_t);\n"%(item, item))
            fp.write("    ptr->type.type = AST_%s_T;\n"%(item))
            fp.write("    ptr->tok = crnt_token();\n")
            fp.write("    return ptr;\n")
            fp.write("}\n\n")

def gen_parse_func(fp, name, data):
    '''
    '''

def gen_parser_src(data):

    rules = data['rules']

    mk_backup_file('parser.c')
    with open("parser.c", "w") as fp:
        fp.write("/*\n  this file is generated.\n  --- DO NOT EDIT ---\n */\n")
        fp.write("#include <stdio.h>\n")
        fp.write("#include <stdlib.h>\n")
        fp.write("#include <stdint.h>\n")
        fp.write("#include <stdbool.h>\n\n")

        fp.write("#include \"ast.h\"\n")
        fp.write("#include \"token_types.h\"\n")
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

def emit_all(data):
    gen_token_header(data['tokens'])
    gen_token_src(data['tokens'])
    gen_ast_header(data)
    gen_ast_src(data)
    gen_parser_header(data)
    gen_parser_src(data)

if __name__ == '__main__':

    data = load_all('grammar.txt')
    #pp(data)
    emit_all(data)
