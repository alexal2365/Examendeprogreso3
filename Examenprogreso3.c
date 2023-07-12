#include <stdio.h>
#include <string.h>

#define MAX_USUARIOS 3
#define MAX_ENTRADAS_GENERAL 100
#define MAX_ENTRADAS_VIP 50
#define MAX_ENTRADAS_BACKSTAGE 20
#define PRECIO_ENTRADA_GENERAL 50
#define PRECIO_ENTRADA_VIP 100
#define PRECIO_ENTRADA_BACKSTAGE 200

int main() {
    char usuario1[] = "usuario1";
    char contrasena1[] = "contrasena1";
    char usuario2[] = "usuario2";
    char contrasena2[] = "contrasena2";
    char usuario3[] = "usuario3";
    char contrasena3[] = "contrasena3";

    int intentos = 3;
    char usuario[20];
    char contrasena[20];

    do {
        printf("Usuario: ");
        scanf("%s", usuario);

        printf("Contraseña: ");
        scanf("%s", contrasena);

        int credencialesValidas = 0;

        if (strcmp(usuario, usuario1) == 0 && strcmp(contrasena, contrasena1) == 0) {
            credencialesValidas = 1;
        } else if (strcmp(usuario, usuario2) == 0 && strcmp(contrasena, contrasena2) == 0) {
            credencialesValidas = 1;
        } else if (strcmp(usuario, usuario3) == 0 && strcmp(contrasena, contrasena3) == 0) {
            credencialesValidas = 1;
        }

        if (credencialesValidas) {
            break;
        } else {
            intentos--;
            printf("Usuario o contraseña incorrectos, intento #%d\n", intentos);
        }

        if (intentos == 0) {
            printf("Imposible ingresar.\n");
            return 0;
        }
    } while (intentos > 0);

    int opcion;
    int entradasVendidas = 0;
    int ingresosGenerados = 0;

    do {
        printf("\n--- Menú ---\n");
        printf("1. Venta de Entradas\n");
        printf("2. Estadísticas de Ventas\n");
        printf("3. Salir\n");

        printf("Opción: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            char tipoEntrada[20];
            int cantidadEntradas;

            printf("Tipo de entrada (General, VIP, Backstage): ");
            scanf("%s", tipoEntrada);

            printf("Cantidad de entradas: ");
            scanf("%d", &cantidadEntradas);

            int maxEntradas;
            int precioEntrada;

            if (strcmp(tipoEntrada, "General") == 0) {
                maxEntradas = MAX_ENTRADAS_GENERAL;
                precioEntrada = PRECIO_ENTRADA_GENERAL;
            } else if (strcmp(tipoEntrada, "VIP") == 0) {
                maxEntradas = MAX_ENTRADAS_VIP;
                precioEntrada = PRECIO_ENTRADA_VIP;
            } else if (strcmp(tipoEntrada, "Backstage") == 0) {
                maxEntradas = MAX_ENTRADAS_BACKSTAGE;
                precioEntrada = PRECIO_ENTRADA_BACKSTAGE;
            } else {
                printf("Tipo de entrada no válido.\n");
                continue;
            }

            if (cantidadEntradas > maxEntradas) {
                printf("No hay suficientes entradas disponibles.\n");
                continue;
            }

            entradasVendidas += cantidadEntradas;
            ingresosGenerados += cantidadEntradas * precioEntrada;

            printf("Entradas vendidas: %d\n", entradasVendidas);
            printf("Ingresos generados: $%d\n", ingresosGenerados);
        } else if (opcion == 2) {
            printf("Total de entradas vendidas: %d\n", entradasVendidas);
            printf("Total de ingresos generados: $%d\n", ingresosGenerados);
        } else if (opcion != 3) {
            printf("Opción no válida.\n");
        }
    } while (opcion != 3);

    return 0;
}
