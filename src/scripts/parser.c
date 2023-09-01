/* generated file. DO NOT EDIT */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "ast.h"
#include "tokens.h"
#include "scanner.h"
#include "parser.h"
#include "mem.h"

/*
 *    module
 *        | MODULE SYMBOL COLON module_type module_body
 */
ast_module_t* parse_module(parser_state_t* state) {
    ast_module_t* ptr = create_module();
    return ptr;
}

/*
 *    module_type
 *        | EXEC
 *        | STATIC
 *        | DYNAMIC
 */
ast_module_type_t* parse_module_type(parser_state_t* state) {
    ast_module_type_t* ptr = create_module_type();
    return ptr;
}

/*
 *    module_body
 *        | OBLOCK module_body_list CBLOCK
 */
ast_module_body_t* parse_module_body(parser_state_t* state) {
    ast_module_body_t* ptr = create_module_body();
    return ptr;
}

/*
 *    module_element
 *        | namespace_element
 *        | import_statement
 *        | entry_definition
 */
ast_module_element_t* parse_module_element(parser_state_t* state) {
    ast_module_element_t* ptr = create_module_element();
    return ptr;
}

/*
 *    module_body_list
 *        | module_element module_body_list
 *        | module_element
 */
ast_module_body_list_t* parse_module_body_list(parser_state_t* state) {
    ast_module_body_list_t* ptr = create_module_body_list();
    return ptr;
}

/*
 *    import_statement
 *        | IMPORT compound_name
 *        | IMPORT compound_name AS SYMBOL
 */
ast_import_statement_t* parse_import_statement(parser_state_t* state) {
    ast_import_statement_t* ptr = create_import_statement();
    return ptr;
}

/*
 *    entry_definition
 *        | ENTRY func_block
 */
ast_entry_definition_t* parse_entry_definition(parser_state_t* state) {
    ast_entry_definition_t* ptr = create_entry_definition();
    return ptr;
}

/*
 *    scope
 *        | PUBLIC
 *        | PRIVATE
 *        | PROTECTED
 */
ast_scope_t* parse_scope(parser_state_t* state) {
    ast_scope_t* ptr = create_scope();
    return ptr;
}

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
ast_type_name_t* parse_type_name(parser_state_t* state) {
    ast_type_name_t* ptr = create_type_name();
    return ptr;
}

/*
 *    empty_parens
 *        | OPAREN CPAREN
 */
ast_empty_parens_t* parse_empty_parens(parser_state_t* state) {
    ast_empty_parens_t* ptr = create_empty_parens();
    return ptr;
}

/*
 *    empty_block
 *        | OBLOCK CBLOCK
 */
ast_empty_block_t* parse_empty_block(parser_state_t* state) {
    ast_empty_block_t* ptr = create_empty_block();
    return ptr;
}

/*
 *    compound_reference
 *        | compound_reference_element DOT compound_reference
 *        | compound_reference_element
 */
ast_compound_reference_t* parse_compound_reference(parser_state_t* state) {
    ast_compound_reference_t* ptr = create_compound_reference();
    return ptr;
}

/*
 *    compound_reference_element
 *        | compound_name
 *        | func_reference
 *        | array_reference
 */
ast_compound_reference_element_t* parse_compound_reference_element(parser_state_t* state) {
    ast_compound_reference_element_t* ptr = create_compound_reference_element();
    return ptr;
}

/*
 *    compound_name
 *        | SYMBOL DOT compound_name
 *        | SYMBOL
 */
ast_compound_name_t* parse_compound_name(parser_state_t* state) {
    ast_compound_name_t* ptr = create_compound_name();
    return ptr;
}

/*
 *    formatted_string
 *        | STRG_CONST expr_parms
 *        | STRG_CONST empty_parens
 *        | STRG_CONST
 */
ast_formatted_string_t* parse_formatted_string(parser_state_t* state) {
    ast_formatted_string_t* ptr = create_formatted_string();
    return ptr;
}

/*
 *    func_reference
 *        | SYMBOL expr_parms
 *        | SYMBOL empty_parens
 */
ast_func_reference_t* parse_func_reference(parser_state_t* state) {
    ast_func_reference_t* ptr = create_func_reference();
    return ptr;
}

/*
 *    array_reference
 *        | SYMBOL array_reference_list
 */
