#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include "funcs.h"

//type definitions
typedef int (* FuncPtr)();

typedef struct {
  double execute_time;
  char** output_list;
  int success;
} TestResult;

// FUNCIONES DE AYUDA
int isPrime(int num);
void printStatus(const char* text, int result);
char* getTestOutput(const char* text, int result);

// SUITE DE PRUEBAS
int checkNegativeNumberSet();
int checkCompositeNumberSet();
int checkPrimeNumberSet();
int checkLargePrimeNumber();
int checkBaseCaseNum1();




int executeTests(){

  TestResult result;
  clock_t start_time, end_time;
  double exec_time;

  FuncPtr pruebas[] = {checkBaseCaseNum1, checkPrimeNumberSet, checkCompositeNumberSet, checkNegativeNumberSet, checkLargePrimeNumber};
  const char* nombres[] = {
    "Comprobar caso numero 1", "Comprobar set numeros primos",
    "Comprobar set numeros compuestos", "Comprobar de numeros negativos",
    "Comprobar numero primo grande", 
  };
  int testSize = sizeof(pruebas) / sizeof(pruebas[0]);

  //START TRACKING TIME
  start_time = clock();

  for (int i = 0; i < testSize; i++) {
    int resultado = pruebas[i]();
    char* cadena = getTestOutput(nombres[i], resultado);
    printf("xd: %s\n", cadena);
    free(cadena);

    if(resultado == EXIT_FAILURE){
      //CALCULATE TEST DURATION
      end_time = clock();
      exec_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
      result.execute_time = exec_time;
      return resultado;
    }
  }


  //CALCULATE TEST DURATION
  end_time = clock();
  exec_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
  result.execute_time = exec_time;

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
