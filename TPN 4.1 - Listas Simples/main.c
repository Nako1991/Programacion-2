#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 30

typedef struct {
    char nombre[DIM];
    int edad;
} stPersona;

typedef struct {
    stPersona persona;
    struct stNodoSimple *siguienteNodo;
} stNodoSimple;

char deseaContinuar();
char deseaContinuarIngresandoPersonas();
stNodoSimple *inicializarLista();
stNodoSimple *insertarPersonasDeArchivoALista(stNodoSimple *, char []);
stNodoSimple *crearNodo(stPersona );
stNodoSimple *insertarPersonaAlFinalDeLista(stNodoSimple * , stPersona );
stNodoSimple *insertarPersonasAListaEnOrden(stNodoSimple * , char []);
stNodoSimple *insertarPersonaAListaEnOrden(stNodoSimple * , stPersona );

int main() {
    menu();
    return 0;
}
void menu() {
    srand(time(NULL));
    int numeroEjercicio;
    char continuar = 's';
    while( continuar == 's' ) {
        mostrarMenu();
        numeroEjercicio = seleccionarEjercicio();
        switch(numeroEjercicio) {
        case 0:
            continuar == 'n';
            break;
        case 1:
            ejercicioNumero1();
            break;
        case 2:
            ejercicioNumero2();
            break;
        case 3:
            ejercicioNumero3();
            break;
        case 4:
            ejercicioNumero4();
            break;
        case 5:
            //ejercicioNumero5();
            break;
        case 6:
            //ejercicioNumero6();
            break;
        case 7:
            //ejercicioNumero7();
            break;
        default:
            printf("\nEl numero de ejercicio ingresado no es valido.");
            break;
        }
        continuar = deseaContinuar();
    }
}
void mostrarMenu() {
    printf("\n\nTrabajo Práctico Nro 4.1: Lista Simplemente Enlazada ");
    printf("\n\nCodifique las funciones básicas que dan funcionamiento a la Lista Enlazada y los Subprogramas que  figuran en el");
    printf("\napunte teórico compartido en el Campus.");
    printf("\n\n1. Hacer un programa que lea de un archivo datos y los inserte en una lista.");
    printf("\n2. Hacer un programa que lea de un archivo datos y los inserte en una lista en forma ordenada.");
    printf("\n3. Hacer una función que retorne un 1 (uno) o 0 (cero) si existe un determinado elemento en una lista dada.");
    printf("\n(considerar caso ordenada y caso desordenada)");
    printf("\n4. Hacer una función que intercale en orden los elementos de dos listas ordenadas generando una nueva lista. Se deben");
    printf("\nredireccionar los punteros, no se deben crear nuevos nodos.");
    printf("\n5. Invertir los elementos de una lista redireccionando solamente los punteros. (No se deben crear nuevos nodos)");
    printf("\n6. Codificar el TDA Pila con las funciones necesarias, implementada con una lista enlazada (Similar al ejercicio");
    printf("\nhecho con arreglo).");
    printf("\n7. Utilizando el TDA Pila creado en el punto 6, cargar la pila con números enteros.");
    printf("\n  1. Luego, recorrer dicha pila e insertar por orden de llegada (al final) en una lista simplemente");
    printf("\n  enlazada aquellos números que sean pares. Cuidado, la función no debe perder la pila original, trabaje");
    printf("\n  de forma tal que se conserven sus datos.");
    printf("\n  2. Eliminar de la lista cargada en el ejercicio anterior, aquellos nodos que contengan valores menores a 10.");
}
int seleccionarEjercicio() {
    int numeroEjercicio;
    printf("\n\nIngrese el numero de ejercicio a ejecutar (0 para salir): ");
    fflush(stdin);
    scanf("%i", &numeroEjercicio);
    return numeroEjercicio;
}
char deseaContinuar() {
    char continuar;
    printf("\n\nDesea continuar ejecutando la guia? ('s' para continuar): ");
    fflush(stdin);
    scanf("%c", &continuar);
    return continuar;
}

