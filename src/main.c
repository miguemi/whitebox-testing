#include <cstdlib>
#include <stdio.h>
#include "tests.h"
#include "utils.h"

int executeTests(); 
int isPrime(int number);
int checkArgs(int argc, char *argv[]);
void mainProgram();

int main(int argc, char *argv[]) {
  if (checkArgs(argc, argv)) {
    int exitCode = executeTests();
    return exitCode;
  }
  mainProgram();
  return EXIT_SUCCESS;
}

void mainProgram(){
  int numero;
  char c = 'c';

  do {
    system("cls||clear");
    printf("\nPor favor ingresa un numero: ");
    int elementosLeidos = scanf("%d", &numero);
    if (elementosLeidos != 1) {
      while (getchar() != '\n'); 
      continue; 
    }
    int prime = isPrime(numero);
    printf("\nEl número \"%d\" es %s.", numero, prime ? "PRIMO" : "NO PRIMO");
    printf("\n\nPor favor presiona la tecla \'c\' para continuar: ");
    scanf(" %c", &c);
  }while(c == 'c');
}
