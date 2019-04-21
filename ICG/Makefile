run:
	lex test.l
	yacc -t -d basic.y
	gcc -g lex.yy.c y.tab.c symnode.c -ly -ll
	./a.out < test_code_2.c > op.txt