ast_array_reference_t* parse_array_reference(parser_state_t* state) {
    ast_array_reference_t* ptr = create_array_reference();
    return ptr;
}

/*
 *    array_brace
 *        | OBRACE expression CBRACE
 */
ast_array_brace_t* parse_array_brace(parser_state_t* state) {
    ast_array_brace_t* ptr = create_array_brace();
    return ptr;
}

/*
 *    array_reference_list
 *        | array_brace array_reference_list
 *        | array_brace
 */
ast_array_reference_list_t* parse_array_reference_list(parser_state_t* state) {
    ast_array_reference_list_t* ptr = create_array_reference_list();
    return ptr;
}

/*
 *    namespace_definition
 *        | NAMESPACE SYMBOL namespace_block
 */
ast_namespace_definition_t* parse_namespace_definition(parser_state_t* state) {
    ast_namespace_definition_t* ptr = create_namespace_definition();
    return ptr;
}

/*
 *    namespace_block
 *        | OBLOCK namespace_body CBLOCK
 *        | empty_block
 */
ast_namespace_block_t* parse_namespace_block(parser_state_t* state) {
    ast_namespace_block_t* ptr = create_namespace_block();
    return ptr;
}

/*
 *    namespace_body
 *        | namespace_element namespace_block
 *        | namespace_element
 */
ast_namespace_body_t* parse_namespace_body(parser_state_t* state) {
    ast_namespace_body_t* ptr = create_namespace_body();
    return ptr;
}

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
ast_namespace_element_t* parse_namespace_element(parser_state_t* state) {
    ast_namespace_element_t* ptr = create_namespace_element();
    return ptr;
}

/*
 *    class_definition
 *        | CLASS SYMBOL class_parameters class_block
 */
ast_class_definition_t* parse_class_definition(parser_state_t* state) {
    ast_class_definition_t* ptr = create_class_definition();
    return ptr;
}

/*
 *    class_parameters
 *        | OPAREN compound_name CPAREN
 *        | empty_parens
 */
ast_class_parameters_t* parse_class_parameters(parser_state_t* state) {
    ast_class_parameters_t* ptr = create_class_parameters();
    return ptr;
}

/*
 *    class_block
 *        | OBLOCK class_body CBLOCK
 *        | empty_block
 */
ast_class_block_t* parse_class_block(parser_state_t* state) {
    ast_class_block_t* ptr = create_class_block();
    return ptr;
}

/*
 *    class_body
 *        | class_body_element class_body
 *        | class_body_element
 */
ast_class_body_t* parse_class_body(parser_state_t* state) {
    ast_class_body_t* ptr = create_class_body();
    return ptr;
}

/*
 *    class_body_element
 *        | var_declaration
 *        | func_declaration
 *        | scope
 */
ast_class_body_element_t* parse_class_body_element(parser_state_t* state) {
    ast_class_body_element_t* ptr = create_class_body_element();
    return ptr;
}

/*
 *    var_declaration
 *        | type_name SYMBOL
 */
ast_var_declaration_t* parse_var_declaration(parser_state_t* state) {
    ast_var_declaration_t* ptr = create_var_declaration();
    return ptr;
}

/*
 *    var_declaration_list
 *        | var_declaration COMMA var_declaration_list
 *        | var_declaration
 */
ast_var_declaration_list_t* parse_var_declaration_list(parser_state_t* state) {
    ast_var_declaration_list_t* ptr = create_var_declaration_list();
    return ptr;
}

/*
 *    func_declaration
 *        | type_name SYMBOL func_decl_parms
 *        | CREATE func_decl_parms
 *        | DESTROY
 */
ast_func_declaration_t* parse_func_declaration(parser_state_t* state) {
    ast_func_declaration_t* ptr = create_func_declaration();
    return ptr;
}

/*
 *    func_decl_parms
 *        | OPAREN var_declaration_list CPAREN
 *        | empty_parens
 */
ast_func_decl_parms_t* parse_func_decl_parms(parser_state_t* state) {
    ast_func_decl_parms_t* ptr = create_func_decl_parms();
    return ptr;
}

/*
 *    bool_literal
 *        | TRUE
 *        | FALSE
 */
ast_bool_literal_t* parse_bool_literal(parser_state_t* state) {
    ast_bool_literal_t* ptr = create_bool_literal();
    return ptr;
}

