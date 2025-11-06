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

    do {
        opcion = mostrarMenu();

        switch (opcion) {
            case 1:
                cantidad = registrarProductos(cantidad, nombres, precios, MAX_PRODUCTOS, stock);
                break;

            case 2:
                if (cantidad == 0) {
                printf("No hay productos registrados.\n");
                } else {
                char nombreBuscado[MAX_NOMBRE];
                printf("Ingrese el nombre del producto a buscar: ");
                scanf("%s", nombreBuscado);
                buscarProducto(nombreBuscado, nombres, precios, stock, cantidad);
                }
                break;

            case 3:
                if (cantidad == 0) {
                    printf("No hay productos.\n");
                } else {
                    char masCaro[MAX_NOMBRE], masBarato[MAX_NOMBRE];
                    float resultadosCaro[1], resultadosBarato[1];
                    encontrarExtremos(precios, nombres, cantidad, masCaro, resultadosCaro, masBarato, resultadosBarato);
                    printf("Más caro: %s - $%.2f\n", masCaro, resultadosCaro[0]);
                    printf("Más barato: %s - $%.2f\n", masBarato, resultadosBarato[0]);
                }
                break;

            case 4:
                if (cantidad == 0) {
                    printf("No hay productos.\n");
                } else {
                    float resultados[2];
                    calcularTotalYPromedio(precios, cantidad, stock, resultados);
                    printf("Total: $%.2f\n", resultados[0]);
                    printf("Promedio: $%.2f\n", resultados[1]);
                }
                break;

            case 5:
                break;

            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 5);

    return 0;
}
