import os
from pprint import pprint as pp

class InputFile:
    '''
    Class that iterates the input file and strips comments and returns a
    '%end' string for blank lines.
    '''
    def __init__(self, fname):
        self.file_name = fname
        self.fp = None

    def __iter__(self):
        return self

    def __enter__(self):
        self.fp = open(self.file_name, 'r')
        return self

    def __exit__(self, type, val, tb):
        #print(type, val, tb)
        self.fp.close()

    def __next__(self):
        while True:
            line = self.fp.readline()
            if not line:
                #self.fp.close()
                raise StopIteration
            else:
                line = line.strip()
                if len(line) > 0:
                    # clip the comments
                    x = line.find('#')
                    if x < 0:
                        return line
                    elif x >= 0:
                        # clip the tail, if any
                        line = line[:x]
                        line = line.strip()
                        if len(line) > 0:
                            return line
                        else:
                            continue
                    else:
                        #return "%end"
                        continue
                else:
                    #return ''
                    continue

def load_keywords(fp):
    retv = {}
    for line in fp:
        if line == '%end':
            # break when a blank line is encountered
            break
        else:
            a = line.split(',')
            retv[a[0].strip()] = {'str': a[1].strip(' "'), 'name':a[2].strip(' "')}

    return retv

def load_operators(fp):
    retv = {}
    for line in fp:
        if line == '%end':
            break
        else:
            a = line.split()
            retv[a[0].strip()] = {'name': a[1].strip(' "')+' operator'}

    return retv

def load_punctuation(fp):
    retv = {}
    for line in fp:
        if line == '%end':
            break
        else:
            a = line.split()
            retv[a[0].strip()] = {'name': a[1].strip(' "')}

    return retv

def load_constructs(fp):
    retv = {}
    for line in fp:
        if line == '%end':
            break
        else:
            a = line.split(',')
            retv[a[0].strip()] = {
                'type':a[1].strip(' "'), 'name':a[2].strip(' "')}

    return retv

def load_other(fp):
    retv = {}
    for line in fp:
        if line == '%end':
            break
        else:
            x = line.strip()
            retv[x] = {'name':x}

    return retv

def load_rules(fp):

    rules = {}
    ast = {}
    for line in fp:
        name = line
        rules[name] = []
        ast[name] = []
        for line in fp:
            if line == '%end':
                break
            elif line[0] == '|':
                rules[name].append(line[2:])
            else:
                if len(line.split()) > 1:
                    ast[name].append(line)
                else:
                    ast[name].append("struct _ast_%s_t_* %s"%(line, line))

    return (rules, ast)

def load_all(fname):

    data = {}
    with InputFile(fname) as infile:
        for line in infile:
            if line == '%keywords':
                data['keywords'] = load_keywords(infile)
            elif line == '%operators':
                data['operators'] = load_operators(infile)
            elif line == '%punctuation':
                data['punctuation'] = load_punctuation(infile)
            elif line == '%constructs':
                data['constructs'] = load_constructs(infile)
            elif line == '%other':
                data['other'] = load_other(infile)
            elif line == '%rules':
                (rules, ast) = load_rules(infile)
                data['rules'] = rules
                data['ast'] = ast

    #pp(data) pretty print
    return data

