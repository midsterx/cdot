%{
#include <stdio.h>
#include "y.tab.h"
#include <string.h>
#include "header.h"
int line1_flag = 0;

void show(void);
void myerror(void);
void comment(void);
int check_type(void);
%}

%%

"/*"			{ comment(); }
"//"[^\n]*      { /* consume //-single comment */ }

"#include"[ ]*"<".*">" { show(); return(HEADER); }
"#include"[ ]*"\"".*"\"" { show(); return(HEADER); }
"do"			{ show(); return(DO); }
"else"			{ show(); return(ELSE); }
"if"			{ show(); return(IF); }
"while"			{ show(); return(WHILE); }


"int"			{ show(); strcpy(yylval.string,yytext); return(INT); }
"char"			{ show(); strcpy(yylval.string,yytext); return(CHAR); }
"long"			{ show(); strcpy(yylval.string,yytext); return(LONG); }
"void"			{ show(); strcpy(yylval.string,yytext); return(VOID); }
"double"		{ show(); strcpy(yylval.string,yytext); return(DOUBLE); }
"float"			{ show(); strcpy(yylval.string,yytext); return(FLOAT); }
"short"         { show(); strcpy(yylval.string,yytext); return(SHORT); }
"unsigned"         { show(); strcpy(yylval.string,yytext); return(UNSIGNED); }
"signed"         { show(); strcpy(yylval.string,yytext); return(SIGNED); }


"static" { show(); return(STATIC); }
"extern" { show(); return(EXTERN); }
"register" { show(); return(REGISTER); }
"auto" { show(); return(AUTO); }

"+=" { show(); return(SHORTHANDADD); }
"-=" { show(); return(SHORTHANDSUB); }
"*=" { show(); return(SHORTHANDMULT); }
"/=" { show(); return(SHORTHANDDIV); }
"!" { show(); return(NOT); }

"++" { show(); return(INCREMENT); }
"--" { show(); return(DECREMENT); }

"<="		{ strcpy(yylval.string,yytext); return(LE_OP); }
">="		{ strcpy(yylval.string,yytext); return(GE_OP); }
"=="		{ strcpy(yylval.string,yytext); return(EQ_OP); }
"!="		{ strcpy(yylval.string,yytext); return(NE_OP); }

"&&" {show(); return(AND); }
"||" {show(); return(OR); }

"break"     { show(); return(BREAK); }
"continue"  { show(); return(CONTINUE); }
"return"    { show(); return(RETURN); }

"struct" { show(); strcpy(yylval.string,yytext); return(STRUCT); }

"[]" { show(); return(ARRTYPE); }

[a-zA-Z_]([a-zA-Z_]|[0-9])*		{ show(); strcpy(yylval.string,yytext); return(IDENTIFIER); }

([0-9])*								{ show(); strcpy(yylval.string,yytext); return(CONSTANT); }
([0-9])+([Ee][+-]?([0-9])+)				{ show(); strcpy(yylval.string,yytext); return(CONSTANT); }
([0-9])*"."([0-9])+([Ee][+-]?([0-9])+)?	{ show(); strcpy(yylval.string,yytext); return(CONSTANT); }
([0-9])+"."([0-9])*([Ee][+-]?([0-9])+)?	{ show(); strcpy(yylval.string,yytext); return(CONSTANT); }


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

[\n]		{ yylineno++;
			  show();
			}
[\t]		{ show(); }
[" "]		{;}
.			{ myerror(); }

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
	//error("unterminated comment");
}


void show(void)
{
	if (yylineno == 1 && line1_flag == 0)
	{
		printf("%d", yylineno);
		line1_flag = 1;
	}
	if (strcmp(yytext,"\n") == 0)
	{
		printf("\n%d", yylineno);	
	}
	else
	{
		ECHO;
	}
	printf(" ");
}

void myerror(void)
{
	printf("Error at Line Number: %d %s", yylineno, yytext);
}