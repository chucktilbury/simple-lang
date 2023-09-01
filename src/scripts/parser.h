/* generated file. DO NOT EDIT */
#ifndef _PARSER_H
#define _PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "ast.h"

typedef struct _parser_state_t_ {
    bool error; /* set if handling an error */
    const char* emsg;
    int errors;
    int warnings;
} parser_state_t;

/* parse function headers */
parser_state_t* create_parser_state();
void destroy_parser_state(parser_state_t* state);

ast_module_t* parse_module(parser_state_t* state);
ast_module_type_t* parse_module_type(parser_state_t* state);
ast_module_body_t* parse_module_body(parser_state_t* state);
ast_module_element_t* parse_module_element(parser_state_t* state);
ast_module_body_list_t* parse_module_body_list(parser_state_t* state);
ast_import_statement_t* parse_import_statement(parser_state_t* state);
ast_entry_definition_t* parse_entry_definition(parser_state_t* state);
ast_scope_t* parse_scope(parser_state_t* state);
ast_type_name_t* parse_type_name(parser_state_t* state);
ast_empty_parens_t* parse_empty_parens(parser_state_t* state);
ast_empty_block_t* parse_empty_block(parser_state_t* state);
ast_compound_reference_t* parse_compound_reference(parser_state_t* state);
ast_compound_reference_element_t* parse_compound_reference_element(parser_state_t* state);
ast_compound_name_t* parse_compound_name(parser_state_t* state);
ast_formatted_string_t* parse_formatted_string(parser_state_t* state);
ast_func_reference_t* parse_func_reference(parser_state_t* state);
ast_array_reference_t* parse_array_reference(parser_state_t* state);
ast_array_brace_t* parse_array_brace(parser_state_t* state);
ast_array_reference_list_t* parse_array_reference_list(parser_state_t* state);
ast_namespace_definition_t* parse_namespace_definition(parser_state_t* state);
ast_namespace_block_t* parse_namespace_block(parser_state_t* state);
ast_namespace_body_t* parse_namespace_body(parser_state_t* state);
ast_namespace_element_t* parse_namespace_element(parser_state_t* state);
ast_class_definition_t* parse_class_definition(parser_state_t* state);
ast_class_parameters_t* parse_class_parameters(parser_state_t* state);
ast_class_block_t* parse_class_block(parser_state_t* state);
ast_class_body_t* parse_class_body(parser_state_t* state);
ast_class_body_element_t* parse_class_body_element(parser_state_t* state);
ast_var_declaration_t* parse_var_declaration(parser_state_t* state);
ast_var_declaration_list_t* parse_var_declaration_list(parser_state_t* state);
ast_func_declaration_t* parse_func_declaration(parser_state_t* state);
ast_func_decl_parms_t* parse_func_decl_parms(parser_state_t* state);
ast_bool_literal_t* parse_bool_literal(parser_state_t* state);
ast_primary_t* parse_primary(parser_state_t* state);
ast_const_expression_t* parse_const_expression(parser_state_t* state);
ast_expression_t* parse_expression(parser_state_t* state);
ast_expr_and_t* parse_expr_and(parser_state_t* state);
ast_expr_equ_t* parse_expr_equ(parser_state_t* state);
ast_expr_compe_t* parse_expr_compe(parser_state_t* state);
ast_expr_comp_t* parse_expr_comp(parser_state_t* state);
ast_expr_term_t* parse_expr_term(parser_state_t* state);
ast_expr_pow_t* parse_expr_pow(parser_state_t* state);
ast_expr_fact_t* parse_expr_fact(parser_state_t* state);
ast_expr_unary_t* parse_expr_unary(parser_state_t* state);
ast_expr_parms_t* parse_expr_parms(parser_state_t* state);
ast_expr_list_t* parse_expr_list(parser_state_t* state);
ast_expr_parens_t* parse_expr_parens(parser_state_t* state);
ast_func_definition_t* parse_func_definition(parser_state_t* state);
ast_ctor_definition_t* parse_ctor_definition(parser_state_t* state);
ast_dtor_definition_t* parse_dtor_definition(parser_state_t* state);
ast_assignment_oper_t* parse_assignment_oper(parser_state_t* state);
ast_assignment_tail_t* parse_assignment_tail(parser_state_t* state);
ast_assignment_t* parse_assignment(parser_state_t* state);
ast_data_definition_t* parse_data_definition(parser_state_t* state);
ast_func_block_t* parse_func_block(parser_state_t* state);
ast_func_block_list_t* parse_func_block_list(parser_state_t* state);
ast_func_block_elem_t* parse_func_block_elem(parser_state_t* state);
ast_print_statement_t* parse_print_statement(parser_state_t* state);
ast_trace_statement_t* parse_trace_statement(parser_state_t* state);
ast_return_statement_t* parse_return_statement(parser_state_t* state);
ast_if_else_clause_t* parse_if_else_clause(parser_state_t* state);
ast_if_clause_t* parse_if_clause(parser_state_t* state);
ast_else_clause_t* parse_else_clause(parser_state_t* state);
ast_else_clause_list_t* parse_else_clause_list(parser_state_t* state);
ast_else_clause_final_t* parse_else_clause_final(parser_state_t* state);
ast_while_clause_t* parse_while_clause(parser_state_t* state);
ast_do_clause_t* parse_do_clause(parser_state_t* state);
ast_for_entry_t* parse_for_entry(parser_state_t* state);
ast_for_clause_t* parse_for_clause(parser_state_t* state);
ast_switch_case_clause_t* parse_switch_case_clause(parser_state_t* state);
ast_switch_clause_t* parse_switch_clause(parser_state_t* state);
ast_case_clause_t* parse_case_clause(parser_state_t* state);
ast_case_clause_list_t* parse_case_clause_list(parser_state_t* state);
ast_case_clause_final_t* parse_case_clause_final(parser_state_t* state);
ast_try_except_clause_t* parse_try_except_clause(parser_state_t* state);
ast_try_clause_t* parse_try_clause(parser_state_t* state);
ast_except_clause_t* parse_except_clause(parser_state_t* state);
ast_except_clause_list_t* parse_except_clause_list(parser_state_t* state);
ast_except_clause_final_t* parse_except_clause_final(parser_state_t* state);

#endif /* _PARSER_H */

