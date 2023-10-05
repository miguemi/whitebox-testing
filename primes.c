#include <cstdlib>
#include <stdio.h>
#include "test.h"
#include "funcs.h"

int executeTests(); 
int isPrime(int number);
int checkArgs(int argc, char *argv[]);

int main(int argc, char *argv[]) {
  if (checkArgs(argc, argv)) {
    // Verificar si se proporcionó el argumento "-test"
    int result = executeTests();
    return result;
  }

  return EXIT_SUCCESS;
}
