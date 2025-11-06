
void mostrarMenu(int opcion);
void registrarProductos(int cantidad, char nombres[][25], float precios[], int max, int stock[]);
void calcularTotalYPromedio(float precios[], int cantidad, int stock[], float total, float promedio);
void encontrarExtremos(float precios[], char nombres[][25], int cantidad, 
                       char masCaro, float precioMax, char masBarato, float precioMin);
void buscarProducto(char nombres[][25], float precios[], int cantidad, int stock[], char busqueda);
int compararCadenas(const char cad1, const char cad2);
void copiarCadena(char destino, const char origen, int tamMax);


