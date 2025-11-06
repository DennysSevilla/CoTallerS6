#include <stdio.h>
#include "funciones.h"

#define MAX_PRODUCTOS 10
#define MAX_NOMBRE 25

char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
float precios[MAX_PRODUCTOS];
int cantidad = 0;
int stock[MAX_PRODUCTOS];

int main() {
    int opcion;
    float total, promedio;
    char masCaro[MAX_NOMBRE], masBarato[MAX_NOMBRE];
    float precioMax, precioMin;

    printf("BIENVENIDO AL SISTEMA DE INVENTARIO\n");

    do {
        mostrarMenu(&opcion);

        switch (opcion) {
            case 1:
                registrarProductos(&cantidad, nombres, precios, MAX_PRODUCTOS, stock);
                break;

            case 2:
             
                break;

            case 3:
                if (cantidad == 0) printf("No hay productos.\n");
                else {
                    encontrarExtremos(precios, nombres, cantidad, masCaro, &precioMax, masBarato, &precioMin);
                    printf("Más caro: %s - $%.2f\n", masCaro, precioMax);
                    printf("Más barato: %s - $%.2f\n", masBarato, precioMin);
                }
                break;

            case 4:
                if (cantidad == 0) printf("No hay productos.\n");
                else {
                    calcularTotalYPromedio(precios, cantidad, stock, &total, &promedio);
                    printf("Total: $%.2f\n", total);
                    printf("Promedio: $%.2f\n", promedio);
                }
                break;

            case 5:
                printf("¡Adiós!\n");
                break;

            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 5);

    return 0;
}
