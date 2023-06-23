yacc -d yacc.y
flex lex.l
g++ lex.yy.c y.tab.c -o parser