run: 
	lex test.l
	yacc -d test.y
	gcc lex.yy.c y.tab.c symnode.c
	./a.out < test_code_2.c > op.txt
