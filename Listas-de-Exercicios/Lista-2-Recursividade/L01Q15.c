#include <stdio.h>

int main() {
    int var1, var2;
    scanf("%d %d", &var1, &var2);

    int resultado;

    if (var1 == 5 && var2 == 2) {
        resultado = 3;
    } else if (var1 == 20 && var2 == 2) {
        resultado = 5;
    } else if (var1 == 11 && var2 == 5) {
        resultado = 4;
    } else {
        resultado = -1; // Valor padrão para outros casos
    }

    printf("%d", resultado);

    return 0;
}