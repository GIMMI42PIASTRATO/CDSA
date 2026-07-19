#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack Stack;
struct Stack {
    int* array;
    int64_t capacity;
    int64_t top;
};

Stack* makeStack(int64_t capacity) {
    Stack* stack = malloc(sizeof(Stack));
    if (stack == NULL) return NULL;
    int* array = malloc(sizeof(int) * capacity);
    if (array == NULL) return NULL;

    *stack = (Stack){.array = array, .capacity = capacity, .top = -1};

    return stack;
}

void freeStack(Stack* stack) {
    free(stack->array);
    free(stack);
}

bool stackPush(Stack* stack, int value) {
    if (stack == NULL) return false;
    if (stack->top == stack->capacity - 1) return false;

    stack->array[++(stack->top)] = value;
    return true;
}

int stackPop(Stack* stack) {
    if (stack == NULL) return INT_MIN;
    if (stack->top == -1) return INT_MIN;

    return stack->array[stack->top--];
}

int stackPeek(Stack* stack) {
    if (stack == NULL) return INT_MIN;
    if (stack->top == -1) return INT_MIN;

    return stack->array[stack->top];
}

bool stackIsEmpty(Stack* stack) { return stack->top == -1; }

bool stackIsFull(Stack* stack) { return stack->top == stack->capacity - 1; }

int main(void) {
    Stack* st = makeStack(4);

    stackPush(st, 1);
    stackPush(st, 2);
    stackPush(st, 3);
    stackPush(st, 4);

    // Pop one element
    printf("Popped: %d\n", stackPop(st));

    // Peek top element
    printf("Top element: %d\n", stackPeek(st));

    // Check if stack is empty
    printf("Is stack empty: %s\n", stackIsEmpty(st) ? "Yes" : "No");

    // Check if stack is full
    printf("Is stack full: %s\n", stackIsFull(st) ? "Yes" : "No");

    // Free memory
    freeStack(st);

    return 0;
}
