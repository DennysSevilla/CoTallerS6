int mostrarMenu();
int registrarProductos(int cantidad, char nombres[][25], float precios[], int max, int stock[]);
void calcularTotalYPromedio(float precios[], int cantidad, int stock[], float resultados[]);
void encontrarExtremos(float precios[], char nombres[][25], int cantidad, 
                       char masCaro[], float resultadosCaro[], char masBarato[], float resultadosBarato[]);
