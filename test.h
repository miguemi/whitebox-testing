// test_result.h
#ifndef TEST_RESULT_H
#define TEST_RESULT_H

typedef struct {
  double execute_time;
  char** output_list;
  int exit_code;
} TestResult;

#endif // TEST_RESULT_H
TestResult executeTests();
