/* Please feel free to modify any content */

/* Definition section */
%{
    #include "compiler_hw_common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

        
    /* Symbol table function - you can add new functions if needed. */
    /* parameters and return type can be changed */
    static void create_symbol(int level);
    static void insert_symbol(char *id, int addr_in);
    static void lookup_symbol(char *id);
    static void dump_symbol(int which_table);
    static void update_table(char *id);

    int yylex_destroy ();
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }
    /* Used to generate code */
    /* As printf; the usage: CODEGEN("%d - %s\n", 100, "Hello world"); */
    /* We do not enforce the use of this macro */
    #define CODEGEN(...) \
        do { \
            for (int i = 0; i < g_indent_cnt; i++) { \
                fprintf(fout, "\t"); \
            } \
            fprintf(fout, __VA_ARGS__); \
        } while (0)

    /* Global variables */
    bool g_has_error = false;
    FILE *fout;
    int g_indent_cnt = 0;
%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 *  - you can add new fields if needed.
 */
%union {
    int i_val;
    float f_val;
    char *s_val;
    /* ... */
    char *id;
    char *msg;
}

/* Token without return */
%token VAR NEWLINE
%token INT FLOAT BOOL STRING
%token INC DEC GEQ LEQ EQL NEQ LOR LAND
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN QUO_ASSIGN REM_ASSIGN
%token IF ELSE FOR SWITCH CASE DEFAULT
%token PRINT PRINTLN
%token TRUE FASLE
%token IDENT
%token PACKAGE
%token FUNC
%token RETURN

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <s_val> STRING_LIT

/* Nonterminal with return, which need to sepcify type */
%type <s_val> Type
%type <s_val> DeclarationStmt

/* Define precedence */
%left LOR
%left LAND
%left GEQ LEQ EQL NEQ '<' '>'
%left '+' '-'
%left '*' '/' '%'

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%

Program
    : GlobalStatementList { dump_symbol(scope_level);}
;

GlobalStatementList 
    : GlobalStatementList GlobalStatement 
    | GlobalStatement
;

GlobalStatement
    : PackageStmt NEWLINES
    | FunctionDeclStmt FuncBlock 
    {
        if(no_return)
            fprintf(fout, "return\n");
        fprintf(fout, ".end method\n");
        no_return = true;
    }
    | NEWLINES
;

NEWLINES
    : NEWLINES NEWLINE {which_expr=0;}
    | NEWLINE {which_expr=0;}
;

PackageStmt
    : PACKAGE IDENT 
    {
        create_symbol(scope_level);
        printf("package: %s\n", yylval.s_val);
        fprintf(fout, ".source hw3.j\n");
        fprintf(fout, ".class public Main\n");
        fprintf(fout, ".super java/lang/Object\n");
    }
;

FunctionDeclStmt
    : FuncParam ReturnType
    {
        fprintf(fout, "%s\n", param_type[param_count-1]);
        fprintf(fout, ".limit stack 100\n");
        fprintf(fout, ".limit locals 100\n");
    }
    | FuncParam
    {
        printf("func_signature: ()V\n");
        strcpy(id_buf, func_id_buf);
        strcpy(type_buf, "func");
        strcpy(func_sig_buf, "()V");
        int tmp = addr;
        addr = 0;
        scope_level--;
        insert_symbol(func_id_buf, -1);
        update_table(func_id_buf); 
        addr = tmp;
        scope_level++;
        fprintf(fout, "V\n");
        fprintf(fout, ".limit stack 100\n");
        fprintf(fout, ".limit locals 100\n");
    }
;

FuncParam
    : FuncOpen '(' ')'
    {
        if (!strcmp(func_id_buf, "main"))
            fprintf(fout, "[Ljava/lang/String;)");
    } 
    | FuncOpen '(' ParameterList ')' 
;

FuncOpen
    : FUNC IDENT 
                { 
                    printf("func: %s\n", $<s_val>2);
                    create_symbol(scope_level + 1); 
                    strcpy(func_id_buf, $<s_val>2); 
                    fprintf(fout, ".method public static %s(", $<s_val>2);
                }
;

ParameterList
    : ParameterList ',' IDENT Type 
    {
        //dfsdfdsfsedfsdfsdfsdfffffffffffffffffff
        printf("param %s, type: %s\n", $<s_val>3, param_type[param_count-1]);
        insert_symbol($<s_val>3, addr++); 
        strcpy(func_sig_buf, "-"); 
        update_table($<s_val>3);
        fprintf(fout, "%s", param_type[param_count-1]);
        
        // printf("> Insert `%s` (addr: %d) to scope level %d\n", $<s_val>3, table_instances[result[0]].addr[result[1]], scope_level);
        // printf("hey %d\n", result[0]);
    }   
    | IDENT Type
    {

        printf("param %s, type: %s\n", $<s_val>1, param_type[param_count-1]);
        insert_symbol($<s_val>1, addr++); 
        strcpy(func_sig_buf, "-"); 
        update_table($<s_val>1);

        fprintf(fout, "%s)", param_type[param_count-1]);
        // printf("> Insert `%s` (addr: %d) to scope level %d\n", $<s_val>1, table_instances[result[0]].addr[result[1]], scope_level);
    }
;

ReturnType
    : Type
;

FuncBlock
    : '{' NEWLINES StatementList '}' { dump_symbol(scope_level + 1); }
;

