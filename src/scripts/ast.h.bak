/* generated file. DO NOT EDIT */
#ifndef _AST_H
#define _AST_H

typedef enum {
    AST_module_T = 1100,
    AST_module_type_T,
    AST_module_body_T,
    AST_module_element_T,
    AST_module_body_list_T,
    AST_import_statement_T,
    AST_entry_definition_T,
    AST_scope_T,
    AST_type_name_T,
    AST_empty_parens_T,
    AST_empty_block_T,
    AST_compound_reference_T,
    AST_compound_reference_element_T,
    AST_compound_name_T,
    AST_formatted_string_T,
    AST_func_reference_T,
    AST_array_reference_T,
    AST_array_brace_T,
    AST_array_reference_list_T,
    AST_namespace_definition_T,
    AST_namespace_block_T,
    AST_namespace_body_T,
    AST_namespace_element_T,
    AST_class_definition_T,
    AST_class_parameters_T,
    AST_class_block_T,
    AST_class_body_T,
    AST_class_body_element_T,
    AST_var_declaration_T,
    AST_var_declaration_list_T,
    AST_func_declaration_T,
    AST_func_decl_parms_T,
    AST_bool_literal_T,
    AST_primary_T,
    AST_const_expression_T,
    AST_expression_T,
    AST_expr_and_T,
    AST_expr_equ_T,
    AST_expr_compe_T,
    AST_expr_comp_T,
    AST_expr_term_T,
    AST_expr_pow_T,
    AST_expr_fact_T,
    AST_expr_unary_T,
    AST_expr_parms_T,
    AST_expr_list_T,
    AST_expr_parens_T,
    AST_func_definition_T,
    AST_ctor_definition_T,
    AST_dtor_definition_T,
    AST_assignment_oper_T,
    AST_assignment_tail_T,
    AST_assignment_T,
    AST_data_definition_T,
    AST_func_block_T,
    AST_func_block_list_T,
    AST_func_block_elem_T,
    AST_print_statement_T,
    AST_trace_statement_T,
    AST_return_statement_T,
    AST_if_else_clause_T,
    AST_if_clause_T,
    AST_else_clause_T,
    AST_else_clause_list_T,
    AST_else_clause_final_T,
    AST_while_clause_T,
    AST_do_clause_T,
    AST_for_entry_T,
    AST_for_clause_T,
    AST_switch_case_clause_T,
    AST_switch_clause_T,
    AST_case_clause_T,
    AST_case_clause_list_T,
    AST_case_clause_final_T,
    AST_try_except_clause_T,
    AST_try_clause_T,
    AST_except_clause_T,
    AST_except_clause_list_T,
    AST_except_clause_final_T,
} AST_TYPE_T;

/* this exists so that we can find out what the type is, even
   if the pointer of of type void */
#define TYPEOF(p) ((ast_type_t*)(p))->type;
typedef struct _ast_type_t_ {
    AST_TYPE_T type;
} ast_type_t;

/* ast data structures and create function protos. */
/*
 *    module
 *        | MODULE SYMBOL COLON module_type module_body
 */
typedef struct _ast_module_t_ {
    ast_type_t type;
} ast_module_t;
ast_module_t* create_module();

/*
 *    module_type
 *        | EXEC
 *        | STATIC
 *        | DYNAMIC
 */
typedef struct _ast_module_type_t_ {
    ast_type_t type;
} ast_module_type_t;
ast_module_type_t* create_module_type();

/*
 *    module_body
 *        | OBLOCK module_body_list CBLOCK
 */
typedef struct _ast_module_body_t_ {
    ast_type_t type;
} ast_module_body_t;
ast_module_body_t* create_module_body();

/*
 *    module_element
 *        | namespace_element
 *        | import_statement
 *        | entry_definition
 */
typedef struct _ast_module_element_t_ {
    ast_type_t type;
} ast_module_element_t;
ast_module_element_t* create_module_element();

/*
 *    module_body_list
 *        | module_element module_body_list
 *        | module_element
 */
typedef struct _ast_module_body_list_t_ {
    ast_type_t type;
} ast_module_body_list_t;
ast_module_body_list_t* create_module_body_list();

