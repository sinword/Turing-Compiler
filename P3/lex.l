/*** Definition section ***/
%{
#include "y.tab.hpp"
#define LEX_DEBUG 0
#define MAX_LINE_LENG 256
#define LIST                { strcat(buf, yytext); strcpy(previous, yytext); }
#define token(t)            { LIST; if(LEX_DEBUG) { printf("<%s>\n", t); } }
#define tokenInteger(t, i)  { LIST; if(LEX_DEBUG) { printf("<%s: %d>\n", t, i); } }
#define tokenFloat(t, f)    { LIST; if(LEX_DEBUG) { printf("<%s: %f>\n", t, f); } }
#define tokenString(t, s)   { LIST; if(LEX_DEBUG) { printf("<%s: %s>\n", t, s); } }
#define identifier(t, s)    { LIST; if(LEX_DEBUG) { printf("<%s: %s>\n", t, s); } }

int linenum = 1;
char buf[MAX_LINE_LENG];
char previous[100] = "";
%}

%x SL_COMMENT ML_COMMENT

digit [0-9]
letter [a-zA-Z]
id {letter}({letter}|{digit})*
integer {digit}|([1-9]{digit}*)
float {integer}("."{integer})?
string \"([^"]|\"\")*\"


/*** Rule section ***/
%%
"."             { token("."); return DOT; }
","             { token(","); return COMMA; }
":"             { token(":"); return COLON; }
";"             { token(";"); return SEMICOLON; }
"("             { token("("); return LPAREN; }
")"             { token(")"); return RPAREN; }
"["             { token("["); return LBRACKET; }
"]"             { token("]"); return RBRACKET; }
"{"             { token("{"); return LBRACE; }
"}"             { token("}"); return RBRACE;}

"+"             { token("+"); return ADD; }
"-"             { token("-"); return SUB; }
"*"             { token("*"); return MUL; }
"/"             { token("/"); return DIV; }
"mod"           { token("MOD"); return MOD;}

":="            { token(":="); return ASSIGN; }
"<"             { token("<"); return LT; }
"<="            { token("<="); return LE; }
">"             { token(">"); return GT; }
">="            { token(">="); return GE; }
"="             { token("="); return EQ; }
"not="          { token("NOT="); return NE; }

"and"           { token("AND"); return AND; }
"or"            { token("OR"); return OR; }
"not"           { token("NOT"); return NOT; }

"put"           { token("PUT"); return PUT; }
"begin"         { token("BEGIN"); return _BEGIN; }
"decreasing"    { token("DECREASING"); return DECREASING; }
"default"       { token("DEFAULT"); return DEFAULT; }
"do"            { token("DO"); return DO; }
"when"          { token("WHEN"); return WHEN; }
"if"            { token("IF"); return IF; }
"else"          { token("ELSE"); return ELSE; }
"end"           { token("END"); return END; }
"exit"          { token("EXIT"); return EXIT; }
"for"           { token("FOR"); return FOR; }
"function"      { token("FUNCTION"); return FUNCTION; }
"get"           { token("GET"); return GET; }
"loop"          { token("LOOP"); return LOOP; }
"of"            { token("OF"); return OF; }
"procedure"     { token("PROCEDURE"); return PROCEDURE; }
"result"        { token("RESULT"); return RESULT; }
"return"        { token("RETURN"); return RETURN; }
"skip"          { token("SKIP"); return SKIP; }
"then"          { token("THEN"); return THEN; }
"true"          { token("TRUE"); return TRUE; yylval.value.i_val = true; }
"false"         { token("FALSE"); return FALSE; yylval.value.i_val = false; }
"bool"          { token("BOOL"); return BOOL; }

"var"           { token("VAR"); return VAR; }
"const"         { token("CONST"); return CONST; }
"int"           { token("INT"); return INT; }
"real"          { token("REAL"); return REAL; } // FLOAT
"string"        { token("STRING"); return STRING; }
"array"         { token("ARRAY"); return ARRAY; }

{id}            { 
                    identifier("id", yytext); 
                    yylval.value.s_val = yytext;
                    return ID;
                }

[+-]?{integer}  { 
                    tokenInteger("integer", atoi(yytext));
                    yylval.value.i_val = atoi(yytext);
                    return I_CONST;
                }

[+-]?{float}    { 
                    tokenFloat("float", atof(yytext)); 
                    yylval.value.f_val = atof(yytext);
                    return F_CONST;
                }

{string}        { 
                    char *c = (char *)malloc(strlen(yytext));
                    strcpy(c, yytext);
                    int len = strlen(c);
                    c++;
                    c[len-2] = '\0';
                    tokenString("string", c);
                    yylval.value.s_val = c;
                    return STR_CONST;
                }

\n              {               
                    LIST;
                    printf("%d: %s", linenum, buf);
                    linenum++;
                    buf[0] = '\0';
                }

[ \t]*           { LIST; }    


"\%"            { LIST; BEGIN SL_COMMENT; }

<SL_COMMENT>\n  {
                    LIST;
                    // printf("%d: %s", linenum, buf);
                    linenum++;

                    buf[0] = '\0'; 
                    BEGIN 0;
                }

<SL_COMMENT>[^\n]   { LIST; }

"{%"            { LIST; BEGIN ML_COMMENT; }

<ML_COMMENT>\n  { 
                    LIST;
                    // printf("%d: %s", linenum, buf); 
                    linenum++;
                    buf[0] = '\0'; 
                }

<ML_COMMENT>[^\%]  { LIST; }

<ML_COMMENT>[^\}]  { LIST; }

<ML_COMMENT>\%\}   { LIST; BEGIN 0; }

<<EOF>>         {
                    if (strcmp(previous, "") != 0) { 
                        printf("%d: %s\n", linenum, buf);
                    }
                    return -1;
                }

.               { 
                    LIST; 
                    // printf("%d:%s\n", linenum, buf);
                    // printf("bad character:'%s'\n",yytext);
                    exit(-1);
                }

%%



/*** Action section ***/
// int main() {
//     yylex();
//     symbolTable.dump();
// }

/***

lex compiler_hw1.l
cc lex.yy.c -ll
./a.out test.c

一般換行     -> \n加入buffer一起輸出，buffer清除
單行註解%    -> \n移除，換行另外加，buffer清除
多行註解{%%} -> 加入buffer回傳，buffer不清除

***/