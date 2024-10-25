#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct {
    int idEquipo;
    char nombreEquipo[30];
} stEquipo;

typedef struct {
    int idJugador;
    int nroCamisetaJugador;
    char nombreJugador[30];
    int puntosAnotados;
} stJugador;

typedef struct {
    int idEquipo;
    char nombreEquipo[30];
    int idJugador;
    int nroCamisetaJugador;
    char nombreJugador[30];
    int puntosAnotados;
} stJugadorEquipo;

typedef struct stNodoJugador {
    stJugador jugador;
    struct stNodoJugador *siguiente;
} stNodoJugador;

typedef struct stNodoEquipo {
    stEquipo equipo;
    stNodoJugador *listaJugador;
    struct stNodoEquipo *siguiente;
} stNodoEquipo;

stNodoEquipo *agregarJugadoresAListaDeLista(char nombreArchivo[], stNodoEquipo *listaEquipos);
stNodoEquipo *agregarEquipoALista(stNodoEquipo *listaEquipos, stEquipo *equipo);
stNodoEquipo *crearNodoEquipo(stEquipo *equipo);
stNodoEquipo *buscarEquipoEnLista(stNodoEquipo *listaEquipos, stEquipo *equipo);
stNodoJugador *crearNodoJugador(stJugador *jugador);
stNodoJugador *agregarJugadorAEquipo(stNodoJugador *listaJugadores, stJugador *jugador);