Expression
    : Expression LOR Expression
    { 
        is_bi_op = true;
        lookup_symbol($<s_val>1);
        int first_index = result[1];
        char first_type[10], second_type[10];
        if(first_index==-1)
        {
            strcpy(first_type, expr_type);
            // if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            // {
            //     fprintf(fout, "ldc %d\n", atoi(yylval.msg));
            // }
            // else if(!strcmp(second_type, "float32"))
            // {
            //     fprintf(fout, "ldc %f\n", atof(yylval.msg));
            // }
            // else if(!strcmp(second_type, "string"))
            // {
            //     fprintf(fout, "ldc %s\n", yylval.s_val);
            // }
        }
        else
        {
            strcpy(first_type, table_instances[result[0]].type[first_index]);
            // if (!has_type_converse)
            // {
            //     if(!strcmp(first_type, "int32") || !strcmp(first_type, "bool"))
            //     {
            //         fprintf(fout, "iload %d\n", first_index);
            //     }
            //     else if(!strcmp(first_type, "float32"))
            //     {
            //         fprintf(fout, "fload %d\n", first_index);
            //     }
            //     else if(!strcmp(first_type, "string"))
            //     {
            //         fprintf(fout, "aload %d\n", first_index);
            //     }
            // }
        }
        lookup_symbol($<s_val>3);
        int second_index = result[1];
        if(second_index==-1)
        {
            if (literal_count>1)
                strcpy(second_type, type_buf);
            else 
                strcpy(second_type, expr_type);

            // if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            // {
            //     fprintf(fout, "ldc %d\n", atoi(yylval.msg));
            // }
            // else if(!strcmp(second_type, "float32"))
            // {
            //     fprintf(fout, "ldc %f\n", atof(yylval.msg));
            // }
            // else if(!strcmp(second_type, "string"))
            // {
            //     fprintf(fout, "ldc %s\n", yylval.s_val);
            // }
        }
        else
        {
            strcpy(second_type, table_instances[result[0]].type[second_index]);
            // if (!has_type_converse)
            // {
            //     if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            //     {
            //         fprintf(fout, "iload %d\n", second_index);
            //     }
            //     else if(!strcmp(second_type, "float32"))
            //     {
            //         fprintf(fout, "fload %d\n", second_index);
            //     }
            //     else if(!strcmp(second_type, "string"))
            //     {
            //         fprintf(fout, "aload %d\n", second_index);
            //     }
            // }
        }

        if(strcmp(first_type, "bool"))
        {
            printf("error:%d: invalid operation: (operator LOR not defined on %s)\n", yylineno, first_type);

            printf("LOR\n");   
        }
        else if(strcmp(second_type, "bool"))
        {
            printf("error:%d: invalid operation: (operator LOR not defined on %s)\n", yylineno, second_type);
            printf("LOR\n");
        }
        literal_count = 0;
        has_type_converse = false;
    }
    | Expression LAND Expression
    { 
        is_bi_op = true;
        lookup_symbol($<s_val>1);
        int first_index = result[1];
        char first_type[10], second_type[10];
        if(first_index==-1)
        {
            strcpy(first_type, expr_type);
            // if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            // {
            //     fprintf(fout, "ldc %d\n", atoi(yylval.msg));
            // }
            // else if(!strcmp(second_type, "float32"))
            // {
            //     fprintf(fout, "ldc %f\n", atof(yylval.msg));
            // }
            // else if(!strcmp(second_type, "string"))
            // {
            //     fprintf(fout, "ldc %s\n", yylval.s_val);
            // }
        }
        else
        {
            strcpy(first_type, table_instances[result[0]].type[first_index]);
            // if (!has_type_converse)
            // {
            //     if(!strcmp(first_type, "int32") || !strcmp(first_type, "bool"))
            //     {
            //         fprintf(fout, "iload %d\n", first_index);
            //     }
            //     else if(!strcmp(first_type, "float32"))
            //     {
            //         fprintf(fout, "fload %d\n", first_index);
            //     }
            //     else if(!strcmp(first_type, "string"))
            //     {
            //         fprintf(fout, "aload %d\n", first_index);
            //     }
            // }
        }
        lookup_symbol($<s_val>3);
        int second_index = result[1];
        if(second_index==-1)
        {
            if (literal_count>1)
                strcpy(second_type, type_buf);
            else 
                strcpy(second_type, expr_type);

            // if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            // {
            //     fprintf(fout, "ldc %d\n", atoi(yylval.msg));
            // }
            // else if(!strcmp(second_type, "float32"))
            // {
            //     fprintf(fout, "ldc %f\n", atof(yylval.msg));
            // }
            // else if(!strcmp(second_type, "string"))
            // {
            //     fprintf(fout, "ldc %s\n", yylval.s_val);
            // }
        }
        else
        {
            strcpy(second_type, table_instances[result[0]].type[second_index]);
            // if (!has_type_converse)
            // {
            //     if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            //     {
            //         fprintf(fout, "iload %d\n", second_index);
            //     }
            //     else if(!strcmp(second_type, "float32"))
            //     {
            //         fprintf(fout, "fload %d\n", second_index);
            //     }
            //     else if(!strcmp(second_type, "string"))
            //     {
            //         fprintf(fout, "aload %d\n", second_index);
            //     }
            // }
        }

        if(strcmp(first_type, "bool"))
        {
            printf("error:%d: invalid operation: (operator LAND not defined on %s)\n", yylineno, first_type);
            printf("LAND\n");   
        }
        else if(strcmp(second_type, "bool"))
        {
            printf("error:%d: invalid operation: (operator LAND not defined on %s)\n", yylineno, second_type);
            printf("LAND\n");   
        }
            literal_count = 0;
            has_type_converse = false;
    }
    | Expression cmp_op Expression 
    { 
        is_bi_op = true;
        lookup_symbol($<s_val>1);
        int first_index = result[1];
        char first_type[10], second_type[10];
        if(first_index==-1)
        {
            strcpy(first_type, expr_type);
            // if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            // {
            //     fprintf(fout, "ldc %d\n", atoi(yylval.msg));
            // }
            // else if(!strcmp(second_type, "float32"))
            // {
            //     fprintf(fout, "ldc %f\n", atof(yylval.msg));
            // }
            // else if(!strcmp(second_type, "string"))
            // {
            //     fprintf(fout, "ldc %s\n", yylval.s_val);
            // }
        }
        else
        {
            strcpy(first_type, table_instances[result[0]].type[first_index]);
            // if (!has_type_converse)
            // {
            //     if(!strcmp(first_type, "int32") || !strcmp(first_type, "bool"))
            //     {
            //         fprintf(fout, "iload %d\n", first_index);
            //     }
            //     else if(!strcmp(first_type, "float32"))
            //     {
            //         fprintf(fout, "fload %d\n", first_index);
            //     }
            //     else if(!strcmp(first_type, "string"))
            //     {
            //         fprintf(fout, "aload %d\n", first_index);
            //     }
            // }
        }
        lookup_symbol($<s_val>3);
        int second_index = result[1];
        if(second_index==-1)
        {
            if (literal_count>1)
                strcpy(second_type, type_buf);
            else 
                strcpy(second_type, expr_type);

            // if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            // {
            //     fprintf(fout, "ldc %d\n", atoi(yylval.msg));
            // }
            // else if(!strcmp(second_type, "float32"))
            // {
            //     fprintf(fout, "ldc %f\n", atof(yylval.msg));
            // }
            // else if(!strcmp(second_type, "string"))
            // {
            //     fprintf(fout, "ldc %s\n", yylval.s_val);
            // }
        }
        else
        {
            strcpy(second_type, table_instances[result[0]].type[second_index]);
            // if (!has_type_converse)
            // {
            //     if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            //     {
            //         fprintf(fout, "iload %d\n", second_index);
            //     }
            //     else if(!strcmp(second_type, "float32"))
            //     {
            //         fprintf(fout, "fload %d\n", second_index);
            //     }
            //     else if(!strcmp(second_type, "string"))
            //     {
            //         fprintf(fout, "aload %d\n", second_index);
            //     }
            // }
        }

        switch(b_op){
            case 6:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: EQL (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "isub") : fprintf(fout, "fcmpl");
                fprintf(fout, "ifeq L_cmp_%d\n", label_cnt++);
                fprintf(fout, "iconst_0\n");
                fprintf(fout, "goto L_cmp_%d\n", label_cnt++);
                fprintf(fout, "L_cmp_%d:\n", label_cnt-2);
                fprintf(fout, "iconst_1\n");
                fprintf(fout, "L_cmp_%d:\n", label_cnt-1);
                printf("EQL\n"); 
                break;
            case 7:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: NEQ (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "isub") : fprintf(fout, "fcmpl");
                fprintf(fout, "ifne L_cmp_%d\n", label_cnt++);
                fprintf(fout, "iconst_0\n");
                fprintf(fout, "goto L_cmp_%d\n", label_cnt++);
                fprintf(fout, "L_cmp_%d:\n", label_cnt-2);
                fprintf(fout, "iconst_1\n");
                fprintf(fout, "L_cmp_%d:\n", label_cnt-1);
                printf("NEQ\n"); 
                break;
            case 8:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: LSS (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "isub") : fprintf(fout, "fcmpl");
                fprintf(fout, "iflt L_cmp_%d\n", label_cnt++);
                fprintf(fout, "iconst_0\n");
                fprintf(fout, "goto L_cmp_%d\n", label_cnt++);
                fprintf(fout, "L_cmp_%d:\n", label_cnt-2);
                fprintf(fout, "iconst_1\n");
                fprintf(fout, "L_cmp_%d:\n", label_cnt-1);
                printf("LSS\n"); 
               break;
            case 9:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: LEQ (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "isub") : fprintf(fout, "fcmpl");
                fprintf(fout, "ifle L_cmp_%d\n", label_cnt++);
                fprintf(fout, "iconst_0\n");
                fprintf(fout, "goto L_cmp_%d\n", label_cnt++);
                fprintf(fout, "L_cmp_%d:\n", label_cnt-2);
                fprintf(fout, "iconst_1\n");
                fprintf(fout, "L_cmp_%d:\n", label_cnt-1);                
                printf("LEQ\n"); 
                break;
            case 10:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: GTR (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "isub") : fprintf(fout, "fcmpl");
                fprintf(fout, "ifgt L_cmp_%d\n", label_cnt++);
                fprintf(fout, "iconst_0\n");
                fprintf(fout, "goto L_cmp_%d\n", label_cnt++);
                fprintf(fout, "L_cmp_%d:\n", label_cnt-2);
                fprintf(fout, "iconst_1\n");
                fprintf(fout, "L_cmp_%d:\n", label_cnt-1);
                printf("GTR\n"); 
                break;
            case 11:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: GEQ (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "isub") : fprintf(fout, "fcmpl");
                fprintf(fout, "ifge L_cmp_%d\n", label_cnt++);
                fprintf(fout, "iconst_0\n");
                fprintf(fout, "goto L_cmp_%d\n", label_cnt++);
                fprintf(fout, "L_cmp_%d:\n", label_cnt-2);
                fprintf(fout, "iconst_1\n");
                fprintf(fout, "L_cmp_%d:\n", label_cnt-1);                
                printf("GEQ\n"); 
                break;
        }
        strcpy(expr_type, "bool");
        literal_count = 0;
        has_type_converse = false;
        // label_cnt = 0;
    }
    | Expression add_op Expression
    { 
        is_bi_op = true;
        lookup_symbol($<s_val>1);
        int first_index = result[1];
        char first_type[10], second_type[10];
        if(first_index==-1)
        {
            strcpy(first_type, expr_type);
            // if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            // {
            //     fprintf(fout, "ldc %d\n", atoi(yylval.msg));
            // }
            // else if(!strcmp(second_type, "float32"))
            // {
            //     fprintf(fout, "ldc %f\n", atof(yylval.msg));
            // }
            // else if(!strcmp(second_type, "string"))
            // {
            //     fprintf(fout, "ldc %s\n", yylval.s_val);
            // }
        }
        else
        {
            strcpy(first_type, table_instances[result[0]].type[first_index]);
            // if (!has_type_converse)
            // {
            //     if(!strcmp(first_type, "int32") || !strcmp(first_type, "bool"))
            //     {
            //         fprintf(fout, "iload %d\n", first_index);
            //     }
            //     else if(!strcmp(first_type, "float32"))
            //     {
            //         fprintf(fout, "fload %d\n", first_index);
            //     }
            //     else if(!strcmp(first_type, "string"))
            //     {
            //         fprintf(fout, "aload %d\n", first_index);
            //     }
            // }
        }
        lookup_symbol($<s_val>3);
        int second_index = result[1];
        if(second_index==-1)
        {
            if (literal_count>1)
                strcpy(second_type, type_buf);
            else 
                strcpy(second_type, expr_type);

            // if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            // {
            //     fprintf(fout, "ldc %d\n", atoi(yylval.msg));
            // }
            // else if(!strcmp(second_type, "float32"))
            // {
            //     fprintf(fout, "ldc %f\n", atof(yylval.msg));
            // }
            // else if(!strcmp(second_type, "string"))
            // {
            //     fprintf(fout, "ldc %s\n", yylval.s_val);
            // }
        }
        else
        {
            strcpy(second_type, table_instances[result[0]].type[second_index]);
            // if (!has_type_converse)
            // {
            //     if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            //     {
            //         fprintf(fout, "iload %d\n", second_index);
            //     }
            //     else if(!strcmp(second_type, "float32"))
            //     {
            //         fprintf(fout, "fload %d\n", second_index);
            //     }
            //     else if(!strcmp(second_type, "string"))
            //     {
            //         fprintf(fout, "aload %d\n", second_index);
            //     }
            // }
        }
        // printf("expr:%s, buf:%s, literal_count=%d\n", expr_type, type_buf, literal_count);
        switch(b_op){
            case 4:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: ADD (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "iadd\n") : fprintf(fout, "fadd\n");
                printf("ADD\n"); 
                break;
            case 5:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: SUB (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "isub\n") : fprintf(fout, "fsub\n");
                printf("SUB\n"); 
                break;
        }
        literal_count = 0;
        has_type_converse = false;
    }
    | Expression mul_op Expression
    { 
        is_bi_op = true;
        lookup_symbol($<s_val>1);
        int first_index = result[1];
        char first_type[10], second_type[10];
        if(first_index==-1)
        {
            strcpy(first_type, expr_type);
            // if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            // {
            //     fprintf(fout, "ldc %d\n", atoi(yylval.msg));
            // }
            // else if(!strcmp(second_type, "float32"))
            // {
            //     fprintf(fout, "ldc %f\n", atof(yylval.msg));
            // }
            // else if(!strcmp(second_type, "string"))
            // {
            //     fprintf(fout, "ldc %s\n", yylval.s_val);
            // }
        }
        else
        {
            // strcpy(first_type, table_instances[result[0]].type[first_index]);
            // if (!has_type_converse)
            // {
            //     if(!strcmp(first_type, "int32") || !strcmp(first_type, "bool"))
            //     {
            //         fprintf(fout, "iload %d\n", first_index);
            //     }
            //     else if(!strcmp(first_type, "float32"))
            //     {
            //         fprintf(fout, "fload %d\n", first_index);
            //     }
            //     else if(!strcmp(first_type, "string"))
            //     {
            //         fprintf(fout, "aload %d\n", first_index);
            //     }
            // }
        }
        lookup_symbol($<s_val>3);
        int second_index = result[1];
        if(second_index==-1)
        {
            if (literal_count>1)
                strcpy(second_type, type_buf);
            else 
                strcpy(second_type, expr_type);

            // if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            // {
            //     fprintf(fout, "ldc %d\n", atoi(yylval.msg));
            // }
            // else if(!strcmp(second_type, "float32"))
            // {
            //     fprintf(fout, "ldc %f\n", atof(yylval.msg));
            // }
            // else if(!strcmp(second_type, "string"))
            // {
            //     fprintf(fout, "ldc %s\n", yylval.s_val);
            // }
        }
        else
        {
            strcpy(second_type, table_instances[result[0]].type[second_index]);
            // if (!has_type_converse)
            // {
            //     if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            //     {
            //         fprintf(fout, "iload %d\n", second_index);
            //     }
            //     else if(!strcmp(second_type, "float32"))
            //     {
            //         fprintf(fout, "fload %d\n", second_index);
            //     }
            //     else if(!strcmp(second_type, "string"))
            //     {
            //         fprintf(fout, "aload %d\n", second_index);
            //     }
            // }
        }

        switch(b_op){
            case 1:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: MUL (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "imul\n") : fprintf(fout, "fmul\n");
                printf("MUL\n"); 
                break;
            case 2:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: QUO (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "idiv\n") : fprintf(fout, "fdiv\n");
                printf("QUO\n"); 
                break;
            case 3:
                if(!strcmp(first_type, "float32") || !strcmp(second_type, "float32"))
                    printf("error:%d: invalid operation: (operator REM not defined on float32)\n", yylineno);
                fprintf(fout, "irem\n");
                printf("REM\n"); 
                break;
        }
        literal_count = 0;
        has_type_converse = false;
    }
    | UnaryExpr
