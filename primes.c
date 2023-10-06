#include <cstdlib>
#include <stdio.h>
#include "test.h"
#include "funcs.h"

int executeTests(); 
int isPrime(int number);
int checkArgs(int argc, char *argv[]);

int main(int argc, char *argv[]) {
  if (checkArgs(argc, argv)) {
    int exitCode = executeTests();
    return exitCode;
  }

  return EXIT_SUCCESS;
}
