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
                    #tokens['keywords'].sort()
                    return tokens
                else:
                    if line == "%keywords":
                        tokens['keywords'] = {}
                        for line in fp:
                            line = line.strip()
                            if line == "%keywords":
                                break
                            else:
                                a = line.split(',')
                                name = a[0].strip()
                                tokens['keywords'][name] = {}
                                tokens['keywords'][name]['str'] = a[1].strip(' "')
                                tokens['keywords'][name]['name'] = a[2].strip(' "')
                                tokens['keywords'][name]['keep'] = a[3].strip(' "')
                    elif line == "%operators":
                        tokens['operators'] = {}
                        for line in fp:
                            line = line.strip()
                            if line == "%operators":
                                break
                            else:
                                a = line.split(',')
                                n = a[0].strip()
                                tokens['operators'][n] = {}
                                if n == 'COMMA':
                                    tokens['operators'][n]['str'] = ','
                                    tokens['operators'][n]['name'] = ','
                                    tokens['operators'][n]['keep'] = 'false'
                                else:
                                    tokens['operators'][n]['str'] = a[1].strip(' "')
                                    tokens['operators'][n]['name'] = a[2].strip(' "')
                                    tokens['operators'][n]['keep'] = a[3].strip(' "')
                                # special cases....
                                # if s[0].strip() != "NOT":
                                #     if s[0].strip() == "COMMA":
                                #         tokens['operators'].append(["COMMA", ' ","', ' ","'])
                                #     else:
                                #         tokens['operators'].append(s)
                    elif line == "%constructs":
                        tokens['constructs'] = {}
                        for line in fp:
                            line = line.strip()
                            if line == "%constructs":
                                break
                            else:
                                a = line.split(',')
                                n = a[0].strip()
                                tokens['constructs'][n] = {}
                                tokens['constructs'][n]['str'] = a[1].strip(' "')
                                tokens['constructs'][n]['name'] = a[2].strip(' "')
                                tokens['constructs'][n]['keep'] = a[3].strip(' "')
                            #tokens['constructs'].append(line.split(','))
                    elif line == "%overhead":
                        tokens['overhead'] = {}
                        for line in fp:
                            line = line.strip()
                            if line == "%overhead":
                                break
                            else:
                                a = line.split(',')
                                n = a[0].strip()
                                tokens['overhead'][n] = {}
                                tokens['overhead'][n]['str'] = a[1].strip(' "')
                                tokens['overhead'][n]['name'] = a[2].strip(' "')
                                tokens['overhead'][n]['keep'] = a[3].strip(' "')
                                #tokens['overhead'].append(line.split(','))
                    elif line == "%punctuation":
                        tokens['punctuation'] = {}
                        for line in fp:
                            line = line.strip()
                            if line == "%punctuation":
                                break
                            else:
                                a = line.split(',')
                                n = a[0].strip()
                                tokens['punctuation'][n] = {}
                                tokens['punctuation'][n]['str'] = a[1].strip(' "')
                                tokens['punctuation'][n]['name'] = a[2].strip(' "')
                                tokens['punctuation'][n]['keep'] = a[3].strip(' "')

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
                        a = name.split(':')
                        rules[a[0]] = {}
                        rules[a[0]]['hints'] = a[1:]
                        rules[a[0]]['alts'] = []
                        for line in fp:
                            if len(line.strip()) == 0:
                                break;
                            else:
                                # If there is a comment embedded in the rule,
                                # then don't stop reading lines, but don't
                                # output it either.
                                if line.strip()[0] != '#':
                                    x = line.split('#') # strip trailing comment
                                    #rules[name].append((x[0].strip()[2:]).split())
                                    rules[a[0]]['alts'].append((x[0].strip()[2:]).split())

def is_terminal(name, tokens):
    '''
    If the symbol is not in rules (i.e. a non-terminal) then it's a terminal.
    '''
    for item in tokens:
        if name in tokens[item]:
            return True

    return False
    #return not (name in rules)

def terminal_type(name, tokens):

    for item, val in tokens.items():
        if name in val:
            return item

def is_keep(name, tokens):

    for item, val in tokens.items():
        if name in val:
            return val[name]['keep']

def normal_ast_struct(name, rule, tokens):
    """
    """
    # lines in a rule
    retv = []
    for item in rule['alts']:
        for name in item:
            if is_terminal(name, tokens):
                if is_keep(name, tokens) == 'true':
                    n = name.lower()+"_term"
                    if terminal_type(name, tokens) == 'keywords' or terminal_type(name, tokens) == 'operators':
                        retv.append(['int', n])
                    elif terminal_type(name, tokens) == 'constructs':
                        t = tokens['constructs'][name]['str']
                        retv.append([t, n])
            else:
                t = "struct _ast_%s_t_*"%(name)
                retv.append([t, name])

    return retv

