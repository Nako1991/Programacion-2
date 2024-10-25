#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>

#define DIM 30

typedef struct {
    int entero;
    float real;
    char cadena[DIM];
} stDatos;

typedef struct {
    stDatos dato;
    struct stNodo *anterior;
    struct stNodo *siguiente;
} stNodo;

typedef struct {
    struct stNodo *comienzo;
    struct stNodo *finale;
} stFila;

stNodo *removerDeFila(stFila **);

int main() { //Notas: Uso excesivo e innecesario de punteros dobles para terminar de aprenderlo.
    srand(time(NULL));

    menu();

    printf("\n\nSaliendo del programa...");
    return 0;
}
void menu() {
    stFila *fila; //Trabajo la fila no inicializada con las funciones basicas del ejercicio 1
    char continuar = 's';
    int numeroDeEjercicio;
    while( continuar == 's' ) {
        mostrarMenu();
        consultarNumeroEjercicio(&numeroDeEjercicio);
        switch( numeroDeEjercicio ) {
        case 1:
            ejercicioNumero1(&fila);
            break;
        case 2:
            ejercicioNumero2(&fila);
            break;
        case 3:
            ejercicioNumero3(&fila);
            break;
        case 4:
            ejercicioNumero4(&fila);
            break;
        case 5:
            printf("\nejecutando ejercicio 5..");
            break;
        case 6:
            printf("\nejecutando ejercicio 6..");
            break;
        case 7:
            printf("\nejecutando ejercicio 7..");
            break;
        case 8:
            printf("\nejecutando ejercicio 8..");
            break;
        case 0:
            continuar = 'q';
            break;
        default:
            printf("\nEl numero de ejercicio ingresado no es correcto.");
            break;
        }
        if( continuar == 's' ) {
            printf("\n\nVolviendo al menu...");
            deseaContinuar(&continuar);
        }
    }
}
void mostrarMenu() {
    printf("\nTP TDA - FILAS");
    printf("\n\n1. Crear la/s funciones basicas de fila para permitir que el usuario ingrese datos enteros a la misma. No sabemos");
    printf("\ncuantos datos seran ingresados. El usuario debe decidir en que momento finalizar. Modularizar por una parte la funcion");
    printf("\nbasica de insercion en la fila y por otra la funcion (cargaFila) que le permita al usuario ir ingresando los datos.");
    printf("\n\n2. Crear la funcion (muestraFila), la cual recorrera y mostrara el contenido de la fila pasada por parametro.");
    printf("\n\n3. Crear una funcion (buscaDato) que permita al usuario buscar un elemento especifico de la fila doblemente enlazada.");
    printf("\nEl usuario debe ingresar el valor del elemento a buscar, y la funcion debera hacer lo indicado informando cuantas");
    printf("\nocurrencias hubo.");
    printf("\n\n4. Crear una funcion (crearArchivoTexto) que guarde el contenido de la fila doblemente enlazada en un archivo de texto.");
    printf("\nPedir al usuario un nombre de archivo y luego escribir los elementos de la fila en ese archivo.");
    printf("\n\n5. Crear una funcion (cargaFila) que permita al usuario cargar una fila a partir de los datos previamente guardados en");
    printf("\nun archivo de texto. Debe leer el archivo y construir la fila doblemente enlazada a partir de los datos almacenados.");
    printf("\n\n6. Implementar una funcion recursiva (muestraFilaRecursiva) que recorra la fila doblemente enlazada desde el principio");
    printf("\nhasta el final e imprima los elementos.");
    printf("\n\n7. Crear una funcion (guardaBuscados) que guarde en un archivo de texto las posiciones (dentro de la fila) donde se");
    printf("\nencuentre un dato buscado. Tener en cuenta que el dato puede aparecer varias veces. Nota: ¿seria de utilidad usar la");
    printf("\nfuncion desarrollada en el ejercicio 2?.");
    printf("\n\n8. Crear la funcion (muetraArchivoFila), la cual recibira un archivo de texto como parametro y mostrara su contenido.");
}
void consultarNumeroEjercicio(int *numeroDeEjercicio) {
    printf("\n\nIngrese el numero de ejercicio que desea ejecutar (0 para salir): ");
    fflush(stdin);
    scanf("%i", numeroDeEjercicio);
}
void deseaContinuar(char *continuar) {
    printf("\nDesea continuar? ('s' para continuar, cualquier otra letra para salir): ");
    fflush(stdin);
    scanf("%c", continuar);
}
// EJERCICIOS
void ejercicioNumero1(stFila **fila) {
    char continuar = 's';
    int numeroDeFuncion;
    while( continuar == 's' ) {
        mostrarFuncionesBasicas();
        consultarNumeroFuncion(&numeroDeFuncion);
        switch( numeroDeFuncion ) {
        case 1:
            funcionNumero1(fila);
            break;
        case 2:
            funcionNumero2(fila);
            break;
        case 3:
            funcionNumero3(fila);
            break;
        case 4:
            funcionNumero4(fila);
            break;
        case 5:
            funcionNumero5(fila);
            break;
        case 6:
            funcionNumero6(fila);
            break;
        case 0:
            continuar = 'q';
            break;
        default:
            printf("\nEl numero de funcion ingresado no es correcto.");
            break;
        }
        if( continuar == 's' ) {
            printf("\n\nVolviendo a las funciones...");
            deseaContinuar(&continuar);
        }
    }
}
void mostrarFuncionesBasicas() {
    printf("\n\nFUNCIONES BASICAS");
    printf("\n\n 1. inicializarFila(stFila **fila) //Establece los punteros comienzo y finale a NULL");
    printf("\n 2. generarFila() //Toma un doble puntero a fila, un puntero a un arreglo de datos(estructura) y validos.");
    printf("\n     Itera sobre el arreglo llamando a la funcion generarDato mientras avanza la posicion.");
    printf("\n     Genera numeros enteros del 0 al 9 para datos.entero");
    printf("\n     Genera numeros reales de 2 decimales entre (0.00, 9.99) para datos.float");
    printf("\n     Genera un string 'Cadena de ejemplo: %.' donde '%' es reemplazado por un entero de 0 a 9 para datos.string");
    printf("\n     Crea nodos y copia los contenidos de los datos dentro de esos nodos.");
    printf("\n     Inserta los nodos creados al final de la fila.");
    printf("\n 3. crearNodo(stNodo **nodo, stDatos *dato) //Toma un puntero a nodo (ya creado) y un dato, copia e inicializa ese nodo");
    printf("\n 4. filaEstaVacia(stFila *fila) //Toma la fila y retorna 1 si esta vacia, sino retorna 0.");
    printf("\n 5. insertarEnFila(stFila **fila, stNodo *nodo) //Toma una fila y un nodo y lo inserta al final.");
    printf("\n 6. stNodo *removerDeFila(stFila **fila) //Toma un puntero doble a fila y remueve el nodo del comienzo.");
    printf("\n     Utilizar la funcion filaEstaVacia para comprobar antes de remover.");
}
void consultarNumeroFuncion(int *numeroDeFuncion) {
    printf("\n\nIngrese el numero de la Funcion que desea ejecutar (0 para salir): ");
    fflush(stdin);
    scanf("%i", numeroDeFuncion);
}
void funcionNumero1(stFila **fila) {
    printf("\nPuntero doble a fila no inicializado:");
    printf("\n fila.comienzo: %p", (*fila)->comienzo);
    printf("\n fila.finale: %p", (*fila)->finale);
    inicializarFila(fila);
    printf("\nPuntero doble a fila inicializado:");
    printf("\n fila.comienzo: %p", (*fila)->comienzo);
    printf("\n fila.finale: %p", (*fila)->finale);
}
void funcionNumero2(stFila **fila) {
    int validos;
    consultarCuantosDatos(&validos);
    printf("\nCargando %i datos generados aleatoriamente dentro de la fila...", validos);
    stDatos **datos = (stDatos **)malloc(sizeof(stDatos) * validos); //array de punteros a datos
    generarDatos(datos, validos);
    //mostrarDatos(datos, 5); //debug
    generarFila(fila, datos, validos);
    mostrarFila(*fila);
}
void consultarCuantosDatos(int *validos) {
    printf("\nCuantos datos desea generar? ");
    fflush(stdin);
    scanf("%i", validos);
}
void funcionNumero3(stFila **fila) {
    printf("\nCreando un dato y mostrandolo...");
    stDatos *dato1 = (stDatos *)malloc(sizeof(stDatos));
    generarDato(&dato1, 0);
    mostrarNodo(dato1);
}
void funcionNumero4(stFila **fila) {
    printf("\nLa fila esta vacia?");
    filaEstaVacia(*fila)? printf("\nLa fila esta vacia.") : printf("\nLa fila no esta vacia.");
}
void funcionNumero5(stFila **fila) {
    printf("\nCreando un dato, insertandolo en la fila y mostrando la fila...");
    stDatos *dato1 = (stDatos *)malloc(sizeof(stDatos));
    generarDato(&dato1, 0);
    generarFila(fila, &dato1, 1);
    mostrarFila(*fila);
}
void funcionNumero6(stFila **fila) {
    printf("\nSi la fila no esta vacia, borrando un dato de ella...");
    if( !filaEstaVacia(*fila) ) removerDeFila(fila);
    mostrarFila(*fila);
}
void ejercicioNumero2(stFila **fila) {
    printf("\nMostrando fila...");
    mostrarFila(*fila);
}
void ejercicioNumero3(stFila **fila) {
    printf("\nBuscando un dato dentro de la fila y mostrandolo...");
    int datoBuscado;
    int numeroDeEncuentros = 0;
    printf("\n\nIngrese el dato que desea buscar dentro de la fila: ");
    fflush(stdin);
    scanf("%i", &datoBuscado);
    buscarYMostrarDato(fila, datoBuscado, &numeroDeEncuentros);
    printf("\nSe encontraron %i elementos que coinciden con la busqueda.", numeroDeEncuentros);
}
void ejercicioNumero4(stFila **fila) {
    printf("\nGuardando los datos de la fila en un archivo de texto...");
    char nombreArchivoTexto[60];
    int largoDeString = 0;
    printf("\nIngrese el nombre del archivo de texto nuevo sin la extencion '.txt'(maximo 60 caracteres): ");
    fflush(stdin);
    gets(nombreArchivoTexto);
    largoDeString = strlen(nombreArchivoTexto);
    nombreArchivoTexto[largoDeString] = '.';
    nombreArchivoTexto[largoDeString + 1] = 't';
    nombreArchivoTexto[largoDeString + 2] = 'x';
    nombreArchivoTexto[largoDeString + 3] = 't';
    nombreArchivoTexto[largoDeString + 4] = '\0';
    if( filaEstaVacia(*fila) ) printf("\nLa fila está vacia.");
    if( !filaEstaVacia(*fila) ) crearArchivoTexto(fila, nombreArchivoTexto);
    printf("\nMostrando datos del archivo:");
    mostrarArchivoTexto(nombreArchivoTexto);
}
//DATOS
void generarDatos(stDatos **datos, int validos) {
    for( int i = 0 ; i < validos ; i++ )
        generarDato(datos, i);
}
void generarDato(stDatos **datos, int indice) {
    stDatos *datoNuevo = (stDatos *) malloc(sizeof(stDatos));
    if( !datoNuevo )
        printf("\nNo se pudo asignar la memoria al dato.");
    if( datoNuevo ) { //si el puntero != NULL
        datoNuevo->entero = rand()%10;
        datoNuevo->real = (float)( rand()%10 + rand()%10*0.1 + rand()%10*0.01 );
        char cadenaEjemplo[] = { "Cadena de ejemplo: %." };
        cadenaEjemplo[19] = rand()%10+48;
        strcpy(datoNuevo->cadena, cadenaEjemplo);
    }
    datos[indice] = datoNuevo;
}
void mostrarDatos(stDatos **datos, int validos) {
    for( int i = 0 ; i < validos ; i++ )
        mostrarDato(datos[i]);
}
void mostrarDato(stDatos *dato) {
    printf("\n--------------------------------------------------");
    printf("\ndato->entero: %i", dato->entero);
    printf("\ndato->real: %.2f", dato->real);
    printf("\ndato->cadena: %s", dato->cadena);
    printf("\n--------------------------------------------------");
}
//FILAS
void inicializarFila(stFila **fila) {
    (*fila)->comienzo = NULL;
    (*fila)->finale = NULL;
}
void crearNodo(stNodo **nodo, stDatos *dato) {
    (*nodo)->dato = *dato;
    (*nodo)->anterior = NULL;
    (*nodo)->siguiente = NULL;
}
int filaEstaVacia(stFila *fila) {
    int filaEstaVacia = 0;
    if( fila->comienzo == NULL && fila->finale == NULL )
        filaEstaVacia = 1;
    return filaEstaVacia;
}
void mostrarFila(stFila *fila) {
    if( filaEstaVacia(fila) )
        printf("\nLa fila esta vacia.");
    if( !filaEstaVacia(fila) ) {
        stNodo *auxIndice = fila->comienzo;
        while( auxIndice != NULL ) {
            mostrarNodo(auxIndice);
            auxIndice = auxIndice->siguiente;
        }
    }
}
void mostrarNodo(stNodo *nodo) {
    printf("\n--------------------------------------------------");
    printf("\nnodo->dato.entero: %i", nodo->dato.entero);
    printf("\nnodo->dato.real: %.2f", nodo->dato.real);
    printf("\nnodo->dato.cadena: %s", nodo->dato.cadena);
    printf("\nnodo->anterior: %p", nodo->anterior); //debug
    printf("\nnodo->actual: %p", nodo); //debug
    printf("\nnodo->siguiente: %p", nodo->siguiente); //debug
    printf("\n--------------------------------------------------");
}
void insertarEnFila(stFila **fila, stNodo *nodo) {
    if( filaEstaVacia(*fila) ) {
        (*fila)->comienzo = nodo;
        (*fila)->finale = nodo;
    }
    else {
        stNodo *auxFinale = (*fila)->finale; //CONSULTAR COMO USAR DOBLE FLECHA
        auxFinale->siguiente = nodo;
        nodo->anterior = auxFinale;
        (*fila)->finale = nodo;
    }
}
void generarFila(stFila **fila, stDatos **datos, int validos) {
    stNodo *bufferNodo;
    for( int i = 0 ; i < validos ; i++ ) {
        bufferNodo = (stNodo *)malloc(sizeof(stNodo));
        crearNodo(&bufferNodo, datos[i]);
        insertarEnFila(fila, bufferNodo);
    }
}
stNodo *removerDeFila(stFila **fila) {
    stNodo *nodoARemover = (*fila)->comienzo;
    if( nodoARemover->siguiente != NULL ) {
        stNodo *nodoARemover = (*fila)->comienzo;
        (*fila)->comienzo = nodoARemover->siguiente;
        stNodo *nuevoComienzo = (*fila)->comienzo;
        nuevoComienzo->anterior = NULL;
    }
    else {
        (*fila)->comienzo = NULL;
        (*fila)->finale = NULL;
    }
    return nodoARemover;
}
void cargarFila(stFila **fila) {
    stDatos datoACargar;
    stNodo *nodoACargar;
    char continuar = 's';
    while( continuar == 's' ) {
        cargarDatos(&datoACargar);
        nodoACargar = (stNodo *)malloc(sizeof(stNodo));
        crearNodo(&nodoACargar, &datoACargar);
        insertarEnFila(fila, nodoACargar);
        continuarCargando(&continuar);
    }
}
void cargarDatos(stDatos *dato) {
    printf("\nIngrese el entero que desea cargar: ");
    fflush(stdin);
    scanf("%i", &(dato->entero));
    printf("\nIngrese el numero real que desea cargar: ");
    fflush(stdin);
    scanf("%f", &(dato->real));
    char bufferCadena[DIM];
    printf("\nIngrese la cadena que desea cargar (30 caracteres maximo): ");
    fflush(stdin);
    gets(dato->cadena);
}
void continuarCargando(char *continuar) {
    printf("\nDesea continuar cargando datos? ('s' para continuar): ");
    fflush(stdin);
    scanf("%c", continuar);
}
void buscarYMostrarDato(stFila **fila, int datoBuscado, int *numeroDeOcurrencias) {
    stNodo *auxIndice = (*fila)->comienzo;
    if( !filaEstaVacia(*fila) ) {
        if( datoBuscado == auxIndice->dato.entero ) {
            mostrarNodo(auxIndice);
            (*numeroDeOcurrencias)++; //se necesitan los parentesis
        }
        while( auxIndice->siguiente != NULL ) {
            auxIndice = auxIndice->siguiente;
            if( datoBuscado == auxIndice->dato.entero ) {
                mostrarNodo(auxIndice);
                (*numeroDeOcurrencias)++;
            }
        }
    }
}
void crearArchivoTexto(stFila **fila,char nombreArchivoTexto[]) {
    stDatos *bufferDatos;
    FILE *archivoDatosTxt = fopen(nombreArchivoTexto, "w");
    stNodo *auxIndice = (*fila)->comienzo;
    if( !archivoDatosTxt )
        printf("\nNo se ha podido crear el archivo.");
    if( archivoDatosTxt ) {
        bufferDatos = &(auxIndice->dato);
        mostrarDato(bufferDatos); //debug
        fwrite(bufferDatos, sizeof(stDatos), 1, archivoDatosTxt);
        while( auxIndice->siguiente != NULL ) {
            auxIndice = auxIndice->siguiente;
            bufferDatos = &(auxIndice->dato);
            mostrarDato(bufferDatos); //debug
            fwrite(bufferDatos, sizeof(stDatos), 1, archivoDatosTxt);
        }
    }
    fclose(archivoDatosTxt);
}
void mostrarArchivoTexto(char nombreArchivoTexto[]) {
    stDatos *bufferDatos;
    FILE *archivoDatosTxt = fopen(nombreArchivoTexto, "r");
    if( !archivoDatosTxt )
        printf("\nNo se ha podido abrir el archivo.");
    if( archivoDatosTxt ) {
        while( !feof(archivoDatosTxt) ) {
            fread(bufferDatos, sizeof(stDatos), 1, archivoDatosTxt);
            if( !feof(archivoDatosTxt) )
                mostrarDato(bufferDatos);
        }
    }
    fclose(archivoDatosTxt);
}
