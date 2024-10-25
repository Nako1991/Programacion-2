#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 30

typedef struct {
    char nombre[DIM];
    char genero;
    int edad;
} stPersona;

typedef struct{
     int valores[100];
     int posicionTope;
} stPila;

char seleccionarGenero();
char ingresarGenero();
char generarGeneroRandom();
stPersona *copiarGeneroAArregloDinamico(stPersona [], int , char );

int main()
{
    mostrarMenu();
    menu();
    return 0;
}
void mostrarMenu() {
    printf("\nTrabajo Practico Numero 2: Estructuras de Datos Estaticas y Dinamicas.");
    printf("\n\n1. Dada la estructura:");
    printf("\n\n | typedef struct {");
    printf("\n |   char nombre[30];");
    printf("\n |   char genero;");
    printf("\n |   int edad;");
    printf("\n | }persona;");
    printf("\n\n a. Crear un arreglo estatico de 30 elementos de esta estructura y cargarlo mediante una funcion.");
    printf("\n b. Hacer una funcion que cuente la cantidad de un genero determinado.");
    printf("\n c. Hacer una funcion que copie los datos de todos los registros de un genero determinado del arreglo");
    printf("\nanterior en otro arreglo del tamanio justo. Usar malloc dentro de la funcion y retornarlo o usar dos");
    printf("\nparametros de tipo arreglo y crear el arreglo dinamico antes de la invocacion.");
    printf("\n\n2. Codificar el algoritmo de ordenamiento por seleccion, sobre la estructura anterior teniendo en");
    printf("\ncuenta la edad como criterio de ordenacion.");
    printf("\n\n3. Simular el uso de una pila de enteros a partir de la siguiente estructura:");
    printf("\n\n | typedef struct{");
    printf("\n | int valores[100];");
    printf("\n | int posTope;");
    printf("\n | } Pila;");
    printf("\n\nImplementar las siguientes funciones:");
    printf("\n void apilar(Pila * p, int valor);");
    printf("\n int desapilar(Pila * p);");
    printf("\n int tope(Pila * p);");
    printf("\n int pilavacia(Pila * p);");
    printf("\n void mostrar(Pila * p);");
    printf("\n void leer (Pila * p);");
    printf("\n void inicPila(Pila * p);");
    printf("\n\n4. Dadas dos pilas (como las anteriores) que se supone que tienen sus datos ordenados, generar una");
    printf("\ntercer pila que contenga los datos de las dos anteriores intercalados, de forma tal que queden ordenados.");
    printf("\n\n5. Funcion insertar en orden en un arreglo.");
    printf("\n\n6. Algoritmo de ordenamiento por insercion.");
    printf("\n\n7. Funcion eliminar un elemento de un arreglo. (ver por desplazamiento si es ordenado)");
    printf("\n\n8. Sistema de notas. Se tiene que administrar un sistema para un curso con 20 alumnos que cursan 5");
    printf("\nmaterias diferentes. Se deben almacenar los datos de los alumnos y las notas que obtuvieron en el examen");
    printf("\nfinal de cada materia.");
    printf("\nPara ello se utilizaran las siguientes estructuras:");
    printf("\n\n | typedef struct {      | typedef struct {        | typedef struct {");
    printf("\n | int matricula;        |   int codigo;           |   int matricula;");
    printf("\n | char nombre[30];      |   char nombreMat[20];   |   int codigo;");
    printf("\n | } Alumno;             | Materia;                |   int nota;");
    printf("\n                                                   | } Nota;");
    printf("\n\nY las siguientes variables:");
    printf("\n\n | Alumno alus[20]; // para almacenar los datos de los 20 alumnos.");
    printf("\n | Materia mats[5]; // para almacenar los codigos y nombres de las 5 materias.");
    printf("\n | Nota notas[100]; // para almacenar todas las notas de los alumnos.");
    printf("\n\nLas notas se almacenan en forma desordenada para todos los alumnos.");
    printf("\n\nSe deben hacer las siguientes funciones:");
    printf("\n 1. Cargar el arreglo de Materia.");
    printf("\n 2. Agregar un Alumno.");
    printf("\n 3. Agregar una Nota, validando que exista 'matricula' y 'codigo'. La funcion debe retornar 1 si la");
    printf("\n operacion fue exitosa y 0 (cero) en Scaso contrario.");
    printf("\n 4. Hacer una funcion que muestre por pantalla el nombre del alumno y la lista de materias con sus");
    printf("\n respectivas notas. La funcion debe recibir como parametro el nombre del alumno. Estrategia: con el");
    printf("\n nombre del alumno se busca su matricula en el arreglo alus, luego se recorre el arreglo notas filtrandolo");
    printf("\n por matricula, y con el codigo se accede al nombre de la materia revisando el arreglo mats.");
}
void menu() {
    stPersona personas[DIM];
    int validosPersonas = 12;
    srand(time(NULL));
    int numeroEjercicio;
    char continuar = 'c';
    while( continuar == 'c' ) {
        mostrarMenu();
        printf("\n\nIngrese el numero de ejercicio a ejecutar ('0' para salir):");
        fflush(stdin);
        scanf("%i", &numeroEjercicio);
        switch( numeroEjercicio ) {
        case 1:
            ejercicioNumero1(personas, validosPersonas);
            break;
        case 2:
            ejercicioNumero2(personas, validosPersonas);
            break;
        case 3:
            ejercicioNumero3();
            break;
        case 4:
            ejercicioNumero4();
            break;
        case 5:
            ejercicioNumero5();
            break;
        case 6:
            ejercicioNumero6();
            break;
        case 7:
            //ejercicioNumero7();
            break;
        case 8:
            //ejercicioNumero8();
            break;
        case 0:
            continuar = 's';
            break;
        default:
            printf("\nEl numero de ejercicio ingresado es incorrecto.");
            break;
        }
        if( continuar != 's' ) {
            printf("\n\nDesea continuar ejecutando la guia? ('c' para continuar):");
            fflush(stdin);
            scanf("%c", &continuar);
            continuar = tolower(continuar);
        }
    }
}

