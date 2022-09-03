#ifndef COMPILER_HW_COMMON_H
#define COMPILER_HW_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Add what you need */

// the global variable of recording the nubmer of address (from -1 start to N)
int addr;

// record the tail index of each table of scope
int scope_stack_top[10];

// record the elements of variable in the table
struct symbol_table
{
    int index[100];
    char name[100][100];
    char type[100][10];
    int addr[100];
    int lineno[100];
    char funcsig[100][100];
};
// declaration of table
struct symbol_table table_instances[10];

int result[2]; // results of lookup table, 0: scope, 1: index
char type[10];

int scope_level;

int b_op;
int u_op;
int assign_op;

char id_buf[100], type_buf[10], func_sig_buf[100];
char func_id_buf[100];

char expr_type[10], expr_type2[10];
int which_expr;
int literal_count;
char param_type[10][10];
int param_count;
int label_cnt;
int switch_cnt;
int case_cnt;
bool no_return;
bool is_bi_op;
bool has_type_converse;
int type_buf_2;
#endif /* COMPILER_HW_COMMON_H */