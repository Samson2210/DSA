#ifndef STACK_H
#define STACK_H

#define SIZE 50
struct stack
{
    int top;
    int items[SIZE];
};
typedef struct stack stack;

stack* createStack();
int isFull(stack *stack);
int isEmpty(stack *stack);
void push(stack *stack,int data);
int pop(stack *stack);
int peek(stack *stack);  //TO DO
void printStack(stack *stack);

#endif
