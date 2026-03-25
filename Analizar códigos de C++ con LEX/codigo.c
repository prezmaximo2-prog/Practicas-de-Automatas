%{
#include <stdio.h>
#include <stdlib.h>

int line = 1;
FILE *out_file;
%}

DIGITO       [0-9]
HEX         [0-9a-fA-F]
LETRA      [a-zA-Z_]
ID          {LETRA}({LETRA}|{DIGITO})*
ENTERO      {DIGITO}+
FLOTANTE    ({DIGITO}+"."{DIGITO}*|"."{DIGITO}+)([eE][+-]?{DIGITO}+)?[fFlL]?
HEXADECIMAL 0[xX]{HEX}+
BINARIO     0[bB][01]+
OCTAL       0[0-7]+
CADENA      \"([^\"\\]|\\.)*\"
CARACTER    \'([^\'\\]|\\.)\'
COMENTARIO_LINEA \/\/[^\n]*
COMENTARIO_BLOQUE \/\*([^*]|\*+[^*/])*\*+\/

%%

\n                      { line++; }
[ \t\r]+                {  }

{COMENTARIO_LINEA}      { fprintf(out_file, "[Ln: %04d] -> %-25s | %s\n", line, "COMENTARIO_LINEA", yytext); }

{COMENTARIO_BLOQUE}     { 
                            for(int i = 0; yytext[i] != '\0'; i++) {
                                if(yytext[i] == '\n') line++;
                            }
                            fprintf(out_file, "[Ln: %04d] -> %-25s | %s\n", line, "COMENTARIO_BLOQUE", yytext); 
                        }

"auto"|"break"|"case"|"catch"|"class"|"const"|"continue"|"default"|"delete"|"do"|"double"|"else"|"enum"|"explicit"|"extern"|"false"|"float"|"for"|"friend"|"goto"|"if"|"inline"|"int"|"long"|"namespace"|"new"|"operator"|"private"|"protected"|"public"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"template"|"this"|"throw"|"true"|"try"|"typedef"|"typename"|"union"|"unsigned"|"using"|"virtual"|"void"|"volatile"|"while" { 
                            fprintf(out_file, "[Ln: %04d] -> %-25s | %s\n", line, "PALABRA_RESERVADA", yytext); 
                        }

{HEXADECIMAL}           { fprintf(out_file, "[Ln: %04d] -> %-25s | %s\n", line, "NUM_HEXADECIMAL", yytext); }
{BINARIO}               { fprintf(out_file, "[Ln: %04d] -> %-25s | %s\n", line, "NUM_BINARIO", yytext); }
{OCTAL}                 { fprintf(out_file, "[Ln: %04d] -> %-25s | %s\n", line, "NUM_OCTAL", yytext); }
{FLOTANTE}              { fprintf(out_file, "[Ln: %04d] -> %-25s | %s\n", line, "NUM_FLOTANTE", yytext); }
{ENTERO}                { fprintf(out_file, "[Ln: %04d] -> %-25s | %s\n", line, "NUM_ENTERO", yytext); }

{CADENA}                { fprintf(out_file, "[Ln: %04d] -> %-25s | %s\n", line, "CADENA_CARACTERES", yytext); }
{CARACTER}              { fprintf(out_file, "[Ln: %04d] -> %-25s | %s\n", line, "CARACTER", yytext); }

"=="|"!="|"<="|">="|"&&"|"||"|"<<"|">>"|"++"|"--"|"+="|"-="|"*="|"/="|"%="|"&="|"|="|"^="|"<<="|">>="|"->"|"::"|"+"|"-"|"*"|"/"|"%"|"<"|">"|"!"|"&"|"|"|"^"|"~"|"="|"?"|":" { 
                            fprintf(out_file, "[Ln: %04d] -> %-25s | %s\n", line, "OPERADOR", yytext); 
                        }

"("|")"|"{"|"}"|"["|"]"|";"|","|"." { 
                            fprintf(out_file, "[Ln: %04d] -> %-25s | %s\n", line, "SEPARADOR", yytext); 
                        }

{ID}                    { fprintf(out_file, "[Ln: %04d] -> %-25s | %s\n", line, "IDENTIFICADOR", yytext); }

.                       { fprintf(out_file, "[Ln: %04d] -> %-25s | %s\n", line, "NO_RECONOCIDO", yytext); }

%%

int main(int argc, char **argv) {
    char *input_name = (argc > 1) ? argv[1] : "codigoEjemplo.c";
    yyin = fopen(input_name, "r");
    if (!yyin) {
        printf("Error: No se pudo abrir el archivo '%s'\n", input_name);
        return 1;
    }

    out_file = fopen("MyScanner.txt", "w");
    fprintf(out_file, "=== REPORTE DE ANÁLISIS LÉXICO ===\n\n");
    
    yylex(); 

    fclose(yyin);
    fclose(out_file);
    return 0;
}

int yywrap() {
    return 1;
}
