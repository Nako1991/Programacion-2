#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define DIM 12

int *generarArrayIntDinamico(int );
char *copiarArrayCharDinamico(char *, int );
int *copiarArrayIntDinamico(int *, int );

int main()
{
    menu();
    return 0;
}

void menu() {
    srand(time(NULL));
    int numeroEjercicio;
    char continuar = 'c';

    while( continuar == 'c' ) {
        printf("\nIngrese el numero de ejercicio a ejecutar ('0' para salir):");
        fflush(stdin);
        scanf("%i", &numeroEjercicio);
        switch( numeroEjercicio ) {
        case 1:
            //ejercicioNumero1();
            break;
        case 2:
            //ejercicioNumero2();
            break;
        case 3:
            //ejercicioNumero3();
            break;
        case 4:
            //ejercicioNumero4();
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
        case 8:
            //ejercicioNumero8();
            break;
        case 9:
            //ejercicioNumero9();
            break;
        case 10:
            ejercicioNumero10();
            break;
        case 11:
            ejercicioNumero11();
            break;
        case 12:
            ejercicioNumero12();
            break;
        case 13:
            ejercicioNumero13();
            break;
        case 14:
            ejercicioNumero14();
            break;
        case 15:
            ejercicioNumero15();
            break;
        case 16:
            ejercicioNumero16();
            break;
        case 17:
            ejercicioNumero17();
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

void ejercicioNumero10() {
    char arrayChar[] = {"Cadena de caracteres."};
    char caracterBuscado;
    char *punteroCaracterBuscado = &caracterBuscado;
    int caracterEncontrado;
    ingresarCaracterABuscar(punteroCaracterBuscado);
    caracterEncontrado = buscarCaracterArrayChar(arrayChar, punteroCaracterBuscado);
    caracterEncontrado? printf("\nSe encontro el caracter dentro de la cadena.") : printf("\nNo se encontro el caracter dentro de la cadena.");
}
void ingresarCaracterABuscar(char *punteroCaracterBuscado) {
    printf("\nIngrese el caracter a buscar dentro de la cadena:");
    fflush(stdin);
    scanf("%c", punteroCaracterBuscado);
}
int buscarCaracterArrayChar(char *punteroArrayChar, char *punteroCaracterBuscado) {
    int encontrado = 0;
    while( *punteroArrayChar ) {
        if( *punteroArrayChar == *punteroCaracterBuscado ) encontrado = 1;
        punteroArrayChar++;
    }
    return encontrado;
}

void ejercicioNumero11() {
    int *punteroArrayInt = generarArrayIntDinamico(DIM);
    mostrarArrayInt(punteroArrayInt, DIM);
}
int *generarArrayIntDinamico(int dimension) {
    int *punteroArrayInt = (int *) malloc(sizeof(int) * dimension);
    if( *punteroArrayInt == NULL ) printf("\nNo se pudo asignar el espacio de memoria.");
    for( int i = 0 ; i < dimension ; i++ ) punteroArrayInt[i] = rand()%10; //FUNCIONA CON ARRAY Y NO CON ARITMETICA DE PUNTEROS
    return punteroArrayInt;
}
void mostrarArrayInt(int array[], int validos) {
    printf("\n----------------------------------------------------------------\n");
    for(int i = 0; i < validos; i++) printf("|%i| ", array[i]);
    printf("\n----------------------------------------------------------------");
}

void ejercicioNumero12() {
    char arrayChar[] = {"Cadena De Caracteres."};
    int validosArrayChar = 0;
    mostrarArrayChar(arrayChar);
    validosArrayChar = calcularValidosArrayChar(arrayChar);
    printf("\nvalidos: %i", validosArrayChar);
    char *copiaArrayChar = copiarArrayCharDinamico(arrayChar, validosArrayChar);
    mostrarArrayChar(copiaArrayChar);
}
void mostrarArrayChar(char *arrayChar) {
    printf("\n----------------------------------------------------------------\n");
    while( *arrayChar ) {
        printf("%c", *arrayChar);
        arrayChar++;
    }
    printf("\n----------------------------------------------------------------");
}
int calcularValidosArrayChar(char *arrayChar) {
    int validos = 0;
    while( *arrayChar ) {
        validos++;
        arrayChar++;
    }
    return validos;
}
char *copiarArrayCharDinamico(char *arrayChar, int validosArrayChar) {
    int i = 0; //si lo declaro dentro del for, la variable solo existe en ese entorno
    char *arrayCharDinamico = (char *) malloc(sizeof(char) * validosArrayChar);
    if( *arrayCharDinamico == NULL ) printf("\nNo se pudo asignar el espacio de memoria.");
    for( i = 0 ; i < validosArrayChar ; i++ ) arrayCharDinamico[i] = arrayChar[i]; //puedo usar srtcpy
    arrayCharDinamico[i] = '\0'; //requiere declarar i fuera del for
    return arrayCharDinamico;
}

void ejercicioNumero13() {
    int *arrayInt = generarArrayIntDinamico(DIM);
    int validosArrayInt = DIM;
    mostrarArrayInt(arrayInt, validosArrayInt);
    int *copiaArrayInt = copiarArrayIntDinamico(arrayInt, validosArrayInt);
    mostrarArrayInt(copiaArrayInt, validosArrayInt);
}
int *copiarArrayIntDinamico(int *arrayInt, int validosArrayInt) {
    int *arrayIntDinamico = (int *) malloc(sizeof(int) * validosArrayInt);
    if( *arrayIntDinamico == NULL ) printf("\nNo se pudo asignar el espacio de memoria.");
    for( int i = 0 ; i < validosArrayInt ; i++ ) arrayIntDinamico[i] = arrayInt[i];
    return arrayIntDinamico;
}

void ejercicioNumero14() { //ya lo habia resuelto de esta manera
    ejercicioNumero12();
}

void ejercicioNumero15() { //los valores no cambian, cambia donde apuntan los punteros
    int numero1 = rand()%10;
    int numero2 = rand()%10;
    int *punteroNumero1 = &numero1;
    int *punteroNumero2 = &numero2;
    printf("\nValores antes de intercambiar:");
    printf("\nnumero1: %i, numero2: %i", *punteroNumero1, *punteroNumero2);
    intercambiarPunterosAEnteros(&punteroNumero1, &punteroNumero2);
    printf("\nIntercambiando valores...");
    printf("\nnumero1: %i, numero2: %i", *punteroNumero1, *punteroNumero2);
}
void intercambiarPunterosAEnteros(int **punteroDobleNumero1, int **punteroDobleNumero2) {
    int *punteroTemporal = *punteroDobleNumero1;
    *punteroDobleNumero1 = *punteroDobleNumero2;
    *punteroDobleNumero2 = punteroTemporal;
}

void ejercicioNumero16() {
    int *arrayInt = generarArrayIntDinamico(DIM);
    mostrarArrayInt(arrayInt, DIM);
    printf("\nMostrando con punteros dobles...");
    int **punteroDobleArrayInt = &arrayInt;
    mostrarArrayIntPunteroDoble(punteroDobleArrayInt, DIM);
}
void mostrarArrayIntPunteroDoble(int **punteroDobleArrayInt, int validos) {
    printf("\n----------------------------------------------------------------\n");
    for( int i = 0 ; i < validos ; i++ ) printf("|%i| ", *(*punteroDobleArrayInt + i) );
    printf("\n----------------------------------------------------------------\n");
}

void ejercicioNumero17() {
    ejercicioNumero16();
}
