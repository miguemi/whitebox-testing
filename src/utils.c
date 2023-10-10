#include <cstdlib>
#include <cstdio>
#include <cstring>
// COLORS TO PRINT
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_RED     "\x1b[31m"
#define COLOR_RESET   "\x1b[0m"

int isPrime(int number) {
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

char* getTestOutput(const char* text, int result) {
  char status[32];
  char buffer[128];

  int green = result == EXIT_SUCCESS;
  snprintf(status, sizeof(status), "%s%s", green ? COLOR_GREEN : COLOR_RED, green ? "[PASSED]" : "[FAILED]");
  snprintf(buffer, sizeof(buffer), "* (TEST: \"%s\")", text);

  char* combined = (char*)malloc(256 * sizeof(char));
  snprintf(combined, 256, "%-60s %8s %s\n", buffer, status, COLOR_RESET);

  return combined;
}