/*
 *    import_statement
 *        | IMPORT compound_name
 *        | IMPORT compound_name AS SYMBOL
 */
typedef struct _ast_import_statement_t_ {
    ast_type_t type;
} ast_import_statement_t;
ast_import_statement_t* create_import_statement();

/*
 *    entry_definition
 *        | ENTRY func_block
 */
typedef struct _ast_entry_definition_t_ {
    ast_type_t type;
} ast_entry_definition_t;
ast_entry_definition_t* create_entry_definition();

/*
 *    scope
 *        | PUBLIC
 *        | PRIVATE
 *        | PROTECTED
 */
typedef struct _ast_scope_t_ {
    ast_type_t type;
} ast_scope_t;
ast_scope_t* create_scope();

/*
 *    type_name
 *        | FLOAT
 *        | INTEGER
 *        | UNSIGNED
 *        | STRING
 *        | DICT
 *        | LIST
 *        | BOOLEAN
 *        | NOTHING
 *        | compound_name
 */
typedef struct _ast_type_name_t_ {
    ast_type_t type;
} ast_type_name_t;
ast_type_name_t* create_type_name();

/*
 *    empty_parens
 *        | OPAREN CPAREN
 */
typedef struct _ast_empty_parens_t_ {
    ast_type_t type;
} ast_empty_parens_t;
ast_empty_parens_t* create_empty_parens();

/*
 *    empty_block
 *        | OBLOCK CBLOCK
 */
typedef struct _ast_empty_block_t_ {
    ast_type_t type;
} ast_empty_block_t;
ast_empty_block_t* create_empty_block();

/*
 *    compound_reference
 *        | compound_reference_element DOT compound_reference
 *        | compound_reference_element
 */
typedef struct _ast_compound_reference_t_ {
    ast_type_t type;
} ast_compound_reference_t;
ast_compound_reference_t* create_compound_reference();

/*
 *    compound_reference_element
 *        | compound_name
 *        | func_reference
 *        | array_reference
 */
typedef struct _ast_compound_reference_element_t_ {
    ast_type_t type;
} ast_compound_reference_element_t;
ast_compound_reference_element_t* create_compound_reference_element();

/*
 *    compound_name
 *        | SYMBOL DOT compound_name
 *        | SYMBOL
 */
typedef struct _ast_compound_name_t_ {
    ast_type_t type;
} ast_compound_name_t;
ast_compound_name_t* create_compound_name();

/*
 *    formatted_string
 *        | STRG_CONST expr_parms
 *        | STRG_CONST empty_parens
 *        | STRG_CONST
 */
typedef struct _ast_formatted_string_t_ {
    ast_type_t type;
} ast_formatted_string_t;
ast_formatted_string_t* create_formatted_string();

/*
 *    func_reference
 *        | SYMBOL expr_parms
 *        | SYMBOL empty_parens
 */
typedef struct _ast_func_reference_t_ {
    ast_type_t type;
} ast_func_reference_t;
ast_func_reference_t* create_func_reference();

/*
 *    array_reference
 *        | SYMBOL array_reference_list
 */
typedef struct _ast_array_reference_t_ {
    ast_type_t type;
} ast_array_reference_t;
ast_array_reference_t* create_array_reference();

/*
 *    array_brace
 *        | OBRACE expression CBRACE
 */
typedef struct _ast_array_brace_t_ {
    ast_type_t type;
} ast_array_brace_t;
ast_array_brace_t* create_array_brace();

/*
 *    array_reference_list
 *        | array_brace array_reference_list
 *        | array_brace
 */
typedef struct _ast_array_reference_list_t_ {
    ast_type_t type;
} ast_array_reference_list_t;
ast_array_reference_list_t* create_array_reference_list();

/*
 *    namespace_definition
 *        | NAMESPACE SYMBOL namespace_block
 */
typedef struct _ast_namespace_definition_t_ {
    ast_type_t type;
} ast_namespace_definition_t;
ast_namespace_definition_t* create_namespace_definition();

/*
 *    namespace_block
 *        | OBLOCK namespace_body CBLOCK
 *        | empty_block
 */
