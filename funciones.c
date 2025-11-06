#include <stdio.h>
#include <string.h>
#include "funciones.h"
#define MAX_NOMBRE 25

int mostrarMenu() {
    int opcion;
    printf("\n============================================\n");
    printf("       SOFTWARE DE GESTIÓN DE INVENTARIO\n");
    printf("============================================\n");
    printf("1. Registrar productos\n");
    printf("2. Buscar producto por nombre\n");
    printf("3. Mostrar producto más caro y más barato\n");
    printf("4. Mostrar precio total y promedio\n");
    printf("5. Salir\n");
    printf(">> ");
    scanf("%d", &opcion);
    return opcion;
}

int registrarProductos(int cantidad, char nombres[][MAX_NOMBRE], float precios[], int max, int stock[]) {
    int nuevosProductos;
    printf("¿Cuántos productos desea registrar? (1-%d): ", max - cantidad);
    scanf("%d", &nuevosProductos);

    if (nuevosProductos < 1 || cantidad + nuevosProductos > max) {
        printf("Error: cantidad inválida (debe ser entre 1 y %d).\n", max - cantidad);
        return cantidad;
    }

    for (int i = cantidad; i < cantidad + nuevosProductos; i++) {
        printf("\n--- Producto %d ---\n", i + 1);
        
        printf("  Nombre: ");
        scanf("%s", nombres[i]);

        do {
            printf("  Stock: ");
            scanf("%d", &stock[i]);
            if (stock[i] < 0) {
                printf("    Error: el stock no puede ser negativo. Intente de nuevo.\n");
            }
        } while (stock[i] < 0);

        do {
            printf("  Precio: $");
            scanf("%f", &precios[i]);
            if (precios[i] < 0) {
                printf("    Error: el precio no puede ser negativo. Intente de nuevo.\n");
            }
        } while (precios[i] < 0);
    }
    printf("¡%d productos registrados con éxito!\n", nuevosProductos);
    return cantidad + nuevosProductos;
}

void calcularTotalYPromedio(float precios[], int cantidad, int stock[], float resultados[]) {
    resultados[0] = 0.0f;
    for (int i = 0; i < cantidad; i++) {
        resultados[0] += precios[i] * stock[i];
    }
    resultados[1] = (cantidad > 0) ? (resultados[0] / cantidad) : 0.0f;
}

void encontrarExtremos(float precios[], char nombres[][MAX_NOMBRE], int cantidad, 
                       char masCaro[], float resultadosCaro[], char masBarato[], float resultadosBarato[]) {
    if (cantidad == 0) {
        masCaro[0] = '\0';
        masBarato[0] = '\0';
        resultadosCaro[0] = 0.0f;
        resultadosBarato[0] = 0.0f;
        return;
    }

    int idxMax = 0, idxMin = 0;
    resultadosCaro[0] = precios[0];
    resultadosBarato[0] = precios[0];
    for (int i = 0; i < MAX_NOMBRE; i++) {
        masCaro[i] = nombres[0][i];
        masBarato[i] = nombres[0][i];
    }

    for (int i = 1; i < cantidad; i++) {
        if (precios[i] > resultadosCaro[0]) {
            resultadosCaro[0] = precios[i];
            for (int j = 0; j < MAX_NOMBRE; j++) {
                masCaro[j] = nombres[i][j];
            }
        }
        if (precios[i] < resultadosBarato[0]) {
            resultadosBarato[0] = precios[i];
            for (int j = 0; j < MAX_NOMBRE; j++) {
                masBarato[j] = nombres[i][j];
            }
        }
    }
}

void buscarProducto(char nombreBuscado[], char nombres[][MAX_NOMBRE], float precios[], int stock[], int cantidad) {
    int encontrado = 0;

    for (int i = 0; i < cantidad; i++) {
        int esIgual = 1;
        for (int j = 0; j < MAX_NOMBRE; j++) {
            if (nombres[i][j] != nombreBuscado[j]) {
                esIgual = 0;
                break;
            }
            if (nombres[i][j] == '\0' && nombreBuscado[j] == '\0') {
                break;
            }
        }

        if (esIgual) {
            printf("Producto encontrado:\n");
            printf("  Nombre: %s\n", nombres[i]);
            printf("  Precio: $%.2f\n", precios[i]);
            printf("  Stock: %d\n", stock[i]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}