def dup_nterm_ast_struct(name, rule, tokens):
    """
    """
    # lines in a rule
    retv = []
    for item in rule['alts']:
        for name in item:
            if is_terminal(name, tokens):
                if is_keep(name, tokens) == 'true':
                    n = name.lower()+"_term"
                    if terminal_type(name, tokens) == 'keywords' or terminal_type(name, tokens) == 'operators':
                        retv.append(['int', n])
                    elif terminal_type(name, tokens) == 'constructs':
                        t = tokens['constructs'][name]['str']
                        retv.append([t, n])
            else:
                t = "struct _ast_%s_t_*"%(name)
                retv.append([t, name])

    return retv

def as_list_ast_struct(name, rule, tokens):
    """
    As a list, there is one non-terminal that is in the list. Find out what
    that is and then just include the first and last pointers to it. The one
    that is not the one we want will be a duplicate. To take a shortcut, it is
    the first item on the first line.
    """
    retv = []
    for item in rule['alts']:
        for name in item:
            if not is_terminal(name, tokens):
                t = "struct _ast_%s_t_*"%(name)
                retv.append([t, "first"])
                retv.append([t, "last"])
                return retv

    return retv # blank list means malformed list rule

def list_item_ast_struct(name, rule, tokens):
    """
    """
    retv = one_nterm_ast_struct(name, rule, tokens)
    retv.append(["void*", "next"])

    return retv

def one_construct_ast_struct(name, rule, tokens):
    """
    """
    # lines in a rule
    retv = []
    flag = False
    for item in rule['alts']:
        for name in item:
            if is_terminal(name, tokens):
                if is_keep(name, tokens) == 'true':
                    n = name.lower()+"_term"
                    if terminal_type(name, tokens) == 'keywords' or terminal_type(name, tokens) == 'operators':
                        retv.append(['int', n])
                    elif terminal_type(name, tokens) == 'constructs':
                        if not flag:
                            t = tokens['constructs'][name]['str']
                            retv.append([t, n])
                            flag = True
            else:
                t = "struct _ast_%s_t_*"%(name)
                retv.append([t, name])

    return retv

def one_keyword_ast_struct(name, rule, tokens):
    """
    """
    # lines in a rule
    retv = []
    flag = False
    for item in rule['alts']:
        for name in item:
            if is_terminal(name, tokens):
                if is_keep(name, tokens) == 'true':
                    if terminal_type(name, tokens) == 'keywords' or terminal_type(name, tokens) == 'operators':
                        if not flag:
                            retv.append(['int', 'term_value'])
                            flag = True
                    elif terminal_type(name, tokens) == 'constructs':
                        t = tokens['constructs'][name]['str']
                        retv.append([t, name.lower()+"_term"])
            else:
                t = "struct _ast_%s_t_*"%(name)
                retv.append([t, name])

    return retv

def one_nterm_ast_struct(name, rule, tokens):
    """
    """
    # lines in a rule
    retv = []
    flag = False
    for item in rule['alts']:
        for name in item:
            if is_terminal(name, tokens):
                if is_keep(name, tokens) == 'true':
                    n = name.lower()+"_term"
                    if terminal_type(name, tokens) == 'keywords' or terminal_type(name, tokens) == 'operators':
                        retv.append(['int', n])
                    elif terminal_type(name, tokens) == 'constructs':
                        t = tokens['constructs'][name]['str']
                        retv.append([t, n])
            else:
                if not flag:
                    retv.append(['void*', 'nterm_value'])
                    flag = True

    return retv

def load_all(fname):
    '''
    Load the rules and the tokens and return a tuple.
    '''
    with open(fname, 'r') as fp:
        tokens = load_tokens(fp)
        rules = load_rules(fp)

    print("%d tokens and %d rules loaded"%(
        len(tokens['keywords'])+
        len(tokens['operators'])+
        len(tokens['overhead'])+
        len(tokens['punctuation'])+
        len(tokens['constructs']), len(rules)))

    # process the data for the AST structure, which determines everything else.
    ast = {}
    for item, val in rules.items():
        if len(val['hints']) > 0:
            if val['hints'][0] == 'normal':
                ast[item] = normal_ast_struct(item, val, tokens)
            elif val['hints'][0] == 'one_keyword':
                ast[item] = one_keyword_ast_struct(item, val, tokens)
            elif val['hints'][0] == 'one_construct':
                ast[item] = one_construct_ast_struct(item, val, tokens)
            elif val['hints'][0] == 'one_nterm':
                ast[item] = one_nterm_ast_struct(item, val, tokens)
            elif val['hints'][0] == 'dup_nterm':
                ast[item] = dup_nterm_ast_struct(item, val, tokens)
            elif val['hints'][0] == 'as_list':
                ast[item] = as_list_ast_struct(item, val, tokens)
            elif val['hints'][0] == 'list_item':
                ast[item] = list_item_ast_struct(item, val, tokens)
        else:
            val['hints'] = ['normal']
            ast[item] = normal_ast_struct(item, val, tokens)

    #pp(tokens)
    #pp(rules)
    #pp(ast)

    return {'tokens': tokens, 'rules':rules, 'ast': ast}

