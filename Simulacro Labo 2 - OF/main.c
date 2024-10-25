#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <malloc.h>

#define DIM 30

typedef struct {
    int numeroCliente;
    char nombreYApellido[DIM];
    int numeroPedido;
    float montoCompra;
} stCompra;

typedef struct {
    int numeroCliente;
    char nombreYApellido[DIM];
} stCliente;

typedef struct {
    int numeroPedido;
    stCliente cliente;
    float montoCompra;
    struct stNodoPedido *anterior;
    struct stNodoPedido *siguiente;
} stNodoPedido;

stNodoPedido *copiarComprasDeArchivoALista(char nombreArchivo[], stNodoPedido *lista);
stNodoPedido *copiarCompraDeArchivoALista(stNodoPedido *lista, stCompra compraACopiar);
stNodoPedido *crearNodo(stCompra nuevaCompra);
stNodoPedido *insertarNodoAlComienzo(stNodoPedido *lista, stNodoPedido *nodoAInsertar);
stNodoPedido *liberarLista(stNodoPedido *lista);
stNodoPedido *eliminarNodoAlComienzo(stNodoPedido *lista);
stNodoPedido *ingresarPedido(stNodoPedido *lista);
float calcularTotalMontoCompra(stNodoPedido *lista);
stCompra *copiarPedidosMayoresA5000(stNodoPedido *lista, int *cantidadPedidos);