typedef struct _ast_namespace_block_t_ {
    ast_type_t type;
} ast_namespace_block_t;
ast_namespace_block_t* create_namespace_block();

/*
 *    namespace_body
 *        | namespace_element namespace_block
 *        | namespace_element
 */
typedef struct _ast_namespace_body_t_ {
    ast_type_t type;
} ast_namespace_body_t;
ast_namespace_body_t* create_namespace_body();

/*
 *    namespace_element
 *        | namespace_definition
 *        | class_definition
 *        | func_definition
 *        | ctor_definition
 *        | dtor_definition
 *        | var_declaration
 *        | scope
 */
typedef struct _ast_namespace_element_t_ {
    ast_type_t type;
} ast_namespace_element_t;
ast_namespace_element_t* create_namespace_element();

/*
 *    class_definition
 *        | CLASS SYMBOL class_parameters class_block
 */
typedef struct _ast_class_definition_t_ {
    ast_type_t type;
} ast_class_definition_t;
ast_class_definition_t* create_class_definition();

/*
 *    class_parameters
 *        | OPAREN compound_name CPAREN
 *        | empty_parens
 */
typedef struct _ast_class_parameters_t_ {
    ast_type_t type;
} ast_class_parameters_t;
ast_class_parameters_t* create_class_parameters();

/*
 *    class_block
 *        | OBLOCK class_body CBLOCK
 *        | empty_block
 */
typedef struct _ast_class_block_t_ {
    ast_type_t type;
} ast_class_block_t;
ast_class_block_t* create_class_block();

/*
 *    class_body
 *        | class_body_element class_body
 *        | class_body_element
 */
typedef struct _ast_class_body_t_ {
    ast_type_t type;
} ast_class_body_t;
ast_class_body_t* create_class_body();

/*
 *    class_body_element
 *        | var_declaration
 *        | func_declaration
 *        | scope
 */
typedef struct _ast_class_body_element_t_ {
    ast_type_t type;
} ast_class_body_element_t;
ast_class_body_element_t* create_class_body_element();

/*
 *    var_declaration
 *        | type_name SYMBOL
 */
typedef struct _ast_var_declaration_t_ {
    ast_type_t type;
} ast_var_declaration_t;
ast_var_declaration_t* create_var_declaration();

/*
 *    var_declaration_list
 *        | var_declaration COMMA var_declaration_list
 *        | var_declaration
 */
typedef struct _ast_var_declaration_list_t_ {
    ast_type_t type;
} ast_var_declaration_list_t;
ast_var_declaration_list_t* create_var_declaration_list();

/*
 *    func_declaration
 *        | type_name SYMBOL func_decl_parms
 *        | CREATE func_decl_parms
 *        | DESTROY
 */
typedef struct _ast_func_declaration_t_ {
    ast_type_t type;
} ast_func_declaration_t;
ast_func_declaration_t* create_func_declaration();

/*
 *    func_decl_parms
 *        | OPAREN var_declaration_list CPAREN
 *        | empty_parens
 */
typedef struct _ast_func_decl_parms_t_ {
    ast_type_t type;
} ast_func_decl_parms_t;
ast_func_decl_parms_t* create_func_decl_parms();

/*
 *    bool_literal
 *        | TRUE
 *        | FALSE
 */
typedef struct _ast_bool_literal_t_ {
    ast_type_t type;
} ast_bool_literal_t;
ast_bool_literal_t* create_bool_literal();

/*
 *    primary
 *        | compound_reference
 *        | const_expression
 *        | expr_parens
 */
typedef struct _ast_primary_t_ {
    ast_type_t type;
} ast_primary_t;
ast_primary_t* create_primary();

/*
 *    const_expression
 *        | formatted_string
 *        | bool_literal
 *        | FLOAT_CONST
 *        | INT_CONST
 *        | UNSIGNED_CONST
 */
typedef struct _ast_const_expression_t_ {
    ast_type_t type;
} ast_const_expression_t;
ast_const_expression_t* create_const_expression();

/*
 *    expression
 *        | expr_and OR expression
 *        | expr_and
 */
typedef struct _ast_expression_t_ {
    ast_type_t type;
} ast_expression_t;
ast_expression_t* create_expression();

