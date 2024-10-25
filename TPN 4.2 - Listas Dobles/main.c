    #include <stdio.h>
    #include <stdlib.h>
    #include <strings.h>
    #include <time.h>

    #define DIM 60

    typedef struct {
        int entero;
        float real;
        char cadena[DIM];
    } stDatos;

    typedef struct {
        struct stNodoDoble *anterior;
        struct stNodoDoble *siguiente;
        stDatos datos;
    } stNodoDoble;

    stNodoDoble *crearNodoDoble(stDatos *bufferDatos);
    stNodoDoble *insertarNodoAlComienzo(stNodoDoble *lista, stNodoDoble *nodoAInsertar);
    stNodoDoble *buscarNodoFinal(stNodoDoble *lista);
    stNodoDoble *insertarNodoAlFinal(stNodoDoble *lista, stNodoDoble *nodoNuevo);
    stNodoDoble *insertarNodoEnOrden(stNodoDoble *lista, stNodoDoble *nodoAInsertar);
    stNodoDoble *borrarNodoAlComienzo(stNodoDoble *lista);
    stNodoDoble *borrarNodoAlFinal(stNodoDoble *lista);
    stNodoDoble *borrarLista(stNodoDoble *lista);
    stNodoDoble *borrarNodoBuscado(stNodoDoble *lista, int datoABorrar);

    int main() {
        srand(time(NULL));

        stDatos *dato1; //se puede usar un array de punteros
        stDatos *dato2;
        stDatos *dato3;
        stDatos *dato4;
        stDatos *dato5;
        generarDato(&dato1);
        generarDato(&dato2);
        generarDato(&dato3);
        generarDato(&dato4);
        generarDato(&dato5);
        stNodoDoble *nodoDato1 = crearNodoDoble(dato1);
        stNodoDoble *nodoDato2 = crearNodoDoble(dato2);
        stNodoDoble *nodoDato3 = crearNodoDoble(dato3);
        stNodoDoble *nodoDato4 = crearNodoDoble(dato4);
        stNodoDoble *nodoDato5 = crearNodoDoble(dato5);
    //    mostrarDato(dato1);
    //    mostrarDato(dato2);
    //    mostrarDato(dato3);
    //    mostrarDato(dato4);
    //    mostrarDato(dato5);

        stNodoDoble *lista;
        inicializarNodoDoble(&lista);

    //    lista = insertarNodoAlComienzo(lista, nodoDato1);
    //    lista = insertarNodoAlComienzo(lista, nodoDato2);
    //    lista = insertarNodoAlComienzo(lista, nodoDato3);
    //    lista = insertarNodoAlComienzo(lista, nodoDato4);
    //    lista = insertarNodoAlComienzo(lista, nodoDato5);

        lista = insertarNodoAlFinal(lista, nodoDato1);
        lista = insertarNodoAlFinal(lista, nodoDato2);
        lista = insertarNodoAlFinal(lista, nodoDato3);
        lista = insertarNodoAlFinal(lista, nodoDato4);
        lista = insertarNodoAlFinal(lista, nodoDato5);

        mostrarLista(lista);

        int encontrado = buscarNodo(lista, 4);
        encontrado? printf("\n\nEncontrado.") :  printf("\n\nNo encontrado.") ;

        stDatos *dato6;
        generarDato(&dato6);
        stNodoDoble *nodoDato6 = crearNodoDoble(dato6);
        printf("\n...............................................................\n");
        mostrarNodoDoble(nodoDato6);
        printf("\n...............................................................\n");
        lista = insertarNodoEnOrden(lista, nodoDato6);
        mostrarLista(lista);

        printf("\n...............................................................\n");
    //    lista = borrarNodoAlComienzo(lista);
    //    lista = borrarNodoAlComienzo(lista);
        lista = borrarNodoAlFinal(lista);
        lista = borrarNodoAlFinal(lista);
        mostrarLista(lista);

        printf("\n...............................................................\n");
        //lista = borrarLista(lista);
        lista = borrarNodoBuscado(lista, 4);
        mostrarLista(lista);

        return 0;
    }

    void generarDato(stDatos **datos) {
        *datos = (stDatos *) malloc(sizeof(stDatos)); //IMPORTANTE NO OLVIDARME
        (*datos)->entero = rand()%10;
        (*datos)->real = (float)(rand()%10 + rand()%10*0.1 + rand()%10*0.01);
        char cadenaEjemplo[] = {"Cadena de ejemplo."};
        strcpy((*datos)->cadena, cadenaEjemplo);
    }
    void mostrarDato(stDatos *datos) {
        printf("\n Datos, entero: %i", datos->entero);
        printf("\n Datos, real: %f", datos->real);
        printf("\n Datos, cadena: %s", datos->cadena);
    }
    void inicializarNodoDoble(stDatos **datos) {
        *datos = NULL;
    }
    stNodoDoble *crearNodoDoble(stDatos *nuevoDato) {
        stNodoDoble *nodoNuevo = (stNodoDoble *) malloc(sizeof(stDatos));
        nodoNuevo->anterior = NULL;
        nodoNuevo->siguiente = NULL;
        nodoNuevo->datos.entero = nuevoDato->entero;
        nodoNuevo->datos.real = nuevoDato->real;
        strcpy(nodoNuevo->datos.cadena, nuevoDato->cadena);
        return nodoNuevo;
    }
    void mostrarNodoDoble(stNodoDoble *nodoAMostrar) {
        printf("\n--------------------------------------------------");
        printf("\n Nodo Doble: ");
        printf("\n  Entero: %i", nodoAMostrar->datos.entero);
        printf("\n  Real: %.2f", nodoAMostrar->datos.real);
        printf("\n  Cadena: %s", nodoAMostrar->datos.cadena);
        printf("\n  Anterior: %p", nodoAMostrar->anterior); //debug
        printf("\n  Actual: %p", nodoAMostrar); //debug
        printf("\n  Siguiente: %p", nodoAMostrar->siguiente); //debug
        printf("\n--------------------------------------------------");
    }
    void mostrarLista(stNodoDoble *lista) {
        if( lista != NULL ){
                mostrarNodoDoble(lista);
            while( lista->siguiente != NULL ) {
                lista = lista->siguiente;
                mostrarNodoDoble(lista);
            }
        }
        else
            printf("\nLa lista esta vacia.");
    }
    stNodoDoble *insertarNodoAlComienzo(stNodoDoble *lista, stNodoDoble *nodoAInsertar) {
        if( lista == NULL )
            lista = nodoAInsertar;
        else {
            nodoAInsertar->siguiente = lista;
            lista->anterior = nodoAInsertar;
            lista = nodoAInsertar;
        }
        return lista;
    }
    stNodoDoble *buscarNodoFinal(stNodoDoble *lista) {
        stNodoDoble *nodoFinal = lista; //es lo mismo sin el auxiliar, pero asi se entiende mejor
        while( nodoFinal->siguiente != NULL )
            nodoFinal = nodoFinal->siguiente;
        return nodoFinal;
    }
    stNodoDoble *insertarNodoAlFinal(stNodoDoble *lista, stNodoDoble *nodoNuevo) {
        stNodoDoble *nodoFinal;
        if( lista == NULL )
            lista = nodoNuevo;
        else {
            nodoFinal = buscarNodoFinal(lista);
            nodoFinal->siguiente = nodoNuevo;
            nodoNuevo->anterior = nodoFinal;
        }
        return lista;
    }
    stNodoDoble *insertarNodoEnOrden(stNodoDoble *lista, stNodoDoble *nodoAInsertar) {
        if( lista == NULL )
            lista = nodoAInsertar;
        else if( nodoAInsertar->datos.entero <= lista->datos.entero )
            lista = insertarNodoAlComienzo(lista, nodoAInsertar);
        else {
            stNodoDoble *indexLista = lista;
            while( (indexLista->siguiente != NULL) && (nodoAInsertar->datos.entero > indexLista->datos.entero) )
                indexLista = indexLista->siguiente;
            if( nodoAInsertar->datos.entero < indexLista->datos.entero ) {
                nodoAInsertar->siguiente = indexLista;
                nodoAInsertar->anterior = indexLista->anterior;
                stNodoDoble *nodoAnterior = indexLista->anterior;
                indexLista->anterior = nodoAInsertar;
                nodoAnterior->siguiente = nodoAInsertar;
            }
            else
                insertarNodoAlFinal(lista, nodoAInsertar);
        }
        return lista;
    }
    int buscarNodo(stNodoDoble *lista, int datoABuscar) {
        int encontrado = 0;
        if( lista->datos.entero == datoABuscar )
            encontrado = 1;
        while( lista->siguiente != NULL ) {
            if( lista->datos.entero == datoABuscar )
                encontrado = 1;
            lista = lista->siguiente;
        }
        if( lista->datos.entero == datoABuscar )
            encontrado = 1;
        return encontrado;
    }
    stNodoDoble *borrarNodoAlComienzo(stNodoDoble *lista) {
        if( lista == NULL )
            printf("\nLa lista esta vacia.");
        if( lista != NULL ) {
            if( lista->siguiente == NULL ) {
                free(lista);
                lista = NULL;
            }
            else {
                lista = lista->siguiente;
                free(lista->anterior);
                lista->anterior = NULL;
            }
        }
        return lista;
    }
    stNodoDoble *borrarNodoAlFinal(stNodoDoble *lista) {
        stNodoDoble *nodoFinal = buscarNodoFinal(lista);
        if( lista == nodoFinal )
            lista = NULL;
        if( nodoFinal->anterior != NULL ) {
            stNodoDoble *nodoAnterior = nodoFinal->anterior;
            nodoAnterior->siguiente = NULL;
        }
        free(nodoFinal);
        return lista;
    }
    stNodoDoble *borrarLista(stNodoDoble *lista) {
        while( lista != NULL )
            lista = borrarNodoAlFinal(lista);
        return NULL;
    }
    stNodoDoble *borrarNodoBuscado(stNodoDoble *lista, int datoABorrar) {
        stNodoDoble *auxLista = lista;
        if( lista == NULL )
            printf("\nLa lista esta vacia.");
        else {
            if( auxLista->anterior == NULL && auxLista->datos.entero == datoABorrar )
                auxLista = borrarNodoAlComienzo(auxLista);
            while( auxLista->siguiente != NULL && auxLista->datos.entero != datoABorrar )
                auxLista = auxLista->siguiente;
            if( auxLista->siguiente == NULL && auxLista->datos.entero == datoABorrar )
                auxLista = borrarNodoAlFinal(lista);
            if( auxLista->siguiente != NULL && auxLista->datos.entero == datoABorrar ) {
                stNodoDoble *auxAnterior = auxLista->anterior;
                stNodoDoble *auxSiguiente = auxLista->siguiente;
                auxAnterior->siguiente = auxSiguiente;
                auxSiguiente->anterior = auxAnterior;
                free(auxLista);
            }
        }
        return lista;
    }