void ejercicioNumero1(stPersona personas[], int validos) {
    int cantidadGenero = 0;
    char generoSeleccionado;
    generarPersonas(personas, validos); //a.
    cantidadGenero = contarGenero(personas, validos); //b.
    printf("\ncantidadGenero: %i", cantidadGenero); //debug
    generoSeleccionado = seleccionarGenero();
    printf("\nGenero Seleccionado: %c", generoSeleccionado);
    copiarGeneroAArregloDinamico(personas, validos, generoSeleccionado); //c
}
void generarPersonas(stPersona personas[], int validos) {
    for( int i = 0 ; i < validos ; i++ ) {
        generarNombre(personas, i);
        generarGenero(personas, i);
        generarEdad(personas, i);
        printf("\n"); //debug
    }
}
void generarNombre(stPersona personas[], int indice) {
    int i;
    int espacioRandom = 0;
    for( i = 0 ; i < 24 ; i++ ) {
        espacioRandom = rand()%10;
        if( espacioRandom == 0 ) {
            personas[indice].nombre[i] = 32;
        } else {
            personas[indice].nombre[i] = rand()%25+65;
        }
    }
    personas[indice].nombre[i] = '\0';
    printf("\nNombre Persona %i: %s", indice, personas[indice].nombre); //debug
}
void generarGenero(stPersona personas[], int indice) {
    int generoRandom;
    generoRandom = rand()%3;
    if( generoRandom == 0 ) personas[indice].genero = 'f';
    if( generoRandom == 1 ) personas[indice].genero = 'm';
    if( generoRandom == 2 ) personas[indice].genero = 'o';
    printf("\nGenero Persona %i: %c", indice, personas[indice].genero); //debug
}
void generarEdad(stPersona personas[], int indice) {
    personas[indice].edad = rand()%30+18;
    printf("\nEdad Persona %i: %i", indice, personas[indice].edad); //debug
}
int contarGenero(stPersona personas[], int validos) {
    int contarGenero = 0;
    char generoRandom;
    generoRandom = rand()%3;
    if( generoRandom == 0 ) generoRandom = 'f';
    if( generoRandom == 1 ) generoRandom = 'm';
    if( generoRandom == 2 ) generoRandom = 'o';
    printf("\ngeneroRandom: %i, generoRandom: %c", generoRandom, generoRandom); //debug
    for( int i = 0 ; i < validos ; i++ ) if( personas[i].genero == generoRandom ) contarGenero++;
    printf("\ncontarGenero: %i", contarGenero);
    return contarGenero;
}
char seleccionarGenero() {
    char generoSeleccionado;
    //generoSeleccionado = ingresarGenero(); //manual
    generoSeleccionado = generarGeneroRandom(); //automatico
    return generoSeleccionado;
}
char generarGeneroRandom() {
    int generoRandom;
    generoRandom = rand()%3;
    if( generoRandom == 0 ) generoRandom = 'f';
    if( generoRandom == 1 ) generoRandom = 'm';
    if( generoRandom == 2 ) generoRandom = 'o';
    return generoRandom;
}
char ingresarGenero() {
    char generoIngresado;
    printf("\n\nIngrese el genero:");
    fflush(stdin);
    scanf("%c", &generoIngresado);
    return generoIngresado;
}
stPersona *copiarGeneroAArregloDinamico(stPersona personas[], int validos, char genero) {
    stPersona *personasDinamico = (stPersona *) malloc( sizeof(personas[0]) * validos );
    int j = 0;
    for( int i = 0 ; i < validos ; i++ )
        if( personas[i].genero == genero ) {
            copiarPersona(personas, personasDinamico, i, j);
            mostrarPersona(personasDinamico, j); //debug
            j++;
        }
}
void copiarPersona(stPersona personas[], stPersona personasDinamico[], int indiceI, int indiceJ) {
    strcpy(personasDinamico[indiceJ].nombre, personas[indiceI].nombre);
    personasDinamico[indiceJ].genero = personas[indiceI].genero;
    personasDinamico[indiceJ].edad = personas[indiceI].edad;
}
void mostrarPersona(stPersona personas[], int indice) {
    printf("\nNombre Persona %i: %s", indice, personas[indice].nombre); //debug
    printf("\nGenero Persona %i: %c", indice, personas[indice].genero); //debug
    printf("\nEdad Persona %i: %i", indice, personas[indice].edad); //debug
}