/*
 *    expr_and
 *        | expr_equ AND expr_and
 *        | expr_equ
 */
typedef struct _ast_expr_and_t_ {
    ast_type_t type;
} ast_expr_and_t;
ast_expr_and_t* create_expr_and();

/*
 *    expr_equ
 *        | expr_compe EQU expr_equ
 *        | expr_compe NEQU expr_equ
 *        | expr_compe
 */
typedef struct _ast_expr_equ_t_ {
    ast_type_t type;
} ast_expr_equ_t;
ast_expr_equ_t* create_expr_equ();

/*
 *    expr_compe
 *        | expr_comp LORE expr_compe
 *        | expr_comp GORE expr_compe
 *        | expr_comp
 */
typedef struct _ast_expr_compe_t_ {
    ast_type_t type;
} ast_expr_compe_t;
ast_expr_compe_t* create_expr_compe();

/*
 *    expr_comp
 *        | expr_term LESS expr_comp
 *        | expr_term MORE expr_comp
 *        | expr_term
 */
typedef struct _ast_expr_comp_t_ {
    ast_type_t type;
} ast_expr_comp_t;
ast_expr_comp_t* create_expr_comp();

/*
 *    expr_term
 *        | expr_pow ADD expr_term
 *        | expr_pow SUB expr_term
 *        | expr_pow
 */
typedef struct _ast_expr_term_t_ {
    ast_type_t type;
} ast_expr_term_t;
ast_expr_term_t* create_expr_term();

/*
 *    expr_pow
 *        | expr_fact POW expr_pow
 *        | expr_fact
 */
typedef struct _ast_expr_pow_t_ {
    ast_type_t type;
} ast_expr_pow_t;
ast_expr_pow_t* create_expr_pow();

/*
 *    expr_fact
 *        | expr_unary MUL expr_fact
 *        | expr_unary DIV expr_fact
 *        | expr_unary MOD expr_fact
 *        | expr_unary
 */
typedef struct _ast_expr_fact_t_ {
    ast_type_t type;
} ast_expr_fact_t;
ast_expr_fact_t* create_expr_fact();

/*
 *    expr_unary
 *        | primary
 *        | SUB expr_unary
 *        | ADD expr_unary
 *        | NOT expr_unary
 *        | type_name OPAREN expr_unary CPAREN
 */
typedef struct _ast_expr_unary_t_ {
    ast_type_t type;
} ast_expr_unary_t;
ast_expr_unary_t* create_expr_unary();

/*
 *    expr_parms
 *        | OPAREN expr_list CPAREN
 */
typedef struct _ast_expr_parms_t_ {
    ast_type_t type;
} ast_expr_parms_t;
ast_expr_parms_t* create_expr_parms();

/*
 *    expr_list
 *        | expression COMMA expr_list
 *        | expression
 */
typedef struct _ast_expr_list_t_ {
    ast_type_t type;
} ast_expr_list_t;
ast_expr_list_t* create_expr_list();

/*
 *    expr_parens
 *        | OPAREN expression CPAREN
 */
typedef struct _ast_expr_parens_t_ {
    ast_type_t type;
} ast_expr_parens_t;
ast_expr_parens_t* create_expr_parens();

/*
 *    func_definition
 *        | var_declaration COLON SYMBOL func_decl_parms func_block
 */
typedef struct _ast_func_definition_t_ {
    ast_type_t type;
} ast_func_definition_t;
ast_func_definition_t* create_func_definition();

/*
 *    ctor_definition
 *        | SYMBOL COLON CREATE func_decl_parms func_block
 */
typedef struct _ast_ctor_definition_t_ {
    ast_type_t type;
} ast_ctor_definition_t;
ast_ctor_definition_t* create_ctor_definition();

/*
 *    dtor_definition
 *        | SYMBOL COLON DESTROY func_block
 */
typedef struct _ast_dtor_definition_t_ {
    ast_type_t type;
} ast_dtor_definition_t;
ast_dtor_definition_t* create_dtor_definition();