;
/* 
    : Expression1 LOR Expression
    { 
        lookup_symbol($<s_val>1);
        int first_index = result[1];
        char first_type[10], second_type[10];
        if(first_index==-1)
            strcpy(first_type, expr_type);
        else
            strcpy(first_type, table_instances[result[0]].type[first_index]);
        lookup_symbol($<s_val>3);
        int second_index = result[1];
        if(second_index==-1)
        {
            if (literal_count>1)
                strcpy(second_type, type_buf);
            else 
                strcpy(second_type, expr_type);
        }
        else
            strcpy(second_type, table_instances[result[0]].type[second_index]);

        if(strcmp(first_type, "bool"))
        {
            printf("error:%d: invalid operation: (operator LOR not defined on %s)\n", yylineno, first_type);
            printf("LOR\n");   
        }
        else if(strcmp(second_type, "bool"))
        {
            printf("error:%d: invalid operation: (operator LOR not defined on %s)\n", yylineno, second_type);
            printf("LOR\n");
        }
        literal_count = 0;
    }
    | Expression1
;

Expression1
    : Expression2 LAND Expression1
    { 
        lookup_symbol($<s_val>1);
        int first_index = result[1];
        char first_type[10], second_type[10];
        if(first_index==-1)
            strcpy(first_type, expr_type);
        else
            strcpy(first_type, table_instances[result[0]].type[first_index]);
        lookup_symbol($<s_val>3);
        int second_index = result[1];
        if(second_index==-1)
        {
            if (literal_count>1)
                strcpy(second_type, type_buf);
            else 
                strcpy(second_type, expr_type);
        }
        else
            strcpy(second_type, table_instances[result[0]].type[second_index]);

        if(strcmp(first_type, "bool"))
        {
            printf("error:%d: invalid operation: (operator LAND not defined on %s)\n", yylineno, first_type);
            printf("LAND\n");   
        }
        else if(strcmp(second_type, "bool"))
        {
            printf("error:%d: invalid operation: (operator LAND not defined on %s)\n", yylineno, second_type);
            printf("LAND\n");   
        }
            literal_count = 0;
    }
    | Expression2
;

Expression2
    : Expression3 cmp_op Expression2
    { 
        lookup_symbol($<s_val>1);
        int first_index = result[1];
        char first_type[10], second_type[10];
        if(first_index==-1)
            strcpy(first_type, expr_type);
        else
            strcpy(first_type, table_instances[result[0]].type[first_index]);
        lookup_symbol($<s_val>3);
        int second_index = result[1];
        if(second_index==-1)
            strcpy(second_type, expr_type);
        else
            strcpy(second_type, table_instances[result[0]].type[second_index]);

        switch(b_op){
            case 6:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: EQL (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                printf("EQL\n"); 
                break;
            case 7:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: NEQ (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                printf("NEQ\n"); 
                break;
            case 8:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: LSS (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                printf("LSS\n"); 
               break;
            case 9:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: LEQ (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                printf("LEQ\n"); 
                break;
            case 10:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: GTR (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                printf("GTR\n"); 
                break;
            case 11:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: GEQ (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                printf("GEQ\n"); 
                break;
        }
        strcpy(expr_type, "bool");
        literal_count = 0;
    }
    
    | Expression3
;

Expression3
    : Expression4 add_op Expression3
    { 
        lookup_symbol($<s_val>1);
        int first_index = result[1];
        char first_type[10], second_type[10];
        if(first_index==-1)
            strcpy(first_type, expr_type);
        else
            strcpy(first_type, table_instances[result[0]].type[first_index]);
        lookup_symbol($<s_val>3);
        int second_index = result[1];
        if(second_index==-1)
        {
            if (literal_count>1)
                strcpy(second_type, type_buf);
            else 
                strcpy(second_type, expr_type);
        }
        else
            strcpy(second_type, table_instances[result[0]].type[second_index]);

        switch(b_op){
            case 4:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: ADD (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                printf("ADD\n"); 
                break;
            case 5:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: SUB (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                printf("SUB\n"); 
                break;
        }
        literal_count = 0;
    }
    | Expression4
;

Expression4
    : UnaryExpr mul_op Expression4
    { 
        lookup_symbol($<s_val>1);
        int first_index = result[1];
        char first_type[10], second_type[10];
        if(first_index==-1)
            strcpy(first_type, expr_type);
        else
            strcpy(first_type, table_instances[result[0]].type[first_index]);
        lookup_symbol($<s_val>3);
        int second_index = result[1];
        if(second_index==-1)
        {
            if (literal_count>1)
                strcpy(second_type, type_buf);
            else 
                strcpy(second_type, expr_type);
        }
        else
            strcpy(second_type, table_instances[result[0]].type[second_index]);

        switch(b_op){
            case 1:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: MUL (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                printf("MUL\n"); 
                break;
            case 2:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: QUO (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                printf("QUO\n"); 
                break;
            case 3:
                if(!strcmp(first_type, "float32") || !strcmp(second_type, "float32"))
                    printf("error:%d: invalid operation: (operator REM not defined on float32)\n", yylineno);
                printf("REM\n"); 
                break;
        }
        literal_count = 0;
    }
    | UnaryExpr
; */

