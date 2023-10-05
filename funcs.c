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

void printStatus(char* text, int result){
  char buffer[255];
  (result == EXIT_SUCCESS) ? sprintf(buffer, "* (Test: \"%s\") %s[PASSED] %s", text,COLOR_GREEN, COLOR_RESET)
  : sprintf(buffer, "* (Test: \"%s\") %s[FAILED] %s", text, COLOR_RED, COLOR_RESET);
  printf("%s\n", buffer);
}