/*
 *    assignment_oper
 *        | ASSIGN
 *        | ADD_ASSIGN
 *        | SUB_ASSIGN
 *        | MUL_ASSIGN
 *        | DIV_ASSIGN
 *        | MOD_ASSIGN
 */
typedef struct _ast_assignment_oper_t_ {
    ast_type_t type;
} ast_assignment_oper_t;
ast_assignment_oper_t* create_assignment_oper();

/*
 *    assignment_tail
 *        | assignment_oper expression
 */
typedef struct _ast_assignment_tail_t_ {
    ast_type_t type;
} ast_assignment_tail_t;
ast_assignment_tail_t* create_assignment_tail();

/*
 *    assignment
 *        | compound_reference assignment_tail
 */
typedef struct _ast_assignment_t_ {
    ast_type_t type;
} ast_assignment_t;
ast_assignment_t* create_assignment();

/*
 *    data_definition
 *        | var_declaration
 *        | var_declaration assignment_tail
 */
typedef struct _ast_data_definition_t_ {
    ast_type_t type;
} ast_data_definition_t;
ast_data_definition_t* create_data_definition();

/*
 *    func_block
 *        | OBLOCK func_block_list CBLOCK
 *        | empty_block
 */
typedef struct _ast_func_block_t_ {
    ast_type_t type;
} ast_func_block_t;
ast_func_block_t* create_func_block();

/*
 *    func_block_list
 *        | func_block_elem
 *        | func_block_elem func_block_list
 */
typedef struct _ast_func_block_list_t_ {
    ast_type_t type;
} ast_func_block_list_t;
ast_func_block_list_t* create_func_block_list();

/*
 *    func_block_elem
 *        | BREAK
 *        | CONTINUE
 *        | IBEGIN STRG_CONST IEND
 *        | EXIT expr_parens
 *        | YIELD OPAREN SYMBOL CPAREN
 *        | RAISE OPAREN compound_name CPAREN
 *        | return_statement
 *        | trace_statement
 *        | print_statement
 *        | data_definition
 *        | assignment
 *        | compound_reference
 *        | while_clause
 *        | do_clause
 *        | for_clause
 *        | try_except_clause
 *        | switch_case_clause
 *        | if_else_clause
 *        | func_block
 */
typedef struct _ast_func_block_elem_t_ {
    ast_type_t type;
} ast_func_block_elem_t;
ast_func_block_elem_t* create_func_block_elem();

/*
 *    print_statement
 *        | PRINT
 *        | PRINT empty_parens
 *        | PRINT OPAREN formatted_string CPAREN
 */
typedef struct _ast_print_statement_t_ {
    ast_type_t type;
} ast_print_statement_t;
ast_print_statement_t* create_print_statement();

/*
 *    trace_statement
 *        | TRACE
 *        | TRACE empty_parens
 *        | TRACE OPAREN formatted_string CPAREN
 */
typedef struct _ast_trace_statement_t_ {
    ast_type_t type;
} ast_trace_statement_t;
ast_trace_statement_t* create_trace_statement();

/*
 *    return_statement
 *        | RETURN
 *        | RETURN empty_parens
 *        | RETURN expr_parens
 */
typedef struct _ast_return_statement_t_ {
    ast_type_t type;
} ast_return_statement_t;
ast_return_statement_t* create_return_statement();

/*
 *    if_else_clause
 *        | if_clause
 *        | if_clause else_clause_list
 *        | if_clause else_clause_final
 *        | if_clause else_clause_list else_clause_final
 */
typedef struct _ast_if_else_clause_t_ {
    ast_type_t type;
} ast_if_else_clause_t;
ast_if_else_clause_t* create_if_else_clause();

/*
 *    if_clause
 *        | IF expr_parens func_block
 */
typedef struct _ast_if_clause_t_ {
    ast_type_t type;
} ast_if_clause_t;
ast_if_clause_t* create_if_clause();

/*
 *    else_clause
 *        | ELSE expr_parens func_block
 */
typedef struct _ast_else_clause_t_ {
    ast_type_t type;
} ast_else_clause_t;
ast_else_clause_t* create_else_clause();

/*
 *    else_clause_list
 *        | else_clause
 *        | else_clause else_clause_list
 */
