#include <stdio.h>
#include <stdlib.h>

#define DIM 30

typedef struct {
    char nombre[DIM];
    int edad;
} stPersona;

typedef struct {
    stPersona persona;
    struct stNodo *sigiuente;
} stNodo;

stNodo *inicializarLista();

int main()
{
    stNodo *lista;
    stPersona persona;
    char auxNombre[] = { "Miguel" };
    strcpy(persona.nombre, auxNombre);
    persona.edad = 21;
    printf("\nlista: %p", lista); //debug
    lista = inicializarLista();
    printf("\nlista: %p", lista); //debug
    stNodo *nuevaPersona = crearNodo(persona);
    lista = agregarPersonaALista(lista, nuevaPersona);
    return 0;
}
stNodo *inicializarLista() {
    return NULL;
}
stNodo *crearNodo(stPersona persona) {
    stNodo *nuevoNodo = (stNodo *) malloc(sizeof(stNodo));
    strcpy( nuevoNodo->persona.nombre, persona.nombre);
    nuevoNodo->persona.edad = persona.edad;
    nuevoNodo->sigiuente = NULL;
    return nuevoNodo;
}
stNodo *agregarNodoAListaInicio(stNodo *lista, stPersona *persona) {
    lista = persona;

}
