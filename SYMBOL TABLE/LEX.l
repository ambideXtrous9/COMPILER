%option noyywrap
%{
#include "y.tab.h"
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

char flag[10];
char reg[200][100];
int regindex=0;
%}
digit [0-9]
letter [A-Za-z]
%%

;     {return SEMI_COL;}
,     {return COMMA_TOK;}
\{    {return LEFT_BRACE;}
\}    {return RIGHT_BRACE;}
\(    {return LEFT_PAR;}
\)    {return RIGHT_PAR;}
int   {return INT_TOK;}
main  {return MAIN_TOK;}

== return  RELATION_TOK;
= return ASSIGN;
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

float   {return FLOAT_TOK;}
char   {return CHAR_TOK;}
if      {return IF_TOK;}
else    {return ELSE_TOK;}
for     {return FOR_TOK;}
while   {return WHILE_TOK;}
return  {return RES_TOK;}
{digit}* {return NUMBER_TOK;}
{letter}({letter}|{digit}|"_")* {strcpy(flag,yytext);return IDENTIFIER;}
{digit}*"."{digit}* {return DEC;}
%%
