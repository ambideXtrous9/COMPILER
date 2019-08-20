%option noyywrap
%{
#include"lex.h"
%}

DIGIT[0-9]
LETTER[A-Za-z]
%%
[' '| '\n' | '\t'] return SPACE;
";" return SEMICOLON_TOK;
">" return GREATER_THAN_TOK;
"<" return LESS_THAN_TOK;
"+" return PLUS_TOK;
"-" return MINUS_TOK;
"*" return MULT_TOK;
"/" return DIVIDE_TOK;
")" return RPAREN_TOK;
"}" return RCURL_TOK;
"(" return LPAREN_TOK;
"{" return LCURL_TOK;
"==" return COMPARE_TOK;
"=" return ASSIGNMENT_TOK;
"||" return LOG_OR_TOK;
"&&" return LOG_AND_TOK;
"int" return ID_TOK;
"void" return ID_TOK;
"main" return ID_TOK;
{DIGIT}* return NUMBER_TOK;
{LETTER}({LETTER}|{DIGIT})* return ID_TOK;
{DIGIT}*"."{DIGIT}* return DEC_TOK;

%%

int main()
{
int val;
  while(yylex()>0)
    {
      val=yylex();
      cout<<"LEXEM =  "<<yytext<<" INDENTIFIER = "<<val<<endl;
    }
              return 0;
}
