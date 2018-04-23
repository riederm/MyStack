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

int main(void)
{
   UnityBegin("MyStack");

   RUN_TEST(test_stack_create);

   UnityEnd();
   return 0;
}