def emit_token_types(data):
    '''
    Emit the header that contains the token type definitions.
    '''
    with open("token_types.h", "w") as fp:
        fp.write("/*\n *  This file is generated.\n *   --- DO NOT EDIT ---\n */\n")
        fp.write("#ifndef _TOKEN_TYPES_H\n#define _TOKEN_TYPES_H\n\n")
        fp.write("#define TOKEN_START 1000\n\n")
        fp.write("typedef enum {\n")
        fp.write("    /* other */\n")
        s = ' = TOKEN_START,'
        for item in data['other']:
            fp.write("    %s%s\n"%(item, s))
            s = ','

        fp.write("\n    /* keywords */\n")
        for item in data['keywords']:
            fp.write("    %s,\n"%(item))

        fp.write("\n    /* operators */\n")
        for item in data['operators']:
            if item != 'NOT':
                fp.write("    %s,\n"%(item))

        fp.write("\n    /* punctuation */\n")
        for item in data['punctuation']:
            fp.write("    %s,\n"%(item))

        fp.write("\n    /* constructs */\n")
        for item in data['constructs']:
            fp.write("    %s,\n"%(item))
        fp.write("} TokenType;\n\n")
        fp.write("#endif /* _TOKEN_TYPES_H */\n")

    with open("token_struct.h", "w") as fp:
        fp.write("/*\n *  This file is generated.\n *   --- DO NOT EDIT ---\n */\n")
        fp.write("#ifndef _TOKEN_STRUCT_H\n#define _TOKEN_STRUCT_H\n\n")
        fp.write("/*\n * This header is to be included exactly once in tokens.c\n */\n")
        fp.write("#include \"token_types.h\"\n\n")
        fp.write("typedef struct {\n")
        fp.write("    TokenType type;\n")
        fp.write("    const char* str;\n")
        fp.write("} token_list_t;\n\n")

        fp.write("static token_list_t token_list[] = {\n")
        for item in dict(sorted(data['keywords'].items())):
            fp.write("    {%s, \"%s\"},\n"%(item, data['keywords'][item]['str']))
        fp.write("};\n")
        fp.write("#define NUM_KEYWORDS (sizeof(token_list_t)/sizeof(token_list))\n\n")

        fp.write("#define TOK_TO_STR(t) (\\\n")
        for item in data['other']:
            fp.write("    ((t) == %s)? \"%s\": \\\n"%(item, item))
        for item in data['keywords']:
            fp.write("    ((t) == %s)? \"%s\": \\\n"%(item, data['keywords'][item]['name']))
        for item in data['operators']:
            fp.write("    ((t) == %s)? \"%s\": \\\n"%(item, data['operators'][item]['name']))
        for item in data['punctuation']:
            fp.write("    ((t) == %s)? \"%s\": \\\n"%(item, data['punctuation'][item]['name']))
        for item in data['constructs']:
            fp.write("    ((t) == %s)? \"%s\": \\\n"%(item, data['constructs'][item]['name']))
        fp.write("    \"UNKNOWN\")\n\n")

        fp.write("#endif /* _TOKEN_STRUCT_H */\n")

def emit_ast(data):
    '''
    Emit the AST data structures and the functions that implement it.
    '''
    with open("ast.h", "w") as fp:
        fp.write("/*\n *  This file is generated.\n *   --- DO NOT EDIT ---\n */\n")
        fp.write("#ifndef _AST_H\n#define _AST_H\n\n")
        fp.write("#include <stdbool.h>\n\n")
        fp.write("#define AST_START 2000\n\n")
        s = ' = AST_START,'
        fp.write("typedef enum {\n")
        for item in data['rules']:
            fp.write("    AST_%s%s\n"%(item.upper(), s))
            s = ','
        fp.write("} AstType;\n\n")

        fp.write("/* Struct that allows the type to be extracted\n")
        fp.write("   from a void* type */\n")
        fp.write("typedef struct {\n")
        fp.write("    AstType type;\n")
        fp.write("} ast_type_t;\n")
        fp.write("#define AST_TYPEOF(p) (((ast_type_t*)(p))->type)\n\n")

        for item in data['rules']:
            fp.write("/*\n")
            fp.write(" *    %s\n"%(item))
            for line in data['rules'][item]:
                fp.write(" *        | %s\n"%(line))
            fp.write(" */\n")
            # individual struct for a node
            fp.write("typedef struct _ast_%s_t_ {\n"%(item))
            fp.write("    ast_type_t type;\n")
            for name in data['ast'][item]:
                fp.write("    %s;\n"%(name))
            fp.write("} ast_%s_t;\n"%(item))
            #function prototypes
            fp.write("struct _ast_%s_t_* create_%s(\n"%(item, item))
            if len(data['ast'][item]) > 0 and 'first' in data['ast'][item][0]:
                fp.write("        %s);\n"%(data['ast'][item][0].replace('first', 'node')))

                fp.write("void add_%s(\n"%(item))
                fp.write("        struct _ast_%s_t_* lst,\n"%(item))
                fp.write("        %s);\n\n"%(data['ast'][item][0].replace('first', 'node')))
            else:
                a = []
                for s in data['ast'][item]:
                    if not 'next' in s:
                        a.append(s)
                fp.write("        %s);\n"%(",\n        ".join(a)))
            fp.write("\n")

        fp.write("#endif /* _AST_H */\n")

    with open("ast.c", "w") as fp:
        fp.write("/*\n *  This file is generated.\n *   --- DO NOT EDIT ---\n */\n")
        fp.write("#include <stdio.h>\n")
        fp.write("#include <stdlib.h>\n")
        fp.write("#include <stdint.h>\n")
        fp.write("#include <stdbool.h>\n\n")
        fp.write("#include \"errors.h\"\n")
        fp.write("#include \"ast.h\"\n")
        fp.write("#include \"mem.h\"\n\n")

        for item in data['rules']:
            fp.write("/*\n")
            fp.write(" *    %s\n"%(item))
            for line in data['rules'][item]:
                fp.write(" *        | %s\n"%(line))
            fp.write(" */\n")
            fp.write("ast_%s_t* create_%s(\n"%(item, item))

            if len(data['ast'][item]) > 0 and 'first' in data['ast'][item][0]:
                fp.write("            %s) {\n\n"%(data['ast'][item][0].replace('first', 'node')))
                fp.write("    TRACE();\n")
                fp.write("    ast_%s_t* ptr = _alloc_ds(ast_%s_t);\n"%(item, item))
                fp.write("    ptr->type.type = AST_%s;\n\n"%(item.upper()))
                fp.write("    ptr->first = node;\n")
                fp.write("    ptr->last = node;\n")
                fp.write("\n    return ptr;\n")
                fp.write("}\n")

                fp.write("void add_%s(\n"%(item))
                fp.write("            struct _ast_%s_t_* lst,\n"%(item))
                fp.write("            %s) {\n\n"%(data['ast'][item][0].replace('first', 'node')))
                fp.write("    TRACE();\n")
                fp.write("    if(lst->first == NULL)\n")
                fp.write("        lst->first = node;\n")
                fp.write("    node->next = lst->last;\n")
                fp.write("    lst->last = node;\n")
                fp.write("}\n")
            else:
                a = []
                for s in data['ast'][item]:
                    if not 'next' in s:
                        a.append(s)
                fp.write("            %s) {\n\n"%(",\n            ".join(a)))
                fp.write("    TRACE();\n")
                fp.write("    ast_%s_t* ptr = _alloc_ds(ast_%s_t);\n"%(item, item))
                fp.write("    ptr->type.type = AST_%s;\n\n"%(item.upper()))
                for name in data['ast'][item]:
                    x = name.split()[-1]
                    if not x == 'next':
                        fp.write("    ptr->%s = %s;\n"%(x, x))
                fp.write("\n    return ptr;\n")
                fp.write("}\n")

            fp.write("\n")

