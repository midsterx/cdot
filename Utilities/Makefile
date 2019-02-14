run: 
	lex test.l
	yacc -d test.y
	gcc lex.yy.c y.tab.c -ly -ll 
	./a.out < test_code.c > op.txt