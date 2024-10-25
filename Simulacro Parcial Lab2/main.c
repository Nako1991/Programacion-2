#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int numeroCliente;
    char nombreYApellido;
    int numeroPedido;
    float montoCompra;
} stRegistroCompraCliente;

typedef struct {
    int numeroCliente;
    char nombreYApellido;
} stCliente;

typedef struct {
    int numeroPedido;
    stCliente cliente;
    float montoCompra;
    struct stNodoPedido *siguiente;
} stNodoPedido;

stNodoPedido *copiarArchivoPedidosANodo(char nombreArchivo[], stNodoPedido *lista);
stNodoPedido *crearNodoPedido(stRegistroCompraCliente *cliente);
stNodoPedido *agregarNodoPedido(stNodoPedido *lista, stNodoPedido *nodoAInsertar);

int main() {
    stNodoPedido *lista;
    inicializarLista(&lista);
    //printf("\nlista: %p", lista); //debug
    char nombreArchivo[] = { "registroCompraCliente.dat" };
    lista = copiarArchivoPedidosANodo(nombreArchivo, lista);
    return 0;
}
void inicializarLista(stNodoPedido **lista) {
    *lista = NULL;
}
stNodoPedido *copiarArchivoPedidosANodo(char nombreArchivo[], stNodoPedido *lista) {
    stNodoPedido *bufferNodo;
    stRegistroCompraCliente *bufferPedido;
    FILE *archivoPedidos = fopen(archivoPedidos, "rb");
    if( archivoPedidos == NULL )
        printf("\nEl archivo no existe.");
    while( !feof(archivoPedidos) ) {
        fread(bufferPedido, sizeof(stRegistroCompraCliente), 1, archivoPedidos);
        if( !feof(archivoPedidos) ) {
            bufferNodo = crearNodoPedido(bufferPedido);
            lista = agregarNodoPedido(lista, bufferNodo);
        }
    }
    return lista;
}
stNodoPedido *crearNodoPedido(stRegistroCompraCliente *cliente) {
    stNodoPedido *nodoNuevo;
    nodoNuevo->cliente.numeroCliente = cliente->numeroCliente;
    strcpy(nodoNuevo->cliente.nombreYApellido, cliente->nombreYApellido);
    nodoNuevo->montoCompra = cliente->montoCompra;
    nodoNuevo->numeroPedido = cliente->numeroPedido;
    nodoNuevo->siguiente = NULL;
    return nodoNuevo;
}
stNodoPedido *agregarNodoPedido(stNodoPedido *lista, stNodoPedido *nodoAInsertar) {

}