void ejercicioNumero2(stPersona personas[], int validos) {
    ordenarPersonasPorEdad(personas, validos);
    mostrarPersonas(personas, validos);
}
void ordenarPersonasPorEdad(stPersona personas[], int validos) { //no ordena el primer elemento CONSULTAR
    int j = 0;
    int posicionMenor;
    for( int i = 0 ; i < validos ; i++ ) {
        posicionMenor = encontrarMenorEdad(personas, validos, i);
        printf("\nposicionMenor: %i", posicionMenor); //debug
        intercambiarPersonas(personas, posicionMenor, j);
        j++;
    }
}
int encontrarMenorEdad(stPersona personas[], int validos, int index) {
    int posicionMenor = 0;
    int edadMenor = personas[0].edad;
    for( int i = index ; i < validos ; i++ )
        if( edadMenor > personas[i].edad ) {
            edadMenor = personas[i].edad;
            posicionMenor = i;
        }
    return posicionMenor;
}
void intercambiarPersonas(stPersona personas[], int origen, int destino) {
    stPersona personaAux;
    strcpy(personaAux.nombre, personas[origen].nombre);
    personaAux.genero = personas[origen].genero;
    personaAux.edad = personas[origen].edad;
    strcpy(personas[origen].nombre, personas[destino].nombre);
    personas[origen].genero = personas[destino].genero;
    personas[origen].edad = personas[destino].edad;
    strcpy(personas[destino].nombre, personaAux.nombre);
    personas[destino].genero = personaAux.genero;
    personas[destino].edad = personaAux.edad;
}
void mostrarPersonas(stPersona personas[], int validos) {
    for( int i = 0 ; i < validos ; i++ ) mostrarPersona(personas, i);
}

void ejercicioNumero3() {
    stPila pila1;
    menuPilas(&pila1);
}
void menuPilas(stPila *pila) {
    char continuar = 'c';
    int seleccionMenu;
    while( continuar == 'c' ) {
        mostrarMenuPilas();
        seleccionarMenu(&seleccionMenu);
        switch( seleccionMenu ) {
        case 1:
            ejemploInicPila(pila);
            break;
        case 2:
            ejemploApilar(pila);
            break;
        case 3:
            ejemploDesapilar(pila);
            break;
        case 4:
            ejercicioLeer(pila);
            break;
        case 5:
            ejercicioTope(pila);
            break;
        case 6:
            ejercicioMostrar(pila);
            break;
        case 7:
            ejercicioPilaVacia(pila);
            break;
        case 0:
            continuar = 's';
            break;
        default:
            printf("\nEl numero de ejercicio ingresado es incorrecto.");
            break;
        }
        if( continuar != 's' ) continuarMenu(&continuar);
    }
}
void mostrarMenuPilas() {
    printf("\n\nEjemplos de funciones de pilas: ");
    printf("\n1. InicPila");
    printf("\n2. Apilar");
    printf("\n3. Desapilar");
    printf("\n4. Leer");
    printf("\n5. Tope");
    printf("\n6. Mostrar");
    printf("\n7. Pilavacia");
}
void seleccionarMenu(int *seleccionMenu) {
    printf("\n\nIngrese el indice del menu a ejecutar ('0' para salir): ");
    fflush(stdin);
    scanf("%i", seleccionMenu);
}
void continuarMenu(char *continuar) {
    printf("\n\nDesea continuar ejecutando el menu de pilas? ('c' para continuar):");
    fflush(stdin);
    scanf("%c", continuar);
    *continuar = tolower(*continuar);
}

