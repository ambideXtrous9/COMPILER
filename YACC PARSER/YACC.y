%{
#include"lex.yy.c"
void yyerror(char *);
int scope=0;
%}


%token LEFT_PAR
%token RIGHT_PAR
%token LEFT_BRACE
%token RIGHT_BRACE
%token GREATER
%token GREATER_EQ
%token LESS
%token LESS_EQ
%token SEMI_COL
%token PLUS
%token MINUS
%token MUL
%token DIV
%token BIT_OR
%token BIT_AND
%token BIT_XOR
%token OR
%token AND
%token INT_TOK
%token FLOAT_TOK
%token CHAR_TOK
%token RES_TOK
%token IDENTIFIER
%token NUMBER_TOK
%token DEC
%token DCR
%token INCR
%token MAIN_TOK
%token SPACE
%token COMMA_TOK
%token IF_TOK
%token ELSE_TOK
%token WHILE_TOK
%token FOR_TOK
%token ASSIGN
%token RELATION_TOK
%start S
%%


S :  datatype MAIN_TOK LEFT_PAR RIGHT_PAR BLOCK        {printf("MAIN FUNCTION\n");}
      | global  S
     ;
global: DECLARATION SEMI_COL                          {printf("GLOBAL VARIABLE\n");}

BLOCK: LEFT_BRACE STATEMENTS  BLOCKS  RIGHT_BRACE     {}
     ;

BLOCKS: BLOCK STATEMENTS BLOCKS                                {}
      |
      ;

STATEMENTS:STATEMENTS  stmt
          |
          ;

stmt      :DECLARATION SEMI_COL       {printf("LOCAL DECLARATION\n");}
          |If                   {printf("CONDITIONAL (IF) STATEMENT\n");}
          |ELSE                 {printf("CONDITIONAL (ELSE) STATEMENT\n");}
          |WHILE                {printf("ITERATIVE (WHILE) STATEMENT\n");}
          |FOR                  {printf("ITERATIVE (FOR) STATEMENT\n");}
          |FUNCTION_CALL        {printf("FUNCTION CALL\n");}
          |ASSINGMENT           {printf("ASSIGNMENT OPERATION\n");}
          |ARITHMETIC           {printf("ARITHMETIC OPERATION\n");}
          ;


DECLARATION:datatype id_token     {}

           ;
ASSINGMENT: DECLARATION ASSIGN NUMBER_TOK SEMI_COL
          | DECLARATION ASSIGN IDENTIFIER SEMI_COL
          | IDENTIFIER ASSIGN IDENTIFIER SEMI_COL
          |IDENTIFIER ASSIGN NUMBER_TOK SEMI_COL
          |IDENTIFIER ASSIGN ARITHMETIC     {printf("ARITHMETIC\n");}
          ;

datatype: INT_TOK
        | FLOAT_TOK
        | CHAR_TOK
        ;

id_token: id_token COMMA_TOK IDENTIFIER         {}
        | IDENTIFIER

        ;

        ELSE : ELSE_TOK If
              | ELSE_TOK BLOCK
              ;


If : IF_TOK LEFT_PAR x RIGHT_PAR BLOCK
      ;


WHILE : WHILE_TOK LEFT_PAR x RIGHT_PAR BLOCK
      ;

FOR : FOR_TOK LEFT_PAR z RIGHT_PAR BLOCK
    ;

z: z1 SEMI_COL z2 SEMI_COL z3
  ;

z1 : IDENTIFIER ASSIGN NUMBER_TOK         
  ;
z2 : IDENTIFIER LESS_EQ NUMBER_TOK
  ;
z3 : IDENTIFIER INCR
    | IDENTIFIER DCR
  ;

x: IDENTIFIER y NUMBER_TOK
    | IDENTIFIER y IDENTIFIER
    |IDENTIFIER
    ;
y: GREATER
  | GREATER_EQ
  | LESS
  | LESS_EQ
  | RELATION_TOK
  ;

FUNCTION_CALL: IDENTIFIER LEFT_PAR actual_parameter RIGHT_PAR SEMI_COL
        ;

actual_parameter: IDENTIFIER
          | IDENTIFIER COMMA_TOK actual_parameter
          ;
ARITHMETIC : IDENTIFIER PLUS ARITHMETIC
          | NUMBER_TOK PLUS ARITHMETIC
          | IDENTIFIER MINUS ARITHMETIC
          | NUMBER_TOK MINUS ARITHMETIC
          | IDENTIFIER MUL ARITHMETIC
          | NUMBER_TOK MUL ARITHMETIC
          | IDENTIFIER DIV ARITHMETIC
          | NUMBER_TOK DIV ARITHMETIC
          | IDENTIFIER PLUS IDENTIFIER SEMI_COL
          | IDENTIFIER PLUS NUMBER_TOK SEMI_COL
          | NUMBER_TOK PLUS IDENTIFIER SEMI_COL
          | NUMBER_TOK PLUS NUMBER_TOK SEMI_COL
          | IDENTIFIER MINUS IDENTIFIER SEMI_COL
          | IDENTIFIER MINUS NUMBER_TOK SEMI_COL
          | NUMBER_TOK MINUS IDENTIFIER SEMI_COL
          | NUMBER_TOK MINUS NUMBER_TOK SEMI_COL
          | IDENTIFIER MUL IDENTIFIER SEMI_COL
          | IDENTIFIER MUL NUMBER_TOK SEMI_COL
          | NUMBER_TOK MUL IDENTIFIER SEMI_COL
          | NUMBER_TOK MUL NUMBER_TOK SEMI_COL
          | IDENTIFIER DIV IDENTIFIER SEMI_COL
          | IDENTIFIER DIV NUMBER_TOK SEMI_COL
          | NUMBER_TOK DIV IDENTIFIER SEMI_COL
          | NUMBER_TOK DIV NUMBER_TOK SEMI_COL
          ;
%%
int main()
{
   if (yyparse()==0) printf("SUCCESSFULLY PARSED...OK\n");
   else printf("\nParsing Error at Line No %d\n", yylineno);

   return(0);

}

void yyerror(char *s)
{
	printf("yyerror: %s\n",s);
}
