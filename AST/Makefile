run:
	lex ast.l
	yacc -t -d ast.y
	gcc -g lex.yy.c y.tab.c graph.c -ll -ly
	./a.out < test_code.c > op.txt