void ejercicioNumero1() {
    char nombreArchivo[] = { "archivoPersonas.txt" };
    //insertarPersonasEnArchivo(nombreArchivo); //Para cargar el archivo antes de iniciar la guia
    printf("\nEl archivo contiene las siguientes personas: ");
    mostrarArchivoPersonas(nombreArchivo);
    stNodoSimple *lista;
    lista = inicializarLista();
    lista = insertarPersonasDeArchivoALista(lista, nombreArchivo);
    printf("\n\nMostrando lista: ");
    mostrarListaDePersonas(lista);
}
stNodoSimple *inicializarLista() {
    return NULL;
}
void insertarPersonasEnArchivo(char nombreArchivo[]) {
    stPersona personaAInsertar;
    char continuar = 's';
    FILE *archivoDeTexto = fopen(nombreArchivo, "a");
    if( archivoDeTexto == NULL )
        printf("\nEl archivo no existe.");
    else
        while( continuar == 's' ) {
            insertarPersona(&personaAInsertar);
            continuar = deseaContinuarIngresandoPersonas();
            fwrite(&personaAInsertar, sizeof(stPersona), 1, archivoDeTexto);
        }
    fclose(archivoDeTexto);
}
char deseaContinuarIngresandoPersonas() {
    char continuar;
    printf("\n\nDesea continuar ingresando personas? ('s' para continuar): ");
    fflush(stdin);
    scanf("%c", &continuar);
    return continuar;
}
void insertarPersona(stPersona *personaNueva) {
    printf("\nIngrese el nombre de la persona a insertar: ");
    fflush(stdin);
    gets(personaNueva->nombre);
    printf("\nIngrese la edad de la persona a insertar: ");
    fflush(stdin);
    scanf("%i", &personaNueva->edad);
}
void mostrarArchivoPersonas(char nombreArchivo[]) {
    stPersona bufferPersona;
    FILE *archivoPersonas = fopen(nombreArchivo, "r");
    if( archivoPersonas == NULL )
        printf("\nEl archivo no existe.");
    else
        while( !feof(archivoPersonas) ){
            fread(&bufferPersona, sizeof(stPersona), 1, archivoPersonas);
            if( !feof(archivoPersonas) )
                mostrarPersona(bufferPersona);
        }
    fclose(archivoPersonas);
}
void mostrarPersona(stPersona personaAMostrar) {
    printf("\n--------------------------------------------------");
    printf("\nNombre: %s", personaAMostrar.nombre);
    printf("\nEdad: %i", personaAMostrar.edad);
    printf("\n--------------------------------------------------");
}
stNodoSimple *insertarPersonasDeArchivoALista(stNodoSimple *lista, char nombreArchivo[]) {
    stPersona bufferPersona;
    FILE *archivoTexto = fopen(nombreArchivo, "r");
    if( archivoTexto == NULL )
        printf("\nEl archivo no existe.");
    else
        while ( !feof(archivoTexto) ) {
            fread(&bufferPersona, sizeof(stPersona), 1, archivoTexto);
            if( !feof(archivoTexto) ) lista = insertarPersonaAlFinalDeLista(lista, bufferPersona);
        }
    fclose(archivoTexto);
    return lista;
}
stNodoSimple *insertarPersonaAlFinalDeLista(stNodoSimple *lista, stPersona personaAInsertar) {
    stNodoSimple *indexLista = lista;
    if( lista == NULL )
        lista = crearNodo(personaAInsertar);
    else {
        while( indexLista->siguienteNodo != NULL )
            indexLista = indexLista->siguienteNodo;
        indexLista->siguienteNodo = crearNodo(personaAInsertar);
    }
    return lista;
}
stNodoSimple *crearNodo(stPersona personaAInsertar) {
    stNodoSimple *nuevoNodo = (stNodoSimple *) malloc(sizeof(stNodoSimple));
    nuevoNodo->persona = personaAInsertar;
    nuevoNodo->siguienteNodo = NULL;
    return nuevoNodo;
}
void mostrarListaDePersonas(stNodoSimple *lista) {
    stNodoSimple *indexLista = lista;
    if( lista == NULL )
        printf("\nLa lista esta vacia.");
    else
        while( indexLista != NULL ) {
            mostrarPersona(indexLista->persona);
            indexLista = indexLista->siguienteNodo;
        }
}

