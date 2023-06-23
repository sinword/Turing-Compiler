/*** Definition section ***/
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <map>
#define MAX_LINE_LENG 256
#define LIST                { strcat(buf, yytext); strcpy(previous, yytext); }
#define token(t)            { LIST; printf("<%s>\n", t);}
#define tokenInteger(t, i)  { LIST; printf("<%s: %d>\n", t, i);}
#define tokenFloat(t, f)    { LIST; printf("<%s: %f>\n", t, f);}
#define tokenString(t, s)   { LIST; printf("<%s: %s>\n", t, s);}
#define identifier(t, s)    { LIST; printf("<%s: %s>\n", t, s);}
using namespace std;


typedef struct Data {
    string id;
    // string type;
    // string value;
} Data; 

class SymbolTable {
public:
    map<int, Data> table;
    int cnt;
    // key: id, Data: index
public:
    SymbolTable() {
        table = map<int, Data>();
        cnt = 0;
    }

    void insert(string id) {
        Data data;
        data.id = id;
        table.insert(pair<int, Data>(cnt, data));
        cnt++;
    }

    int lookup(string id) {
        map<int, Data>::iterator iter;
        for(iter = table.begin(); iter != table.end(); iter++) {
            if(iter->second.id == id) {
                return iter->first;
            }
        }
        return -1;
    }

    void dump() {
        map<int, Data>::iterator iter;
        cout << "\n\nSymbol Table\n";
        cout << "Index\t\tID\n";
        cout << "----------------------------\n";
        for(iter = table.begin(); iter!= table.end(); iter++) {
            cout << iter->first << "\t\t" << iter->second.id << endl;
        }
    }
    
};

SymbolTable symbolTable;
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
"."             { token("."); }
","             { token(","); }
":"             { token(":"); }
";"             { token(";"); }
"("             { token("("); }
")"             { token(")"); }
"["             { token("["); }
"]"             { token("]"); }
"{"             { token("{"); }
"}"             { token("}"); }

"+"             { token("+"); }
"-"             { token("-"); }
"*"             { token("*"); }
"/"             { token("/"); }

"mod"           { token("MOD"); }
":="            { token(":="); }
"<"             { token("<"); }
"<="            { token("<="); }
">"             { token(">"); }
">="            { token(">="); }
"="             { token("="); }
"not="          { token("NOT="); }

"and"           { token("AND"); }
"or"            { token("OR"); }
"not"           { token("NOT"); }

"put"           { token("PUT"); }
"begin"         { token("BEGIN"); }
"decreasing"    { token("DECREASING"); }
"default"       { token("DEFAULT"); }
"do"            { token("DO"); }
"when"          { token("WHEN"); }
"if"            { token("IF"); }
"else"          { token("ELSE"); }
"end"           { token("END"); }
"exit"          { token("EXIT"); }
"for"           { token("FOR"); }
"function"      { token("FUNCTION"); }
"get"           { token("GET"); }
"loop"          { token("LOOP"); }
"of"            { token("OF"); }
"procedure"     { token("PROCEDURE"); }
"real"          { token("REAL"); }
"result"        { token("RESULT"); }
"return"        { token("RETURN"); }
"skip"          { token("SKIP"); }
"then"          { token("THEN"); }
"true"          { token("TRUE"); }
"false"         { token("FALSE"); }

"var"           { token("VAR"); }
"const"         { token("CONST"); }
"int"           { token("INT"); }
"float"         { token("FLOAT"); }
"char"          { token("CHAR"); }
"string"        { token("STRING"); }
"array"         { token("ARRAY"); }
"bool"          { token("BOOL"); }

{id}            { 
                identifier("id", yytext); 
                Data data; 
                if(symbolTable.lookup(yytext) == -1) {
                    symbolTable.insert(yytext);
                }
                
                }

[+-]?{integer}  { tokenInteger("integer", atoi(yytext)); }
[+-]?{float}    { tokenFloat("float", atof(yytext)); }
{string}        { 
                char *c = (char *)malloc(strlen(yytext));
                strcpy(c, yytext);
                int len = strlen(c);
                c++;
                c[len-2] = '\0';
                tokenString("string", c);
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
                    printf("%d: %s", linenum, buf);
                    linenum++;
                    // char c = yyinput();
                    // if (c != '\n') {
                    //     unput(c);
                    // }
                    buf[0] = '\0'; 
                    BEGIN 0;
                }
<SL_COMMENT>[^\n] { LIST; }

"{%"            { LIST; BEGIN ML_COMMENT; }
<ML_COMMENT>\n  { 
                    LIST;
                    printf("%d: %s", linenum, buf); 
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
                    printf("%d:%s\n", linenum, buf);
                    printf("bad character:'%s'\n",yytext);
                    exit(-1);
                }

%%


/*** Action section ***/

int main() {
    yylex();
    symbolTable.dump();
}

/***

lex compiler_hw1.l
cc lex.yy.c -ll
./a.out test.c

一般換行     -> \n加入buffer一起輸出，buffer清除
單行註解%    -> \n移除，換行另外加，buffer清除
多行註解{%%} -> 加入buffer回傳，buffer不清除

***/