run: 
	lex test.l
	yacc -d test.y
	yacc -v test.y
	gcc lex.yy.c y.tab.c symnode.c -ly -ll 
	./a.out < irc_for_if.c > op.txt