run:
	lex test.l
	yacc -d basic.y
	gcc lex.yy.c y.tab.c symnode.c
	./a.out < test_code_2.c > op.txt
