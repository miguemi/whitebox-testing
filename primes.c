#include <cstdlib>
#include <stdio.h>
#include "test.h"
#include "funcs.h"

TestResult executeTests(); 
int isPrime(int number);
int checkArgs(int argc, char *argv[]);

int main(int argc, char *argv[]) {
  if (checkArgs(argc, argv)) {
    TestResult result = executeTests();
    int exitCode = result.exit_code;
    double time = result.execute_time;
    int sizeMsg = 5;
    for (int i = 0; i < sizeMsg; i++) {
      printf(result.output_list[i]);
      free(result.output_list[i]);
    }

    printf("Ejecucion de pruebas finalizada: %d", time);
    free(result.output_list);

    return exitCode;
  }

  return EXIT_SUCCESS;
}
