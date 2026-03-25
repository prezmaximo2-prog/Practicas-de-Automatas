#include <stdio.h>
int main() {
    float num1, num2;
    char op;
    printf("Ingrese dos números y un operador (+, -, *, /): ");
    scanf("%f %c %f", &num1, &op, &num2);
    switch(op) {
        case '+': printf("Resultado: %.2f\n", num1 + num2); break;
        case '-': printf("Resultado: %.2f\n", num1 - num2); break;
        case '*': printf("Resultado: %.2f\n", num1 * num2); break;
        case '/': 
            if(num2 != 0) printf("Resultado: %.2f\n", num1 / num2);
            else printf("Error: División por cero.\n");
            break;
        default: printf("Operador inválido.\n");
    }
    return 0;
}   
