#include <cstdlib>
#include <cstdio>
#include <cstring>
// COLORS TO PRINT
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_RED     "\x1b[31m"
#define COLOR_RESET   "\x1b[0m"


int isPrime(int number) {
  /* 
   * En matemáticas, un número primo es un número natural 
   * mayor que 1 que tiene únicamente dos divisores positivos 
   * distintos: él mismo y el 1 
  */
  if (number < 2) { 
    return false; 
  }

  for (int i = 2; i * i <= number; i++) {
    if (number % i == 0) {
      return false;
    }
  }
  return true;
}

int checkArgs(int argc, char *argv[]){
  return argc > 1 && strcmp(argv[1], "-test") == 0;
}

void printStatus(const char* text, int result){
  char status[18];
  char buffer[100];
  char combined[256];
  int green = result == EXIT_SUCCESS;
  sprintf(status, "%s%s", green ? COLOR_GREEN : COLOR_RED, green ? "[PASSED]" : "[FAILED]");
  sprintf(buffer,"* (Test: \"%s\")", text);
  printf("%-70s %8s %s\n", buffer, status, COLOR_RESET);
}

char* getTestOutput(const char* text, int result){
  char status[18];
  char buffer[100];
  char combined[256];
  char* cadena = (char*)malloc(256 * sizeof(char));

  int green = result == EXIT_SUCCESS;
  sprintf(status, "%s%s", green ? COLOR_GREEN : COLOR_RED, green ? "[PASSED]" : "[FAILED]");
  sprintf(buffer,"* (Test: \"%s\")", text);
  sprintf(combined, "%-70s %8s %s\n", buffer, status, COLOR_RESET);
  strcpy(cadena, combined);
  return cadena;
}