UnaryExpr
    : PrimaryExpr 
    | unary_op UnaryExpr %prec '*'
    { 
        switch(u_op){
            // case 1:
            //     printf("POS\n"); 
            //     break;
            case 2:
                printf("NEG\n"); 
                (!strcmp(expr_type, "int32")) ? fprintf(fout, "ineg\n") : fprintf(fout, "fneg\n");
                break;
            case 3:
                printf("NOT\n"); 
                fprintf(fout, "ixor\n");
                break;
        }
    }
;

binary_op
    : LOR {b_op=13;} | LAND {b_op=12;} | cmp_op | add_op | mul_op
;

cmp_op 
    : EQL  {b_op=6;}
    | NEQ  {b_op=7;}
    | '<'  {b_op=8;}
    | LEQ  {b_op=9;}
    | '>'  {b_op=10;}
    | GEQ  {b_op=11;}
;

add_op 
    : '+' {b_op=4;}
    | '-' {b_op=5;}
;

mul_op 
    : '*' {b_op=1;}
    | '/' {b_op=2;}
    | '%' {b_op=3;}
;

unary_op 
    : '+' {u_op=1;}
    | '-' {u_op=2;}
    | '!' {u_op=3;}
;

PrimaryExpr
    : Operand | ConversionExpr
;

