#include <cstdlib>
#include <stdio.h>
#include "funcs.h"

typedef int (* FuncPtr)();

// FUNCIONES DE AYUDA
int isPrime(int num);
void printStatus(const char* text, int result);

// SUITE DE PRUEBAS
int checkNegativeNumberSet();
int checkCompositeNumberSet();
int checkPrimeNumberSet();
int checkLargePrimeNumber();
int checkBaseCaseNum1();


int executeTests(){
  FuncPtr pruebas[] = {checkBaseCaseNum1, checkPrimeNumberSet, checkCompositeNumberSet, checkNegativeNumberSet, checkLargePrimeNumber};
  const char* nombres[] = {
    "Comprobar caso de numero 1", "Comprobar set de numeros primos",
    "Comprobar set de numeros compuestos", "Comprobar set de numeros negativos",
    "Comprobar numero primo grande", 
  };

  printf("%-70s %8s \n\n", "NOMBRE DE LA PRUEBA", "ESTADO");

  for (int i = 0; i < sizeof(pruebas) / sizeof(pruebas[0]); i++) {
    int resultado = pruebas[i]();
    printStatus(nombres[i], resultado);
    if(resultado == EXIT_FAILURE){
      return resultado;
    }
  }
  return EXIT_SUCCESS;
}


// AREA DE PRUEBAS
int checkBaseCaseNum1(){
  return isPrime(1) ? EXIT_FAILURE : EXIT_SUCCESS;
}

int checkPrimeNumberSet(){
  int primes[]= {2,3,5,7,11,13,17,19,23};
  for(int i = 0; i < sizeof(primes)/sizeof(primes[0]); i++){
    if(!isPrime(primes[i])){
      return EXIT_FAILURE;
    }
  }
  return EXIT_SUCCESS;
}

int checkCompositeNumberSet(){
  int composites[] = {4,6,8,9,10,12,14,15,16};
  for(int i = 0; i < sizeof(composites)/sizeof(composites[0]); i++){
    if(isPrime(composites[i])){
      return EXIT_FAILURE;
    }
  }
  return EXIT_SUCCESS;
}

int checkNegativeNumberSet(){
  for (int i=-1; i>=-10 ; i--) {
    if(isPrime(i)){
      return EXIT_FAILURE;
    }
  }
  return EXIT_SUCCESS;
}

int checkLargePrimeNumber(){
  // int largePrime = 2147483647;
  int largePrime = 46273;
  return isPrime(largePrime) ? EXIT_SUCCESS : EXIT_FAILURE;
}
