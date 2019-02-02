%{
#include <stdio.h>
#include "y.tab.h"
%}

%%
"int" | "bool" | "char" | "void" | "double" | "unsigned short int" | "unsigned long int" | "unsigned long long int" | "signed short int" | "signed long int" | "signed long long int"					{return type_const;}	
"if"																	{return IF;}
"else"																	{return ELSE;}
"do"																	{return DO;}
"while"																	{return WHILE;}
"goto"																	{return GOTO;}
"continue"																{return CONTINUE;}
"break"																	{return BREAK;}
"struct"|"union"														{return record_const;}
"return"																{return RETURN;}
"sizeof"																{return SIZEOF;}
"||" 																	{return or_const;}
"&&"																	{return and_const;}
"=="|"!="																{return eq_const;}
"<="|">="																{return rel_const;}
">>"|"<<"																{return shift_const;}
"++"|"--"																{return inc_const;}
"->"																	{return point_const;}
";" | "=" | "," | "{" | "}" | "(" | ")" | "[" | "]" | "*" | "+" | "-" | "/" | "?" | ":" | "&" | "|" | "^" | "!" | "~" | "%" | "<" | ">"					                                            {return yytext[0];}
"*="|"/="|"+="|"%="|">>="|"-="|"<<="|"&="|"^="|"|="						{return op_assign;}
[0-9]+																	{return int_const;}
[0-9]+"."[0-9]+															{return float_const;}	
"'"."'"																	{return char_const;}
[a-zA-z_][a-zA-z_0-9]*			 										{return id;}
\"(\\.|[^\"])*\"														{return string;}
"//"(\\.|[^\n])*[\n]													;
[/][*]([^*]|[*]*[^*/])*[*]+[/]                                          ;
[ \t\n]																	;
%%

int yywrap(void)
{
    return 1;
}