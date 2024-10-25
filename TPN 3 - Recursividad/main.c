#include <stdio.h>
#include <stdlib.h>

int main() {
    menu();
    return 0;
}
void mostrarMenu()
{
    printf("\nTrabajo Practico Numero 3 - Recursion");
    printf("\n1) Calcular el factorial de un numero en forma recursiva");
    printf("\n2) Calcular la potencia de un número en forma recursiva");
    printf("\n3) Recorrer un arreglo y mostrar sus elementos en forma recursiva");
    printf("\n4) Recorrer un arreglo comenzando desde la posicion 0 y mostrar sus elementos en forma invertida (recursivo)");
    printf("\n5) Determinar en forma recursiva si un arreglo es capicua");
    printf("\n6) Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de la suma");
    printf("\n7) Buscar el menor elemento de un arreglo en forma recursiva");
    printf("\n8) Ingresar valores a una variable de tipo char (por teclado) y mostrarlo en el orden inverso (hasta ingresar un ‘*’) de forma recursiva. NO usar arreglos");
    printf("\n9) Determinar si un arreglo contiene un determinado elemento de forma recursiva. (Pueden intentarlo tambien con una funcion void)(Tener en cuenta para un arreglo desordenado y el caso para un arreglo ordenado)");
    printf("\n10) Determinar el promedio de un arreglo con Recursividad");
    printf("\n11) Funcion suma digitos, recibe un numero entero y me devuelva la suma de sus digitos");
    printf("\n12) Funcion que cuente digitos pares. Recibe un numero entero y devuelve cuantos numeros de esos digitos son pares");
    printf("\n13) Funcion es primo, recibe el numero y el divisor. Debe retornar si es primo o no el numero");
    printf("\n14) Funcion contar mayores. Recibe un arreglo, un numero para fijarnos cuantos numeros hay mayores a ese numero");
    printf("\n15) Funcion invertir digitos. Reciba un numero que invierta sus digitos");
}
void menu() {
    srand(time(NULL));
    int numeroEjercicio;
    char continuar = 'c';
    while( continuar == 'c' )
    {
        mostrarMenu();
        printf("\n\nIngrese el numero de ejercicio a ejecutar ('0' para salir):");
        fflush(stdin);
        scanf("%i", &numeroEjercicio);
        switch( numeroEjercicio )
        {
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
            //ejercicioNumero9();
            break;
        case 10:
            //ejercicioNumero10();
            break;
        case 11:
            //ejercicioNumero11();
            break;
        case 12:
            //ejercicioNumero12();
            break;
        case 0:
            continuar = 's';
            break;
        default:
            printf("\nEl numero de ejercicio ingresado es incorrecto.");
            break;
        }
        if( continuar != 's' )
        {
            printf("\n\nDesea continuar ejecutando la guia? ('c' para continuar):");
            fflush(stdin);
            scanf("%c", &continuar);
            continuar = tolower(continuar);
        }
    }
}
void ejercicioNumero1() {
    int numero;
    int numeroFactorizado;
    numero = ingresarNumeroAFactorizar();
    numeroFactorizado = factorizarNumeroEntero(numero);
    printf("\nEl factorial de %i es: %i", numero, numeroFactorizado);
}
int ingresarNumeroAFactorizar() {
    int numero;
    printf("\n\nIngrese el numero a factorizar:");
    fflush(stdin);
    scanf("%i", &numero);
    return numero;
}
int factorizarNumeroEntero(int numero) {
    int numeroFactorizado;
    if( numero == 0 ) numeroFactorizado = 1;
    else numeroFactorizado = numero * factorizarNumeroEntero(numero - 1);
    //printf("\nnumero: %i, numeroFactorizado: %i", numero, numeroFactorizado); //debug
    return numeroFactorizado;
}

void ejercicioNumero2() {
    int numero;
    int potencia;
    int numeroPotenciado;
    ingresarNumeroAPotenciar(&numero, &potencia);
    numeroPotenciado = potenciarNumero(numero, potencia);

}
void ingresarNumeroAPotenciar(int *numero, int *potencia) {
    printf("\nIngrese el numero a potenciar: ");
    fflush(stdin);
    scanf("%i", numero);
    printf("\nIngrese la potencia: ");
    fflush(stdin);
    scanf("%i", potencia);
}
int potenciarNumero(int numero, int potencia) {
    int numeroPotenciado;
    if( potencia == 0 ) numeroPotenciado = 1;
    else numeroPotenciado = numero * potenciarNumero(numero, potencia - 1);
    printf("\nnumero: %i, , potencia: %i, numeroPotenciado: %i", numero, potencia, numeroPotenciado); //debug
    return numeroPotenciado;
}

void ejercicioNumero3() {
    int arrayInt[12];
    int validos = 12;
    generarArrayInt(arrayInt, validos);
    mostrarArrayInt(arrayInt, validos);
    mostrarArrayIntRecursivo(arrayInt, validos, 0);
}
void generarArrayInt(int arrayInt[], int validos) {
    for( int i = 0 ; i < validos ; i++ ) arrayInt[i] = rand()%10;
}
void mostrarArrayIntRecursivo(int arrayInt[], int validos, int i) {
    if( i == validos ) return 0;
    else {
        printf("|%i| ", arrayInt[i]);
        mostrarArrayIntRecursivo(arrayInt, validos, i + 1);
    }
}

