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
    HEADER = 258,
    IF = 259,
    ELSE = 260,
    WHILE = 261,
    DO = 262,
    BREAK = 263,
    CONTINUE = 264,
    RETURN = 265,
    SHORTHANDADD = 266,
    SHORTHANDSUB = 267,
    SHORTHANDMULT = 268,
    SHORTHANDDIV = 269,
    INCREMENT = 270,
    DECREMENT = 271,
    IDENTIFIER = 272,
    CONSTANT = 273,
    TYPE_NAME = 274,
    CHAR = 275,
    INT = 276,
    LONG = 277,
    FLOAT = 278,
    DOUBLE = 279,
    VOID = 280,
    SHORT = 281,
    UNSIGNED = 282,
    SIGNED = 283,
    STRUCT = 284,
    RELOP = 285,
    AND = 286,
    OR = 287,
    NOT = 288,
    STATIC = 289,
    EXTERN = 290,
    REGISTER = 291,
    AUTO = 292,
    ARRTYPE = 293
  };
#endif
/* Tokens.  */
#define HEADER 258
#define IF 259
#define ELSE 260
#define WHILE 261
#define DO 262
#define BREAK 263
#define CONTINUE 264
#define RETURN 265
#define SHORTHANDADD 266
#define SHORTHANDSUB 267
#define SHORTHANDMULT 268
#define SHORTHANDDIV 269
#define INCREMENT 270
#define DECREMENT 271
#define IDENTIFIER 272
#define CONSTANT 273
#define TYPE_NAME 274
#define CHAR 275
#define INT 276
#define LONG 277
#define FLOAT 278
#define DOUBLE 279
#define VOID 280
#define SHORT 281
#define UNSIGNED 282
#define SIGNED 283
#define STRUCT 284
#define RELOP 285
#define AND 286
#define OR 287
#define NOT 288
#define STATIC 289
#define EXTERN 290
#define REGISTER 291
#define AUTO 292
#define ARRTYPE 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 73 "basic.y" /* yacc.c:1909  */

	int ival;
	long int lival;
	double dval;
	float fval;
	char* idname;

#line 138 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
