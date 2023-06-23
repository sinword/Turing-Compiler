/*** Definition section ***/
%{
#include <stdio.h>
#define LIST     strcat(buf, yytext)
#define token(t) { LIST; printf("<%s>\n", t);}
#define tokenInteger(t, i) {LIST; printf("<%s, %d>\n", "t", i);}
#define tokenString(t, s) {LIST; printf("<%s, %s>\n", "t", s);}

#define MAX_LINE_LENG 256
int linenum = 1;
char buf[MAX_LINE_LENG];
%}

digit [0-9]
letter [a-zA-Z]
id {letter}({letter}|{digit})*
integer {digit}|([1-9]{digit}*)
float {integer}("."{integer})?
double-doublequote \"\"
string \"([^"]|{double-doublequote})*\"
/* string \"[("")|(^")]*\" */
/* string \"[^"]*\" */

/*** Rule section ***/
%%
"."             { printf("%d \t DOT \t %s\n", linenum, yytext); }
","             { printf("%d \t COMMA \t %s\n", linenum, yytext); }
":"             { printf("%d \t COLON \t %s\n", linenum, yytext); }
";"             { printf("%d \t SEMI \t %s\n", linenum, yytext); }
"{"             { printf("%d \t LB \t %s\n", linenum, yytext); }
"}"             { printf("%d \t RB \t %s\n", linenum, yytext); }
"("             { printf("%d \t LP \t %s\n", linenum, yytext);}
")"             { printf("%d \t RP \t %s\n", linenum, yytext); }

"+"             { printf("%d \t ADD \t %s\n", linenum, yytext); }
"-"             { printf("%d \t SUB \t %s\n", linenum, yytext); }
"*"             { printf("%d \t MUL \t %s\n", linenum, yytext); }
"/"             { printf("%d \t DIV \t %s\n", linenum, yytext); }

"mod"           { printf("%d \t MOD \t %s\n", linenum, yytext); }
":="            { printf("%d \t ASSIGN \t %s\n", linenum, yytext); }
"<"             { printf("%d \t LT \t %s\n", linenum, yytext); }
"<="            { printf("%d \t LEQ \t %s\n", linenum, yytext); }
">"             { printf("%d \t GT \t %s\n", linenum, yytext); }
">="            { printf("%d \t GEQ \t %s\n", linenum, yytext); }
"="             { printf("%d \t EQ \t %s\n", linenum, yytext); }
"not="          { printf("%d \t NEQ \t %s\n", linenum, yytext); }

"and"           { printf("%d \t AND \t %s\n", linenum, yytext); }
"or"            { printf("%d \t OR \t %s\n", linenum, yytext); }
"not"           { printf("%d \t NOT \t %s\n", linenum, yytext); }


"begin"         { printf("%d \t BEGIN \t %s\n", linenum, yytext); }
"decreasing"    { printf("%d \t DECREASING \t %s\n", linenum, yytext); }
"default"       { printf("%d \t DEFAULT \t %s\n", linenum, yytext); }
"do"            { printf("%d \t DO \t %s\n", linenum, yytext); }
"when"          { printf("%d \t WHEN \t %s\n", linenum, yytext); }
"if"            { printf("%d \t IF \t %s\n", linenum, yytext); }
"else"          { printf("%d \t ELSE \t %s \n", linenum, yytext); }
"end"           { printf("%d \t END \t %s\n", linenum, yytext); }
"exit"          { printf("%d \t EXIT \t %s\n", linenum, yytext); }
"for"           { printf("%d \t FOR \t %s\n", linenum, yytext); }
"function"      { printf("%d \t FUNCTION \t %s\n", linenum, yytext); }
"get"           { printf("%d \t GET \t %s\n", linenum, yytext); }
"loop"          { printf("%d \t LOOP \t %s\n", linenum, yytext); }
"of"            { printf("%d \t OF \t %s\n", linenum, yytext); }
"put"           { printf("%d \t PUT \t %s\n", linenum, yytext); }
"procedure"     { printf("%d \t PROCEDURE \t %s\n", linenum, yytext); }
"real"          { printf("%d \t REAL \t %s\n", linenum, yytext); }
"result"        { printf("%d \t RESULT \t %s\n", linenum, yytext); }
"return"        { printf("%d \t RETURN \t %s\n", linenum, yytext); }
"skip"          { printf("%d \t SKIP \t %s\n", linenum, yytext); }
"then"          { printf("%d \t THEN \t %s\n", linenum, yytext); }
"true"          { printf("%d \t TRUE \t %s\n", linenum, yytext); }
"false"         { printf("%d \t FALSE \t %s\n", linenum, yytext); }


"var"           { printf("%d \t VAR \t %s\n", linenum, yytext); }
"const"         { printf("%d \t CONST \t %s\n", linenum, yytext); }
"int"           { printf("%d \t INT \t %s\n", linenum, yytext); }
"float"         { printf("%d \t FLOAT \t %s\n", linenum, yytext); }
"char"          { printf("%d \t CHAR \t %s\n", linenum, yytext); }
"string"        { printf("%d \t STRING \t %s\n", linenum, yytext); }
"array"         { printf("%d \t ARRAY \t %s\n", linenum, yytext); } 
"bool"          { printf("%d \t BOOL \t %s\n", linenum, yytext); }

{id}            { printf("%d \t ID \t %s\n", linenum, yytext); }
[+-]?{integer}  { printf("%d \t CONST_INT \t %s\n", linenum, yytext); }
[+-]?{float}    { printf("%d \t CONST_FLOAT \t %s\n", linenum, yytext); }
{string}        { printf("%d \t CONST_STR \t %s\n", linenum, yytext); }

[\n]            { printf("\n"); linenum++; }
[\t]            {}    
.               {}
%%

/*** Action section ***/
int main() {
    yylex();
}

/***
string "hello"" world"
string      { printf("%d \t CONST_STR \t %s\n", linenum, yytext); }

lex compiler_hw1.l
cc lex.yy.c -ll
./a.out test.c

***/