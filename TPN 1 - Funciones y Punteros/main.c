#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define DIM 12

float calcularPromedioArrayInt(int [], int );
float calcularMaximaPrecipitacionDelMes(int , int , int , float [][31]);

int main() {
    mostrarMenu();
    menu();

    return 0;
}
void mostrarMenu() {
    printf("\nTrabajo Practico N° 1: Funciones y punteros");
    mostrarEjercicio1();
    mostrarEjercicio2();
    printf("\n\n3. Hacer una funcion que reciba como parametro un arreglo de numeros enteros de un digito y retorne el valor decimal");
    printf("\nde dicho numero. Por ejemplo, un arreglo que tiene cargados los valores 3, 2, 8 y 9, la fn retorna el valor 3289.");
    printf("\n\n4. Hacer una funcion que retorne la posicion del valor maximo de un arreglo de numeros enteros. ");
    mostrarEjercicio5();
    printf("\n\n6. Dada una cadena de caracteres, hacer una funcion que determine si dicha cadena es palindromo (se lee de igual forma de");
    printf("\nadelante para atras como viceversa) o no. La funcion recibe como parametro la cadena y retorna 1 o 0 segun sea la respuesta.");
    printf("\n\n7. Hacer una funcion que intercambie el contenido de dos variables. (pasaje de parametros por referencia)");
    printf("\n\n8. Dados dos arreglos de numeros enteros ordenados de menor a mayor, hacer una funcion que los reciba como parametros y ");
    printf("\nretorne un tercer arreglo que contenga los datos de los arreglos anteriores, tambien ordenados. Se los debe intercalar. ");
    printf("\n\n9. Dados dos arreglos paralelos, uno con apellidos y otro con edades. Se debe hacer un programa para encontrar el ");
    printf("\napellido de la persona de mayor edad. Se debe modularizar. ");
    printf("\n\n10. Hacer una funcion que reciba como parametros de entrada un arreglo de enteros y su dimension, y tres parametros de salida, ");
    printf("\ntres numeros enteros que representen: valor maximo, valor minimo y promedio. Se debe usar pasaje de parametros por referencia. ");
}
void mostrarEjercicio1() {
    printf("\n\n1. Se tiene un arreglo de numeros enteros positivos. Se desea obtener el promedio de sus valores. Para ello se debe: ");
    printf("\n a. Hacer una funcion que inicialice las celdas del arreglo en menos 1. ");
    printf("\n b. Hacer una funcion que permita al usuario ingresar los valores. No se conoce la cantidad de antemano. ");
    printf("\n c. Hacer una funcion que sume el contenido del arreglo y lo retorne. ");
    printf("\n d. Hacer una funcion que cuente la cantidad de valores ingresados. ");
    printf("\n e. Hacer una funcion que reciba como parametro el arreglo ya cargado, calcule y retorne el valor promedio ");
    printf("\n usando las funciones anteriores (c y d). ");
    printf("\n f. Hacer la funcion main correspondiente. ");
}
void mostrarEjercicio2() {
    printf("\n\n2. Invertir el contenido de un arreglo de caracteres. Para ello se debe modularizar de la siguiente forma: ");
    printf("\n a. Hacer una funcion para la carga del arreglo. ");
    printf("\n b. Hacer una funcion para invertir el arreglo. ");
    printf("\n c. Hacer una funcion para mostrar el contenido del arreglo. ");
    printf("\n d. Hacer la funcion main con el menu correspondiente. ");
}
void mostrarEjercicio5() {
    printf("\n\n5. Sea una matriz de numeros enteros, de dimensiones: 12 filas y 31 columnas. Contienen las precipitaciones ");
    printf("\ncorrespondientes a un anio entero. Las filas corresponden a los meses y las columnas a los dias. Se pide: ");
    printf("\n a. Hacer una funcion para cargar la matriz de forma automatica. ");
    printf("\n b. Hacer una funcion que retorne el dia de maxima precipitacion para un mes determinado. ");
    printf("\n c. Hacer una funcion que cargue en un arreglo de 12 posiciones el resultado de aplicar la fn anterior a cada mes de anio.");
    printf("\n d. Hacer la funcion main con el menu correspondiente. ");
}
void menu() {
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
            ejercicioNumero5();
            break;
        case 6:
            ejercicioNumero6();
            break;
        case 7:
            ejercicioNumero7();
            break;
        case 8:
            ejercicioNumero8();
            break;
        case 9:
            ejercicioNumero9();
            break;
        case 10:
            ejercicioNumero10();
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
void ejercicioNumero1() {
    int arrayInt[DIM];
    int validosArrayInt = DIM;
    char incisoEjercicio;
    char continuar = 'c';
    generarArrayInt(arrayInt, DIM);
    while( continuar == 'c' ) {
        mostrarEjercicio1();
        mostrarArrayInt(arrayInt, DIM);
        printf("\n\nIngrese el inciso a ejecutar ('0' para salir):");
        fflush(stdin);
        scanf("%c", &incisoEjercicio);
        incisoEjercicio = tolower(incisoEjercicio);
        switch( incisoEjercicio ) {
        case 'a':
            ejercicio1IncisoA(arrayInt, validosArrayInt);
            break;
        case 'b':
            ejercicio1IncisoB(arrayInt, &validosArrayInt);
            break;
        case 'c':
            ejercicio1IncisoC(arrayInt, validosArrayInt);
            break;
        case 'd':
            ejercicio1IncisoD(arrayInt);
            break;
        case 'e':
            ejercicio1IncisoE(arrayInt, validosArrayInt);
            break;
        case '0':
            continuar = 's';
            break;
        default:
            printf("\nEl inciso ingresado es incorrecto.");
            break;
        }
        if( continuar != 's' ) {
            printf("\n\nDesea continuar ejecutando el ejercicio 1? ('c' para continuar):");
            fflush(stdin);
            scanf("%c", &continuar);
            continuar = tolower(continuar);
        }
    }
}
void generarArrayInt(int arrayInt[], int validosArrayInt) {
    for( int i = 0 ; i < validosArrayInt ; i++ ) arrayInt[i] = rand()%10;
}
void mostrarArrayInt(int arrayInt[], int validosArrayInt){
    printf("\n------------------------------------------------------------\n");
    for( int i = 0 ; i < validosArrayInt ; i++ ) printf("|%i| ", arrayInt[i]);
    printf("\n------------------------------------------------------------\n");
}

void ejercicio1IncisoA(int arrayInt[], int validosArrayInt) {
    inicializarArrayInt(arrayInt, validosArrayInt);
    mostrarArrayInt(arrayInt, validosArrayInt);
}
void inicializarArrayInt(int arrayInt[], int validosArrayInt) {
    for( int i = 0 ; i < validosArrayInt ; i++ ) arrayInt[i] = -1;
}

void ejercicio1IncisoB(int arrayInt[], int *validosArrayInt) {
    ingresarValoresArrayInt(arrayInt, validosArrayInt);
    mostrarArrayInt(arrayInt, *validosArrayInt);
}
void ingresarValoresArrayInt(int arrayInt[], int *validosArrayInt) {
    int i = 0;
    char continuar = 'c';
    while( continuar == 'c' ) {
        arrayInt[i] = ingresarValorInt();
        i++;
        continuarIngresandoValores(&continuar);
    }
    *validosArrayInt = i;
}
int ingresarValorInt() {
    int valorAIngresar;
    printf("\nIngrese un valor entero para cargar:");
    fflush(stdin);
    scanf("%i", &valorAIngresar);
    return valorAIngresar;
}
void continuarIngresandoValores(char *continuar) {
    printf("\nDesea continuar ingresando valores? ('c' para continuar):");
    fflush(stdin);
    scanf("%c", continuar);
}

void ejercicio1IncisoC(int arrayInt[], int validosArrayInt) {
    mostrarArrayInt(arrayInt, validosArrayInt);
    int sumaArrayInt = sumarArrayInt(arrayInt, validosArrayInt);
    printf("\nLa suma de los elementos del array es de: %i", sumaArrayInt);
}
int sumarArrayInt(int arrayInt[], int validosArrayInt) {
    int sumaArrayInt = 0;
    for( int i = 0 ; i < validosArrayInt ; i++ ) sumaArrayInt += arrayInt[i];
    return sumaArrayInt;
}

void ejercicio1IncisoD() {
    //utilizo validos por puntero, la funcion de carga de datos automaticamente calcula este valor
}

void ejercicio1IncisoE(int arrayInt[], int validosArrayInt) {
    float promedio = calcularPromedioArrayInt(arrayInt, validosArrayInt);
    printf("\nEl promedio del arreglo es de: %f", promedio);
}
float calcularPromedioArrayInt(int arrayInt[], int validosArrayInt) {
    float promedio;
    int sumaArrayInt = sumarArrayInt(arrayInt, validosArrayInt);
    promedio = (float) sumaArrayInt / validosArrayInt;
    return promedio;
}

void ejercicioNumero2() {
    char arrayChar[DIM*10];
    char incisoEjercicio;
    char continuar = 'c';
    while( continuar == 'c' ) {
        mostrarEjercicio2();
        printf("\n\nIngrese el inciso a ejecutar ('0' para salir):");
        fflush(stdin);
        scanf("%c", &incisoEjercicio);
        incisoEjercicio = tolower(incisoEjercicio);
        switch( incisoEjercicio ) {
        case 'a':
            ejercicio2IncisoA(arrayChar);
            break;
        case 'b':
            ejercicio2IncisoB(arrayChar);
            break;
        case 'c':
            ejercicio2IncisoC(arrayChar);
            break;
        default:
            printf("\nEl inciso ingresado es incorrecto.");
            break;
        }
        if( continuar != 's' ) {
            printf("\n\nDesea continuar ejecutando el ejercicio 2? ('c' para continuar):");
            fflush(stdin);
            scanf("%c", &continuar);
            continuar = tolower(continuar);
        }
    }
}

void ejercicio2IncisoA(char arrayChar[]) {
    cargarArrayChar(arrayChar);
    printf("\nLa cadena de caracteres ingresada es: '%s'", arrayChar);
}
void cargarArrayChar(char arrayChar[]) {
    printf("\nIngrese una cadena de caracteres: \n");
    fflush(stdin);
    gets(arrayChar);
}

void ejercicio2IncisoB(char arrayChar[]) {
    printf("\nInvirtiendo elementos del arreglo...");
    invertirArrayChar(arrayChar);
    printf("\n%s", arrayChar);
}
void invertirArrayChar(char arrayChar[]) {
    char *punteroArrayCharIzquierda = arrayChar;
    char *punteroArrayCharDerecha = arrayChar;
    while( *punteroArrayCharDerecha ) punteroArrayCharDerecha++;
    punteroArrayCharDerecha--; //lo posiciono en la ultima ubicacion del array
    while( punteroArrayCharIzquierda < punteroArrayCharDerecha ) {
        intercambiarValoresChar(punteroArrayCharIzquierda, punteroArrayCharDerecha);
        punteroArrayCharIzquierda++;
        punteroArrayCharDerecha--;
    }
}
void intercambiarValoresChar(char *punteroChar1, char *punteroChar2) {
    char auxiliar;
    auxiliar = *punteroChar1;
    *punteroChar1 = *punteroChar2;
    *punteroChar2 = auxiliar;
}

void ejercicio2IncisoC(char arrayChar[]) {
    printf("\n------------------------------------------------------------\n");
    mostrarArrayChar(arrayChar);
    printf("\n------------------------------------------------------------");
}
void mostrarArrayChar(char arrayChar[]) {
    for( int i = 0 ; arrayChar[i] != '\0' ; i++ ) printf("%c", arrayChar[i]);
}

void ejercicioNumero3() {
    int validosArrayInt = DIM/2;
    int arrayInt[validosArrayInt];
    int arrayIntDecimal;
    generarArrayInt(arrayInt, validosArrayInt);
    mostrarArrayInt(arrayInt, validosArrayInt);
    arrayIntDecimal = convertirArrayIntADecimal(arrayInt, validosArrayInt);
    printf("\n%i", arrayIntDecimal);
}
int convertirArrayIntADecimal(int arrayInt[], int validosArrayInt) {
    int arrayIntDecimal = 0;
    for( int i = 0 ; i < validosArrayInt ; i++ ) arrayIntDecimal += (int)(pow(10, i) * arrayInt[i]);
    return arrayIntDecimal;
}

void ejercicioNumero4() {
    int arrayInt[DIM];
    int posicionMaximo;
    generarArrayInt(arrayInt, DIM);
    mostrarArrayInt(arrayInt, DIM);
    posicionMaximo = calcularPosicionMaximoArrayInt(arrayInt, DIM);
    printf("\nPosicion del valor maximo dentro del array: '%i'", posicionMaximo);
}
int calcularPosicionMaximoArrayInt(int arrayInt[], int validosArrayInt) {
    int posicionMaximo = 0;
    int valorMaximo = 0;
    valorMaximo = arrayInt[0];
    for( int i = 0 ; i < validosArrayInt ; i++ )
        if( arrayInt[i] > valorMaximo ) {
            valorMaximo = arrayInt[i];
            posicionMaximo = i;
        }
    return posicionMaximo;
}

void ejercicioNumero5() {
    int meses = 12;
    int dias = 31;
    float matrizPrecipitaciones[meses][dias];

    char incisoEjercicio;
    char continuar = 'c';
    while( continuar == 'c' ) {
        mostrarEjercicio5();
        printf("\n\nIngrese el inciso a ejecutar ('0' para salir):");
        fflush(stdin);
        scanf("%c", &incisoEjercicio);
        incisoEjercicio = tolower(incisoEjercicio);
        switch( incisoEjercicio ) {
        case 'a':
            ejercicio5IncisoA(meses, dias, matrizPrecipitaciones);
            break;
        case 'b':
            ejercicio5IncisoB(meses, dias, matrizPrecipitaciones);
            break;
        case 'c':
            ejercicio5IncisoC(meses, dias, matrizPrecipitaciones);
            break;
        default:
            printf("\nEl inciso ingresado es incorrecto.");
            break;
        }
        if( continuar != 's' ) {
            printf("\n\nDesea continuar ejecutando el ejercicio 2? ('c' para continuar):");
            fflush(stdin);
            scanf("%c", &continuar);
            continuar = tolower(continuar);
        }
    }
}
void ejercicio5IncisoA(int meses, int dias, float matrizPrecipitaciones[][dias]) {
    cargarMatrizPrecipitaciones(meses, dias, matrizPrecipitaciones);
    mostrarMatrizPrecipitaciones(meses, dias, matrizPrecipitaciones);
}
void cargarMatrizPrecipitaciones(int meses, int dias, float matrizPrecipitaciones[][dias]) {
    for( int i = 0 ; i < meses ; i++ )
        for( int j = 0 ; j < dias ; j++ )
            matrizPrecipitaciones[i][j] = (float)( (rand()%100) + (rand()%100) * 0.01 );
}
void mostrarMatrizPrecipitaciones(int meses, int dias, float matrizPrecipitaciones[][dias]) {
    for( int i = 0 ; i < meses ; i++ ) {
        printf("\n Mes %i:\n", i + 1);
        for( int j = 0 ; j < dias ; j++ )
            printf("|%.2f| ", matrizPrecipitaciones[i][j]);
    }
}

void ejercicio5IncisoB(int meses, int dias, float matrizPrecipitaciones[][dias]) {
    int mesACalcular;
    float maximaPrecipitacion;
    printf("\nIngrese el numero de mes para calcular la maxima presipitacion diaria:");
    fflush(stdin);
    scanf("%i", &mesACalcular);
    mesACalcular--;
    maximaPrecipitacion = calcularMaximaPrecipitacionDelMes(mesACalcular, meses, dias, matrizPrecipitaciones);
    printf("\nLa precipitacion maxima del mes %i es de: %.2f", mesACalcular, maximaPrecipitacion);
}
float calcularMaximaPrecipitacionDelMes(int mesACalcular, int meses, int dias, float matrizPrecipitaciones[][dias]) {
    float maximaPrecipitacion = 0;
    for( int i = 0 ; i < dias ; i++ )
        if( maximaPrecipitacion < matrizPrecipitaciones[mesACalcular][i])
            maximaPrecipitacion = matrizPrecipitaciones[mesACalcular][i];
    return maximaPrecipitacion;
}

void ejercicio5IncisoC(int meses, int dias, float matrizPrecipitaciones[][dias]) {
    float arrayMaximasPrecipitaciones[meses];
    calcularMaximaPrecipitacionDeCadaMes(meses, dias, matrizPrecipitaciones, arrayMaximasPrecipitaciones);
    mostrarArrayMaximasPrecipitaciones(meses, arrayMaximasPrecipitaciones);
}
void calcularMaximaPrecipitacionDeCadaMes(int meses, int dias, float matrizPrecipitaciones[][dias], float arrayMaximasPrecipitaciones[]) {
    for( int i = 0 ; i < meses ; i++)
        arrayMaximasPrecipitaciones[i] = calcularMaximaPrecipitacionDelMes(i, meses, dias, matrizPrecipitaciones);
}
void mostrarArrayMaximasPrecipitaciones(int meses, float arrayMaximasPrecipitaciones[]) {
    printf("\n------------------------------------------------------------\n");
    for( int i = 0 ; i < meses ; i++ ) printf("|%.2f|", arrayMaximasPrecipitaciones[i]);
    printf("\n------------------------------------------------------------");
}

void ejercicioNumero6() {
    char arrayChar[] = {"abcdedbca"};
    int esPalindromo;
    printf("\nCadena de caracteres: %s", arrayChar);
    esPalindromo = arrayCharEsPalindromo(arrayChar);
    esPalindromo? printf("\nLa cadena es un palindromo.") : printf("\nLa cadena no es un palindromo.") ;
}
int arrayCharEsPalindromo(char arrayChar[]) {
    int esPalindromo = 1;
    char *punteroCadenaIzquierda = arrayChar;
    while( *arrayChar ) arrayChar++;
    char *punteroCadenaDerecha = arrayChar - 1; //se posiciona al final de la cadena
    arrayChar = punteroCadenaIzquierda;
    while( punteroCadenaIzquierda < punteroCadenaDerecha ) {
        if( *punteroCadenaIzquierda != *punteroCadenaDerecha ) esPalindromo = 0;
        punteroCadenaIzquierda++;
        punteroCadenaDerecha--;
    }
    return esPalindromo;
}

void ejercicioNumero7() {
    int numero1 = 5;
    int numero2 = 7;
    printf("\nNumero1: %i, Numero2: %i", numero1, numero2);
    printf("\nIntercambiando valores de las variables...");
    intercambiarValoresInt(&numero1, &numero2);
    printf("\nNumero1: %i, Numero2: %i", numero1, numero2);
}
void intercambiarValoresInt(int *numero1, int *numero2) {
    int auxiliar = *numero1;
    *numero1 = *numero2;
    *numero2 = auxiliar;
}

void ejercicioNumero8() {
    int arrayInt1[] = { 2, 3, 3, 7, 8, 12 };
    int arrayInt2[] = { 1, 1, 8, 9, 11, 13 };
    int validosArrayInt1 = 6;
    int validosArrayInt2 = 6;
    int arrayIntercalado[DIM];
    int validosArrayIntercalado;
    printf("\nArreglos ordenados:");
    mostrarArrayInt(arrayInt1, validosArrayInt1);
    mostrarArrayInt(arrayInt2, validosArrayInt2);
    validosArrayIntercalado = intercalarOrdenadoArrayInt(arrayInt1, validosArrayInt1, arrayInt2, validosArrayInt2, arrayIntercalado);
    mostrarArrayInt(arrayIntercalado, validosArrayIntercalado);
}
int intercalarOrdenadoArrayInt(int arrayInt1[], int validosArrayInt1, int arrayInt2[], int validosArrayInt2, int arrayIntercalado[]) {
    int i = 0, j = 0, k = 0;
    while( i != validosArrayInt1 || j != validosArrayInt2 ) {
        if( arrayInt1[i] < arrayInt2[j] ) {
            arrayIntercalado[k] = arrayInt1[i];
            printf("\narrayIntercalado[k]: %i, arrayInt1[i]: %i", arrayIntercalado[k], arrayInt1[i]);
            i++;
        } else {
            arrayIntercalado[k] = arrayInt2[j];
            printf("\narrayIntercalado[k]: %i, arrayInt2[j]]: %i", arrayIntercalado[k], arrayInt2[j]);
            j++;
        }
        printf("\ni: %i, j: %i, k: %i", i, j, k);
        k++;
    }
    return k;
}

void ejercicioNumero9() {
    char apellidos[4][30];
    int edad[4];
    int posPersonaMayorEdad;
    cargarApellidos(apellidos, 4);
    generarEdades(edad);
    mostrarPersonas(apellidos, edad, 4);
    posPersonaMayorEdad = posicionPersonaMayorEdad(apellidos, edad, 4);
    printf("\nApellido de la persona de mayor edad: %s", apellidos[posPersonaMayorEdad]);
}
void cargarApellidos(char apellidos[][30]) {
    char continuar = 'c';
    int i = 0;
    while( continuar == 'c' ) {
        if( i < 4 ) {
            cargarApellido(apellidos, i);
            if( i != 3 ) deseaContinuar(&continuar);
        } else {
            continuar = 'q';
        }
        i++;
    }
}
void cargarApellido(char apellidos[][30], int i) {
    printf("\nApellido a ingresar: ");
    fflush(stdin);
    gets(apellidos[i]);
}
void deseaContinuar(char *continuar) {
    printf("\nDesea continuar ingresando apellidos? ('c' para continuar):");
    fflush(stdin);
    scanf("%c", continuar);
}
void generarEdades(int edad[]) {
    for( int i = 0 ; i < 4 ; i++ ) edad[i] = rand()%20 + 18;
}
void mostrarPersonas(char apellidos[][30], int edad[], int validos) {
    for( int i = 0 ; i < validos ; i++ ) {
        printf("\n------------------------------------------------------------\n");
        printf("\nPersona codigo: %i", i);
        printf("\nApellido: %s", apellidos[i]);
        printf("\nEdad: %i", edad[i]);
        printf("\n------------------------------------------------------------");
    }
}
int posicionPersonaMayorEdad(char apellidos[][30], int edad[], int validos) {
    int mayorEdad = 0;
    int posicionMayorEdad = 0;
    for( int i = 0 ; i < validos ; i++ )
        if( mayorEdad < edad[i] ) {
            mayorEdad = edad[i];
            posicionMayorEdad = i;
        }
    return posicionMayorEdad;
}

void ejercicioNumero10() {
    int arrayInt[DIM];
    int validosArrayInt = DIM;
    int valorMaximo;
    int valorMinimo;
    float promedio;
    cargarArrayInt(arrayInt, DIM);
    mostrarArrayInt(arrayInt, DIM);
    calcularMaximoMinimoPromedioArrayInt(arrayInt, validosArrayInt, &valorMaximo, &valorMinimo, &promedio);
    printf("\nvalorMaximo: %i, valorMinimo: %i, promedio: %.2f", valorMaximo, valorMinimo, promedio);
}
void cargarArrayInt(int arrayInt[], int validos) {
    for( int i = 0 ; i < validos ; i++ ) arrayInt[i] = rand()%10;
}
void calcularMaximoMinimoPromedioArrayInt(int arrayInt[], int validosArrayInt, int *valorMaximo, int *valorMinimo, float *promedio) {
    int suma = 0;
    *valorMaximo = arrayInt[0];
    *valorMinimo = arrayInt[0];
    for( int i = 0 ; i < validosArrayInt ; i++ ) {
        suma += arrayInt[i];
        if( *valorMaximo < arrayInt[i] ) *valorMaximo = arrayInt[i];
        if( *valorMinimo > arrayInt[i] ) *valorMinimo = arrayInt[i];
    }
    *promedio = (float) suma / validosArrayInt;
}