void ejercicioNumero2() {
    char nombreArchivo[] = { "archivoPersonas.txt" };
    printf("\nEl archivo contiene las siguientes personas: ");
    mostrarArchivoPersonas(nombreArchivo);
    stNodoSimple *lista;
    lista = inicializarLista();
    lista = insertarPersonasAListaEnOrden(lista, nombreArchivo);
    printf("\n\nMostrando lista ordenada: ");
    mostrarListaDePersonas(lista);
}
stNodoSimple *insertarPersonasAListaEnOrden(stNodoSimple *lista, char nombreArchivo[]) {
    stPersona bufferPersona;
    int validosPersonas = contarPersonasEnArchivo(nombreArchivo);
    FILE *archivoPersonas = fopen(nombreArchivo, "r");
    if( archivoPersonas == NULL )
        printf("\nEl archivo no existe");
    else {
        while( !feof(archivoPersonas) ) {
            fread(&bufferPersona, sizeof(stPersona), 1, archivoPersonas);
            if( !feof(archivoPersonas) )
                lista = insertarPersonaAListaEnOrden(lista, bufferPersona);
        }
    }
    fclose(archivoPersonas);
    return lista;
}
stNodoSimple *insertarPersonaAListaEnOrden(stNodoSimple *lista, stPersona personaAInsertar) {
    stNodoSimple *index = lista;
    stNodoSimple *indexAnterior;
    stNodoSimple *nuevoNodo = crearNodo(personaAInsertar);
    //printf("\n\nPersona a insertar"); //debug
    //mostrarPersona(personaAInsertar); //debug
    if( lista == NULL )
        lista = nuevoNodo;
    else if ( personaAInsertar.edad <= lista->persona.edad ) {
        lista = nuevoNodo;
        lista->siguienteNodo = index;
    }
    else {
        while( index->siguienteNodo != NULL && personaAInsertar.edad > index->persona.edad) {
                indexAnterior = index;
                index = index->siguienteNodo;
            }
            indexAnterior->siguienteNodo = nuevoNodo;
            nuevoNodo->siguienteNodo = index;
    }
    //printf("\n\nMostrando lista en progreso..."); //debug
    //mostrarListaDePersonas(lista); //debug
    return lista;
}
int contarPersonasEnArchivo(char nombreArchivo[]) {
    int validos = 0;
    stPersona bufferPersona;
    FILE *archivoPersonas = fopen(nombreArchivo, "r");
    if( archivoPersonas == NULL )
        printf("\nEl archivo no existe");
    else
        while( !feof(archivoPersonas) ) {
            fread(&bufferPersona, sizeof(stPersona), 1, archivoPersonas);
            if( !feof(archivoPersonas) )
                validos++;
        }
    fclose(archivoPersonas);
    return validos;
}
void copiarPersona(stPersona personaDestino, stPersona personaOrigen) {
    strcpy(personaDestino.nombre, personaOrigen.nombre);
    personaDestino.edad = personaOrigen.edad;
}

void ejercicioNumero3() {
    char nombreArchivo[] = { "archivoPersonas.txt" };
    int edadABuscar = 20;
    int edadEncontrada = 0;
    printf("\nEl archivo contiene las siguientes personas: ");
    mostrarArchivoPersonas(nombreArchivo);
    stNodoSimple *lista;
    lista = inicializarLista();
    lista = insertarPersonasDeArchivoALista(lista, nombreArchivo);
    printf("\n\nMostrando lista ordenada: ");
    mostrarListaDePersonas(lista);
    edadEncontrada = buscarEdadEnLista(lista, 21);
    edadEncontrada?
        printf("\n\nSe encontro la edad dentro de la lista.") :
        printf("\n\nNo se encontro la edad dentro de la lista.") ;
}
int buscarEdadEnLista(stNodoSimple *lista, int edadABuscar) {
    stNodoSimple *auxLista = lista;
    int edadEncontrada = 0;
    if( auxLista->persona.edad == edadABuscar )
        edadEncontrada = 1;
    while( auxLista->siguienteNodo != NULL ) {
        auxLista = auxLista->siguienteNodo;
        if( auxLista->persona.edad == edadABuscar )
            edadEncontrada = 1;
    }
    return edadEncontrada;
}

void ejercicioNumero4() {

}
