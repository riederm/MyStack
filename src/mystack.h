#ifndef MYSTACK_H
#define MYSTACK_H

#include <stdbool.h>

#define MAX_STACK_SIZE 16

typedef struct _MyStack_ {
   int top;  // the top-pointer of the stack
   int data[MAX_STACK_SIZE];  //the actual stack data
} MyStack;

/*
* instantiates a new stack and returns a pointer to it.
* must be free'ed using stack_delete(...)
*/
MyStack* stack_create();

/*
* deletes a given stack
*/
void stack_delete(MyStack* stack);

/*
* pushes the give element to the stack
* returns true if the push was successful,
* returns false if not (the stack is full)
*/
bool stack_push(MyStack* stack, int data);

/*
* pops the top element from the stack and writes its value into
* the given value-pointer
* returns true if something was pop'ed
* returns false if the stack was empty
*/
bool stack_pop(MyStack* stack, int* value);

/*
* writes the stack's top value into
* the given value-pointer without removing it
* returns true if the stack was not empty
* returns false if the stack was empty
*/
bool stack_peek(MyStack* stack, int* value);

/*
* returns true if the stack is empty, otherwhise false
*/
bool stack_isEmpty(MyStack* stack);

#endif
