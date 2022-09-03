#ifndef COMPILER_HW_COMMON_H
#define COMPILER_HW_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Add what you need */

int scope_level;

// binary operators for 2~6 precedences

int b_op; 
int u_op;
int assign_op;

char id_buf[100], type_buf[10], func_sig_buf[100];
char func_id_buf[100];

char expr_type[10], expr_type2[10];
int which_expr;
int literal_count;
#endif /* COMPILER_HW_COMMON_H */