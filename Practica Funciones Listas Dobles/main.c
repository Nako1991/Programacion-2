#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <strings.h>
#include <time.h>

#define DIM 30

typedef struct {
    int numeroEntero;
    float numeroReal;
    char cadena[DIM];
} stDato;

typedef struct {
    stDato dato;
    struct stNodo *anterior;
    struct stNodo *siguiente;
} stNodo;

stNodo *crearNodo(stDato *nuevoDato);
stNodo *insertarDatos(stNodo *lista, stDato *datos, int validosDatos);
stNodo *insertarDatoAlComienzo(stNodo *lista, stDato *datoAInsertar);
stNodo *buscarNodoFinal(stNodo *lista);
stNodo *insertarNodoAlFinal(stNodo *lista, stNodo *nodoAInsertar);
stNodo *insertarNodoAlComienzo(stNodo *lista, stNodo *nodoAInsertar);
stNodo *insertarNodoEnOrden(stNodo *lista, stNodo *nodoAInsertar);
stNodo *borrarNodoAlComienzo(stNodo *lista);

int main() {
    srand(time(NULL));
    stNodo *lista;

    int validosDatos = 5;
    stDato *datos = (stDato *) malloc(sizeof(stDato) * validosDatos);
    generarDatos(datos, validosDatos);
    //mostrarDatos(datos, validosDatos);

    inicializarLista(&lista);
    printf("\nlista: %p", lista);

    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

    lista = insertarDatos(lista, datos, validosDatos);
    mostrarLista(lista);

    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

    stNodo *nodoAInsertar1 = crearNodo(datos);
    mostrarNodo(nodoAInsertar1);
    stNodo *nodoAInsertar2 = crearNodo(datos + 2);
    mostrarNodo(nodoAInsertar2);
    lista = insertarNodoAlFinal(lista, nodoAInsertar1);
    lista = insertarNodoAlFinal(lista, nodoAInsertar2);
    mostrarLista(lista);

    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

    stNodo *nodoAInsertarEnOrden = crearNodo(datos + 3);
    mostrarNodo(nodoAInsertarEnOrden);
    lista = insertarNodoEnOrden(lista, nodoAInsertarEnOrden);
    mostrarLista(lista);

    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

    lista = borrarNodoAlComienzo(lista);
    lista = borrarNodoAlComienzo(lista);
    mostrarLista(lista);

    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

    return 0;
}

void generarDatos(stDato *datos, int validosDatos) {
    for( int i = 0 ; i < validosDatos ; i++ )
        generarDato(datos, i);
}
void generarDato(stDato *datos, int index) {
    datos[index].numeroEntero = rand()%50;
    datos[index].numeroReal = (float) ( rand()%10 + rand()%10 * 0.1 + rand()%10 * 0.01 );
    char bufferCadena[] = { "Cadena de ejemplo." };
    strcpy(datos[index].cadena, bufferCadena);
}
void mostrarDatos(stDato *datos, int validosDatos) {
    for( int i = 0 ; i < validosDatos ; i++ )
        mostrarDato(datos, i);
}
void mostrarDato(stDato *datos, int index) {
    printf("\n--------------------------------------------------\n");
    printf("\nNumero Entero: %i", datos[index].numeroEntero);
    printf("\nNumero Real: %.2f", datos[index].numeroReal);
    printf("\nCadena: %s", datos[index].cadena);
    printf("\n--------------------------------------------------\n");
}

