option noyywrap
%{
#include <stdio.h>
%}
%%
[0-9]+ {printf("\n reconocido como entero: %s\n", yytext);}
. {}
%%
int main()
{
yylex();
return 0;
}
