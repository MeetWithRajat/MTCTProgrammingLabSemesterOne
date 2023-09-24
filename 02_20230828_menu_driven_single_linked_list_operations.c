/* Menu driven program - List operations [Assignment 02 - 20230828 - Rajat Roy]*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *start1 = NULL, *start2 = NULL;

void createList(struct Node **start) {
    // this function will create a single linked list and store the 1st node address to start1
    int n;
    struct Node *ptr;
    if (*start != NULL)
        start = &start2;
    printf("\nEnter the size of the list: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        struct Node *node = (struct Node *)malloc(sizeof(struct Node)); // dynamically allocated memory for a node
        printf("Enter the value for the %d no node: ", i);
        scanf("%d", &node->data);
        node->next = NULL;

        if (i == 1) {
            *start = node;
            ptr = node;
        }
        else{
            ptr->next = node;
            ptr = ptr->next;
        }  
    }
    if (n <= 0)
        printf("List not created!");
    else
        printf("List created!");
}

void printList() {
    // this function will print all the linked list
    struct Node *ptr;
    if (start1 == NULL && start2 == NULL)
        printf("\nList not created yet, You may want to create first!");    
    else{
        if (start2 == NULL)
            printf("\nThe list is:\n");
        else
            printf("\nThe first list is:\n");

        ptr = start1;
        while (ptr != NULL) {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL");
        ptr = start2;
        if (ptr != NULL) {  // if the 2nd list is also created at that moment
            printf("\nThe second list is:\n");
            while (ptr != NULL) {
                printf("%d -> ", ptr->data);
                ptr = ptr->next;
            }
            printf("NULL");
        }
    }
}

void insertElementAfterKthNode() {
    // this function will insert an element to after the Kth node in the list
    struct Node *ptr = start1;
    int position, i;
    if (start1 == NULL)
        printf("\nList not created yet, You may want to create first!");    
    else{
        printf("\nEnter the position (Kth node) you want to insert after: ");
        scanf("%d", &position);

        for (i = 1; ptr != NULL && i < position; i++)
            ptr = ptr->next;

        if (position < 1)
            printf("Element can't be inserted after this position, Position must be greater than 0");
        else if (ptr == NULL)
            printf("Element can't be inserted after this position, Position must be between 1 to %d", i - 1);
        else{
            struct Node *node = (struct Node *)malloc(sizeof(struct Node)); // dynamically allocated memory for a node
            printf("Enter the value to be inserted: ");
            scanf("%d", &node->data);
            node->next = ptr->next;
            ptr->next = node;
            printf("Element inserted after %d no node!", position);
        }
    }
}

void insertElementAfterValueNode() {
    // this function will insert an element to after the given value in the list
    struct Node *ptr = start1;
    int value, i;
    if (start1 == NULL)
        printf("\nList not created yet, You may want to create first!");    
    else{
        printf("\nEnter the value (node) you want to insert after: ");
        scanf("%d", &value);

        while (ptr != NULL && value != ptr->data) // try to find first occurrence of value
            ptr = ptr->next;

        if (ptr == NULL)
            printf("Given value not present in the list, so can't be inserted after!");
        else{
            struct Node *node = (struct Node *)malloc(sizeof(struct Node)); // dynamically allocated memory for a node
            printf("Enter the value to be inserted: ");
            scanf("%d", &node->data);
            node->next = ptr->next;
            ptr->next = node;
            printf("Element inserted after the node %d!", value);
        }
    }
}

void insertElementBeforeKthNode() {
    // this function will insert an element before the Kth node in the list
    struct Node *ptr = start1;
    int position, i;
    if (start1 == NULL)
        printf("\nList not created yet, You may want to create first!");    
    else{
        printf("\nEnter the position (Kth node) you want to insert before: ");
        scanf("%d", &position);

        for (i = 1; ptr != NULL && i < position - 1; i++)
            ptr = ptr->next;

        if (position < 1)
            printf("Element can't be inserted before this position, Position must be greater than 0");
        else if (ptr == NULL)
            printf("Element can't be inserted before this position, Position must be between 1 to %d", i - 1);
        else if (ptr->next == NULL)
            printf("Element can't be inserted before this position, Position must be between 1 to %d", i);
        else{
            struct Node *node = (struct Node *)malloc(sizeof(struct Node)); // dynamically allocated memory for a node
            printf("Enter the value to be inserted: ");
            scanf("%d", &node->data);
            
            if (position == 1) {
                node->next = ptr;
                start1 = node;
            }
            else{
                node->next = ptr->next;
                ptr->next = node;
            }
            printf("Element inserted before %d no node!", position);
        }     
    }
}

void insertElementBeforeValueNode() {
    // this function will insert an element before the given value in the list
    struct Node *ptr = start1, *previous = NULL;
    int value, i;
    if (start1 == NULL)
        printf("\nList not created yet, You may want to create first!");    
    else{
        printf("\nEnter the value (node) you want to insert before: ");
        scanf("%d", &value);

        while (ptr != NULL && value != ptr->data) { // try to find first occurrence of value
            previous = ptr;
            ptr = ptr->next;
        }
        if (ptr == NULL)
            printf("Given value not present in the list, so can't be inserted before!");
        else{
            struct Node *node = (struct Node *)malloc(sizeof(struct Node)); // dynamically allocated memory for a node
            printf("Enter the value to be inserted: ");
            scanf("%d", &node->data);

            if (previous == NULL) {
                node->next = ptr;
                start1 = node;
            }
            else{
                node->next = previous->next;
                previous->next = node;
            }
            printf("Element inserted before the node %d!", value);
        }
    }
}

void deleteKthNode() {
    // this function will delete the Kth node from the list
    struct Node *ptr = start1, *previous = NULL;
    int position, i;
    if (start1 == NULL)
        printf("\nList not created yet, You may want to create first!");    
    else{
        printf("\nEnter the position (Kth node) you want to delete: ");
        scanf("%d", &position);

        for (i = 1; ptr != NULL && i < position; i++) {
            previous = ptr;
            ptr = ptr->next;
        }

        if (position < 1)
            printf("Element can't be deleted from this position, Position must be greater than 0");
        else if (ptr == NULL)
            printf("Element can't be deleted from this position, Position must be between 1 to %d", i - 1);
        else{
            if (previous == NULL)
                start1 = ptr->next;
            else
                previous->next = ptr->next;
            free(ptr);
            printf("%d no node deleted from the list!", i);
            
        }
    }
}

void deleteValueNode() {
    // this function will delete the node for the given value from the list
    struct Node *ptr = start1, *previous = NULL;
    int value, i;
    if (start1 == NULL)
        printf("\nList not created yet, You may want to create first!");    
    else{
        printf("\nEnter the value (node) you want to delete: ");
        scanf("%d", &value);

        while (ptr != NULL && value != ptr->data) { // try to find first occurrence of value
            previous = ptr;
            ptr = ptr->next;
        }
        if (ptr == NULL)
            printf("Given value not present in the list, so can't be deleted!");
        else{
            if (previous == NULL)
                start1 = ptr->next;
            else
                previous->next = ptr->next;
            free(ptr);
            printf("Element %d deleted from the list!", value);
        }
    }
}

void compareTwoList() {
    // this function will compare two list and and print 1 or 0
    int option;
    if (start2 == NULL) {
        printf("\nSecond list not created yet, You may want to create first!");
        printf("\nChoose a option. Press 1) Create 2nd list else Abort: ");
        scanf("%d", &option);
        if (option == 1) {
            createList(&start2);
            printf("\n");
            printList();
            printf("\n");
            compareTwoList();
        }else
            printf("\nAborted!");
    }else{
        if (start1 == NULL)
            printf("\n0");
        else{
            struct Node *ptr1 = start1, *ptr2 = start2;
            while (ptr1 != NULL && ptr2 != NULL) {
                if (ptr1->data != ptr2->data)
                    break;
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            if (ptr1 == NULL && ptr2 == NULL)
                printf("\n1");
            else
                printf("\n0");
        }
    }
}

void reverseList() {
    // this function will reverse the first list
    struct Node* previous = NULL;
    struct Node* current = start1;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;   // store the next node in 'next'
        current->next = previous;   // reverse the link for the current node
        previous = current; // move 'previous' and 'current' one step forward
        current = next;
    }
    start1 = previous;  // update the start1 to point to the new first node
    printf("\nList reversed!");
}

void concatTwoList() {
    // this function will concat two lists
    int option;
    if (start2 == NULL) {
        printf("\nSecond list not created yet, You may want to create first!");
        printf("\nChoose a option. Press 1) Create 2nd list else Abort: ");
        scanf("%d", &option);
        if (option == 1) {
            createList(&start2);
            printf("\n");
            printList();
            printf("\n");
            concatTwoList();
        }else
            printf("\nLists not concatenated!");
    }else{
        if (start1 == NULL)
            start1 = start2;    // if the first list is empty, then point it to the second list
        else{
            struct Node *ptr = start1;
            while (ptr->next != NULL)
                ptr = ptr->next;    // traversing upto last node of first list
            ptr->next = start2; // concatenate the second list to the end of the first list
        }
        start2 = NULL;
        printf("\nLists concatenated!");
    }
}

void sortList(struct Node **start) {
    // this function is for sort the list (uses merge sort)
    int temp;
    if (start != NULL) {

    }
}

void mergeTwoList() {
    // this function will merge two sorted list (before and after)
    int option;
    if (start2 == NULL) {
        printf("\nSecond list not created yet, You may want to create first!");
        printf("\nChoose a option. Press 1) Create 2nd list else Abort: ");
        scanf("%d", &option);
        if (option == 1) {
            createList(&start2);
            printf("\n");
            printList();
            printf("\n");
            mergeTwoList();
        }else
            printf("\nLists not merged!");
    }else{
        sortList(&start1);
        sortList(&start2);
        printf("\nLists sorted first\n");
        printList();
        if (start1 == NULL)
            start1 = start2;    // if the first list is empty, then point it to the second list
        else{
            struct Node *ptr1 = start1, *ptr2 = start2, *previous = NULL, *temp = NULL;
            while (ptr1 != NULL && ptr2 != NULL) {
                if (ptr1->data > ptr2->data) {
                    temp = ptr2;
                    ptr2 = ptr2->next;
                    temp->next = ptr1;
                    if (previous == NULL)
                        start1 = temp;
                    else
                        previous->next = temp;
                }
                else{
                    previous = ptr1;
                    ptr1 = ptr1->next;
                }
            }
            if (ptr1 == NULL)
                previous->next = ptr2;  // attach the remaining elements of ptr2 to the end of the merged list
        }
        start2 = NULL;
        printf("\nLists merged!");
    }
}

int main() {
    char choice;
    printf("\n----------------- Menu driven program [Single Linked list Operations] -----------------");
    do{
        printf("\n\n\ta) Create list\t\t\t\tb) Print list\t\n");
        printf("\tc) Insert node after kth node\t\td) Insert node after node (value)\n");
        printf("\te) Insert node before kth node\t\tf) Insert node before node (value)\n");
        printf("\tg) Delete kth node\t\t\th) Delete the node (value)\n");
        printf("\ti) Compare two list\t\t\tj) Reverse list\n");
        printf("\tk) Concat two list\t\t\tl) Merge two lists\n");
        printf("\tm) Sort List\t\t\t\tn) Exit\n");
        printf("Enter you choice: ");
        scanf(" %c", &choice);

        switch (choice) {
        case 'a':
            createList(&start1);
            break;

        case 'b':
            printList();
            break;

        case 'c':
            insertElementAfterKthNode();
            break;

        case 'd':
            insertElementAfterValueNode();
            break;

        case 'e':
            insertElementBeforeKthNode();
            break;

        case 'f':
            insertElementBeforeValueNode();
            break;

        case 'g':
            deleteKthNode();
            break;

        case 'h':
            deleteValueNode();
            break;

        case 'i':
            compareTwoList();
            break;

        case 'j':
            reverseList();
            break;

        case 'k':
            concatTwoList();
            break;

        case 'l':
            mergeTwoList();
            break;

        case 'm':
            sortList();
            break;

        case 'n':
            printf("\nExiting from the program!!\n\n");
            break;

        default:
            printf("\nWrong entered!, Please choose from the above options!");
            break;
        }
    }while (choice != 'n' && choice != 'n');
    return 0;
}