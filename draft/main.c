#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct {
    int numeroCliente;
    char nombreYApellido[30];
    int numeroPedido;
    float montoCompra;
} stRegistroCompraCliente;

typedef struct {
    int numeroCliente;
    char nombreYApellido[30];
} stCliente;

typedef struct {
    int numeroPedido;
    stCliente cliente;
    float montoCompra;
    struct stNodoPedido *siguiente;
} stNodoPedido;

stNodoPedido *inicializarLista();
stNodoPedido *crearNodoPedido(stRegistroCompraCliente );
stNodoPedido *agregarNodoPedido(stNodoPedido * , stNodoPedido * );
stNodoPedido *crearListaPedidos(stNodoPedido *listaPedidos, char nombreArchivo[]);
stNodoPedido *liberarLista(stNodoPedido *listaALiberar);
stNodoPedido *ingresarPedido(stNodoPedido *listaACargar);
float calcularTotalMontoCompraRecursivo(stNodoPedido *listaPedidos, float suma);
stRegistroCompraCliente *copiarPedidosMayores5000(stNodoPedido *listaPedidos, int *validosPedidos);

void main() {
    stNodoPedido *listaPedidos;
    printf("\nInicializando lista...");
    listaPedidos = inicializarLista();

    char nombreArchivo[] = { "registroCompraCliente.dat" };
    float sumaMonto = 0;
    stRegistroCompraCliente *arregloPedidosGrandes;
    int validosPedidos = 0;

    printf("\nCopiando de archivo a lista...");
    listaPedidos = crearListaPedidos(listaPedidos, nombreArchivo); //EJERCICIO 3

    mostrarListaPedidos(listaPedidos); //EJERCICIO 4

    //printf("\nLiberando lista... \n");
    //listaPedidos = liberarLista(listaPedidos); //EJERCICIO 5
    //mostrarListaPedidos(listaPedidos);

    //listaPedidos = ingresarPedido(listaPedidos); //EJERCICIO 6
    //mostrarListaPedidos(listaPedidos);

    sumaMonto = calcularTotalMontoCompraRecursivo(listaPedidos, 0); //EJERCICIO 7
    printf("\nMonto total sumado de todas las cuentas: %f", sumaMonto);

    printf("\nCalculando cantidad total de pedidos...");
    validosPedidos = calcularValidosEnLista(listaPedidos);
    printf("\nvalidosPedidos: %i", validosPedidos);

    arregloPedidosGrandes = copiarPedidosMayores5000(listaPedidos, &validosPedidos); //EJERCICIO 8
    printf("\nValidosPedidos: %i", validosPedidos);
    mostrarPedidosArreglo(arregloPedidosGrandes, validosPedidos); //EJERCICIO 9

    return 0;
}
stNodoPedido *inicializarLista() {
    return NULL;
}
stNodoPedido *crearListaPedidos(stNodoPedido *listaPedidos, char nombreArchivo[]) {
    stNodoPedido *bufferNodo;
    stRegistroCompraCliente bufferCliente;
    FILE *archivoRegistroClientes = fopen(nombreArchivo, "r");
    printf("\n listaPedidos: %p", listaPedidos); //debug
    if( archivoRegistroClientes == NULL )
        printf("\nEl archivo no existe.");
    else while ( !feof(archivoRegistroClientes) ){
        fread(&bufferCliente, sizeof(stRegistroCompraCliente), 1, archivoRegistroClientes);
        if( !feof(archivoRegistroClientes) )
            mostrarRegistroCompraCliente(bufferCliente); //debug
            bufferNodo = crearNodoPedido(bufferCliente); //EJERCICIO 1
            listaPedidos = agregarNodoPedido(listaPedidos, bufferNodo); //EJERCICIO 2
    }
    fclose(archivoRegistroClientes);
    return listaPedidos;
}
void mostrarRegistroCompraCliente(stRegistroCompraCliente clienteAMostrar) {
    printf("\n--------------------------------------------------\n");
    printf("\nCliente:");
    printf("\n Numero de cliente: %i", clienteAMostrar.numeroCliente);
    printf("\n Nombre y apellido: %s", clienteAMostrar.nombreYApellido);
    printf("\n Numero de pedido: %i", clienteAMostrar.numeroPedido);
    printf("\n Monto de compra: %f", clienteAMostrar.montoCompra);
    printf("\n--------------------------------------------------\n");
}
stNodoPedido *crearNodoPedido(stRegistroCompraCliente cliente) {
    stNodoPedido *nodoNuevo = (stNodoPedido *) malloc(sizeof(stNodoPedido));
    //printf("\n numero pedido: %i", cliente.numeroCliente); //debug
    nodoNuevo->numeroPedido = cliente.numeroPedido;
    nodoNuevo->montoCompra = cliente.montoCompra;
    nodoNuevo->cliente.numeroCliente = cliente.numeroPedido;
    strcpy(nodoNuevo->cliente.nombreYApellido, cliente.nombreYApellido);
    nodoNuevo->siguiente = NULL;
    return nodoNuevo;
}
void mostrarNodo(stNodoPedido *nodoAMostrar) {
    printf("\n--------------------------------------------------\n");
    printf("\nNodo:");
    printf("\n Nombre y apellido: %s", nodoAMostrar->cliente.nombreYApellido);
    printf("\n Numero de cliente: %i", nodoAMostrar->cliente.numeroCliente);
    printf("\n Numero de pedido: %i", nodoAMostrar->numeroPedido);
    printf("\n Monto de compra: %f", nodoAMostrar->montoCompra);
    printf("\n Siguiente: %p", nodoAMostrar->siguiente);
    printf("\n--------------------------------------------------\n");
}
stNodoPedido *agregarNodoPedido(stNodoPedido *listaPedidos, stNodoPedido *nodoAInsertar) {
    stNodoPedido *indexListaPedidos = listaPedidos;
    if( listaPedidos == NULL )
        listaPedidos = nodoAInsertar;
    else {
        while( indexListaPedidos->siguiente != NULL )
            indexListaPedidos = indexListaPedidos->siguiente;
        indexListaPedidos->siguiente = nodoAInsertar;
    }
    return listaPedidos;
}
void mostrarListaPedidos(stNodoPedido *listaAMostrar) {
    if( listaAMostrar == NULL )
        printf("\nLa lista esta vacia.\n");
    else if( listaAMostrar != NULL && listaAMostrar->siguiente == NULL )
        mostrarNodo(listaAMostrar);
    else while( listaAMostrar->siguiente != NULL ) {
        mostrarNodo(listaAMostrar);
        listaAMostrar = listaAMostrar->siguiente;
    }
}
stNodoPedido *liberarLista(stNodoPedido *listaALiberar) {
    stNodoPedido *indexAnteriorLista;
    //printf("\nlistaALiberar: %p", listaALiberar); //debug
    while ( listaALiberar->siguiente != NULL ) {
        indexAnteriorLista = listaALiberar;
        listaALiberar = listaALiberar->siguiente;
        //printf("\nLiberando indexListaAnterior: "); //debug
        free(indexAnteriorLista);
        //printf("\nindexAnteriorLista: %p", indexAnteriorLista); //debug
    }
    //printf("\nLiberando listaALiberar...");
    free(listaALiberar);
    return NULL;
}
stNodoPedido *ingresarPedido(stNodoPedido *listaACargar) {
    stRegistroCompraCliente bufferCliente;
    stNodoPedido *nuevoNodo;
    printf("\nCargando un pedido nuevo...");
    printf("\nIngrese el nombre y apellido del cliente: ");
    fflush(stdin);
    gets(bufferCliente.nombreYApellido);
    printf("\nIngrese el numero de cliente: ");
    fflush(stdin);
    scanf("%i", &bufferCliente.numeroCliente);
    printf("\nIngrese el numero de pedido: ");
    fflush(stdin);
    scanf("%i", &bufferCliente.numeroPedido);
    printf("\nIngrese el monto de compra del pedido: ");
    fflush(stdin);
    scanf("%f", &bufferCliente.montoCompra);
    nuevoNodo = crearNodoPedido(bufferCliente);
    listaACargar = agregarNodoPedido(listaACargar, nuevoNodo);
    return listaACargar;
}
float calcularTotalMontoCompraRecursivo(stNodoPedido *listaPedidos, float suma) {
    if( listaPedidos == NULL )
        return 0;
    else {
        //printf("\nsuma: %f", suma); //debug
        suma = suma + calcularTotalMontoCompraRecursivo(listaPedidos->siguiente, listaPedidos->montoCompra);
    }
    return suma;
}
int calcularValidosEnLista(stNodoPedido *listaPedidos) {
    int validosPedidos = 0;
    if( listaPedidos == NULL )
        printf("\nLa lista esta vacia.");
    if( listaPedidos != NULL && listaPedidos->siguiente == NULL )
        validosPedidos++;
    else while( listaPedidos->siguiente != NULL) {
        validosPedidos++;
        listaPedidos = listaPedidos->siguiente;
    }
    return validosPedidos;
}
stRegistroCompraCliente *copiarPedidosMayores5000(stNodoPedido *listaPedidos, int *validosPedidos) {
    stRegistroCompraCliente *arregloPedidosGrandes = (stRegistroCompraCliente *) malloc(sizeof(stRegistroCompraCliente) * (*validosPedidos));
    int i = 0; //indice del arreglo de Pedidos
    if( listaPedidos == NULL )
        printf("\nLa lista esta vacia.");
    if( (listaPedidos != NULL && listaPedidos->siguiente == NULL) && listaPedidos->montoCompra > 5000 ) {
        copiarRegistroPedidoAArray(arregloPedidosGrandes, listaPedidos, i);
        listaPedidos = listaPedidos->siguiente;
        i++;
    }
    else while( (listaPedidos->siguiente != NULL) && listaPedidos->montoCompra > 5000 ) {
        copiarRegistroPedidoAArray(arregloPedidosGrandes, listaPedidos, i);
        listaPedidos = listaPedidos->siguiente;
        i++;
    }
    *validosPedidos = i;
    (stRegistroCompraCliente *) realloc(arregloPedidosGrandes, sizeof(stRegistroCompraCliente) * (*validosPedidos));
    return arregloPedidosGrandes;
}
void copiarRegistroPedidoAArray(stRegistroCompraCliente *arregloPedidos, stNodoPedido *listaPedidos, int indice) {
    arregloPedidos[indice].numeroCliente = listaPedidos->cliente.numeroCliente;
    strcpy(arregloPedidos[indice].nombreYApellido, listaPedidos->cliente.nombreYApellido);
    arregloPedidos[indice].numeroPedido = listaPedidos->cliente.numeroCliente;
    arregloPedidos[indice].montoCompra = listaPedidos->cliente.numeroCliente;
}
void mostrarPedidosArreglo(stRegistroCompraCliente *arregloPedidosAMostrar, int validosPedidos) {
    for( int i = 0 ; i < validosPedidos ; i++ )
        mostrarPedidoArreglo(arregloPedidosAMostrar, i);
}
void mostrarPedidoArreglo(stRegistroCompraCliente *arregloPedidosAMostrar, int indice) {
    printf("\n--------------------------------------------------");
    printf("\nNumero de cliente: %i", arregloPedidosAMostrar[indice].numeroCliente);
    printf("\nNombre y Apellido: %s", arregloPedidosAMostrar[indice].nombreYApellido);
    printf("\nNumero de pedido: %i", arregloPedidosAMostrar[indice].numeroPedido);
    printf("\nMonto de compra: %f", arregloPedidosAMostrar[indice].montoCompra);
    printf("\n--------------------------------------------------\n");
}
