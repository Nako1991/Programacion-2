#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define DIM 30
///Estructuras

typedef struct {
    int nroCliente;
    int nroPedido;
    float montoCompra;
    char nombreYapellido[DIM];
}RegistroCompraCliente;

typedef struct {
    int nroCliente;
    char nombreYapellido[DIM];
}Cliente;

typedef struct {
    Cliente infoCliente;
    int nroPedido;
    float montoCompra;

    struct NodoDoblePedido *ptrSiguiente;
    struct NodoDoblePedido *ptrAnterior;
}NodoDoblePedido;

///Prototipado
NodoDoblePedido *inicializarLista();
NodoDoblePedido *crearNodo(RegistroCompraCliente cliente);
NodoDoblePedido *buscarUltimoNodo(NodoDoblePedido *ptrLista);
NodoDoblePedido *agregarNodosAlPrincipio(NodoDoblePedido *ptrLista, NodoDoblePedido *nuevoNodo);
NodoDoblePedido *agregarNodosAlFinal(NodoDoblePedido *ptrLista, NodoDoblePedido *nuevoNodo);

/*--------------------------------------------------------------------------------------------*/
int main() {
    char nombreArchivoCompraCliente[] = {"registroCompraCliente.dat"};

    mostrarArchivo(nombreArchivoCompraCliente);

    return 0;
}
/*--------------------------------------------------------------------------------------------*/
NodoDoblePedido *inicializarLista() {
    return NULL;
}

NodoDoblePedido *crearNodo(RegistroCompraCliente cliente) {

    NodoDoblePedido *nuevoNodo = (NodoDoblePedido *) malloc(sizeof(NodoDoblePedido));

    strcpy(nuevoNodo->infoCliente.nombreYapellido, cliente.nombreYapellido);
    nuevoNodo->infoCliente.nroCliente = cliente.nroCliente;
    nuevoNodo->nroPedido = cliente.nroPedido;
    nuevoNodo->montoCompra = cliente.montoCompra;
    nuevoNodo->ptrAnterior = NULL;
    nuevoNodo->ptrSiguiente = NULL;

    return nuevoNodo;
}

NodoDoblePedido *agregarNodosAlPrincipio(NodoDoblePedido *ptrLista, NodoDoblePedido *nuevoNodo) {

    if(ptrLista == NULL) ptrLista = nuevoNodo;

    else {
        nuevoNodo->ptrAnterior = ptrLista;
        ptrLista->ptrAnterior = nuevoNodo;
        ptrLista = nuevoNodo;
    }
    return ptrLista;
}

NodoDoblePedido *agregarNodosAlFinal(NodoDoblePedido *ptrLista, NodoDoblePedido *nuevoNodo) {

    if(ptrLista == NULL) ptrLista = nuevoNodo;

    else {
        NodoDoblePedido *ultimoNodo = buscarUltimoNodo(ptrLista);
        ultimoNodo->ptrSiguiente = nuevoNodo;
        nuevoNodo->ptrSiguiente = NULL;
    }
    return ptrLista;
}

NodoDoblePedido *buscarUltimoNodo(NodoDoblePedido *ptrLista) {

    NodoDoblePedido *ptrSeguidor = ptrLista;

    if(ptrLista != NULL) while(ptrSeguidor->ptrSiguiente != NULL) ptrSeguidor = ptrSeguidor->ptrSiguiente;

    return ptrSeguidor;
}

void mostrarRegistroCompraCliente(RegistroCompraCliente unCliente) {
    printf("Nombre y Apellido --> |%s| \n", unCliente.nombreYapellido);
    printf("Nro Pedido --> |%i| \n", unCliente.nroPedido);
    printf("Nro Cliente --> |%i|\n", unCliente.nroCliente);
    printf("Total a Pagar --> |%.2f|\n\n\n", unCliente.montoCompra);
}

void mostrarArchivo(char nombreArchivo[]) {

    RegistroCompraCliente unCliente;

    FILE *ptrArchivo = fopen(nombreArchivo, "rb");

    if(ptrArchivo == NULL) printf("Error al abrir el archivo \n");

    else {
        while(!feof(ptrArchivo)) {

            fread(&unCliente, sizeof(RegistroCompraCliente), 1, ptrArchivo);

            if(!feof(ptrArchivo)) mostrarRegistroCompraCliente(unCliente);
        }
        fclose(ptrArchivo);
    }
}
