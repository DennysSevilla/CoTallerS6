#include <stdio.h>
#include "funciones.h"
#define MAX_NOMBRE 25

void mostrarMenu(int opcion) {
    printf("\n============================================\n");
    printf("       SOFTWARE DE GESTIÓN DE INVENTARIO\n");
    printf("============================================\n");
    printf("1. Registrar productos\n");
    printf("2. Buscar producto por nombre\n");
    printf("3. Mostrar producto más caro y más barato\n");
    printf("4. Mostrar precio total y promedio\n");
    printf("5. Salir\n");
    printf(">> ");
    scanf("%d", opcion);
}

void registrarProductos(int cantidad, char nombres[][MAX_NOMBRE], float precios[], int max, int stock[]) {
    printf("¿Cuántos productos desea registrar? (1-%d): ", max);
    scanf("%d", cantidad);

    if (cantidad < 1 || cantidad > max) {
        printf("Error: cantidad inválida (debe ser entre 1 y %d).\n", max);
        cantidad = 0;
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        printf("\n--- Producto %d ---\n", i + 1);
        
        printf("  Nombre: ");
        scanf("%s", nombres[i]);

        int temp_stock;
        do {
            printf("  Stock: ");
            scanf("%d", &temp_stock);
            if (temp_stock < 0) {
                printf("    Error: el stock no puede ser negativo. Intente de nuevo.\n");
            }
        } while (temp_stock < 0);
        stock[i] = temp_stock;

        float temp_precio;
        do {
            printf("  Precio: $");
            scanf("%f", &temp_precio);
            if (temp_precio < 0) {
                printf("    Error: el precio no puede ser negativo. Intente de nuevo.\n");
            }
        } while (temp_precio < 0);
        precios[i] = temp_precio;
    }
    printf("¡%d productos registrados con éxito!\n", cantidad);
}

void calcularTotalYPromedio(float precios[], int cantidad, int stock[], float total, float promedio) {
    total = 0.0f;
    for (int i = 0; i < cantidad; i++) {
        total += precios[i] * stock[i];
    }
    promedio = (cantidad > 0) ? (total / cantidad) : 0.0f;
}

void encontrarExtremos(float precios[], char nombres[][MAX_NOMBRE], int cantidad, 
                       char masCaro, float precioMax, char masBarato, float precioMin) {
    if (cantidad == 0) {
        copiarCadena(masCaro, "N/A", MAX_NOMBRE);
        copiarCadena(masBarato, "N/A", MAX_NOMBRE);
        precioMax = precioMin = 0.0f;
        return;
    }

    int idxMax = 0, idxMin = 0;
    precioMax = precios[0];
    precioMin = precios[0];
    copiarCadena(masCaro, nombres[0], MAX_NOMBRE);
    copiarCadena(masBarato, nombres[0], MAX_NOMBRE);

    for (int i = 1; i < cantidad; i++) {
        if (precios[i] > precioMax) {
            precioMax = precios[i];
            copiarCadena(masCaro, nombres[i], MAX_NOMBRE);
        }
        if (precios[i] < precioMin) {
            precioMin = precios[i];
            copiarCadena(masBarato, nombres[i], MAX_NOMBRE);
        }
    }
}