Operand
    : Literal 
    | IDENT 
    { 
        lookup_symbol($<s_val>1);
        strcpy(expr_type, table_instances[result[0]].type[result[1]]); 
        printf("IDENT (name=%s, address=%d)\n", $<s_val>1, table_instances[result[0]].addr[result[1]]);
        lookup_symbol($<s_val>1);
        int index = result[1];
        if(!strcmp(expr_type, "int32"))
            fprintf(fout, "iload %d\n", index);
        else if(!strcmp(expr_type, "float32"))
            fprintf(fout, "fload %d\n", index);
        else if(!strcmp(expr_type, "string"))
            fprintf(fout, "aload %d\n", index);
        else if(!strcmp(expr_type, "bool"))
            fprintf(fout, "bload %d\n", index);
    }
    | '(' Expression ')'
;

ConversionExpr
    : Type '(' Expression ')' 
    {
        // lookup_symbol($<s_val>3);
        // int first_index = result[1];
        // // printf("%d\n", first_index);
        // if (first_index<0)
        // {
        //     strcpy(expr_type[0], expr_type[which_expr-1]);
        //     printf("hihi, it's %s\n", expr_type[0]);     
        // }
        // else
        //     strcpy(expr_type[0], table_instances[result[0]].type[first_index]);
        

        // add load here~~~~~~~~~~~~~~~
        has_type_converse = true;
        lookup_symbol($<s_val>3);
        int index = result[1];
        if (!strcmp(expr_type, "int32"))
        {
            // if (index!=-1)
            //     fprintf(fout, "iload %d\n", index);
            printf("i"); 
            fprintf(fout, "i");
        }
        else if (!strcmp(expr_type, "float32"))
        {
            // if (index!=-1)
            //     fprintf(fout, "fload %d\n", index);
            printf("f");
            fprintf(fout, "f");
        }
        else if (!strcmp(expr_type, "string"))
        {
            // if (index!=-1)
            //     fprintf(fout, "aload %d\n", index);
            printf("s");
            fprintf(fout, "s");
        }
        else if (!strcmp(expr_type, "bool"))
        {
            // if (index!=-1)
            //     fprintf(fout, "bload %d\n", index);
            printf("b");    
            fprintf(fout, "b");
        }
        
        printf("2");
        fprintf(fout, "2");

        if (!strcmp(type_buf, "int32"))
        {
            printf("i\n");
            fprintf(fout, "i\n");
        }
        else if (!strcmp(type_buf, "float32"))
        {
            printf("f\n");
            fprintf(fout, "f\n");
        }
        else if (!strcmp(type_buf, "string"))
        {
            printf("s\n");
            fprintf(fout, "s\n");
        }
        else if (!strcmp(type_buf, "bool"))
        {
            printf("b\n"); 
            fprintf(fout, "b\n");
        }
    }
;

/* InputList
    : InputList ',' Expression
    | Expression
; */

Block
    : BlockStart StatementList '}' { dump_symbol(scope_level + 1); }
;

BlockStart
    : '{' NEWLINES { create_symbol(scope_level); }
;

StatementList
    : StatementList Statement
    | Statement
;

Statement
    : DeclarationStmt NEWLINES
    | SimpleStmt NEWLINES 
    | Block 
    | IfStmt 
    | ForStmt 
    | SwitchStmt 
    | CaseStmt 
    | PrintStmt NEWLINES 
    | ReturnStmt NEWLINES
    | NEWLINES 
;

