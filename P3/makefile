a.out:y.tab.cpp lex.yy.cpp
	g++ -Wno-write-strings -std=c++11 symboltable.hpp javaclass.hpp y.tab.cpp -o parser -ll -ly -Wall

lex.yy.cpp: lex.l
	flex -o lex.yy.cpp lex.l

y.tab.cpp: yacc.y
	yacc -y -v -d yacc.y -o y.tab.cpp

clean:
	-rm -f a.out
	-rm -f *.cpp
	-rm -f y.tab.hpp
	-rm -f y.output
	-rm -f parser