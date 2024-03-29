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
    HEADER = 258,
    ELSE = 259,
    IF = 260,
    WHILE = 261,
    DO = 262,
    BREAK = 263,
    CONTINUE = 264,
    REDUCE = 265,
    RETURN = 266,
    SHORTHANDADD = 267,
    SHORTHANDSUB = 268,
    SHORTHANDMULT = 269,
    SHORTHANDDIV = 270,
    INCREMENT = 271,
    DECREMENT = 272,
    IDENTIFIER = 273,
    CONSTANT = 274,
    TYPE_NAME = 275,
    CHAR = 276,
    INT = 277,
    LONG = 278,
    FLOAT = 279,
    DOUBLE = 280,
    VOID = 281,
    SHORT = 282,
    UNSIGNED = 283,
    SIGNED = 284,
    STRUCT = 285,
    RELOP = 286,
    AND = 287,
    OR = 288,
    NOT = 289,
    STATIC = 290,
    EXTERN = 291,
    REGISTER = 292,
    AUTO = 293,
    ARRTYPE = 294
  };
#endif
/* Tokens.  */
#define HEADER 258
#define ELSE 259
#define IF 260
#define WHILE 261
#define DO 262
#define BREAK 263
#define CONTINUE 264
#define REDUCE 265
#define RETURN 266
#define SHORTHANDADD 267
#define SHORTHANDSUB 268
#define SHORTHANDMULT 269
#define SHORTHANDDIV 270
#define INCREMENT 271
#define DECREMENT 272
#define IDENTIFIER 273
#define CONSTANT 274
#define TYPE_NAME 275
#define CHAR 276
#define INT 277
#define LONG 278
#define FLOAT 279
#define DOUBLE 280
#define VOID 281
#define SHORT 282
#define UNSIGNED 283
#define SIGNED 284
#define STRUCT 285
#define RELOP 286
#define AND 287
#define OR 288
#define NOT 289
#define STATIC 290
#define EXTERN 291
#define REGISTER 292
#define AUTO 293
#define ARRTYPE 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 129 "basic.y" /* yacc.c:1909  */

	int ival;
	long int lival;
	double dval;
	float fval;
	char* idname;

#line 140 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