DeclarationStmt 
    : VAR IDENT Type 
    {
        lookup_symbol($<s_val>2);
        int index = result[1];
        // havn't been declare
        if (index==-1)
        {
            // insert symbol
            --yylineno;
            insert_symbol($<id>2, addr++); strcpy(func_sig_buf, "-"); update_table($<id>2); 
            ++yylineno;
            lookup_symbol($<s_val>2);
            int cur_index = result[1];
            if (!strcmp(type_buf, "int32"))
            {
                fprintf(fout, "ldc 0\n");
                fprintf(fout, "istore %d\n", cur_index);
            }
            else if (!strcmp(type_buf, "float32"))
            {
                fprintf(fout, "ldc 0.000000\n");
                fprintf(fout, "fstore %d\n", cur_index);
            }
            else if (!strcmp(type_buf, "string"))
            {
                fprintf(fout, "ldc \"\"\n");
                fprintf(fout, "astore %d\n", cur_index);
            }
            else if (!strcmp(type_buf, "bool"))
            {
                fprintf(fout, "iconst_1\n");
                fprintf(fout, "bstore %d\n", cur_index);  
            }
        }
    }
    | VAR IDENT Type '=' Expression 
    {
        lookup_symbol($<s_val>2);
        int index = result[1];
        // havn't been declare
        if (index==-1)
        {
            --yylineno;
            insert_symbol($<id>2, addr++);
            strcpy(id_buf, $<id>2);
            strcpy(func_sig_buf, "-"); 
            update_table($<id>2);
            ++yylineno;
            lookup_symbol($<s_val>2);
            int cur_index = result[1];
            if (!strcmp(type_buf, "int32"))
                fprintf(fout, "istore %d\n", cur_index);
            else if (!strcmp(type_buf, "float32"))
                fprintf(fout, "fstore %d\n", cur_index);
            else if (!strcmp(type_buf, "string"))
                fprintf(fout, "astore %d\n", cur_index);
            else if (!strcmp(type_buf, "bool"))
                fprintf(fout, "bstore %d\n", cur_index);   
        }

    }
;

Type
    : INT    { strcpy(type_buf, "int32"); strcpy(param_type[param_count], "I"); param_count++; }
    | FLOAT  { strcpy(type_buf, "float32"); strcpy(param_type[param_count], "F"); param_count++; }
    | STRING { strcpy(type_buf, "string"); strcpy(param_type[param_count], "S"); param_count++; }
    | BOOL   { strcpy(type_buf, "bool"); strcpy(param_type[param_count], "B"); param_count++; }
;

Literal 
    : INT_LIT            { printf("INT_LIT %d\n", atoi(yylval.msg)); if (literal_count==1) strcpy(type_buf, "int32"); else strcpy(expr_type, "int32"); literal_count++; fprintf(fout, "ldc %d\n", atoi(yylval.msg)); }
    | FLOAT_LIT          { printf("FLOAT_LIT %f\n", atof(yylval.msg)); if (literal_count==1) strcpy(type_buf, "float32"); else strcpy(expr_type, "float32"); literal_count++; fprintf(fout, "ldc %f\n", atof(yylval.msg)); } 
    | '"' STRING_LIT '"' { printf("STRING_LIT %s\n", yylval.s_val); if (literal_count==1) strcpy(type_buf, "string"); else strcpy(expr_type, "string"); literal_count++; fprintf(fout, "ldc %s\n", yylval.s_val); }
    | TRUE               { printf("TRUE 1\n"); if (literal_count==1) strcpy(type_buf, "bool"); else strcpy(expr_type, "bool"); literal_count++; fprintf(fout, "iconst_1\n"); }
    | FASLE              { printf("FALSE 0\n"); if (literal_count==1) strcpy(type_buf, "bool"); else strcpy(expr_type, "bool"); literal_count++; fprintf(fout, "iconst_0\n"); }
;

SimpleStmt
    : AssignmentStmt | Expression | IncDecStmt
;

