%{
#include <stdio.h>
#include "y.tab.h"
#include <string.h>
int line1_flag = 0;
struct tokens
{
	char name[100];
	char type[100];
} toks[1000];
int tok_count = 0;
void show(void);
void myerror(void);
void comment(void);
int check_type(void);
void tokprint();
%}

%%
"bye"			{ tokprint();}
"/*"			{ comment(); }
"//"[^\n]*      { /* consume //-single comment */ }

"#include"[ ]*"<".*">" { show(); return(HEADER); }
"#include"[ ]*"\"".*"\"" { show(); return(HEADER); }
"do"			{ show(); return(DO); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"keyword"); }
"else"			{ show(); return(ELSE); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"keyword"); }
"if"			{ show(); return(IF); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"keyword"); }
"while"			{ show(); return(WHILE); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"keyword"); }


"int"			{ show(); return(INT); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"keyword"); }
"char"			{ show(); return(CHAR); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"keyword"); }
"long"			{ show(); return(LONG); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"keyword"); }
"void"			{ show(); return(VOID); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"keyword"); }
"double"		{ show(); return(DOUBLE); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"keyword"); }
"float"			{ show(); return(FLOAT); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"keyword"); }
"short"         { show(); return(SHORT); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"keyword"); }
"unsigned"         { show(); return(UNSIGNED); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"keyword"); }
"signed"         { show(); return(SIGNED); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"keyword"); }


"static" { show(); return(STATIC); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"keyword");}
"extern" { show(); return(EXTERN); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"keyword");}
"register" { show(); return(REGISTER); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"keyword");}
"auto" { show(); return(AUTO); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"keyword"); }

"+=" { show(); return(SHORTHANDADD); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"operator"); }
"-=" { show(); return(SHORTHANDSUB); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"operator"); }
"*=" { show(); return(SHORTHANDMULT); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"operator"); }
"/=" { show(); return(SHORTHANDDIV); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"operator"); }
"!" { show(); return(NOT); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"operator");}

"++" { show(); return(INCREMENT); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"operator"); }
"--" { show(); return(DECREMENT); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"operator"); }

[><] { show(); return(RELOP); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"operator"); }
">=" { show(); return(RELOP); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"operator"); }
"<=" { show(); return(RELOP); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"operator"); }
"==" { show(); return(RELOP); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"operator"); }
"!=" { show(); return(RELOP); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"operator"); }

"&&" {show(); return(AND); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"operator"); }
"||" {show(); return(OR); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"operator"); }

"break"     { show(); return(BREAK); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"keyword"); }
"continue"  { show(); return(CONTINUE); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"keyword"); }
"return"    { show(); return(RETURN); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"keyword"); }

"struct" { show(); yylval.idname = strdup(yytext); return(STRUCT); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"keyword");}

"[]" { show(); return(ARRTYPE); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"symbol"); }

[a-zA-Z_]([a-zA-Z_]|[0-9])*		{ show(); yylval.idname = strdup(yytext); return(IDENTIFIER); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"identifier"); }

([0-9])*								{ show(); yylval.ival = atoi(yytext); return(CONSTANT); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"constant"); }
([0-9])+([Ee][+-]?([0-9])+)				{ show(); yylval.ival = atoi(yytext); return(CONSTANT); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"constant"); }
([0-9])*"."([0-9])+([Ee][+-]?([0-9])+)?	{ show(); yylval.ival = atoi(yytext); return(CONSTANT); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"constant"); }
([0-9])+"."([0-9])*([Ee][+-]?([0-9])+)?	{ show(); yylval.ival = atoi(yytext); return(CONSTANT); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"constant"); }


";"			{ show(); return(';'); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"symbol"); }
"{" 		{ show(); return('{'); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"symbol"); }
"}" 		{ show(); return('}'); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"symbol"); }
","			{ show(); return(','); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"symbol"); }
"="			{ show(); return('='); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"operator"); }
"("			{ show(); return('('); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"symbol"); }
")"			{ show(); return(')'); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"symbol"); }
"-"			{ show(); return('-'); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"operator"); }
"+"			{ show(); return('+'); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"operator"); }
"*"			{ show(); return('*'); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"operator"); }
"/"			{ show(); return('/'); strcpy(toks[tok_count++].name,yytext); strcpy(toks[tok_count++].type,"operator"); }

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

void tokprint()
{
	FILE *fptr;
	fptr = fopen("tokens.txt", "w+");
	// for (int i = 0;i < tok_count;i++)
	// {
	// 	fprintf(fptr, "Hello");
	// 	fclose(fptr);
	// 	fprintf(fptr, "<%s,%s>\n", toks[i].name, toks[i].type);
	// }
	fprintf(fptr,"%s", toks[0].name);
	fclose(fptr);
	puts(toks[0].name);
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