typedef struct _ast_else_clause_list_t_ {
    ast_type_t type;
} ast_else_clause_list_t;
ast_else_clause_list_t* create_else_clause_list();

/*
 *    else_clause_final
 *        | ELSE empty_parens func_block
 *        | ELSE func_block
 */
typedef struct _ast_else_clause_final_t_ {
    ast_type_t type;
} ast_else_clause_final_t;
ast_else_clause_final_t* create_else_clause_final();

/*
 *    while_clause
 *        | WHILE expr_parens func_block
 */
typedef struct _ast_while_clause_t_ {
    ast_type_t type;
} ast_while_clause_t;
ast_while_clause_t* create_while_clause();

/*
 *    do_clause
 *        | DO func_block WHILE expr_parens
 */
typedef struct _ast_do_clause_t_ {
    ast_type_t type;
} ast_do_clause_t;
ast_do_clause_t* create_do_clause();

/*
 *    for_entry
 *        | FOR OPAREN SYMBOL IN
 */
typedef struct _ast_for_entry_t_ {
    ast_type_t type;
} ast_for_entry_t;
ast_for_entry_t* create_for_entry();

/*
 *    for_clause
 *        | for_entry compound_reference CPAREN func_block
 *        | for_entry expression TO expression CPAREN func_block
 */
typedef struct _ast_for_clause_t_ {
    ast_type_t type;
} ast_for_clause_t;
ast_for_clause_t* create_for_clause();

/*
 *    switch_case_clause
 *        | switch_clause case_clause_list case_clause_final
 */
typedef struct _ast_switch_case_clause_t_ {
    ast_type_t type;
} ast_switch_case_clause_t;
ast_switch_case_clause_t* create_switch_case_clause();

/*
 *    switch_clause
 *        | SWITCH expr_parens OBLOCK
 */
typedef struct _ast_switch_clause_t_ {
    ast_type_t type;
} ast_switch_clause_t;
ast_switch_clause_t* create_switch_clause();

/*
 *    case_clause
 *        | CASE OPAREN const_expression CPAREN func_block
 */
typedef struct _ast_case_clause_t_ {
    ast_type_t type;
} ast_case_clause_t;
ast_case_clause_t* create_case_clause();

/*
 *    case_clause_list
 *        | case_clause case_clause_list
 *        | case_clause
 */
typedef struct _ast_case_clause_list_t_ {
    ast_type_t type;
} ast_case_clause_list_t;
ast_case_clause_list_t* create_case_clause_list();

/*
 *    case_clause_final
 *        | CBLOCK
 *        | DEFAULT func_block CBLOCK
 */
typedef struct _ast_case_clause_final_t_ {
    ast_type_t type;
} ast_case_clause_final_t;
ast_case_clause_final_t* create_case_clause_final();

/*
 *    try_except_clause
 *        | try_clause except_clause_list
 *        | try_clause except_clause_final
 *        | try_clause except_clause_list except_clause_final
 */
typedef struct _ast_try_except_clause_t_ {
    ast_type_t type;
} ast_try_except_clause_t;
ast_try_except_clause_t* create_try_except_clause();

/*
 *    try_clause
 *        | TRY func_block
 */
typedef struct _ast_try_clause_t_ {
    ast_type_t type;
} ast_try_clause_t;
ast_try_clause_t* create_try_clause();

/*
 *    except_clause
 *        | EXCEPT OPAREN compound_name CPAREN AS SYMBOL func_block
 */
typedef struct _ast_except_clause_t_ {
    ast_type_t type;
} ast_except_clause_t;
ast_except_clause_t* create_except_clause();

/*
 *    except_clause_list
 *        | except_clause except_clause_list
 *        | except_clause
 */
typedef struct _ast_except_clause_list_t_ {
    ast_type_t type;
} ast_except_clause_list_t;
ast_except_clause_list_t* create_except_clause_list();

/*
 *    except_clause_final
 *        | EXCEPT empty_parens func_block
 *        | EXCEPT func_block
 */
typedef struct _ast_except_clause_final_t_ {
    ast_type_t type;
} ast_except_clause_final_t;
ast_except_clause_final_t* create_except_clause_final();

#endif /* _AST_H */