AssignmentStmt
    : Expression assign_op Expression 
    {
        lookup_symbol($<s_val>1);
        int first_index = result[1];
        char first_type[10], second_type[10];
        if(first_index==-1)
        {
            strcpy(first_type, expr_type);
            // if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            // {
            //     fprintf(fout, "ldc %d\n", atoi(yylval.msg));
            // }
            // else if(!strcmp(second_type, "float32"))
            // {
            //     fprintf(fout, "ldc %f\n", atof(yylval.msg));
            // }
            // else if(!strcmp(second_type, "string"))
            // {
            //     fprintf(fout, "ldc %s\n", yylval.s_val);
            // }
        }
        else
        {
            strcpy(first_type, table_instances[result[0]].type[first_index]);
            if(!strcmp(first_type, "int32") || !strcmp(first_type, "bool"))
            {
                fprintf(fout, "istore %d\n", first_index);
            }
            else if(!strcmp(first_type, "float32"))
            {
                fprintf(fout, "fstore %d\n", first_index);
            }
            else if(!strcmp(first_type, "string"))
            {
                fprintf(fout, "astore %d\n", first_index);
            }
        }
        lookup_symbol($<s_val>3);
        int second_index = result[1];
        if(second_index==-1)
        {
            if (literal_count>1)
                strcpy(second_type, type_buf);
            else 
                strcpy(second_type, expr_type);

            // if(!strcmp(second_type, "int32") || !strcmp(second_type, "bool"))
            // {
            //     fprintf(fout, "ldc %d\n", atoi(yylval.msg));
            // }
            // else if(!strcmp(second_type, "float32"))
            // {
            //     fprintf(fout, "ldc %f\n", atof(yylval.msg));
            // }
            // else if(!strcmp(second_type, "string"))
            // {
            //     fprintf(fout, "ldc %s\n", $<s_val>3);
            // }
        }
        else
        {
            strcpy(second_type, table_instances[result[0]].type[second_index]);
            // if (!is_bi_op)
            // {
            //     if(!strcmp(first_type, "int32"))
            //     {
            //         fprintf(fout, "iload %d\n", second_index);
            //     }
            //     else if(!strcmp(first_type, "float32"))
            //     {
            //         fprintf(fout, "fload %d\n", second_index);
            //     }
            //     else if(!strcmp(first_type, "string"))
            //     {
            //         fprintf(fout, "aload %d\n", second_index);
            //     }
            //     else if(!strcmp(first_type, "bool"))
            //     {
            //         fprintf(fout, "bload %d\n", second_index);
            //     }
            // }
        }
        switch(assign_op){
            case 0:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: ASSIGN (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                // fprintf(fout, "istore %");
                printf("ASSIGN\n"); 
                break;
            case 1:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: ADD (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "iadd\n") : fprintf(fout, "fadd\n");
                printf("ADD\n"); 
                break;
            case 2:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: SUB (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "isub\n") : fprintf(fout, "fsub\n");
                printf("SUB\n"); 
                break;
            case 3:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: MUL (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "imul\n") : fprintf(fout, "fmul\n");
                printf("MUL\n"); 
                break;
            case 4:
                if(strcmp(first_type, second_type))
                    printf("error:%d: invalid operation: QUO (mismatched types %s and %s)\n", yylineno, first_type, second_type);
                (!strcmp(first_type, "int32")) ? fprintf(fout, "idiv\n") : fprintf(fout, "fdiv\n");
                printf("QUO\n"); 
                break;
            case 5:
                if(!strcmp(first_type, "float32") || !strcmp(second_type, "float32"))
                    printf("error:%d: invalid operation: (operator REM not defined on float32)\n", yylineno);
                printf("REM\n"); 
                fprintf(fout, "irem\n");
                break;
        }

        is_bi_op = false;
        literal_count = 0;
    }
;

assign_op 
    : '=' {assign_op=0;}       
    | ADD_ASSIGN {assign_op=1;}
    | SUB_ASSIGN {assign_op=2;}
    | MUL_ASSIGN {assign_op=3;}
    | QUO_ASSIGN {assign_op=4;}
    | REM_ASSIGN {assign_op=5;}
;

IncDecStmt
    : Expression INC 
    { 
        printf("INC\n"); 
        lookup_symbol($<s_val>1);
        int index = result[1];
        if(!strcmp(expr_type, "int32"))
        {
            // fprintf(fout, "iload %d\n", index);
            fprintf(fout, "ldc 1\n");
            fprintf(fout, "iadd\n");
            fprintf(fout, "istore %d\n", index);
        }
        else if(!strcmp(expr_type, "float32"))
        {
            // fprintf(fout, "fload %d\n", index);
            fprintf(fout, "ldc 1.0\n");
            fprintf(fout, "fadd\n");
            fprintf(fout, "fstore %d\n", index);
        }
    }
    | Expression DEC 
    { 
        printf("DEC\n"); 
        lookup_symbol($<s_val>1);
        int index = result[1];
        if(!strcmp(expr_type, "int32"))
        {
            // fprintf(fout, "iload %d\n", index);
            fprintf(fout, "ldc 1\n");
            fprintf(fout, "isub\n");
            fprintf(fout, "istore %d\n", index);
        }
        else if(!strcmp(expr_type, "float32"))
        {
            // fprintf(fout, "fload %d\n", index);
            fprintf(fout, "ldc 1.0\n");
            fprintf(fout, "fsub\n");
            fprintf(fout, "fstore %d\n", index);
        }
    }
;

IfStmt 
    : IF Condition Block
    | IF Condition Block ELSE IfStmt
    | IF Condition Block ELSE Block
;

Condition : Expression
{
    // int id = result[1];
    // if (id!=-1)
    //     if(!(b_op>=6&&b_op<=11))
    //         strcpy(type_buf, table_instances[result[0]].type[id]);

    if (strcmp(expr_type, "bool"))
    {
        printf("error:%d: non-bool (type %s) used as for condition\n", yylineno+1, expr_type);
        break;
    }
        
}

ForStmt : FOR Condition Block | FOR ForClause Block;
 
ForClause : InitStmt ';' Condition ';' PostStmt;

InitStmt : SimpleStmt;

PostStmt : SimpleStmt;

SwitchStmt : SWITCH Expression Block
            {
                fprintf(fout, "goto L_switch_begin_%d:\n", switch_cnt++);
                fprintf(fout, "L_switch_begin_%d\n", switch_cnt-1);
                fprintf(fout, "lookupswitch\n");
                case_cnt = 0;
            }
;

CaseStmt : CaseNum ':' Block 
        | DEFAULT ':' Block 
        {
            fprintf(fout, "default: L_case_%d\n", case_cnt);
            fprintf(fout, "L_switch_end_%d:\n", switch_cnt-1);
            fprintf(fout, "return\n");
        }
;

CaseNum  : CASE INT_LIT { 
                            printf("case %s\n", yylval.msg);   
                            fprintf(fout, "%d: L_case_%d\n",case_cnt, case_cnt);
                            fprintf(fout, "L_case_%d:\n", case_cnt);
                            fprintf(fout, "goto L_switch_end_%d\n", switch_cnt-1);
                            case_cnt++;
                        };

PrintStmt  
    : PRINT '(' Expression ')'   {  char tmp_type[10];
                                    lookup_symbol($<s_val>3);
                                    if (literal_count>1)    
                                    {
                                        printf("PRINT %s\n", type_buf);
                                        strcpy(tmp_type, type_buf);
                                    }
                                    else
                                    {
                                       printf("PRINT %s\n", expr_type);
                                       strcpy(tmp_type, expr_type);
                                    }
                                    literal_count = 0; 
                                    int which_type = 0;
                                    int index = result[1];
                                    if(!strcmp(tmp_type, "int32"))
                                    {
                                        // fprintf(fout, "ldc %d\n", atoi(yylval.msg));
                                        // if(!is_bi_op)
                                        //     fprintf(fout, "iload %d\n", index);
                                        which_type = 1;
                                    }
                                    else if(!strcmp(tmp_type, "float32"))
                                    {
                                        // fprintf(fout, "ldc %f\n", atof(yylval.msg));
                                        // if(!is_bi_op)
                                        //     fprintf(fout, "fload %d\n", index);
                                        which_type = 2;
                                    }
                                    else if(!strcmp(tmp_type, "string"))
                                    {
                                        // fprintf(fout, "ldc %s\n", $<s_val>3);
                                        // if(!is_bi_op)
                                        //     fprintf(fout, "aload %d\n", index);
                                        which_type = 3; 
                                    }
                                    else if(!strcmp(tmp_type, "bool"))
                                    {
                                        // fprintf(fout, "ldc %d\n", atoi(yylval.msg));
                                        // if(!is_bi_op)
                                        //     fprintf(fout, "bload %d\n", index);
                                        which_type = 4;
                                    }
                                    is_bi_op = false;
                                    fprintf(fout, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                    fprintf(fout, "swap\n");
                                    
                                    switch(which_type)
                                    {
                                        case 1:
                                            fprintf(fout, "invokevirtual java/io/PrintStream/print(I)V\n");
                                            break;
                                        case 2:
                                            fprintf(fout, "invokevirtual java/io/PrintStream/print(F)V\n");
                                            break;
                                        case 3:                                            
                                            fprintf(fout, "invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
                                            break;
                                        case 4:
                                            fprintf(fout, "iconst_1\n");
                                            fprintf(fout, "ifne L_ cmp_%d\n", label_cnt++);
                                            fprintf(fout, "ldc \"false\"\n");
                                            fprintf(fout, "goto L_cmp_%d\n", label_cnt++);
                                            fprintf(fout, "L_cmp_%d:\n", label_cnt-2);
                                            fprintf(fout, "ldc \"true\"\n");
                                            fprintf(fout, "L_cmp_%d:\n", label_cnt-1);
                                            fprintf(fout, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                            fprintf(fout, "swap\n");
                                            fprintf(fout, "invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
                                            break;
                                    }
                                    

                                
                                }
    | PRINTLN '(' Expression ')' {  char tmp_type[10];
                                    lookup_symbol($<s_val>3);
                                    if (literal_count>1)    
                                    {
                                        printf("PRINTLN %s\n", type_buf);
                                        strcpy(tmp_type, type_buf);
                                    }
                                    else
                                    {
                                       printf("PRINTLN %s\n", expr_type);
                                       strcpy(tmp_type, expr_type);
                                    }
                                    literal_count = 0; 
                                    int which_type = 0;
                                    int index = result[1];
                                    if(!strcmp(tmp_type, "int32"))
                                    {
                                        // fprintf(fout, "ldc %d\n", atoi(yylval.msg));
                                        // if(!is_bi_op)
                                        //     fprintf(fout, "iload %d\n", index);
                                        which_type = 1;
                                    }
                                    else if(!strcmp(tmp_type, "float32"))
                                    {
                                        // fprintf(fout, "ldc %f\n", atof(yylval.msg));
                                        // if(!is_bi_op)
                                        //     fprintf(fout, "fload %d\n", index);
                                        which_type = 2;
                                    }
                                    else if(!strcmp(tmp_type, "string"))
                                    {
                                        // fprintf(fout, "ldc %s\n", $<s_val>3);
                                        // if(!is_bi_op)
                                        //     fprintf(fout, "aload %d\n", index);
                                        which_type = 3; 
                                    }
                                    else if(!strcmp(tmp_type, "bool"))
                                    {
                                        // fprintf(fout, "ldc %d\n", atoi(yylval.msg));
                                        // if(!is_bi_op)
                                        //     fprintf(fout, "bload %d\n", index);
                                        which_type = 4;
                                    }
                                    is_bi_op = false;
                                    fprintf(fout, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                    fprintf(fout, "swap\n");
                                    
                                    switch(which_type)
                                    {
                                        case 1:
                                            fprintf(fout, "invokevirtual java/io/PrintStream/println(I)V\n");
                                            break;
                                        case 2:
                                            fprintf(fout, "invokevirtual java/io/PrintStream/println(F)V\n");
                                            break;
                                        case 3:                                            
                                            fprintf(fout, "invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
                                            break;
                                        case 4:
                                            fprintf(fout, "iconst_1\n");
                                            fprintf(fout, "ifne L_ cmp_%d\n", label_cnt++);
                                            fprintf(fout, "ldc \"false\"\n");
                                            fprintf(fout, "goto L_cmp_%d\n", label_cnt++);
                                            fprintf(fout, "L_cmp_%d:\n", label_cnt-2);
                                            fprintf(fout, "ldc \"true\"\n");
                                            fprintf(fout, "L_cmp_%d:\n", label_cnt-1);
                                            fprintf(fout, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                            fprintf(fout, "swap\n");
                                            fprintf(fout, "invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
                                            break;
                                    }
                                }
;

ReturnStmt 
    : RETURN Expression 
    { 
        no_return = false;
        printf("return\n");
        if (!strcmp(expr_type, "int32"))      
            fprintf(fout, "ireturn\n");
        else if (!strcmp(expr_type, "float32"))
            fprintf(fout, "freturn\n");
        else if (!strcmp(expr_type, "string"))
            fprintf(fout, "areturn\n");
        else if (!strcmp(expr_type, "bool"))
            fprintf(fout, "breturn\n"); 
    }
    | RETURN { no_return=false; printf("return\n"); fprintf(fout ,"return\n"); }
;

%%

/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    yylineno = 0;

    scope_level = 0;

    for(int i=0; i<10; i++){
        scope_stack_top[i] = 0;
    }

    memset(expr_type,0,strlen(expr_type));
    memset(type_buf,0,strlen(type_buf));

    addr = 0;
    no_return = true;
    is_bi_op = false;
    has_type_converse = false;
    fout = fopen("hw3.j", "w");
    yyparse();

    printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    fclose(fout);
    /* CODEGEN("\n"); */
    /* CODEGEN("%d - %s\n", 100, "Hello world"); */
    return 0;
}

static void create_symbol(int level) {
    printf("> Create symbol table (scope level %d)\n", level);
}

static void insert_symbol(char *id, int addr_in) {
    printf("> Insert `%s` (addr: %d) to scope level %d\n", id, addr_in, scope_level);
}

static void lookup_symbol(char *id) {
    for(int a=scope_level; a>=0; a--){
        for(int i=0; i<10; i++){
            if(!strcmp(table_instances[a].name[i], id)){
                result[0] = a;
                result[1] = i;
                return;
            }
        }
    }
    
    result[1] = -1;
}

static void dump_symbol(int which_table) {
    printf("\n> Dump symbol table (scope level: %d)\n", which_table);
    printf("%-10s%-10s%-10s%-10s%-10s%-10s\n",
            "Index", "Name", "Type", "Addr", "Lineno", "Func_sig");
    for(int i=0; i<scope_stack_top[which_table]; i++){
        printf("%-10d%-10s%-10s%-10d%-10d%-10s\n",
            table_instances[which_table].index[i], 
            table_instances[which_table].name[i], 
            table_instances[which_table].type[i], 
            table_instances[which_table].addr[i], 
            table_instances[which_table].lineno[i], 
            table_instances[which_table].funcsig[i]);
    }
    printf("\n");

    for(int i=scope_stack_top[which_table] - 1; i>=0; i--){
        table_instances[which_table].index[i] = -1;
        strcpy(table_instances[which_table].name[i], "");
        strcpy(table_instances[which_table].type[i], "");
        table_instances[which_table].addr[i] = -2;
        table_instances[which_table].lineno[i] = 0;
        strcpy(table_instances[which_table].funcsig[i], "");
    }
    scope_stack_top[which_table] = 0;
}

static void update_table(char *id) {
    int top = scope_stack_top[scope_level];
    table_instances[scope_level].index[top] = top;
    strcpy(table_instances[scope_level].name[top], id);
    strcpy(table_instances[scope_level].type[top], type_buf);
    table_instances[scope_level].addr[top] = addr - 1;
    table_instances[scope_level].lineno[top] = yylineno + 1;
    strcpy(table_instances[scope_level].funcsig[top], func_sig_buf);
    scope_stack_top[scope_level]++;
}