/*
 *    primary
 *        | compound_reference
 *        | const_expression
 *        | expr_parens
 */
ast_primary_t* parse_primary(parser_state_t* state) {
    ast_primary_t* ptr = create_primary();
    return ptr;
}

/*
 *    const_expression
 *        | formatted_string
 *        | bool_literal
 *        | FLOAT_CONST
 *        | INT_CONST
 *        | UNSIGNED_CONST
 */
ast_const_expression_t* parse_const_expression(parser_state_t* state) {
    ast_const_expression_t* ptr = create_const_expression();
    return ptr;
}

/*
 *    expression
 *        | expr_and OR expression
 *        | expr_and
 */
ast_expression_t* parse_expression(parser_state_t* state) {
    ast_expression_t* ptr = create_expression();
    return ptr;
}

/*
 *    expr_and
 *        | expr_equ AND expr_and
 *        | expr_equ
 */
ast_expr_and_t* parse_expr_and(parser_state_t* state) {
    ast_expr_and_t* ptr = create_expr_and();
    return ptr;
}

/*
 *    expr_equ
 *        | expr_compe EQU expr_equ
 *        | expr_compe NEQU expr_equ
 *        | expr_compe
 */
ast_expr_equ_t* parse_expr_equ(parser_state_t* state) {
    ast_expr_equ_t* ptr = create_expr_equ();
    return ptr;
}

/*
 *    expr_compe
 *        | expr_comp LORE expr_compe
 *        | expr_comp GORE expr_compe
 *        | expr_comp
 */
ast_expr_compe_t* parse_expr_compe(parser_state_t* state) {
    ast_expr_compe_t* ptr = create_expr_compe();
    return ptr;
}

/*
 *    expr_comp
 *        | expr_term LESS expr_comp
 *        | expr_term MORE expr_comp
 *        | expr_term
 */
ast_expr_comp_t* parse_expr_comp(parser_state_t* state) {
    ast_expr_comp_t* ptr = create_expr_comp();
    return ptr;
}

/*
 *    expr_term
 *        | expr_pow ADD expr_term
 *        | expr_pow SUB expr_term
 *        | expr_pow
 */
ast_expr_term_t* parse_expr_term(parser_state_t* state) {
    ast_expr_term_t* ptr = create_expr_term();
    return ptr;
}

/*
 *    expr_pow
 *        | expr_fact POW expr_pow
 *        | expr_fact
 */
ast_expr_pow_t* parse_expr_pow(parser_state_t* state) {
    ast_expr_pow_t* ptr = create_expr_pow();
    return ptr;
}

/*
 *    expr_fact
 *        | expr_unary MUL expr_fact
 *        | expr_unary DIV expr_fact
 *        | expr_unary MOD expr_fact
 *        | expr_unary
 */
ast_expr_fact_t* parse_expr_fact(parser_state_t* state) {
    ast_expr_fact_t* ptr = create_expr_fact();
    return ptr;
}

/*
 *    expr_unary
 *        | primary
 *        | SUB expr_unary
 *        | ADD expr_unary
 *        | NOT expr_unary
 *        | type_name OPAREN expr_unary CPAREN
 */
ast_expr_unary_t* parse_expr_unary(parser_state_t* state) {
    ast_expr_unary_t* ptr = create_expr_unary();
    return ptr;
}

/*
 *    expr_parms
 *        | OPAREN expr_list CPAREN
 */
ast_expr_parms_t* parse_expr_parms(parser_state_t* state) {
    ast_expr_parms_t* ptr = create_expr_parms();
    return ptr;
}

/*
 *    expr_list
 *        | expression COMMA expr_list
 *        | expression
 */
ast_expr_list_t* parse_expr_list(parser_state_t* state) {
    ast_expr_list_t* ptr = create_expr_list();
    return ptr;
}

/*
 *    expr_parens
 *        | OPAREN expression CPAREN
 */
ast_expr_parens_t* parse_expr_parens(parser_state_t* state) {
    ast_expr_parens_t* ptr = create_expr_parens();
    return ptr;
}

/*
 *    func_definition
 *        | var_declaration COLON SYMBOL func_decl_parms func_block
 */
