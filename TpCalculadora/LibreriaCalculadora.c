#include <stdio.h>
#include <stdlib.h>
#include "LibreriaCalculadora.h"

int pedirNumero(){
        int numero;
        printf("Ingrese un numero: ");
        scanf("%d", &numero);
        return numero;
}
int sumarNumeros( int numeroUno,int  numeroDos){
    int resultado;
    resultado=numeroUno+numeroDos;
    return resultado;
    }
int restarNumeros(int numeroUno,int numeroDos){
    int resultado;
    resultado=numeroUno-numeroDos;
    return resultado;
    }
float dividirNumeros(int numeroU,int numeroD){
    float resultado;

    resultado=(float)numeroU/numeroD;

    return resultado;
    }
int multiplicarNumeros(int numeroUno,int numeroDos){
    int resultado;
    resultado=(numeroUno*numeroDos);
    return resultado;
}
int calcularFactoriales(int numero){
    int resultado;
    if (numero<0){
        resultado=-1;
    }
    else if(numero==0||numero==1){
        resultado=1;
    }
   else{
        resultado= numero*calcularFactoriales(numero-1);
   }

    return resultado;
}
void calculadora(){
    int numeroA;
    int numeroB;
    float resultado;
    int resultadoFactorialA;
    int resultadoFactorialB;
    numeroA=pedirNumero();
    numeroB=pedirNumero();


    printf("El numero asignado a A= %d.\nY el numero asignado a B= %d", numeroA, numeroB);
    resultado=sumarNumeros(numeroA,numeroB);

    printf("\nLa suma de %d y %d es: %.1f",numeroA, numeroB,resultado);

    resultado=restarNumeros(numeroA,numeroB);
    printf("\nLa resta de %d y %d es: %.1f",numeroA, numeroB,resultado);

    resultado=multiplicarNumeros(numeroA,numeroB);
    printf("\nLa multiplicacion de %d y %d es: %.2f",numeroA, numeroB,resultado);

    resultado=dividirNumeros((float)numeroA,(float)numeroB);
    if(numeroB==0){
        printf("\nNo se puede dividir entre 0");
    }
    else{
    printf("\nLa division de %d entre %d es: %f",numeroA, numeroB,resultado);
    }
    resultadoFactorialA=calcularFactoriales(numeroA);

    if(resultadoFactorialA==-1){
        printf("\nNo existe el factorial de los negativos");
    }
    else if(numeroA>11){
        printf("\nEl numero es demasiado grande para ser factoreado.");
    }
    else{
        printf("\nEl factorial de %d es:%d",numeroA,resultadoFactorialA);
    }
    resultadoFactorialB=calcularFactoriales(numeroB);
    if (resultadoFactorialB==-1){
        printf("\nNo existe el factorial de los negativos");
    }
    else if(numeroB>11){
        printf("\nEl numero es demasiado grande para ser factoreado.");
    }
    else{
    printf("\nEl factorial de %d es:%d",numeroB, resultadoFactorialB);
    }
    preguntarAlUsuario();
    }
void preguntarAlUsuario(){
    char respuestaUsuario;
    printf("\n¿Desea continuar ingresando numeros?");
    fflush(stdin);
    scanf("%c",&respuestaUsuario);
    if(respuestaUsuario=='s'){
        calculadora();
    }
    else{
        printf("Gracias por utilizar la calculadora.");
    }
    }


