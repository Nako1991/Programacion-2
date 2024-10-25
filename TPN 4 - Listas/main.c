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

stNodoSimple *insertarPersonasDeArchivoALista(stNodoSimple *lista, char nombreArchivo[]);
stNodoSimple *crearNodo(stPersona *personaAInsertar);

int main() {
    ejercicioNumero1();
    return 0;
}
void ejercicioNumero1() {
    //insertarPersonasEnArchivo(); //Para cargar el archivo antes de iniciar la guia
    stNodoSimple *lista;
    inicializarLista(lista);
    char nombreArchivo[] = { "archivoPersonas.txt" };
    printf("\ntest1"); //debug
    insertarPersonasDeArchivoALista(lista, nombreArchivo);
}
void inicializarLista(stNodoSimple *lista) {
    lista = NULL;
}
void insertarPersonasEnArchivo(stNodoSimple *lista, char nombreArchivo[]) {
    stPersona personaAInsertar;
    char continuar = 's';
    FILE *archivoDeTexto = fopen(nombreArchivo, "a");
    if( archivoDeTexto == NULL )
        printf("\nEl archivo no existe.");
    else while( continuar == 's' ) {
            insertarPersona(&personaAInsertar);
            printf("\n--------------------------------------------------");
            printf("\nNombre: %s, Edad: %i", personaAInsertar.nombre, personaAInsertar.edad);
            printf("\n--------------------------------------------------");
            deseaContinuar(&continuar);
            fwrite(&personaAInsertar, sizeof(stPersona), 1, archivoDeTexto);
        }
    fclose(archivoDeTexto);
}
void insertarPersona(stPersona *personaNueva) {
    printf("\nIngrese el nombre de la persona a insertar: ");
    fflush(stdin);
    gets(personaNueva->nombre);
    printf("\nIngrese la edad de la persona a insertar: ");
    fflush(stdin);
    scanf("%i", &personaNueva->edad);
}
void deseaContinuar(char *continuar) {
    printf("\nDesea continuar ingresando personas? ('s' para continuar): ");
    fflush(stdin);
    scanf("%c", continuar);
}
stNodoSimple *insertarPersonasDeArchivoALista(stNodoSimple *lista, char nombreArchivo[]) {
    stPersona *bufferPersona;
    FILE *archivoTexto = fopen(nombreArchivo, "r");
    printf("\ntest2"); //debug
    if( archivoTexto == NULL )
        printf("\nEl archivo no existe.");
    else while ( !feof(archivoTexto) ) {
        printf("\ntest3"); //debug
        fread(bufferPersona, sizeof(stPersona), 1, archivoTexto);
        printf("\n--------------------------------------------------"); //debug
        printf("\nNombre: %s, Edad: %i", bufferPersona->nombre, bufferPersona->edad); //debug
        printf("\n--------------------------------------------------"); //debug
        printf("\ntest4"); //debug
        if( !feof(archivoTexto) ) insertarPersonaAlFinalLista(lista, bufferPersona);
        printf("\ntest fin bucle"); //debug
    }
    fclose(archivoTexto);
    return lista;
}
void insertarPersonaAlFinalLista(stNodoSimple *lista, stPersona *personaAInsertar) {
    stNodoSimple *index = lista;
    printf("\ntest5"); //debug
    if( index == NULL ) index = crearNodo(personaAInsertar);
    else while( index->siguienteNodo != NULL ) {
        index = index->siguienteNodo;
    }
    index->siguienteNodo = crearNodo(personaAInsertar);
    printf("\ntest7"); //debug
}
stNodoSimple *crearNodo(stPersona *personaAInsertar) {
    stNodoSimple *nuevoNodo = (stNodoSimple *) malloc(sizeof(stNodoSimple));
    nuevoNodo->persona = *personaAInsertar;
    nuevoNodo->siguienteNodo = NULL;
    return nuevoNodo;
}