ast_func_definition_t* parse_func_definition(parser_state_t* state) {
    ast_func_definition_t* ptr = create_func_definition();
    return ptr;
}

/*
 *    ctor_definition
 *        | SYMBOL COLON CREATE func_decl_parms func_block
 */
ast_ctor_definition_t* parse_ctor_definition(parser_state_t* state) {
    ast_ctor_definition_t* ptr = create_ctor_definition();
    return ptr;
}

/*
 *    dtor_definition
 *        | SYMBOL COLON DESTROY func_block
 */
ast_dtor_definition_t* parse_dtor_definition(parser_state_t* state) {
    ast_dtor_definition_t* ptr = create_dtor_definition();
    return ptr;
}

/*
 *    assignment_oper
 *        | ASSIGN
 *        | ADD_ASSIGN
 *        | SUB_ASSIGN
 *        | MUL_ASSIGN
 *        | DIV_ASSIGN
 *        | MOD_ASSIGN
 */
ast_assignment_oper_t* parse_assignment_oper(parser_state_t* state) {
    ast_assignment_oper_t* ptr = create_assignment_oper();
    return ptr;
}

/*
 *    assignment_tail
 *        | assignment_oper expression
 */
ast_assignment_tail_t* parse_assignment_tail(parser_state_t* state) {
    ast_assignment_tail_t* ptr = create_assignment_tail();
    return ptr;
}

/*
 *    assignment
 *        | compound_reference assignment_tail
 */
ast_assignment_t* parse_assignment(parser_state_t* state) {
    ast_assignment_t* ptr = create_assignment();
    return ptr;
}

/*
 *    data_definition
 *        | var_declaration
 *        | var_declaration assignment_tail
 */
ast_data_definition_t* parse_data_definition(parser_state_t* state) {
    ast_data_definition_t* ptr = create_data_definition();
    return ptr;
}

/*
 *    func_block
 *        | OBLOCK func_block_list CBLOCK
 *        | empty_block
 */
ast_func_block_t* parse_func_block(parser_state_t* state) {
    ast_func_block_t* ptr = create_func_block();
    return ptr;
}

/*
 *    func_block_list
 *        | func_block_elem
 *        | func_block_elem func_block_list
 */
ast_func_block_list_t* parse_func_block_list(parser_state_t* state) {
    ast_func_block_list_t* ptr = create_func_block_list();
    return ptr;
}

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
ast_func_block_elem_t* parse_func_block_elem(parser_state_t* state) {
    ast_func_block_elem_t* ptr = create_func_block_elem();
    return ptr;
}

/*
 *    print_statement
 *        | PRINT
 *        | PRINT empty_parens
 *        | PRINT OPAREN formatted_string CPAREN
 */
ast_print_statement_t* parse_print_statement(parser_state_t* state) {
    ast_print_statement_t* ptr = create_print_statement();
    return ptr;
}

/*
 *    trace_statement
 *        | TRACE
 *        | TRACE empty_parens
 *        | TRACE OPAREN formatted_string CPAREN
 */
ast_trace_statement_t* parse_trace_statement(parser_state_t* state) {
    ast_trace_statement_t* ptr = create_trace_statement();
    return ptr;
}

/*
 *    return_statement
 *        | RETURN
 *        | RETURN empty_parens
 *        | RETURN expr_parens
 */
ast_return_statement_t* parse_return_statement(parser_state_t* state) {
    ast_return_statement_t* ptr = create_return_statement();
    return ptr;
}

/*
 *    if_else_clause
 *        | if_clause
 *        | if_clause else_clause_list
 *        | if_clause else_clause_final
 *        | if_clause else_clause_list else_clause_final
 */
ast_if_else_clause_t* parse_if_else_clause(parser_state_t* state) {
    ast_if_else_clause_t* ptr = create_if_else_clause();
    return ptr;
}

/*
 *    if_clause
 *        | IF expr_parens func_block
 */
ast_if_clause_t* parse_if_clause(parser_state_t* state) {
    ast_if_clause_t* ptr = create_if_clause();
    return ptr;
}

/*
 *    else_clause
 *        | ELSE expr_parens func_block
 */
ast_else_clause_t* parse_else_clause(parser_state_t* state) {
    ast_else_clause_t* ptr = create_else_clause();
    return ptr;
}

/*
 *    else_clause_list
 *        | else_clause
 *        | else_clause else_clause_list
 */
