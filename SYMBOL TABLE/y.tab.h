/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    LEFT_PAR = 258,
    RIGHT_PAR = 259,
    LEFT_BRACE = 260,
    RIGHT_BRACE = 261,
    GREATER = 262,
    GREATER_EQ = 263,
    LESS = 264,
    LESS_EQ = 265,
    SEMI_COL = 266,
    PLUS = 267,
    MINUS = 268,
    MUL = 269,
    DIV = 270,
    BIT_OR = 271,
    BIT_AND = 272,
    BIT_XOR = 273,
    OR = 274,
    AND = 275,
    INT_TOK = 276,
    FLOAT_TOK = 277,
    CHAR_TOK = 278,
    RES_TOK = 279,
    IDENTIFIER = 280,
    NUMBER_TOK = 281,
    DEC = 282,
    DCR = 283,
    INCR = 284,
    MAIN_TOK = 285,
    SPACE = 286,
    COMMA_TOK = 287,
    IF_TOK = 288,
    ELSE_TOK = 289,
    WHILE_TOK = 290,
    FOR_TOK = 291,
    ASSIGN = 292,
    RELATION_TOK = 293
  };
#endif
/* Tokens.  */
#define LEFT_PAR 258
#define RIGHT_PAR 259
#define LEFT_BRACE 260
#define RIGHT_BRACE 261
#define GREATER 262
#define GREATER_EQ 263
#define LESS 264
#define LESS_EQ 265
#define SEMI_COL 266
#define PLUS 267
#define MINUS 268
#define MUL 269
#define DIV 270
#define BIT_OR 271
#define BIT_AND 272
#define BIT_XOR 273
#define OR 274
#define AND 275
#define INT_TOK 276
#define FLOAT_TOK 277
#define CHAR_TOK 278
#define RES_TOK 279
#define IDENTIFIER 280
#define NUMBER_TOK 281
#define DEC 282
#define DCR 283
#define INCR 284
#define MAIN_TOK 285
#define SPACE 286
#define COMMA_TOK 287
#define IF_TOK 288
#define ELSE_TOK 289
#define WHILE_TOK 290
#define FOR_TOK 291
#define ASSIGN 292
#define RELATION_TOK 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
