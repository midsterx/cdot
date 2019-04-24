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
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    HASH = 258,
    INCLUDE = 259,
    DEFINE = 260,
    STDIO = 261,
    STDLIB = 262,
    MATH = 263,
    STRING = 264,
    TIME = 265,
    HEADER_LITERAL = 266,
    IF = 267,
    ELSE = 268,
    WHILE = 269,
    DO = 270,
    BREAK = 271,
    CONTINUE = 272,
    RETURN = 273,
    SHORTHANDADD = 274,
    SHORTHANDSUB = 275,
    SHORTHANDMULT = 276,
    SHORTHANDDIV = 277,
    INCREMENT = 278,
    DECREMENT = 279,
    IDENTIFIER = 280,
    CONSTANT = 281,
    TYPE_NAME = 282,
    CHAR = 283,
    INT = 284,
    LONG = 285,
    FLOAT = 286,
    DOUBLE = 287,
    VOID = 288,
    MAIN = 289,
    SHORT = 290,
    UNSIGNED = 291,
    SIGNED = 292,
    STRUCT = 293,
    GE_OP = 294,
    LE_OP = 295,
    NE_OP = 296,
    EQ_OP = 297,
    AND = 298,
    OR = 299,
    NOT = 300,
    STATIC = 301,
    EXTERN = 302,
    REGISTER = 303,
    AUTO = 304,
    ARRTYPE = 305
  };
#endif
/* Tokens.  */
#define HASH 258
#define INCLUDE 259
#define DEFINE 260
#define STDIO 261
#define STDLIB 262
#define MATH 263
#define STRING 264
#define TIME 265
#define HEADER_LITERAL 266
#define IF 267
#define ELSE 268
#define WHILE 269
#define DO 270
#define BREAK 271
#define CONTINUE 272
#define RETURN 273
#define SHORTHANDADD 274
#define SHORTHANDSUB 275
#define SHORTHANDMULT 276
#define SHORTHANDDIV 277
#define INCREMENT 278
#define DECREMENT 279
#define IDENTIFIER 280
#define CONSTANT 281
#define TYPE_NAME 282
#define CHAR 283
#define INT 284
#define LONG 285
#define FLOAT 286
#define DOUBLE 287
#define VOID 288
#define MAIN 289
#define SHORT 290
#define UNSIGNED 291
#define SIGNED 292
#define STRUCT 293
#define GE_OP 294
#define LE_OP 295
#define NE_OP 296
#define EQ_OP 297
#define AND 298
#define OR 299
#define NOT 300
#define STATIC 301
#define EXTERN 302
#define REGISTER 303
#define AUTO 304
#define ARRTYPE 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 30 "ast.y" /* yacc.c:1909  */

	int ival;
	struct nodeType *nPtr;
	char string[128];

#line 160 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
