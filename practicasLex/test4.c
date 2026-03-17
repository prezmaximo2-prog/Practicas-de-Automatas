option noyywrap
%{
#include <stdio.h>
%}
DIGITO          [0-9]
LETRA           [A-ZÑ&]
FECHA           [0-9]{2}(0[1-9]|1[0-2])(0[1-9]|[12][0-9]|3[01])
HOMOCLAVE       [A-Z0-9]{3}
%%
({LETRA}{4}{FECHA}{HOMOCLAVE}) {
    printf("\n RFC: %s\n", yytext);
}
%%

int main()
{
    yylex();
    return 0;
}
