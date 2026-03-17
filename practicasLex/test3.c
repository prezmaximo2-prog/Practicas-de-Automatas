option noyywrap
%{
#include <stdio.h>
%}

%%
[a-zA-Z][a-zA-Z0-9_]* {printf("\n reconocido como identificador: %s\n", yytext);}
%%

int main()
{
    yylex();
    return 0;
}
