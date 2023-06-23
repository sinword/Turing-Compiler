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

#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
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
    DOT = 258,
    COMMA = 259,
    COLON = 260,
    LPAREN = 261,
    RPAREN = 262,
    LBRACKET = 263,
    RBRACKET = 264,
    LBRACE = 265,
    RBRACE = 266,
    SEMICOLON = 267,
    BOOL = 268,
    ASSIGN = 269,
    PUT = 270,
    _BEGIN = 271,
    DECREASING = 272,
    DEFAULT = 273,
    DO = 274,
    WHEN = 275,
    IF = 276,
    ELSE = 277,
    END = 278,
    EXIT = 279,
    FOR = 280,
    FUNCTION = 281,
    GET = 282,
    LOOP = 283,
    OF = 284,
    PROCEDURE = 285,
    REAL = 286,
    RESULT = 287,
    RETURN = 288,
    SKIP = 289,
    THEN = 290,
    VAR = 291,
    CONST = 292,
    INT = 293,
    STRING = 294,
    ARRAY = 295,
    NOT = 296,
    AND = 297,
    OR = 298,
    LT = 299,
    LE = 300,
    EQ = 301,
    GE = 302,
    GT = 303,
    NE = 304,
    ADD = 305,
    SUB = 306,
    MUL = 307,
    DIV = 308,
    MOD = 309,
    UMINUS = 310,
    I_CONST = 311,
    F_CONST = 312,
    STR_CONST = 313,
    ID = 314,
    TRUE = 315,
    FALSE = 316
  };
#endif
/* Tokens.  */
#define DOT 258
#define COMMA 259
#define COLON 260
#define LPAREN 261
#define RPAREN 262
#define LBRACKET 263
#define RBRACKET 264
#define LBRACE 265
#define RBRACE 266
#define SEMICOLON 267
#define BOOL 268
#define ASSIGN 269
#define PUT 270
#define _BEGIN 271
#define DECREASING 272
#define DEFAULT 273
#define DO 274
#define WHEN 275
#define IF 276
#define ELSE 277
#define END 278
#define EXIT 279
#define FOR 280
#define FUNCTION 281
#define GET 282
#define LOOP 283
#define OF 284
#define PROCEDURE 285
#define REAL 286
#define RESULT 287
#define RETURN 288
#define SKIP 289
#define THEN 290
#define VAR 291
#define CONST 292
#define INT 293
#define STRING 294
#define ARRAY 295
#define NOT 296
#define AND 297
#define OR 298
#define LT 299
#define LE 300
#define EQ 301
#define GE 302
#define GT 303
#define NE 304
#define ADD 305
#define SUB 306
#define MUL 307
#define DIV 308
#define MOD 309
#define UMINUS 310
#define I_CONST 311
#define F_CONST 312
#define STR_CONST 313
#define ID 314
#define TRUE 315
#define FALSE 316

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */
