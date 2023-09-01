/* generated file. DO NOT EDIT */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "ast.h"
#include "mem.h"

/*
 *    module
 *        | MODULE SYMBOL COLON module_type module_body
 */
ast_module_t* create_module() {
    ast_module_t* ptr = _alloc_ds(ast_module_t);
    return ptr;
}

/*
 *    module_type
 *        | EXEC
 *        | STATIC
 *        | DYNAMIC
 */
ast_module_type_t* create_module_type() {
    ast_module_type_t* ptr = _alloc_ds(ast_module_type_t);
    return ptr;
}

/*
 *    module_body
 *        | OBLOCK module_body_list CBLOCK
 */
ast_module_body_t* create_module_body() {
    ast_module_body_t* ptr = _alloc_ds(ast_module_body_t);
    return ptr;
}

/*
 *    module_element
 *        | namespace_element
 *        | import_statement
 *        | entry_definition
 */
ast_module_element_t* create_module_element() {
    ast_module_element_t* ptr = _alloc_ds(ast_module_element_t);
    return ptr;
}

/*
 *    module_body_list
 *        | module_element module_body_list
 *        | module_element
 */
ast_module_body_list_t* create_module_body_list() {
    ast_module_body_list_t* ptr = _alloc_ds(ast_module_body_list_t);
    return ptr;
}

/*
 *    import_statement
 *        | IMPORT compound_name
 *        | IMPORT compound_name AS SYMBOL
 */
ast_import_statement_t* create_import_statement() {
    ast_import_statement_t* ptr = _alloc_ds(ast_import_statement_t);
    return ptr;
}

/*
 *    entry_definition
 *        | ENTRY func_block
 */
ast_entry_definition_t* create_entry_definition() {
    ast_entry_definition_t* ptr = _alloc_ds(ast_entry_definition_t);
    return ptr;
}

/*
 *    scope
 *        | PUBLIC
 *        | PRIVATE
 *        | PROTECTED
 */