def mk_backup_file(fname):

    bak = fname+".bak"
    if os.path.exists(fname):
        if os.path.exists(bak):
            os.remove(bak)
        os.rename(fname, bak)

def gen_token_header(data):

    tokens = data['tokens']

    mk_backup_file('tokens.h')
    with open('tokens.h', 'w') as fp:
        fp.write("/*\n  this file is generated.\n  --- DO NOT EDIT ---\n */\n")
        fp.write("#ifndef _TOKENS_H\n")
        fp.write("#define _TOKENS_H\n\n")
        fp.write("#define TOK_BEGIN 1000\n\n")
        fp.write("typedef enum {\n")
        s = " = TOK_BEGIN,"
        for item in tokens:
            fp.write("\n    /* %s */\n"%(item))
            if item == 'keywords':
                for name in dict(sorted(tokens[item].items())):
                    fp.write("    %s%s\n"%(name, s))
                    s = ","
            else:
                for name in tokens[item]:
                    if name != 'NOT':
                        fp.write("    %s%s\n"%(name, s))
                    s = ","
        fp.write("} token_type_t;\n\n")
        fp.write("const char* tok_to_str(token_type_t type);\n")
        fp.write("token_type_t search_keyword(const char* str);\n\n")
        fp.write("#endif /* _TOKENS_H */\n\n")

def gen_token_src(data):

    tokens = data['tokens']

    mk_backup_file('tokens.c')
    with open('tokens.c', 'w') as fp:
        fp.write("/*\n  this file is generated.\n  --- DO NOT EDIT ---\n */\n")
        fp.write("#include <stdio.h>\n")
        fp.write("#include <stdlib.h>\n")
        fp.write("#include <stdint.h>\n")
        fp.write("#include <string.h>\n")
        fp.write("#include <stdbool.h>\n\n")
        fp.write("#include \"tokens.h\"\n\n")

        fp.write("typedef struct {\n")
        fp.write("    token_type_t type;\n")
        fp.write("    const char* str;\n")
        fp.write("    const char* name;\n")
        fp.write("} token_value_t;\n\n")
        for item in tokens:
            fp.write("/* %s */\n"%(item))
            if item == 'keywords':
                fp.write("static token_value_t %s[] = {\n"%(item))
                for name in dict(sorted(tokens[item].items())):
                    val = tokens[item][name]
                    fp.write("    {%s, \"%s\", \"%s\"},\n"%(name, val['str'], val['name']))
                fp.write("};\n\n")
            # This could be used in the future...
            # else:
            #     fp.write("static token_value_t %s[] = {\n"%(item))
            #     for name, val in tokens[item].items():
            #         fp.write("    {%s, \"%s\", \"%s\"},\n"%(name, val['str'], val['name']))
            #     fp.write("};\n\n")
        # fp.write("#define MAX_TOKENS ((sizeof(keywords)+ \\\n")
        # fp.write("                     sizeof(operators)+ \\\n")
        # fp.write("                     sizeof(overhead)+ \\\n")
        # fp.write("                     sizeof(constructs))/sizeof(token_value_t))\n\n")
        # fp.write("#define TOK_IDX(t) ((t)-TOK_BEGIN)\n\n")
        fp.write("\n#define NUM_KEYWORDS (sizeof(keywords)/sizeof(token_value_t))\n\n")

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
        fp.write("    return search(keywords, str, 0, NUM_KEYWORDS);\n")
        fp.write("}\n\n")

        fp.write("const char* tok_to_str(token_type_t type) {\n")
        fp.write("    return\n")
        for item in tokens:
            for name in tokens[item]:
                fp.write("        (type == %s)? \"%s\":\n"%(name, tokens[item][name]['name']))
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

        fp.write("#include \"ast.h\"\n")
        fp.write("#include \"scanner.h\"\n\n")

        fp.write("typedef struct _token_stack_ {\n")
        fp.write("    Token* tok;\n")
        fp.write("    struct _token_stack_* next;\n")
        fp.write("} TokenStack;\n\n")

        fp.write("typedef struct _parser_state_t_ {\n")
        fp.write("    bool match; /* set if a rule match was found */\n")
        fp.write("    TokenStack* tstk; /* token stack */\n")
        fp.write("    int errors; /* number of errors encountered */\n")
        fp.write("    int warnings; /* number of warnings */\n")
        fp.write("} parser_state_t;\n\n")

        fp.write("/* parse function headers */\n")
        fp.write("parser_state_t* create_parser_state();\n")
        fp.write("void destroy_parser_state(parser_state_t* state);\n\n")

        for item in rules:
            fp.write("ast_%s_t* parse_%s(parser_state_t* state);\n"%(item, item))
        fp.write("\n")

        fp.write("#endif /* _PARSER_H */\n\n")

