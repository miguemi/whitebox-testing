#include <cstdlib>
#include <stdio.h>
#include <cstring>
#include <time.h>
#include "funcs.h"

//TYPE DEFS
typedef int (* FuncPtr)();

// FUNCIONES DE AYUDA
int isPrime(int num);
char* getTestOutput(const char* text, int result);

// SUITE DE PRUEBAS
int checkNegativeNumberSet();
int checkCompositeNumberSet();
int checkPrimeNumberSet();
int checkLargePrimeNumber();
int checkBaseCaseNum1();

int executeTests(){
  FuncPtr pruebas[] = {checkBaseCaseNum1, checkPrimeNumberSet, checkCompositeNumberSet, checkNegativeNumberSet, checkLargePrimeNumber};
  const char* nombres[] = {"Comprobar caso numero 1", "Comprobar set numeros primos", "Comprobar set numeros compuestos", "Comprobar de numeros negativos", "Comprobar numero primo grande", };
  int testSize = sizeof(pruebas) / sizeof(pruebas[0]);
  // TEST RESULT VARIABLES
  clock_t start_time, end_time;
  double test_time;
  //START TRACKING
  start_time = clock();

  for (int i = 0; i < testSize; i++) {
    int resultado = pruebas[i]();
    char* resultString = getTestOutput(nombres[i], resultado);
    printf("%s", resultString);
    free(resultString);

    if(resultado == EXIT_FAILURE){
      end_time = clock();
      test_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
      return EXIT_FAILURE;
    }
  }
  //CALCULATE TEST DURATION
  end_time = clock();
  test_time =((double)(end_time - start_time)) / CLOCKS_PER_SEC; 
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
  int largePrime = 2147483647;
  // int largePrime = 46273;
  return isPrime(largePrime) ? EXIT_SUCCESS : EXIT_FAILURE;
}
