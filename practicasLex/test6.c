option noyywrap
%{
#include <stdio.h>
%}

%%
[a-z]{2}[0-9]{6}"@uaeh.edu.mx" {
    printf("\n Correo Institucional detectado: %s\n", yytext);
}
%%

int main()
{
    yylex();
    return 0;
}
