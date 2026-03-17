option noyywrap
%{
#include <stdio.h>
%}

%%
[0-9]+"."[0-9]+ {printf("\n reconocido como decimal: %s\n", yytext);}
%%

int main()
{
    yylex();
    return 0;
}