def gen_ast_header(data):

    rules = data['rules']

    mk_backup_file('ast.h')
    with open('ast.h', 'w') as fp:
        fp.write("/*\n  this file is generated.\n  --- DO NOT EDIT ---\n */\n")
        fp.write("#ifndef _AST_H\n")
        fp.write("#define _AST_H\n\n")
        fp.write("#include \"scanner.h\"\n")
        fp.write("#include \"tokens.h\"\n\n")
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
            if len(rules[item]['hints']) != 0:
                fp.write(" *    generator: %s\n"%(rules[item]['hints'][0]))
            fp.write(" *    %s\n"%(item))
            for line in rules[item]['alts']:
                fp.write(" *        | %s\n"%(" ".join(line)))
            fp.write(" */\n")
            fp.write("typedef struct _ast_%s_t_ {\n"%(item))
            fp.write("    ast_type_t type;\n")
            for name in data['ast'][item]:
                fp.write("    %s %s;\n"%(name[0], name[1]))
            #data['ast'][item] = gen_ast_struct(fp, item, data)
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
            if len(rules[item]['hints']) != 0:
                fp.write(" *    generator: %s\n"%(rules[item]['hints'][0]))
            fp.write(" *    %s\n"%(item))
            for line in rules[item]['alts']:
                fp.write(" *        | %s\n"%(" ".join(line)))
            fp.write(" */\n")
            fp.write("ast_%s_t* create_%s() {\n"%(item, item))
            fp.write("    ast_%s_t* ptr = _alloc_ds(ast_%s_t);\n"%(item, item))
            fp.write("    ptr->type.type = AST_%s_T;\n"%(item))
            fp.write("    return ptr;\n")
            fp.write("}\n\n")

def gen_parse_func_line(fp, clause, line, data):
    '''
    Emit a parse function line.
    '''
    fp.write("    %s(state->match == false) {\n"%(clause))
    for item in line:
        fp.write("        // %s is a terminal = %s\n"%(item, is_terminal(item, data['tokens'])))
    fp.write("    }\n")

def gen_parse_func(fp, name, data):
    '''
    Emit all of the nested IF clauses for the parser function.
    '''
    rule = data['rules'][name]

    # for each line in the rule
    clause = "if"
    for item in rule['alts']:
        gen_parse_func_line(fp, clause, item, data)
        clause = "else if"
    fp.write("    else if(state->match == false) {\n")
    fp.write("        // flag a syntax error\n")
    fp.write("    }\n")
    fp.write("    else {\n")
    fp.write("        // save the production and allocate the AST\n")
    fp.write("    }\n")

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
        fp.write("#include \"tokens.h\"\n")
        fp.write("#include \"scanner.h\"\n")
        fp.write("#include \"parser.h\"\n")
        fp.write("#include \"mem.h\"\n\n")

        for item in rules:
            fp.write("/*\n")
            if len(rules[item]['hints']) != 0:
                fp.write(" *    generator: %s\n"%(rules[item]['hints'][0]))
            fp.write(" *    %s\n"%(item))
            for line in rules[item]['alts']:
                fp.write(" *        | %s\n"%(" ".join(line)))
            fp.write(" */\n")
            fp.write("ast_%s_t* parse_%s(parser_state_t* state) {\n\n"%(item, item))
            fp.write("    ast_%s_t* ptr = NULL;\n"%(item))
            fp.write("    state->match = false;\n\n")
            gen_parse_func(fp, item, data)
            fp.write("    return ptr;\n")
            fp.write("}\n\n")

def emit_all(data):
    gen_token_header(data)
    gen_token_src(data)
    gen_ast_header(data)
    gen_ast_src(data)
    gen_parser_header(data)
    gen_parser_src(data)

if __name__ == '__main__':

    data = load_all('grammar.txt')
    emit_all(data)
#    pp(data)
