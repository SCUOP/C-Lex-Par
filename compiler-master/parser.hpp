/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    K_ELSE = 258,                  /* K_ELSE  */
    K_IF = 259,                    /* K_IF  */
    K_RETURN = 260,                /* K_RETURN  */
    K_WHILE = 261,                 /* K_WHILE  */
    K_PRINTF = 262,                /* K_PRINTF  */
    K_READ = 263,                  /* K_READ  */
    K_INT = 264,                   /* K_INT  */
    K_VOID = 265,                  /* K_VOID  */
    ID = 266,                      /* ID  */
    NUM = 267,                     /* NUM  */
    O_ASSIGN = 268,                /* O_ASSIGN  */
    O_COMMA = 269,                 /* O_COMMA  */
    O_SEMI = 270,                  /* O_SEMI  */
    O_LSBRACKER = 271,             /* O_LSBRACKER  */
    O_RSBRACKER = 272,             /* O_RSBRACKER  */
    O_LMBRACKER = 273,             /* O_LMBRACKER  */
    O_RMBRACKER = 274,             /* O_RMBRACKER  */
    O_LLBRACKER = 275,             /* O_LLBRACKER  */
    O_RLBRACKER = 276,             /* O_RLBRACKER  */
    O_ADD = 277,                   /* O_ADD  */
    O_SUB = 278,                   /* O_SUB  */
    O_MUL = 279,                   /* O_MUL  */
    O_DIV = 280,                   /* O_DIV  */
    O_LESS = 281,                  /* O_LESS  */
    O_L_EQUAL = 282,               /* O_L_EQUAL  */
    O_GREATER = 283,               /* O_GREATER  */
    O_G_EQUAL = 284,               /* O_G_EQUAL  */
    O_EQUAL = 285,                 /* O_EQUAL  */
    O_U_EQUAL = 286,               /* O_U_EQUAL  */
    COMMENT = 287,                 /* COMMENT  */
    SPACES = 288,                  /* SPACES  */
    U_LEGAL = 289,                 /* U_LEGAL  */
    U_neg = 290                    /* U_neg  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define K_ELSE 258
#define K_IF 259
#define K_RETURN 260
#define K_WHILE 261
#define K_PRINTF 262
#define K_READ 263
#define K_INT 264
#define K_VOID 265
#define ID 266
#define NUM 267
#define O_ASSIGN 268
#define O_COMMA 269
#define O_SEMI 270
#define O_LSBRACKER 271
#define O_RSBRACKER 272
#define O_LMBRACKER 273
#define O_RMBRACKER 274
#define O_LLBRACKER 275
#define O_RLBRACKER 276
#define O_ADD 277
#define O_SUB 278
#define O_MUL 279
#define O_DIV 280
#define O_LESS 281
#define O_L_EQUAL 282
#define O_GREATER 283
#define O_G_EQUAL 284
#define O_EQUAL 285
#define O_U_EQUAL 286
#define COMMENT 287
#define SPACES 288
#define U_LEGAL 289
#define U_neg 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 70 "parser.y"

    int type;
    char * code;
    int addr;
    Node * node;

#line 144 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
