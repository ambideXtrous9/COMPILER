%option noyywrap
%{
#include <stdio.h>
#include "y.tab.h"


%}
digit [0-9]
letter [A-Za-z]
%%

\;     {return SEMI_COL;}
\,     {return COMMA_TOK;}
\{    {return LEFT_BRACE;}
\}    {return RIGHT_BRACE;}
\(    {return LEFT_PAR;}
\)    {return RIGHT_PAR;}
\== return  RELATION_TOK;
\= return ASSIGN;
\+ return PLUS;
\++ return INCR;

\<= return LESS_EQ;
\<  return LESS;
\>= return GREATER_EQ;
\>  return GREATER;
\-  return MINUS;
\-- return DCR;
\* return MUL;
\/ return DIV;

int   {return INT_TOK;}
main  {return MAIN_TOK;}
float   {return FLOAT_TOK;}
char   {return CHAR_TOK;}
if      {return IF_TOK;}
else    {return ELSE_TOK;}
for     {return FOR_TOK;}
while   {return WHILE_TOK;}
return  {return RES_TOK;}
{digit}* {return NUMBER_TOK;}
{letter}({letter}|{digit}|"_")* {return IDENTIFIER;}
{digit}*"."{digit}* {return DEC;}
%%
