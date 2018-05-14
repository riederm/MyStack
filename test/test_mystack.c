#include "vendor/unity.h"
#include "../src/mystack.h"
#include <stdlib.h>

MyStack* stack = NULL;

void setUp(void) {
    stack = stack_create();
}

void tearDown(void) {
    stack_delete(stack);
}

void test_stack_create(void)
{
  TEST_ASSERT_NOT_NULL(stack);
  TEST_ASSERT_EQUAL_INT(-1, stack->top);

  for (size_t i = 0; i < MAX_STACK_SIZE; i++) {
    TEST_ASSERT_EQUAL_INT_MESSAGE(0, stack->data[i], "data should be 0");
  }
}


void test_stack_push_onStackWithOneElement(void){
  // GIVEN a stack with one element "1"
  stack->data[0] = 1;
  stack->top = 0;

  // WHEN I push a "2" onto the stack
  int result = stack_push(stack, 2);

  // THEN top should be 1 and data[1] should be 2
  TEST_ASSERT_EQUAL_INT(1, stack->top);
  TEST_ASSERT_EQUAL_INT(2, stack->data[1]);

  //AND the stack returned TRUE
  TEST_ASSERT_TRUE_MESSAGE(result, "push returned false for non-full stack");

  // AND it did not change the rest of the stack
  TEST_ASSERT_EQUAL_INT(1, stack->data[0]);
  for (size_t i = 2; i < MAX_STACK_SIZE; i++) {
    TEST_ASSERT_EQUAL_INT(0, stack->data[i]);
  }
}


void test_stack_push_stackIsFull(void){
    //GIVEN a full stack
    stack->top = MAX_STACK_SIZE-1;

    //WHEN I try to push another element
    bool result = stack_push(stack, 4711);

    //THEN the stack should return false
    TEST_ASSERT_FALSE_MESSAGE(result, "stack_push returned false");

    //AND top was not changed
    TEST_ASSERT_EQUAL_INT(
          MAX_STACK_SIZE-1,
          stack->top);
}


void test_stack_pop_fromEmptyStack(void){
  int value = -1;
  //GIVEN an empty stack

  //WHEN i try to pop
  bool result = stack_pop(stack, &value);

  //THEN it should return false ...
  TEST_ASSERT_FALSE(result);

  //AND the value pointer should not be changed
  TEST_ASSERT_EQUAL(-1, value);
}

void test_stack_pop_fromFilledStack(void){
  //GIVEN a filled stack
  stack_push(stack, 1);
  stack_push(stack, 2);
  stack_push(stack, 3);

  //WHEN I try to pop
  int value = -1;
  bool result = stack_pop(stack, &value);

  //THEN I expect a successful pop and the top item
  TEST_ASSERT_TRUE(result);
  TEST_ASSERT_EQUAL(3, value);
}

void test_stack_pop_everything(){
  //GIVEN a filled stack
  stack_push(stack, 1);
  stack_push(stack, 2);
  stack_push(stack, 3);

  //WHEN I try to pop
  int values[3];
  bool results[3];


  results[0] = stack_pop(stack, &values[0]);
  results[1] = stack_pop(stack, &values[1]);
  results[2] = stack_pop(stack, &values[2]);

  //THEN I expect a successful pop and the top item
  TEST_ASSERT_TRUE(results[0]);
  TEST_ASSERT_EQUAL(3, values[0]);

  TEST_ASSERT_TRUE(results[1]);
  TEST_ASSERT_EQUAL(2, values[1]);

  TEST_ASSERT_TRUE(results[2]);
  TEST_ASSERT_EQUAL(1, values[2]);
}


int main(void)
{
   UnityBegin("MyStack");

   RUN_TEST(test_stack_create);
   RUN_TEST(test_stack_push_onStackWithOneElement);
   RUN_TEST(test_stack_push_stackIsFull);
   RUN_TEST(test_stack_pop_fromEmptyStack);
   RUN_TEST(test_stack_pop_fromFilledStack);
   RUN_TEST(test_stack_pop_everything);
   UnityEnd();
   return 0;
}