int main() {
    char nombreArchivo[] = { "registroCompraCliente.dat" };

    stNodoPedido *lista;
    inicializarLista(&lista);

    lista = copiarComprasDeArchivoALista(nombreArchivo, lista);
    mostrarLista(lista);

    printf("\n......................................................................\n");
    //lista = liberarLista(lista);
    //lista = ingresarPedido(lista);
    //mostrarLista(lista);

    float montoTotal = calcularTotalMontoCompra(lista);
    printf("\n\n Total monto de compra: %.2f", montoTotal);

    printf("\n......................................................................\n");
    int cantidadPedidos = calcularCantidadPedidos(lista);
    printf("\n\n Cantidad de pedidos: %i", cantidadPedidos);
    stCompra *arregloCompras = copiarPedidosMayoresA5000(lista, &cantidadPedidos);
    mostrarPedidos(arregloCompras, cantidadPedidos);
    printf("\n\n Cantidad de pedidos: %i", cantidadPedidos);

    return 0;
}
void inicializarLista(stNodoPedido **lista) {
    *lista = NULL;
}
stNodoPedido *copiarComprasDeArchivoALista(char nombreArchivo[], stNodoPedido *lista) {
    stCompra bufferCompra;
    stNodoPedido *nodoACopiar;
    FILE *archivoCompras = fopen(nombreArchivo, "rb");
    if( archivoCompras == NULL )
        printf("\nEl archivo no existe.");
    while( !feof(archivoCompras) ) {
        fread(&bufferCompra, sizeof(stCompra), 1, archivoCompras);
        if( !feof(archivoCompras) ){
            nodoACopiar = crearNodo(bufferCompra);
            lista = insertarNodoAlComienzo(lista, nodoACopiar);
        }
    }
    fclose(archivoCompras);
    return lista;
}
stNodoPedido *insertarNodoAlComienzo(stNodoPedido *lista, stNodoPedido *nodoAInsertar) {
    if( lista == NULL )
        lista = nodoAInsertar;
    else if( lista != NULL)
        nodoAInsertar->siguiente = lista;
        lista->anterior = nodoAInsertar;
        lista = nodoAInsertar;
    return lista;
}
stNodoPedido *crearNodo(stCompra nuevaCompra) {
    stNodoPedido *nuevoNodo = (stNodoPedido *) malloc(sizeof(stNodoPedido));
    nuevoNodo->anterior = NULL;
    nuevoNodo->siguiente = NULL;
    strcpy(nuevoNodo->cliente.nombreYApellido, nuevaCompra.nombreYApellido);
    nuevoNodo->cliente.numeroCliente = nuevaCompra.numeroCliente;
    nuevoNodo->numeroPedido = nuevaCompra.numeroPedido;
    nuevoNodo->montoCompra = nuevaCompra.montoCompra;
    return nuevoNodo;
}
void mostrarNodo(stNodoPedido *nodoAMostrar) {
    printf("\n--------------------------------------------------\n");
    printf("\nNumero de cliente: %i", nodoAMostrar->cliente.numeroCliente);
    printf("\nNombre Y Apellido: %s", nodoAMostrar->cliente.nombreYApellido);
    printf("\nNumero pedido: %i", nodoAMostrar->numeroPedido);
    printf("\nMonto Compra: %.2f", nodoAMostrar->montoCompra);
    printf("\nAnterior: %p", nodoAMostrar->anterior); //debug
    printf("\nActual: %p", nodoAMostrar); //debug
    printf("\nSiguiente: %p", nodoAMostrar->siguiente); //debug
    printf("\n--------------------------------------------------\n");
}
void mostrarLista(stNodoPedido *lista) {
    if( lista == NULL )
        printf("\n\nLa lista esta vacia.");
    while( lista != NULL) {
        mostrarNodo(lista);
        lista = lista->siguiente;
    }
}
stNodoPedido *liberarLista(stNodoPedido *lista) {
    while( lista != NULL )
        lista = eliminarNodoAlComienzo(lista);
    return NULL;
}
stNodoPedido *eliminarNodoAlComienzo(stNodoPedido *lista) {
    if( lista != NULL ) {
        stNodoPedido *auxLista = lista;
        lista = lista->siguiente;
        if( lista != NULL )
            lista->anterior = NULL;
        free(auxLista);
    }
    return lista;
}
stNodoPedido *ingresarPedido(stNodoPedido *lista) {
    stNodoPedido *nuevoNodo;
    stCompra bufferCompra;
    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\nIngrese el numero de cliente:");
    fflush(stdin);
    scanf("%i", &bufferCompra.numeroCliente);
    printf("\nIngrese el Nombre y Apellido:");
    fflush(stdin);
    gets(bufferCompra.nombreYApellido);
    printf("\nIngrese el numero de podido:");
    fflush(stdin);
    scanf("%i", &bufferCompra.numeroPedido);
    printf("\nIngrese el monto de compra:");
    fflush(stdin);
    scanf("%f", &bufferCompra.montoCompra);
    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    nuevoNodo = crearNodo(bufferCompra);
    lista = insertarNodoAlComienzo(lista, nuevoNodo);
    return lista;
}
float calcularTotalMontoCompra(stNodoPedido *lista) {
    float totalMonto;
    if( lista == NULL )
        return 0;
    else
        totalMonto = lista->montoCompra + calcularTotalMontoCompra(lista->siguiente);
    return totalMonto;
}
int calcularCantidadPedidos(stNodoPedido *lista) {
    int cantidadPedidos = 0;
    while( lista != NULL ) {
        cantidadPedidos++;
        lista = lista->siguiente;
    }
    return cantidadPedidos;
}
stCompra *copiarPedidosMayoresA5000(stNodoPedido *lista, int *cantidadPedidos) {
    stCompra *arregloCompras = (stCompra *) malloc(sizeof(stCompra) * (*cantidadPedidos));
    int nuevaCantidadPedidos = 0;
    if( arregloCompras == NULL )
        printf("\nError al asignar la memoria.");
    if( lista == NULL )
        printf("\nLa lista esta vacia.");
    else {
        while( lista != NULL ) {
            if( lista->montoCompra > 5000 ) {
                copiarPedidoAArrayDinamico(arregloCompras, nuevaCantidadPedidos, lista);
                nuevaCantidadPedidos++;
            }
            lista = lista->siguiente;
        }
    }
    *cantidadPedidos = nuevaCantidadPedidos;
    realloc(arregloCompras, sizeof(sizeof(stCompra) * (*cantidadPedidos)));
    return arregloCompras;
}
void copiarPedidoAArrayDinamico(stCompra *arregloCompras, int index, stNodoPedido *nodoAInsertar) {
    arregloCompras[index].numeroCliente = nodoAInsertar->cliente.numeroCliente;
    strcpy(arregloCompras[index].nombreYApellido, nodoAInsertar->cliente.nombreYApellido);
    arregloCompras[index].numeroPedido = nodoAInsertar->numeroPedido;
    arregloCompras[index].montoCompra = nodoAInsertar->montoCompra;
}
void mostrarPedido(stCompra *arregloCompras, int index) {
    printf("\n--------------------------------------------------\n");
    printf("\nNumero de cliente: %i", arregloCompras[index].numeroCliente);
    printf("\nNombre Y Apellido: %s", arregloCompras[index].nombreYApellido);
    printf("\nNumero pedido: %i", arregloCompras[index].numeroPedido);
    printf("\nMonto Compra: %.2f", arregloCompras[index].montoCompra);
    printf("\n--------------------------------------------------\n");
}
void mostrarPedidos(stCompra *arregloCompras, int cantidadCompras) {
    for( int i = 0 ; i < cantidadCompras ; i++ )
        mostrarPedido(arregloCompras, i);
}