int main() {
    char nombreArchivo[] = { "registroJugador.dat" };
    //mostrarArchivo(nombreArchivo);
    printf("asdsd"); ///sin esta linea o si esta linea imprime menos caracteres se crashea la ejecucion -.-

    stNodoEquipo *listaEquipos;
    inicializarListaEquipos(&listaEquipos);

    listaEquipos = agregarJugadoresAListaDeLista(nombreArchivo, listaEquipos);

    mostrarListaEquipos(listaEquipos);
    return 0;
}
void mostrarArchivo(char nombreArchivo[]) {
    stJugadorEquipo *bufferJugadorEquipo;
    FILE *bufferArchivo = fopen(nombreArchivo, "rb");
    if( bufferArchivo == NULL ) printf("\nNo se pudo abrir el archivo!");
    if( bufferArchivo != NULL ) {
        while( !feof(bufferArchivo) ) {
            fread(bufferJugadorEquipo, sizeof(stJugadorEquipo), 1, bufferArchivo);
            if( !feof(bufferArchivo) )
                mostrarJugadorEquipo(bufferJugadorEquipo);
        }
    }
    fclose(bufferArchivo);
}
void mostrarJugadorEquipo(stJugadorEquipo *jugadorEquipo) {
    printf("\n --------------------------------------------------");
    printf("\n idEquipo: %i", jugadorEquipo->idEquipo);
    printf("\n nombreEquipo: %s", jugadorEquipo->nombreEquipo);
    printf("\n idJugador: %i", jugadorEquipo->idJugador);
    printf("\n nroCamisetaJugador: %i", jugadorEquipo->nroCamisetaJugador);
    printf("\n nombreJugador: %c", jugadorEquipo->nombreJugador);
    printf("\n puntosAnotados: %i", jugadorEquipo->puntosAnotados);
    printf("\n --------------------------------------------------");
}
stNodoEquipo *agregarJugadoresAListaDeLista(char nombreArchivo[], stNodoEquipo *listaEquipos) {
    stJugadorEquipo bufferJugadorEquipo;
    stEquipo bufferEquipo;
    stJugador bufferJugador;
    FILE *bufferArchivo = fopen(nombreArchivo, "rb");
    stNodoEquipo *equipoEncontrado;
    if( bufferArchivo == NULL ) printf("\nNo se pude abrir el archivo!");
    if( bufferArchivo != NULL ) {
        while( !feof(bufferArchivo) ) {
            fread(&bufferJugadorEquipo, sizeof(stJugadorEquipo), 1, bufferArchivo);
            if( !feof(bufferArchivo) ) {
                //mostrarJugadorEquipo(&bufferJugadorEquipo); //DEBUG
                separarJugadorEquipo(&bufferJugadorEquipo, &bufferEquipo, &bufferJugador); ///FUNCIONA CORRECTAMENTE
                mostrarEquipo(&bufferEquipo); //DEBUG
                mostrarJugador(&bufferJugador); //DEBUG
                if( buscarEquipoEnLista(listaEquipos, &bufferEquipo) == NULL )
                    listaEquipos = agregarEquipoALista(listaEquipos, &bufferEquipo);
                equipoEncontrado = buscarEquipoEnLista(listaEquipos, &bufferEquipo);
                equipoEncontrado->listaJugador = agregarJugadorAEquipo(equipoEncontrado->listaJugador, &bufferJugador);
                mostrarListaJugadores(equipoEncontrado->listaJugador);
            }
        }
    }
    fclose(bufferArchivo);
    return listaEquipos;
}
stNodoEquipo *buscarEquipoEnLista(stNodoEquipo *listaEquipos, stEquipo *equipo) {
    stNodoEquipo *encontrado = NULL;
    if( listaEquipos != NULL ) {
        while( listaEquipos != NULL ) {
            if( listaEquipos->equipo.idEquipo == equipo->idEquipo )
                encontrado = listaEquipos;
            listaEquipos = listaEquipos->siguiente;
        }
    }
    return encontrado;
}
void mostrarEquipo(stEquipo *equipo) {
    printf("\n ++++++++++++++++++++++++++++++");
    printf("\n idEquipo: %i", equipo->idEquipo);
    printf("\n nombreEquipo: %s", equipo->nombreEquipo);
    printf("\n ++++++++++++++++++++++++++++++");
}
void mostrarJugador(stJugador *jugador) {
    printf("\n ******************************");
    printf("\n idJugador: %i", jugador->idJugador);
    printf("\n nroCamisetaJugador: %i", jugador->nroCamisetaJugador);
    printf("\n nombreJugador: %s", jugador->nombreJugador);
    printf("\n puntosAnotados: %i", jugador->puntosAnotados);
    printf("\n ******************************");
}
void separarJugadorEquipo(stJugadorEquipo *jugadorEquipo, stEquipo *equipo, stJugador *jugador) {
    equipo->idEquipo = jugadorEquipo->idEquipo;
    strcpy(equipo->nombreEquipo, jugadorEquipo->nombreEquipo);

    jugador->idJugador = jugadorEquipo->idJugador;
    jugador->nroCamisetaJugador = jugadorEquipo->nroCamisetaJugador;
    strcpy(jugador->nombreJugador, jugadorEquipo->nombreJugador);
    jugador->puntosAnotados = jugadorEquipo->puntosAnotados;
}
void inicializarListaEquipos(stNodoEquipo **listaEquipos) {
    *listaEquipos = NULL;
}
void inicializarListaJugador(stNodoJugador **listaJugador) {
    *listaJugador = NULL;
}
stNodoEquipo *agregarEquipoALista(stNodoEquipo *listaEquipos, stEquipo *equipo) {
    stNodoEquipo *nuevoNodoEquipo = crearNodoEquipo(equipo);
    if( listaEquipos == NULL )
        listaEquipos = nuevoNodoEquipo;
    else {
        nuevoNodoEquipo->siguiente = listaEquipos;
        listaEquipos = nuevoNodoEquipo;
    }
    return listaEquipos;
}
stNodoJugador *agregarJugadorAEquipo(stNodoJugador *listaJugadores, stJugador *jugador) {
    stNodoJugador *nodoJugador = crearNodoJugador(jugador);
    //mostrarNodoJugador(nodoJugador); //debug
    if( listaJugadores == NULL )
        listaJugadores = nodoJugador;
    else {
        nodoJugador->siguiente = listaJugadores;
        listaJugadores = nodoJugador;
    }
    return listaJugadores;
}
stNodoJugador *crearNodoJugador(stJugador *jugador) {
    stNodoJugador *nuevoJugador = (stNodoJugador *)malloc(sizeof(stNodoJugador));
    nuevoJugador->siguiente = NULL;
    nuevoJugador->jugador.idJugador = jugador->idJugador;
    strcpy(nuevoJugador->jugador.nombreJugador, jugador->nombreJugador);
    nuevoJugador->jugador.nroCamisetaJugador = jugador->nroCamisetaJugador;
    nuevoJugador->jugador.puntosAnotados = jugador->puntosAnotados;
    return nuevoJugador;
}
void mostrarNodoJugador(stNodoJugador *nodoJugador) {
    printf("\n !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n nodoJugador: %p", nodoJugador);
    printf("\n nodoJugador->siguiente: %p", nodoJugador->siguiente);
    printf("\n idJugador: %i", nodoJugador->jugador.idJugador);
    printf("\n nroCamisetaJugador: %i", nodoJugador->jugador.nroCamisetaJugador);
    printf("\n nombreJugador: %s", nodoJugador->jugador.nombreJugador);
    printf("\n puntosAnotados: %i", nodoJugador->jugador.puntosAnotados);
    printf("\n !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
}
void mostrarListaJugadores(stNodoJugador *listaJugadores) {
    if( listaJugadores == NULL ) printf("\nLa lista esta vacia");
    if( listaJugadores != NULL ) {
        while( listaJugadores != NULL ) {
            mostrarNodoJugador(listaJugadores);
            listaJugadores = listaJugadores->siguiente;
        }
    }
}
stNodoEquipo *crearNodoEquipo(stEquipo *equipo) {
    stNodoEquipo *nuevoNodoEquipo = (stNodoEquipo *)malloc(sizeof(stNodoEquipo));
    nuevoNodoEquipo->equipo = *equipo;
    //mostrarEquipo(&(nuevoNodoEquipo->equipo)); //DEBUG
    nuevoNodoEquipo->siguiente = NULL;
    inicializarListaJugador(&(nuevoNodoEquipo->listaJugador));
    return nuevoNodoEquipo;
}
void mostrarNodoEquipo(stNodoEquipo *nodoEquipo) {
    printf("\n nodoEquipo: %p", nodoEquipo);
    printf("\n nodoEquipo->siguiente: %p", nodoEquipo->siguiente);
    printf("\n nodoEquipo->listaJugador: %p", nodoEquipo->listaJugador);
    printf("\n nodoEquipo->equipo.idEquipo: %i", nodoEquipo->equipo.idEquipo);
    printf("\n nodoEquipo->equipo.idEquipo: %s", nodoEquipo->equipo.nombreEquipo);
}
void mostrarListaEquipos(stNodoEquipo *listaEquipos) {
    if( listaEquipos == NULL ) printf("\nLa lista esta vacia");
    if( listaEquipos != NULL ) {
        while( listaEquipos != NULL ) {
            printf("\n %s", listaEquipos->equipo.nombreEquipo);
            listaEquipos = listaEquipos->siguiente;
        }
    }
}
