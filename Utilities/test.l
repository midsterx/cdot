%{
#include <stdio.h>
#include "y.tab.h"

void show(void);
%}


%%
"/*"			{ comment(); }
"//"[^\n]*      { /* consume //-comment */ }



"char"			{ show(); return(CHAR); }
"do"			{ show(); return(DO); }
"double"		{ show(); return(DOUBLE); }
"else"			{ show(); return(ELSE); }
"float"			{ show(); return(FLOAT); }
"if"			{ show(); return(IF); }
"int"			{ show(); return(INT); }
"long"			{ show(); return(LONG); }
"void"			{ show(); return(VOID); }
"while"			{ show(); return(WHILE); }

[a-zA-Z_]([a-zA-Z_]|[0-9])*		{ show(); return(check_type()); }

([0-9])*								{ show(); return(CONSTANT);}
([0-9])+([Ee][+-]?([0-9])+)				{ show(); return(CONSTANT); }
([0-9])*"."([0-9])+([Ee][+-]?([0-9])+)?	{ show(); return(CONSTANT); }
([0-9])+"."([0-9])*([Ee][+-]?([0-9])+)?	{ show(); return(CONSTANT); }


";"			{ show(); return(';'); }
"{" 		{ show(); return('{'); }
"}" 		{ show(); return('}'); }
","			{ show(); return(','); }
"="			{ show(); return('='); }
"("			{ show(); return('('); }
")"			{ show(); return(')'); }
"-"			{ show(); return('-'); }
"+"			{ show(); return('+'); }
"*"			{ show(); return('*'); }
"/"			{ show(); return('/'); }


[\t\n]		{ show(); }
.			{ /* Add error code or whatever - not matching*/ }

%%

int yywrap(void)
{
	return 1;
}


void comment(void)
{
	char c, prev = 0;
  
	while ((c = input()) != 0)      /* (EOF maps to 0) */
	{
		if (c == '/' && prev == '*')
			return;
		prev = c;
	}
	error("unterminated comment");
}


void show(void)
{
	ECHO;
	printf(" ");
}


int check_type(void)
{
	return IDENTIFIER;
}