void ejemploInicPila(stPila *pila) {
    printf("\nInicializando la pila...");
    inicPila(pila);
    printf("\nPosicion del tope: %i", pila->posicionTope);
}
void inicPila(stPila *pila) {
    pila->posicionTope = -1;
}

void ejemploApilar(stPila *pila) {
    int valorAApilar = rand()%10;
    printf("\nApilando un valor en la pila...");
    apilar(pila, valorAApilar);
    printf("\nValor apilado: %i, Posicion del tope actualizada: %i", pila->valores[pila->posicionTope], pila->posicionTope);
}
void apilar(stPila *pila, int valor){
    pila->posicionTope++;
    pila->valores[pila->posicionTope] = valor;
}

void ejemploDesapilar(stPila *pila){
    printf("\nDesapilando un valor de la pila...");
    desapilar(pila);
    printf("\nMostrando Valor del tope nuevo: %i", pila->valores[pila->posicionTope]);
}
int desapilar(stPila *pila) {
    if( pila->posicionTope >= 0 ) pila->posicionTope--;
    return pila->valores[pila->posicionTope + 1];
}

void ejercicioLeer(stPila *pila) {
    printf("\nValor del tope: %i", pila->valores[pila->posicionTope]);
    leer(pila);
    printf("\nValor del tope: %i", pila->valores[pila->posicionTope]);
}
void leer(stPila *pila) {
    int valorAIngresar = 0;
    printf("\nIngrese el valor entero que desea cargar a la pila: ");
    fflush(stdin);
    scanf("%i", &valorAIngresar);
    apilar(pila, valorAIngresar);
}

void ejercicioTope(stPila *pila) {
    printf("\nValor del tope de la pila: %i", tope(*pila));
}
int tope(stPila pila) {
   return pila.valores[pila.posicionTope];
}

void ejercicioMostrar(stPila *pila) {
    printf("\nMostrando la pila...\n");
    mostrar(*pila);
}
void mostrar(stPila pila) {
    printf("\nBASE ------------------------------------------------------------ TOPE\n");
    for( int i = 0 ; i <= pila.posicionTope ; i++ ) printf("|%i| ", pila.valores[i]);
    printf("\nBASE ------------------------------------------------------------ TOPE\n");
}

void ejercicioPilaVacia(stPila *pila) {
    printf("\nComprobando si la pila esta vacia...");
    pilaVacia(*pila)? printf("\nLa pila esta vacia.") : printf("\nLa pila contiene al menos un elemento.");
}
int pilaVacia(stPila pila) {
    if( pila.posicionTope == -1 ) return 1;
    if( pila.posicionTope != -1 ) return 0;
}

