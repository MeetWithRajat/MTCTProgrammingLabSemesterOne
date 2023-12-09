/* [Assignment 03 - P1 - Stacks using array - 20230828 - Rajat Roy]
1. Write a program to implement a stack data structure using an array.
2. Implement a system which can handle more than one stack (n stacks) using arrays.
3. Write a Boolean function to return true if two stacks are equal.*/


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Stack structure
typedef struct Stack {
    int top;
    int* arr; // Use a pointer for flexible stack size
    int maxSize; // Maximum size of a stack
} Stack;

// Function to create a new stack
Stack* createStack(int size) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->arr = (int*) malloc(size * sizeof(int)); // Allocate memory for the stack based on the specified size
    stack->top = -1;
    stack->maxSize = size;
    return stack;
}

// Function to push an element into the stack
void push(Stack* stack, int item) {
    if (stack->top == stack->maxSize - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = item;
    printf("Element pushed\n");
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Function to peek the top element of the stack
int peek(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

// Function to count the element of the stack
int count(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top + 1;
}

// Function to check if two stacks are equal
bool areEqual(Stack* stack1, Stack* stack2) {
    if (stack1->top != stack2->top)
        return false;

    for (int i = 0; i <= stack1->top; i++) {
        if (stack1->arr[i] != stack2->arr[i])
            return false;
    }

    return true;
}

// Function to print elements of a single stack
void printSingleStack(Stack* stack, int stackIndex) {
    printf("Stack: %d: ", stackIndex);
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    if (stack->top == -1)
        printf("Empty");
    printf("\n");
}

// Function to print elements of all stacks
void printAllStacks(Stack** stacks, int n) {
    printf("\nPrinting all stacks\n");
    for (int i = 0; i < n; i++) {
        printf("Stack %d: ", i);
        for (int j = 0; j <= stacks[i]->top; j++) {
            printf("%d ", stacks[i]->arr[j]);
        }
        if (stacks[i]->top == -1)
            printf("Empty");
        printf("\n");
    }
}

int main() {
    int n, stackSize;

    printf("\n-------------------- Menu driven program [Stack Operations] --------------------\n");
    printf("Enter the number of stacks: ");
    if (scanf("%d", &n) != 1) { // Check if scanf successfully read an integer
        printf("\nInvalid input. Expecting a valid integer. Exiting the execution!\n"); // Handle invalid input
        exit(EXIT_FAILURE);
    } else if (n <= 0) {
        printf("\nInvalid size. Stack count should be greater than 0. Exiting the execution!\n");
        exit(EXIT_FAILURE);
    }

    Stack** stacks = (Stack**) malloc(n * sizeof(Stack*)); // Create an array of pointers to stacks

    for (int i = 0; i < n; i++) { // Initialize each stack
        printf("Enter the size for the stack no %d: ", i);
        if (scanf("%d", &stackSize) != 1) {
            printf("Invalid input. Expecting a valid integer. Setting default stack size to 10\n");
            while (getchar() != '\n'); // Flush the input buffer
            stackSize = 10;
        } else if (stackSize <= 0) {
            printf("Invalid size. Stack size should be greater than 0. Setting default stack size to 10\n");
            stackSize = 10;
        }
        stacks[i] = createStack(stackSize);
    }

    int choice, value, stackIndex;

    while (1) {
        printf("\n1. Push\t\t\t2. Pop\t\t\t3. Peek\t\t\t4. Count");
        printf("\n5. Check Equal\t\t6. Print Stack\t\t7. Print All Stacks\t8. Exit\n");

        printf("Enter your choice: ");        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please enter a valid integer.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("\nEnter the stack index (0-%d): ", n - 1);
                if (scanf("%d", &stackIndex) != 1) {
                    printf("\nInvalid input. Please enter a valid integer.\n");
                    while (getchar() != '\n');
                    break;
                }

                if (stackIndex >= 0 && stackIndex < n) {
                    printf("Enter the value to push into Stack %d: ", stackIndex);
                    scanf("%d", &value);
                    push(stacks[stackIndex], value);
                } else
                    printf("Invalid stack index\n");
                break;

            case 2:
                printf("\nEnter the stack index (0-%d): ", n - 1);
                if (scanf("%d", &stackIndex) != 1) {
                    printf("\nInvalid input. Please enter a valid integer.\n");
                    while (getchar() != '\n');
                    break;
                }

                if (stackIndex >= 0 && stackIndex < n) {
                    value = pop(stacks[stackIndex]);
                    if (value != -1)
                        printf("Popped element from Stack %d: %d\n", stackIndex, value);
                } else
                    printf("Invalid stack index\n");
                break;

            case 3:
                printf("\nEnter the stack index (0-%d): ", n - 1);
                if (scanf("%d", &stackIndex) != 1) {
                    printf("\nInvalid input. Please enter a valid integer.\n");
                    while (getchar() != '\n');
                    break;
                }

                if (stackIndex >= 0 && stackIndex < n) {
                    value = peek(stacks[stackIndex]);
                    if (value != -1)
                        printf("Top element of Stack %d: %d\n", stackIndex, value);
                } else
                    printf("Invalid stack index\n");
                break;
            
            case 4:
                printf("\nEnter the stack index (0-%d): ", n - 1);
                if (scanf("%d", &stackIndex) != 1) {
                    printf("\nInvalid input. Please enter a valid integer.\n");
                    while (getchar() != '\n');
                    break;
                }

                if (stackIndex >= 0 && stackIndex < n) {
                    value = count(stacks[stackIndex]);
                    if (value != -1)
                        printf("Element count of Stack %d: %d\n", stackIndex, value);
                } else
                    printf("Invalid stack index\n");
                break;

            case 5:
                printf("\nEnter the first stack index (0-%d): ", n - 1);
                if (scanf("%d", &stackIndex) != 1) {
                    printf("\nInvalid input. Please enter a valid integer.\n");
                    while (getchar() != '\n');
                    break;
                }
                printf("Enter the second stack index (0-%d): ", n - 1);
                if (scanf("%d", &value) != 1) {
                    printf("\nInvalid input. Please enter a valid integer.\n");
                    while (getchar() != '\n');
                    break;
                }

                if (stackIndex >= 0 && stackIndex < n && value >= 0 && value < n) {
                    if (areEqual(stacks[stackIndex], stacks[value]))
                        printf("The stacks are equal\n");
                    else
                        printf("The stacks are not equal\n");
                } else
                    printf("Invalid stack indices\n");
                break;

            case 6:
                printf("\nEnter the stack index (0-%d): ", n - 1);
                if (scanf("%d", &stackIndex) != 1) {
                    printf("\nInvalid input. Please enter a valid integer.\n");
                    while (getchar() != '\n');
                    break;
                }

                if (stackIndex >= 0 && stackIndex < n) {
                    printSingleStack(stacks[stackIndex], stackIndex);
                } else
                    printf("Invalid stack index\n");
                break;

            case 7:
                printAllStacks(stacks, n);
                break;

            case 8:
                for (int i = 0; i < n; i++)     // Free the allocated memory and exit
                    free(stacks[i]);
                free(stacks);
                printf("\nMemory Freed! Exited!\n\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
