%{
#include <stdio.h>
#include "y.tab.h"
%}
[a-zA-Z]?\"(\\.|[^\\"\n])*\"		{   return(STRING_LITERAL); }


"+="			{   return(ADD_ASSIGN); }
"-="			{   return(SUB_ASSIGN); }
"*="			{   return(MUL_ASSIGN); }
"/="			{   return(DIV_ASSIGN); }
"%="			{   return(MOD_ASSIGN); }


">>"			{   return(RIGHT_OP); }
"<<"			{   return(LEFT_OP); }

"++"			{   return(INC_OP); }
"--"			{   return(DEC_OP); }

"&&"			{   return(AND_OP); }
"||"			{   return(OR_OP); }


"<="			{   return(LE_OP); }
">="			{   return(GE_OP); }
"=="			{   return(EQ_OP); }
"!="			{   return(NE_OP); }
";"				{   return(';'); }
"{"				{   return('{'); }
"}"				{   return('}'); }
","				{   return(','); }
":"				{   return(':'); }
"="				{   return('='); }
"("				{   return('('); }
")"				{   return(')'); }
"["				{   return('['); }
"]"				{   return(']'); }
"."				{   return('.'); }
"&"				{   return('&'); }
"!"				{   return('!'); }
"~"				{   return('~'); }
"-"				{   return('-'); }
"+"				{   return('+'); }
"*"				{   return('*'); }
"/"				{   return('/'); }
"%"				{   return('%'); }
"<"				{   return('<'); }
">"				{   return('>'); }
"^"				{   return('^'); }
"|"				{   return('|'); }
"?"				{   return('?'); }