ast_else_clause_list_t* parse_else_clause_list(parser_state_t* state) {
    ast_else_clause_list_t* ptr = create_else_clause_list();
    return ptr;
}

/*
 *    else_clause_final
 *        | ELSE empty_parens func_block
 *        | ELSE func_block
 */
ast_else_clause_final_t* parse_else_clause_final(parser_state_t* state) {
    ast_else_clause_final_t* ptr = create_else_clause_final();
    return ptr;
}

/*
 *    while_clause
 *        | WHILE expr_parens func_block
 */
ast_while_clause_t* parse_while_clause(parser_state_t* state) {
    ast_while_clause_t* ptr = create_while_clause();
    return ptr;
}

/*
 *    do_clause
 *        | DO func_block WHILE expr_parens
 */
ast_do_clause_t* parse_do_clause(parser_state_t* state) {
    ast_do_clause_t* ptr = create_do_clause();
    return ptr;
}

/*
 *    for_entry
 *        | FOR OPAREN SYMBOL IN
 */
ast_for_entry_t* parse_for_entry(parser_state_t* state) {
    ast_for_entry_t* ptr = create_for_entry();
    return ptr;
}

/*
 *    for_clause
 *        | for_entry compound_reference CPAREN func_block
 *        | for_entry expression TO expression CPAREN func_block
 */
ast_for_clause_t* parse_for_clause(parser_state_t* state) {
    ast_for_clause_t* ptr = create_for_clause();
    return ptr;
}

/*
 *    switch_case_clause
 *        | switch_clause case_clause_list case_clause_final
 */
ast_switch_case_clause_t* parse_switch_case_clause(parser_state_t* state) {
    ast_switch_case_clause_t* ptr = create_switch_case_clause();
    return ptr;
}

/*
 *    switch_clause
 *        | SWITCH expr_parens OBLOCK
 */
ast_switch_clause_t* parse_switch_clause(parser_state_t* state) {
    ast_switch_clause_t* ptr = create_switch_clause();
    return ptr;
}

/*
 *    case_clause
 *        | CASE OPAREN const_expression CPAREN func_block
 */
ast_case_clause_t* parse_case_clause(parser_state_t* state) {
    ast_case_clause_t* ptr = create_case_clause();
    return ptr;
}

/*
 *    case_clause_list
 *        | case_clause case_clause_list
 *        | case_clause
 */
ast_case_clause_list_t* parse_case_clause_list(parser_state_t* state) {
    ast_case_clause_list_t* ptr = create_case_clause_list();
    return ptr;
}

/*
 *    case_clause_final
 *        | CBLOCK
 *        | DEFAULT func_block CBLOCK
 */
ast_case_clause_final_t* parse_case_clause_final(parser_state_t* state) {
    ast_case_clause_final_t* ptr = create_case_clause_final();
    return ptr;
}

/*
 *    try_except_clause
 *        | try_clause except_clause_list
 *        | try_clause except_clause_final
 *        | try_clause except_clause_list except_clause_final
 */
ast_try_except_clause_t* parse_try_except_clause(parser_state_t* state) {
    ast_try_except_clause_t* ptr = create_try_except_clause();
    return ptr;
}

/*
 *    try_clause
 *        | TRY func_block
 */
ast_try_clause_t* parse_try_clause(parser_state_t* state) {
    ast_try_clause_t* ptr = create_try_clause();
    return ptr;
}

/*
 *    except_clause
 *        | EXCEPT OPAREN compound_name CPAREN AS SYMBOL func_block
 */
ast_except_clause_t* parse_except_clause(parser_state_t* state) {
    ast_except_clause_t* ptr = create_except_clause();
    return ptr;
}

/*
 *    except_clause_list
 *        | except_clause except_clause_list
 *        | except_clause
 */
ast_except_clause_list_t* parse_except_clause_list(parser_state_t* state) {
    ast_except_clause_list_t* ptr = create_except_clause_list();
    return ptr;
}

/*
 *    except_clause_final
 *        | EXCEPT empty_parens func_block
 *        | EXCEPT func_block
 */
ast_except_clause_final_t* parse_except_clause_final(parser_state_t* state) {
    ast_except_clause_final_t* ptr = create_except_clause_final();
    return ptr;
}