ast_scope_t* create_scope() {
    ast_scope_t* ptr = _alloc_ds(ast_scope_t);
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
ast_type_name_t* create_type_name() {
    ast_type_name_t* ptr = _alloc_ds(ast_type_name_t);
    return ptr;
}

/*
 *    empty_parens
 *        | OPAREN CPAREN
 */
ast_empty_parens_t* create_empty_parens() {
    ast_empty_parens_t* ptr = _alloc_ds(ast_empty_parens_t);
    return ptr;
}

/*
 *    empty_block
 *        | OBLOCK CBLOCK
 */
ast_empty_block_t* create_empty_block() {
    ast_empty_block_t* ptr = _alloc_ds(ast_empty_block_t);
    return ptr;
}

/*
 *    compound_reference
 *        | compound_reference_element DOT compound_reference
 *        | compound_reference_element
 */
ast_compound_reference_t* create_compound_reference() {
    ast_compound_reference_t* ptr = _alloc_ds(ast_compound_reference_t);
    return ptr;
}

/*
 *    compound_reference_element
 *        | compound_name
 *        | func_reference
 *        | array_reference
 */
ast_compound_reference_element_t* create_compound_reference_element() {
    ast_compound_reference_element_t* ptr = _alloc_ds(ast_compound_reference_element_t);
    return ptr;
}

/*
 *    compound_name
 *        | SYMBOL DOT compound_name
 *        | SYMBOL
 */
ast_compound_name_t* create_compound_name() {
    ast_compound_name_t* ptr = _alloc_ds(ast_compound_name_t);
    return ptr;
}

/*
 *    formatted_string
 *        | STRG_CONST expr_parms
 *        | STRG_CONST empty_parens
 *        | STRG_CONST
 */
ast_formatted_string_t* create_formatted_string() {
    ast_formatted_string_t* ptr = _alloc_ds(ast_formatted_string_t);
    return ptr;
}

/*
 *    func_reference
 *        | SYMBOL expr_parms
 *        | SYMBOL empty_parens
 */
ast_func_reference_t* create_func_reference() {
    ast_func_reference_t* ptr = _alloc_ds(ast_func_reference_t);
    return ptr;
}

/*
 *    array_reference
 *        | SYMBOL array_reference_list
 */
ast_array_reference_t* create_array_reference() {
    ast_array_reference_t* ptr = _alloc_ds(ast_array_reference_t);
    return ptr;
}

/*
 *    array_brace
 *        | OBRACE expression CBRACE
 */
ast_array_brace_t* create_array_brace() {
    ast_array_brace_t* ptr = _alloc_ds(ast_array_brace_t);
    return ptr;
}

/*
 *    array_reference_list
 *        | array_brace array_reference_list
 *        | array_brace
 */
ast_array_reference_list_t* create_array_reference_list() {
    ast_array_reference_list_t* ptr = _alloc_ds(ast_array_reference_list_t);
    return ptr;
}

/*
 *    namespace_definition
 *        | NAMESPACE SYMBOL namespace_block
 */
ast_namespace_definition_t* create_namespace_definition() {
    ast_namespace_definition_t* ptr = _alloc_ds(ast_namespace_definition_t);
    return ptr;
}

/*
 *    namespace_block
 *        | OBLOCK namespace_body CBLOCK
 *        | empty_block
 */
ast_namespace_block_t* create_namespace_block() {
    ast_namespace_block_t* ptr = _alloc_ds(ast_namespace_block_t);
    return ptr;
}

/*
 *    namespace_body
 *        | namespace_element namespace_block
 *        | namespace_element
 */
ast_namespace_body_t* create_namespace_body() {
    ast_namespace_body_t* ptr = _alloc_ds(ast_namespace_body_t);
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
ast_namespace_element_t* create_namespace_element() {
    ast_namespace_element_t* ptr = _alloc_ds(ast_namespace_element_t);
    return ptr;
}

/*
 *    class_definition
 *        | CLASS SYMBOL class_parameters class_block
 */
ast_class_definition_t* create_class_definition() {
    ast_class_definition_t* ptr = _alloc_ds(ast_class_definition_t);
    return ptr;
}

/*
 *    class_parameters
 *        | OPAREN compound_name CPAREN
 *        | empty_parens
 */
ast_class_parameters_t* create_class_parameters() {
    ast_class_parameters_t* ptr = _alloc_ds(ast_class_parameters_t);
    return ptr;
}

/*
 *    class_block
 *        | OBLOCK class_body CBLOCK
 *        | empty_block
 */
ast_class_block_t* create_class_block() {
    ast_class_block_t* ptr = _alloc_ds(ast_class_block_t);
    return ptr;
}

/*
 *    class_body
 *        | class_body_element class_body
 *        | class_body_element
 */
ast_class_body_t* create_class_body() {
    ast_class_body_t* ptr = _alloc_ds(ast_class_body_t);
    return ptr;
}

/*
 *    class_body_element
 *        | var_declaration
 *        | func_declaration
 *        | scope
 */
ast_class_body_element_t* create_class_body_element() {
    ast_class_body_element_t* ptr = _alloc_ds(ast_class_body_element_t);
    return ptr;
}

/*
 *    var_declaration
 *        | type_name SYMBOL
 */
ast_var_declaration_t* create_var_declaration() {
    ast_var_declaration_t* ptr = _alloc_ds(ast_var_declaration_t);
    return ptr;
}

/*
 *    var_declaration_list
 *        | var_declaration COMMA var_declaration_list
 *        | var_declaration
 */
ast_var_declaration_list_t* create_var_declaration_list() {
    ast_var_declaration_list_t* ptr = _alloc_ds(ast_var_declaration_list_t);
    return ptr;
}

/*
 *    func_declaration
 *        | type_name SYMBOL func_decl_parms
 *        | CREATE func_decl_parms
 *        | DESTROY
 */
ast_func_declaration_t* create_func_declaration() {
    ast_func_declaration_t* ptr = _alloc_ds(ast_func_declaration_t);
    return ptr;
}

/*
 *    func_decl_parms
 *        | OPAREN var_declaration_list CPAREN
 *        | empty_parens
 */
ast_func_decl_parms_t* create_func_decl_parms() {
    ast_func_decl_parms_t* ptr = _alloc_ds(ast_func_decl_parms_t);
    return ptr;
}

/*
 *    bool_literal
 *        | TRUE
 *        | FALSE
 */
ast_bool_literal_t* create_bool_literal() {
    ast_bool_literal_t* ptr = _alloc_ds(ast_bool_literal_t);
    return ptr;
}

/*
 *    primary
 *        | compound_reference
 *        | const_expression
 *        | expr_parens
 */
ast_primary_t* create_primary() {
    ast_primary_t* ptr = _alloc_ds(ast_primary_t);
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
ast_const_expression_t* create_const_expression() {
    ast_const_expression_t* ptr = _alloc_ds(ast_const_expression_t);
    return ptr;
}

/*
 *    expression
 *        | expr_and OR expression
 *        | expr_and
 */
ast_expression_t* create_expression() {
    ast_expression_t* ptr = _alloc_ds(ast_expression_t);
    return ptr;
}

/*
 *    expr_and
 *        | expr_equ AND expr_and
 *        | expr_equ
 */
ast_expr_and_t* create_expr_and() {
    ast_expr_and_t* ptr = _alloc_ds(ast_expr_and_t);
    return ptr;
}

/*
 *    expr_equ
 *        | expr_compe EQU expr_equ
 *        | expr_compe NEQU expr_equ
 *        | expr_compe
 */
ast_expr_equ_t* create_expr_equ() {
    ast_expr_equ_t* ptr = _alloc_ds(ast_expr_equ_t);
    return ptr;
}

/*
 *    expr_compe
 *        | expr_comp LORE expr_compe
 *        | expr_comp GORE expr_compe
 *        | expr_comp
 */
ast_expr_compe_t* create_expr_compe() {
    ast_expr_compe_t* ptr = _alloc_ds(ast_expr_compe_t);
    return ptr;
}

/*
 *    expr_comp
 *        | expr_term LESS expr_comp
 *        | expr_term MORE expr_comp
 *        | expr_term
 */
ast_expr_comp_t* create_expr_comp() {
    ast_expr_comp_t* ptr = _alloc_ds(ast_expr_comp_t);
    return ptr;
}

/*
 *    expr_term
 *        | expr_pow ADD expr_term
 *        | expr_pow SUB expr_term
 *        | expr_pow
 */
ast_expr_term_t* create_expr_term() {
    ast_expr_term_t* ptr = _alloc_ds(ast_expr_term_t);
    return ptr;
}

/*
 *    expr_pow
 *        | expr_fact POW expr_pow
 *        | expr_fact
 */
ast_expr_pow_t* create_expr_pow() {
    ast_expr_pow_t* ptr = _alloc_ds(ast_expr_pow_t);
    return ptr;
}

/*
 *    expr_fact
 *        | expr_unary MUL expr_fact
 *        | expr_unary DIV expr_fact
 *        | expr_unary MOD expr_fact
 *        | expr_unary
 */
ast_expr_fact_t* create_expr_fact() {
    ast_expr_fact_t* ptr = _alloc_ds(ast_expr_fact_t);
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
ast_expr_unary_t* create_expr_unary() {
    ast_expr_unary_t* ptr = _alloc_ds(ast_expr_unary_t);
    return ptr;
}

/*
 *    expr_parms
 *        | OPAREN expr_list CPAREN
 */
ast_expr_parms_t* create_expr_parms() {
    ast_expr_parms_t* ptr = _alloc_ds(ast_expr_parms_t);
    return ptr;
}

/*
 *    expr_list
 *        | expression COMMA expr_list
 *        | expression
 */
ast_expr_list_t* create_expr_list() {
    ast_expr_list_t* ptr = _alloc_ds(ast_expr_list_t);
    return ptr;
}

/*
 *    expr_parens
 *        | OPAREN expression CPAREN
 */
ast_expr_parens_t* create_expr_parens() {
    ast_expr_parens_t* ptr = _alloc_ds(ast_expr_parens_t);
    return ptr;
}

/*
 *    func_definition
 *        | var_declaration COLON SYMBOL func_decl_parms func_block
 */
ast_func_definition_t* create_func_definition() {
    ast_func_definition_t* ptr = _alloc_ds(ast_func_definition_t);
    return ptr;
}

/*
 *    ctor_definition
 *        | SYMBOL COLON CREATE func_decl_parms func_block
 */
ast_ctor_definition_t* create_ctor_definition() {
    ast_ctor_definition_t* ptr = _alloc_ds(ast_ctor_definition_t);
    return ptr;
}

/*
 *    dtor_definition
 *        | SYMBOL COLON DESTROY func_block
 */
ast_dtor_definition_t* create_dtor_definition() {
    ast_dtor_definition_t* ptr = _alloc_ds(ast_dtor_definition_t);
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
ast_assignment_oper_t* create_assignment_oper() {
    ast_assignment_oper_t* ptr = _alloc_ds(ast_assignment_oper_t);
    return ptr;
}

/*
 *    assignment_tail
 *        | assignment_oper expression
 */
ast_assignment_tail_t* create_assignment_tail() {
    ast_assignment_tail_t* ptr = _alloc_ds(ast_assignment_tail_t);
    return ptr;
}

/*
 *    assignment
 *        | compound_reference assignment_tail
 */
ast_assignment_t* create_assignment() {
    ast_assignment_t* ptr = _alloc_ds(ast_assignment_t);
    return ptr;
}

/*
 *    data_definition
 *        | var_declaration
 *        | var_declaration assignment_tail
 */
ast_data_definition_t* create_data_definition() {
    ast_data_definition_t* ptr = _alloc_ds(ast_data_definition_t);
    return ptr;
}

/*
 *    func_block
 *        | OBLOCK func_block_list CBLOCK
 *        | empty_block
 */
ast_func_block_t* create_func_block() {
    ast_func_block_t* ptr = _alloc_ds(ast_func_block_t);
    return ptr;
}

/*
 *    func_block_list
 *        | func_block_elem
 *        | func_block_elem func_block_list
 */
ast_func_block_list_t* create_func_block_list() {
    ast_func_block_list_t* ptr = _alloc_ds(ast_func_block_list_t);
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
ast_func_block_elem_t* create_func_block_elem() {
    ast_func_block_elem_t* ptr = _alloc_ds(ast_func_block_elem_t);
    return ptr;
}

/*
 *    print_statement
 *        | PRINT
 *        | PRINT empty_parens
 *        | PRINT OPAREN formatted_string CPAREN
 */
ast_print_statement_t* create_print_statement() {
    ast_print_statement_t* ptr = _alloc_ds(ast_print_statement_t);
    return ptr;
}

/*
 *    trace_statement
 *        | TRACE
 *        | TRACE empty_parens
 *        | TRACE OPAREN formatted_string CPAREN
 */
ast_trace_statement_t* create_trace_statement() {
    ast_trace_statement_t* ptr = _alloc_ds(ast_trace_statement_t);
    return ptr;
}

/*
 *    return_statement
 *        | RETURN
 *        | RETURN empty_parens
 *        | RETURN expr_parens
 */
ast_return_statement_t* create_return_statement() {
    ast_return_statement_t* ptr = _alloc_ds(ast_return_statement_t);
    return ptr;
}

/*
 *    if_else_clause
 *        | if_clause
 *        | if_clause else_clause_list
 *        | if_clause else_clause_final
 *        | if_clause else_clause_list else_clause_final
 */
ast_if_else_clause_t* create_if_else_clause() {
    ast_if_else_clause_t* ptr = _alloc_ds(ast_if_else_clause_t);
    return ptr;
}

/*
 *    if_clause
 *        | IF expr_parens func_block
 */
ast_if_clause_t* create_if_clause() {
    ast_if_clause_t* ptr = _alloc_ds(ast_if_clause_t);
    return ptr;
}

/*
 *    else_clause
 *        | ELSE expr_parens func_block
 */
ast_else_clause_t* create_else_clause() {
    ast_else_clause_t* ptr = _alloc_ds(ast_else_clause_t);
    return ptr;
}

/*
 *    else_clause_list
 *        | else_clause
 *        | else_clause else_clause_list
 */
ast_else_clause_list_t* create_else_clause_list() {
    ast_else_clause_list_t* ptr = _alloc_ds(ast_else_clause_list_t);
    return ptr;
}

/*
 *    else_clause_final
 *        | ELSE empty_parens func_block
 *        | ELSE func_block
 */
ast_else_clause_final_t* create_else_clause_final() {
    ast_else_clause_final_t* ptr = _alloc_ds(ast_else_clause_final_t);
    return ptr;
}

/*
 *    while_clause
 *        | WHILE expr_parens func_block
 */
ast_while_clause_t* create_while_clause() {
    ast_while_clause_t* ptr = _alloc_ds(ast_while_clause_t);
    return ptr;
}

/*
 *    do_clause
 *        | DO func_block WHILE expr_parens
 */
ast_do_clause_t* create_do_clause() {
    ast_do_clause_t* ptr = _alloc_ds(ast_do_clause_t);
    return ptr;
}

/*
 *    for_entry
 *        | FOR OPAREN SYMBOL IN
 */
ast_for_entry_t* create_for_entry() {
    ast_for_entry_t* ptr = _alloc_ds(ast_for_entry_t);
    return ptr;
}

/*
 *    for_clause
 *        | for_entry compound_reference CPAREN func_block
 *        | for_entry expression TO expression CPAREN func_block
 */
ast_for_clause_t* create_for_clause() {
    ast_for_clause_t* ptr = _alloc_ds(ast_for_clause_t);
    return ptr;
}

/*
 *    switch_case_clause
 *        | switch_clause case_clause_list case_clause_final
 */
ast_switch_case_clause_t* create_switch_case_clause() {
    ast_switch_case_clause_t* ptr = _alloc_ds(ast_switch_case_clause_t);
    return ptr;
}

/*
 *    switch_clause
 *        | SWITCH expr_parens OBLOCK
 */
ast_switch_clause_t* create_switch_clause() {
    ast_switch_clause_t* ptr = _alloc_ds(ast_switch_clause_t);
    return ptr;
}

/*
 *    case_clause
 *        | CASE OPAREN const_expression CPAREN func_block
 */
ast_case_clause_t* create_case_clause() {
    ast_case_clause_t* ptr = _alloc_ds(ast_case_clause_t);
    return ptr;
}

/*
 *    case_clause_list
 *        | case_clause case_clause_list
 *        | case_clause
 */
ast_case_clause_list_t* create_case_clause_list() {
    ast_case_clause_list_t* ptr = _alloc_ds(ast_case_clause_list_t);
    return ptr;
}

/*
 *    case_clause_final
 *        | CBLOCK
 *        | DEFAULT func_block CBLOCK
 */
ast_case_clause_final_t* create_case_clause_final() {
    ast_case_clause_final_t* ptr = _alloc_ds(ast_case_clause_final_t);
    return ptr;
}

/*
 *    try_except_clause
 *        | try_clause except_clause_list
 *        | try_clause except_clause_final
 *        | try_clause except_clause_list except_clause_final
 */
ast_try_except_clause_t* create_try_except_clause() {
    ast_try_except_clause_t* ptr = _alloc_ds(ast_try_except_clause_t);
    return ptr;
}

/*
 *    try_clause
 *        | TRY func_block
 */
ast_try_clause_t* create_try_clause() {
    ast_try_clause_t* ptr = _alloc_ds(ast_try_clause_t);
    return ptr;
}

/*
 *    except_clause
 *        | EXCEPT OPAREN compound_name CPAREN AS SYMBOL func_block
 */
ast_except_clause_t* create_except_clause() {
    ast_except_clause_t* ptr = _alloc_ds(ast_except_clause_t);
    return ptr;
}

/*
 *    except_clause_list
 *        | except_clause except_clause_list
 *        | except_clause
 */
ast_except_clause_list_t* create_except_clause_list() {
    ast_except_clause_list_t* ptr = _alloc_ds(ast_except_clause_list_t);
    return ptr;
}

/*
 *    except_clause_final
 *        | EXCEPT empty_parens func_block
 *        | EXCEPT func_block
 */
ast_except_clause_final_t* create_except_clause_final() {
    ast_except_clause_final_t* ptr = _alloc_ds(ast_except_clause_final_t);
    return ptr;
}

