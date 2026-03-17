option noyywrap
%{
#include <stdio.h>
%}

DIGITO          [0-9]
LETRA           [A-Z]
FECHA           {DIGITO}{2}(0[1-9]|1[0-2])(0[1-9]|[12][0-9]|3[01])
SEXO            [HM]
ESTADO          (AS|BC|BS|CC|CS|CH|CL|CM|DF|DG|GT|GR|HG|JC|MC|MN|MS|NT|NL|OC|PL|QT|QR|SP|SL|SR|TC|TS|TL|VZ|YN|ZS|NE)

%%
{LETRA}{4}{FECHA}{SEXO}{ESTADO}{LETRA}{3}{DIGITO}{2} {
    printf("\n CURP detectada: %s\n", yytext);
}
%%

int main()
{
    yylex();
    return 0;
}
