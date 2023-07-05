#include <stdio.h>

int main() {
    int opcion;
    int num;
    int inicio, fin;
    int variable1, variable2, sum;

    do {
        printf("Menú:\n");
        printf("1. Comprobar si un número es perfecto\n");
        printf("2. Determinar la cantidad de números perfectos en un intervalo e imprimirlos\n");
        printf("3. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese un numero: ");
                scanf("%d", &num);

                sum = 0;
                for (variable1 = 1; variable1 <= num / 2; variable1++) {
                    if (num % variable1 == 0) {
                        sum += variable1;
                    }
                }

                if (sum == num) {
                    printf("%d es un número perfecto.\n", num);
                } else {
                    printf("%d no es un número perfecto.\n", num);
                }

                break;
            case 2:
                printf("Ingrese el inicio del intervalo: ");
                scanf("%d", &inicio);
                printf("Ingrese el fin del intervalo: ");
                scanf("%d", &fin);

                printf("Números perfectos en el intervalo [%d, %d]:\n", inicio, fin);
                for (variable1 = inicio; variable1 <= fin; variable1++) {
                    sum = 0;
                    for (variable2 = 1; variable2 <= variable1 / 2; variable2++) {
                        if (variable1 % variable2 == 0) {
                            sum += variable2;
                        }
                    }
                    if (sum == variable1) {
                        printf("%d ", variable1);
                    }
                }
                printf("\n");

                break;
            case 3:
                printf("Hasta Pronto...\n");
                break;
            default:
                printf("Opción inválida. Por favor, seleccione una opción válida.\n");
                break;
        }
    } while (opcion != 3);

    return 0;
}