void inicializarLista(stNodo **lista) {
    *lista = NULL;
}
stNodo *crearNodo(stDato *nuevoDato) {
    stNodo *nuevoNodo = (stNodo *) malloc(sizeof(stNodo));
    nuevoNodo->anterior = NULL;
    nuevoNodo->siguiente = NULL;
    nuevoNodo->dato.numeroEntero = nuevoDato->numeroEntero;
    nuevoNodo->dato.numeroReal = nuevoDato->numeroReal;
    strcpy(nuevoNodo->dato.cadena, nuevoDato->cadena);
    return nuevoNodo;
}
void mostrarNodo(stNodo *nodoAMostrar) {
    printf("\n--------------------------------------------------\n");
    printf("\nNumero Entero: %i", nodoAMostrar->dato.numeroEntero);
    printf("\nNumero Real: %.2f", nodoAMostrar->dato.numeroReal);
    printf("\nCadena: %s", nodoAMostrar->dato.cadena);
    printf("\nAnterior: %p", nodoAMostrar->anterior);
    printf("\nActual: %p", nodoAMostrar);
    printf("\nSiguiente: %p", nodoAMostrar->siguiente);
    printf("\n--------------------------------------------------\n");
}
void mostrarLista(stNodo *lista) {
    if( lista == NULL )
        printf("\nLa lista esta vacia.");
    while( lista != NULL ) {
        mostrarNodo(lista);
        lista = lista->siguiente;
    }
}
stNodo *insertarDatos(stNodo *lista, stDato *datos, int validosDatos) {
    for( int i = 0 ; i < validosDatos ; i++ )
        lista = insertarDatoAlComienzo(lista, datos + i);
    return lista;
}
stNodo *insertarDatoAlComienzo(stNodo *lista, stDato *datoAInsertar) {
    if( lista == NULL )
        lista = crearNodo(datoAInsertar);
    else {
        stNodo *nuevoNodo = crearNodo(datoAInsertar);
        nuevoNodo->siguiente = lista;
        lista->anterior = nuevoNodo;
        lista = nuevoNodo;
    }
    return lista;
}
stNodo *insertarNodoAlComienzo(stNodo *lista, stNodo *nodoAInsertar) {
    if( lista == NULL )
        lista = nodoAInsertar;
    else {
        nodoAInsertar->siguiente = lista;
        lista->anterior = nodoAInsertar;
        lista = nodoAInsertar;
    }
    return lista;
}
stNodo *buscarNodoFinal(stNodo *lista) {
    stNodo *nodoFinal = lista;
    if( lista == NULL )
        printf("\nLa lista esta vacia.");
    else {
        while( nodoFinal->siguiente != NULL )
            nodoFinal = nodoFinal->siguiente;
    }
    return nodoFinal;
}
stNodo *insertarNodoAlFinal(stNodo *lista, stNodo *nodoAInsertar) {
    if( lista == NULL ) {
        lista = nodoAInsertar;
    }
    else {
        stNodo *nodoFinal = buscarNodoFinal(lista);
        nodoFinal->siguiente = nodoAInsertar;
        nodoAInsertar->anterior = nodoFinal;
    }
    return lista;
}
stNodo *insertarNodoEnOrden(stNodo *lista, stNodo *nodoAInsertar) {
    if( lista == NULL )
        printf("\nLa lista esta vacia.");
    else {
        if( nodoAInsertar->dato.numeroEntero < lista->dato.numeroEntero )
            lista = insertarNodoAlComienzo(lista, nodoAInsertar);
        else {
            stNodo *indexLista = lista;
            while( (indexLista->siguiente != NULL) && ( nodoAInsertar->dato.numeroEntero >= indexLista->dato.numeroEntero ) )
                indexLista = indexLista->siguiente;
            if( nodoAInsertar->dato.numeroEntero < indexLista->dato.numeroEntero ) {
                stNodo *indexAnterior = indexLista->anterior;
                nodoAInsertar->siguiente = indexLista;
                nodoAInsertar->anterior = indexAnterior;
                indexLista->anterior = nodoAInsertar;
                indexAnterior->siguiente = nodoAInsertar;
            }
            else
                lista = insertarNodoAlFinal(indexLista, nodoAInsertar);
        }
    }
    return lista;
}
stNodo *borrarNodoAlComienzo(stNodo *lista) {
    if( lista == NULL )
        printf("\nLa lista esta vacia.");
    else {
        stNodo *auxLista = lista;
        lista = lista->siguiente;
        lista->anterior = NULL;
        free(auxLista);
    }
    return lista;
}