void ejercicioNumero4() {
    int arrayInt[12];
    int validos = 12;
    generarArrayInt(arrayInt, validos);
    mostrarArrayInt(arrayInt, validos);
    mostrarArrayIntInvertidoRecursivo(arrayInt, validos, 0);
}
void mostrarArrayInt(int arrayInt[], int validos) {
    printf("\n------------------------------------------------------------\n");
    for( int i = 0 ; i < validos ; i++ ) printf("|%i| ", arrayInt[i]);
    printf("\n------------------------------------------------------------\n");
}
void mostrarArrayIntInvertidoRecursivo(int arrayInt[], int validos, int i) {
    if( i == validos ) return 0;
    else {
        printf("|%i| ", arrayInt[validos-1 - i]);
        mostrarArrayIntInvertidoRecursivo(arrayInt, validos, i + 1);
    }
}

void ejercicioNumero5() {
    int capicua;
    int arrayInt1[] = { 3, 1, 7, 1, 3 };
    int arrayInt2[] = { 2, 5, 1, 2, 9 };
    int validos = 5;
    mostrarArrayInt(arrayInt1, validos);
    mostrarArrayInt(arrayInt2, validos);
    capicua = esCapicuaRecursivo(arrayInt1, 0, validos-1);
    printf("\nArreglo 1:");
    capicua? printf("\nEl arreglo es capicua.") : printf("\nEl arreglo no es capicua.");
    capicua = esCapicuaRecursivo(arrayInt2, 0, validos-1);
    printf("\nArreglo 2:");
    capicua? printf("\nEl arreglo es capicua.") : printf("\nEl arreglo no es capicua.");
}
int esCapicuaRecursivo(int arrayInt[], int inicio, int fin) {
    if( inicio > fin ) return 1;
    else {
        //printf("\narrayInt[%i]: %i, arrayInt[%i]: %i", inicio, arrayInt[inicio], fin, arrayInt[fin]); //debug
        if( arrayInt[inicio] == arrayInt[fin] ) esCapicuaRecursivo(arrayInt, fin-1, inicio+1);
        else return 0;
    }
}

void ejercicioNumero6() {
    int arrayInt[12];
    int validos = 12;
    int suma;
    generarArrayInt(arrayInt, validos);
    mostrarArrayInt(arrayInt, validos);
    suma = sumarArrayIntRecursivo(arrayInt, validos-1);
    printf("\nLa suma del array es de: %i", suma);
}
int sumarArrayIntRecursivo(int arrayInt[], int posicion){
    int suma = arrayInt[posicion];
    if( posicion == -1 ) return 0;
    else {
        //printf("\n arrayInt[%i]: %i, suma: %i", posicion, arrayInt[posicion], suma); //debug
        suma += sumarArrayIntRecursivo(arrayInt, posicion - 1);
    }
    return suma;
}

void ejercicioNumero7() {
    int arrayInt[12];
    int validos = 12;
    int menor;
    generarArrayInt(arrayInt, validos);
    mostrarArrayInt(arrayInt, validos);
    menor = buscarMenorRecursivoInt(arrayInt, validos, arrayInt[validos - 1], validos - 1);
    printf("\nEl menor valor del array es: %i", menor);
}
int buscarMenorRecursivoInt(int arrayInt[], int validos, int menor, int posicion) {
    if( posicion == 0 ) return arrayInt[0];
    else {
        //printf("\n'if( arrayInt[posicion] < menor ) menor = arrayInt[posicion];'"); //debug
        //printf("\n'if( %i < %i )", arrayInt[posicion], menor); //debug
        //arrayInt[posicion] < menor ? printf(" si. \n menor = %i", arrayInt[posicion]) : printf(" no. \n menor = %i", menor) ; //debug
        menor = buscarMenorRecursivoInt(arrayInt, validos, menor, posicion - 1);
        if( arrayInt[posicion] < menor ) menor = arrayInt[posicion];
        //printf("\nmenor: %i", menor); //debug
        return menor;
    }
}

void ejercicioNumero8() { //crash
    int menor;
    int bufferInt;
    char nombreArchivoInt[] = {"integers.bin"};
    FILE *archivoInt = fopen(nombreArchivoInt, "ab");
    if( archivoInt == NULL )
        printf("\nEl archivo no existe.");
    else
        menor = buscarMenorRecursivoArchivoInt(archivoInt, bufferInt);
    fclose(archivoInt);
    printf("\nmenor: %i", menor);
}
int buscarMenorRecursivoArchivoInt(FILE *archivoInt, int bufferInt, int menor) {
    if( feof(archivoInt) ) menor = bufferInt;
    else {
        while( !feof(archivoInt) ) {
            fread(&bufferInt, sizeof(int), 1, archivoInt);
            if( !feof(archivoInt) ) {
                menor = buscarMenorRecursivoArchivoInt(archivoInt, bufferInt, menor);
                if( bufferInt < menor ) menor = bufferInt;
            }
        }
        return menor;
    }
}
