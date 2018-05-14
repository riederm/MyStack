#include "mystack.h"
#include <stddef.h>
#include <stdlib.h>

/*
* instantiates a new stack and returns a pointer to it.
* must be free'ed using stack_delete(...)
*/
MyStack* stack_create(){
  MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
  stack->top = -1;
  //initialize stack data to 0
  for (size_t i = 0; i < MAX_STACK_SIZE; i++) {
    stack->data[i] = 0;
  }
  return stack;
}

/*
* deletes a given stack
*/
void stack_delete(MyStack* stack){
  free(stack);
}

/*
* pushes the give element to the stack
* returns true if the push was successful,
* returns false if not (the stack is full)
*/
bool stack_push(MyStack* pStack, int data){
  if (pStack->top < MAX_STACK_SIZE-1){
    pStack->data[++pStack->top] = data;
    return true;
  }
  return false;
}

/*
* pops the top element from the stack and writes its value into
* the given value-pointer
* returns true if something was pop'ed
* returns false if the stack was empty
*/
bool stack_pop(MyStack* pStack, int* value){
  if (pStack->top > 0){
    pStack->top--;
    bool result = stack_peek(pStack, value);
    return result;
  }
  return false;
}

/*
* writes the stack's top value into
* the given value-pointer without removing it
* returns true if the stack was not empty
* returns false if the stack was empty
*/
bool stack_peek(MyStack* pStack, int* value){
  if (pStack->top >= 0){
    *value = pStack->data[pStack->top];
    return true;
  }
  return false;
}

/*
* returns true if the stack is empty, otherwhise false
*/
bool stack_isEmpty(MyStack* pStack){
  return pStack->top < 0;
}