def emit_parser(data):
    '''
    Emit the parser data structures and the functions that implement it.
    '''
    with open("parser.h", "w") as fp:
        fp.write("/*\n *  This file is generated.\n *   --- DO NOT EDIT ---\n */\n")
        fp.write("#ifndef _PARSER_H\n#define _PARSER_H\n\n")
        fp.write("#include \"ast.h\"\n\n")

        fp.write("typedef void* TokenQueue;\n\n")

        fp.write("typedef struct _parser_state_t_ {\n")
        fp.write("    bool found;\n")
        fp.write("    TokenQueue* toks;\n")
        fp.write("} parser_state_t;\n\n")

        for item in data['rules']:
            fp.write("ast_%s_t* parse_%s(parser_state_t* state);\n"%(item, item))
        fp.write("\n#endif /* _PARSER_H */\n\n")

    with open("parser.c", "w") as fp:
        fp.write("/*\n *  This file is generated.\n *   --- DO NOT EDIT ---\n */\n")
        fp.write("#include <stdio.h>\n")
        fp.write("#include <stdlib.h>\n")
        fp.write("#include <stdint.h>\n")
        fp.write("#include <stdbool.h>\n\n")
        fp.write("#include \"errors.h\"\n")
        fp.write("#include \"parser.h\"\n")
        fp.write("#include \"ast.h\"\n")
        fp.write("#include \"token_types.h\"\n\n")

        for item in data['rules']:
            fp.write("/*\n")
            fp.write(" *    %s\n"%(item))
            for line in data['rules'][item]:
                fp.write(" *        | %s\n"%(line))
            fp.write(" */\n")
            fp.write("ast_%s_t* parse_%s(parser_state_t* state) {\n\n"%(item, item))
            fp.write("    TRACE();\n")
            for line in data['ast'][item]:
                fp.write("    %s;\n"%(line))
            fp.write("    state->found = false;\n\n")
            fp.write("    return NULL;\n")
            fp.write("}\n\n")

def emit_all(data):

    emit_token_types(data)
    emit_ast(data)
    emit_parser(data)

    print("Statistics: %d keywords: %d tokens: %d rules"%(
            len(data['keywords']),
            len(data['keywords']) + len(data['operators']) +
            len(data['punctuation']) + len(data['constructs'])+
            len(data['other']), len(data['rules'])))

if __name__ == '__main__':

    emit_all(load_all('grammar.txt'))

