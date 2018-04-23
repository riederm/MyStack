#include "vendor/unity.h"
#include "../src/mystack.h"
#include <stdlib.h>

MyStack* stack;

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

void test_stack_peek(void)
{
  stack->data[0] = 0;
  stack->data[1] = 1;
  stack->data[2] = 2;
  stack->top = 2;

  int value = 0;
  bool result = stack_peek(stack, &value);

  TEST_ASSERT_TRUE(result);
  TEST_ASSERT_EQUAL_INT(2, value);
}

void test_stack_push(void)
{
  //GIVEN an empty stack

  //WHEN I push 7 onto it
  bool result = stack_push(stack, 7);

  //THEN I expect seven at data[0]
  TEST_ASSERT_TRUE(result);
  TEST_ASSERT_EQUAL_INT(7, stack->data[0]);
}

void test_stack_multi_push(void)
{
  //GIVEN an empty stack

  //WHEN I push a couple of numbers onto it
  bool result = stack_push(stack, 7);
  result &= stack_push(stack, 8);
  result &= stack_push(stack, 9);
  result &= stack_push(stack, 10);

  //THEN I expect seven at data[0]
  TEST_ASSERT_TRUE(result);
  TEST_ASSERT_EQUAL_INT(7, stack->data[0]);
  TEST_ASSERT_EQUAL_INT(8, stack->data[1]);
  TEST_ASSERT_EQUAL_INT(9, stack->data[2]);
  TEST_ASSERT_EQUAL_INT(10, stack->data[3]);
  TEST_ASSERT_EQUAL_INT(3, stack->top);
}

void test_stack_pop(void){
  //GIVEN a stack with 1 on it
  stack_push(stack, 1);

  //WHEN I pop an element from it
  int value = -1;
  bool result = stack_pop(stack, &value);

  //THEN I expect to get 1
  TEST_ASSERT_TRUE(result);
  TEST_ASSERT_EQUAL_INT(1, value);
}

void test_stack_multi_pops(void){
  //GIVEN a stack with 1,2,3 on it
  stack_push(stack, 1);
  stack_push(stack, 2);
  stack_push(stack, 3);

  //WHEN I pop all three elements, I expect 3, 2 and 1
  int value = -1;
  bool result = false;

  result = stack_pop(stack, &value);
  TEST_ASSERT_TRUE(result);
  TEST_ASSERT_EQUAL_INT(3, value);

  result = stack_pop(stack, &value);
  TEST_ASSERT_TRUE(result);
  TEST_ASSERT_EQUAL_INT(2, value);

  result = stack_pop(stack, &value);
  TEST_ASSERT_TRUE(result);
  TEST_ASSERT_EQUAL_INT(1, value);
}

int main(void)
{
   UnityBegin("MyStack");

   RUN_TEST(test_stack_create);
   RUN_TEST(test_stack_peek);
   //pushes

   RUN_TEST(test_stack_push);
   RUN_TEST(test_stack_multi_push);

   //pops
   RUN_TEST(test_stack_pop);
   RUN_TEST(test_stack_multi_pops);

   UnityEnd();
   return 0;
}
