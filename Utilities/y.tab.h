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
    IDENTIFIER = 258,
    CONSTANT = 259,
    TYPE_NAME = 260,
    CHAR = 261,
    INT = 262,
    LONG = 263,
    FLOAT = 264,
    DOUBLE = 265,
    VOID = 266,
    SHORT = 267,
    UNSIGNED = 268,
    SIGNED = 269,
    IF = 270,
    ELSE = 271,
    WHILE = 272,
    DO = 273,
    BREAK = 274,
    CONTINUE = 275,
    RETURN = 276,
    RELOP = 277,
    AND = 278,
    OR = 279,
    NOT = 280,
    SHORTHANDADD = 281,
    SHORTHANDSUB = 282,
    SHORTHANDMULT = 283,
    SHORTHANDDIV = 284,
    INCREMENT = 285,
    DECREMENT = 286,
    STRUCT = 287,
    STATIC = 288,
    EXTERN = 289,
    REGISTER = 290,
    AUTO = 291,
    ARRTYPE = 292,
    HEADER = 293
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define TYPE_NAME 260
#define CHAR 261
#define INT 262
#define LONG 263
#define FLOAT 264
#define DOUBLE 265
#define VOID 266
#define SHORT 267
#define UNSIGNED 268
#define SIGNED 269
#define IF 270
#define ELSE 271
#define WHILE 272
#define DO 273
#define BREAK 274
#define CONTINUE 275
#define RETURN 276
#define RELOP 277
#define AND 278
#define OR 279
#define NOT 280
#define SHORTHANDADD 281
#define SHORTHANDSUB 282
#define SHORTHANDMULT 283
#define SHORTHANDDIV 284
#define INCREMENT 285
#define DECREMENT 286
#define STRUCT 287
#define STATIC 288
#define EXTERN 289
#define REGISTER 290
#define AUTO 291
#define ARRTYPE 292
#define HEADER 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