void ejercicioNumero4() {
    stPila pila1;
    inicPila(&pila1);
    stPila pila2;
    inicPila(&pila2);
    stPila pilaIntercalada;
    inicPila(&pilaIntercalada);
    generarPilaOrdenada(&pila1);
    generarPilaOrdenada(&pila2);
    mostrar(pila1);
    mostrar(pila2);
    printf("\nIntercalando pilas...");
    intercalarPilasOrdenadamente(pila1, pila2, &pilaIntercalada);
    printf("\nPilaIntercalada: ");
    mostrar(pilaIntercalada);
}
void generarPilaOrdenada(stPila *pila) {
    int valorGenerado = 0;
    for( int i = 0 ; i < 10 ; i++ ) {
        valorGenerado += rand()%3;
        apilar(pila, valorGenerado);
    }
}
void intercalarPilasOrdenadamente(stPila pila1, stPila pila2, stPila *pilaIntercalada) {
    invertirPila(&pila1);
    //mostrar(pila1); //debug
    invertirPila(&pila2);
    //mostrar(pila2); //debug
    while( !pilaVacia(pila1) && !pilaVacia(pila2) ) {
            if( tope(pila1) < tope(pila2) )  apilar(pilaIntercalada, desapilar(&pila1));
            if( tope(pila2) <= tope(pila1) ) apilar(pilaIntercalada, desapilar(&pila2));
    }
    while( pilaVacia(pila1) && !pilaVacia(pila2) ) apilar(pilaIntercalada, desapilar(&pila2));
    while( pilaVacia(pila2) && !pilaVacia(pila1) ) apilar(pilaIntercalada, desapilar(&pila1));
}
void invertirPila(stPila *pila){
    int i = 0;
    int aux;
    while( i <= (pila->posicionTope - i) ) {
        aux = pila->valores[i];
        pila->valores[i] = pila->valores[pila->posicionTope - i];
        pila->valores[pila->posicionTope - i] = aux;
        //printf("\nBucle: %i", i);
        //printf("\npila->valores[%i]: %i, pila->valores[%i]: %i", i, pila->valores[i], pila->posicionTope - i, pila->valores[pila->posicionTope - i]);
        i++;
    }
}

void ejercicioNumero5() {
    int arrayInt[12];
    int validosArrayInt = 12;
    int enteroAInsertar;
    generarArrayIntOrdenado(arrayInt, 12);
    mostrarArrayInt(arrayInt, 12);
    ingresarEntero(&enteroAInsertar);
    printf("\nEl entero a insertar en el array es: %i", enteroAInsertar);
    validosArrayInt = insertarEnteroOrdenadamente(arrayInt, validosArrayInt, enteroAInsertar);
    printf("\nArreglo con el valor insertado:");
    mostrarArrayInt(arrayInt, validosArrayInt);
}
void generarArrayIntOrdenado(int arrayInt[], int validos) {
    int valorGenerado = 0;
    for( int i = 0 ; i < validos ; i++ ) {
            valorGenerado += rand()%3;
            arrayInt[i] = valorGenerado;
    }
}
void mostrarArrayInt(int array[], int validos) {
    printf("\n------------------------------------------------------------\n");
    for( int i = 0 ; i < validos ; i++ ) printf("|%i| ", array[i]);
    printf("\n------------------------------------------------------------\n");
}
void ingresarEntero(int *entero) {
    printf("\nIngrese el entero que desea insertar en el array: ");
    fflush(stdin);
    scanf("%i", entero);
}
int insertarEnteroOrdenadamente(int arrayInt[], int validos, int enteroAInsertar) {
    int i, j, auxiliar, posicionAInsertar;
    j = 0;
    posicionAInsertar = 0;
    for( i = 0 ; i < validos ; i++ ) {
        if( enteroAInsertar >= arrayInt[i] ) posicionAInsertar++;
        if( enteroAInsertar < arrayInt[i] ) {
            arrayInt[ validos - j] = arrayInt[ validos - j - 1];
            j++;
        }
        //printf("\nauxiliar: %i, arrayInt[%i]: %i, arrayInt[%i]: %i", auxiliar,i, arrayInt[i], i + 1, arrayInt[i + 1]);
    }
    arrayInt[posicionAInsertar] = enteroAInsertar;
    return validos + 1;
}

void ejercicioNumero6() {
    int arrayInt[12];
    int validosArrayInt = 12;
    int enteroAInsertar;
    generarArrayInt(arrayInt, 12);
    mostrarArrayInt(arrayInt, 12);
    printf("\nOrdenando arreglo de enteros por insercion...");
    ordenarArrayIntPorInsercion(arrayInt, validosArrayInt);
    mostrarArrayInt(arrayInt, validosArrayInt);
}
void generarArrayInt(int arrayInt[], int validos) {
    for( int i = 0 ; i < validos ; i++ ) arrayInt[i] = rand()%10;
}
void ordenarArrayIntPorInsercion(int arrayInt[], int validos) {
    int i, j, seleccion;
    for( int i = 1 ; i < validos ; i++ ) {
        j = i;
        while( j >= 0 ) {
            if( arrayInt[j] < arrayInt[j - 1] ) intercambiarArrayInt(arrayInt, j, j-1);
            j--;
        }
    }
}
void intercambiarArrayInt(int arrayInt[], int indice1, int indice2) {
    int aux;
    aux = arrayInt[indice1];
    arrayInt[indice1] = arrayInt[indice2];
    arrayInt[indice2] = aux;
}
