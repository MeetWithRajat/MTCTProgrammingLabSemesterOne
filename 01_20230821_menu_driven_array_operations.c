/* Menu driven program - Array operations [Assignment 01 - 20230821 - Rajat Roy]*/

#include<stdio.h>
#include<stdlib.h>

int n1 = 0, n2 = 0, *ptr1 = NULL, *ptr2 = NULL;

void createFirstArray(){
    // this function is for create the first array for n element
    if (ptr1 != NULL){
        free(ptr1);
        n1 = 0;
    }
    printf("\nEnter the size of the array to be created: ");
    scanf("%d", &n1);

    ptr1 = (int *)malloc(n1 * sizeof(int)); // dynamically allocated memory for n1 element

    for (int i = 0; i < n1; i++){
        printf("Enter the element for index %d: ", i);
        scanf("%d", &ptr1[i]);
    }
    if (n1 <= 0){
        printf("Array not created!");
        n1 = 0;
    }
    else
        printf("Array created!");
}

void createSecondArray(){
    // this function is for create the second array for n element
    if (ptr2 != NULL){
        free(ptr2);
        n2 = 0;
    }
    printf("\nEnter the size of the array to be created: ");
    scanf("%d", &n2);

    ptr2 = (int *)malloc(n2 * sizeof(int)); // dynamically allocated memory for n2 element

    for (int i = 0; i < n2; i++){
        printf("Enter the element for index %d: ", i);
        scanf("%d", &ptr2[i]);
    }
    if (n2 <= 0){
        printf("Array not created!");
        n2 = 0;
    }
    else
        printf("Array created!");
}

void showArray(){
    // this function will print the array
    if (n1 == 0 && n2 == 0)
        printf("\nArray not created yet, you may want to create first!");
    else{
        if (ptr2 == NULL)
            printf("\nThe array is:\n");
        else
            printf("\nThe first array is:\n");

        for (int i = 0; i < n1; i++)
            printf("%d ", ptr1[i]);

        if (ptr2 != NULL){  // if the array is split at that moment
            printf("\nThe second array is:\n");
            for (int i = 0; i < n2; i++)
                printf("%d ", ptr2[i]);
        }
    }
}

void countArray(){
    // this function is for count & print the no of element present in the array
    if (ptr2 == NULL)
        printf("\n%d elements present in the array at this moment", n1);
    else{
        printf("\n%d elements present in the 1st array at this moment", n1);
        printf("\n%d elements present in the 2nd array at this moment", n2);
    }
}

void indexedElement(){
    // this function is for print the element for the given index
    int index, option;
    if (n1 == 0 && n2 == 0)
        printf("\nArray not created yet, you may want to create first!");
    else if (ptr2 != NULL){
        printf("\nArray split, choose source array. Press 1) 1st array else 2nd array: ");
        scanf("%d", &option);
        printf("Enter the index no: ");
        scanf("%d", &index);

        if (option == 1){
            if (index >= 0 && index < n1)
                printf("The element in the index %d (1st array) is: %d", index, ptr1[index]);
            else
                printf("Index number must be between 0 to %d for the 1st array", n1 - 1);
        }else{
            if (index >= 0 && index < n2)
                printf("The element in the index %d (2nd array) is: %d", index, ptr2[index]);
            else
                printf("Index number must be between 0 to %d for the 2nd array", n2 - 1);
        }
    }else{
        printf("\nEnter the index no: ");
        scanf("%d", &index);
        if (index >= 0 && index < n1)
            printf("The element in the index %d is: %d", index, ptr1[index]);
        else
            printf("Index number must be between 0 to %d", n1 - 1);
    }
}

void insertElement(){
    // this function is for insert an element to the given index
    int index, option;
    if (ptr2 != NULL){
        printf("\nArray split, choose source array. Press 1) 1st array else 2nd array: ");
        scanf("%d", &option);
        printf("Enter the index no: ");
        scanf("%d", &index);

        if (option != 1){
            if (index >= 0 && index <= n2){
                n2 += 1;
                ptr2 = (int *)realloc(ptr2, n2 * sizeof(int));  // allocate one extra memory for 2nd array

                for (int i = n2 - 1; i > index; i--)    // element right shifting
                    ptr2[i] = ptr2[i - 1];
                printf("Enter the value to be inserted: ");
                scanf("%d", &ptr2[index]);
                printf("Element inserted!");
            }else
                printf("Element can't be inserted at this index, Index must be between 0 to %d", n2);
            return;
        }
    }else{
        printf("\nEnter the index no: ");
        scanf("%d", &index);
    }

    if (index >= 0 && index <= n1){
        n1 += 1;
        ptr1 = (int *)realloc(ptr1, n1 * sizeof(int));  // allocate one extra memory for 1st array

        for (int i = n1 - 1; i > index; i--)    // element right shifting
            ptr1[i] = ptr1[i - 1];
        printf("Enter the value to be inserted: ");
        scanf("%d", &ptr1[index]);
        printf("Element inserted!");
    }else
        printf("Element can't be inserted at this index, Index must be between 0 to %d", n1);
}

int findElement(int *arr, int n, int ele){
    // this function will find the element from the given array and return index if not present return -1
    int i, index = -1;
    for (i = 0; i < n; i++){
        if (arr[i] == ele){
            index = i;
            break;
        }
    }
    if (i == n)
        printf("Element not present in the array");
    return index;
}

void deleteElement(){
    // this function is for delete an element for the given value
    int element, option, value, index=-1;
    if (n1 == 0 && n2 == 0){
        printf("\nArray not created yet, you may want to create first!");
        return;
    }
    else if (ptr2 != NULL){
        printf("\nArray split, choose source array. Press 1) 1st array else 2nd array: ");
        scanf("%d", &option);
        printf("Enter the element to be deleted: ");
        scanf("%d", &element);

        if (option != 1){
            index = findElement(ptr2, n2, element);
            if (index != -1){
                for (int i = index; i < n2 - 1; i++)    // element left shifting
                    ptr2[i] = ptr2[i + 1];
                n2 -= 1;
                if (n2 == 0){
                    free(ptr2);
                    ptr2 = NULL;
                }else
                    ptr2 = (int *)realloc(ptr2, n2 * sizeof(int));  // deallocate one extra memory for 2nd array
                printf("Element deleted!");
            }
            return;
        }else if (n1 == 0){
            printf("No element present in the 1st array, You may want to delete from the 2nd array!");
            return;
        }
    }else{
        printf("Enter the element to be deleted: ");
        scanf("%d", &element);
    }

    index = findElement(ptr1, n1, element);
    if (index != -1){
        for (int i = index; i < n1 - 1; i++)    // element left shifting
            ptr1[i] = ptr1[i + 1];
        n1 -= 1;
        if (n1 == 0){
            free(ptr1);
            ptr1 = NULL;
        }else
            ptr1 = (int *)realloc(ptr1, n1 * sizeof(int));  // deallocate one extra memory for 1st array
        printf("Element deleted!");
    }
}

void splitArray(){
    // the function is for split the array into two array
    int position;
    if (n1 == 0 && n2 == 0)
        printf("\nArray not created yet, you may want to create first!");
    else if (n2 != 0)
        printf("\nArray already split!");
    else if (n1 == 1)
        printf("\nOnly one element is present, can not be split!");
    else{
        printf("\nEnter the the position to be split: ");
        scanf("%d", &position);

        if (position > 0 && position < n1){
            n2 = n1 - position;
            ptr2 = (int *)malloc(n2 * sizeof(int)); // dynamically allocated memory for n2 element

            for (int i = position, j = 0; i < n1; i++, j++) // assigning value to the 2nd array from the 1st array
                ptr2[j] = ptr1[i];

            n1 -= n2;   // reducing the size for the 1st array
            ptr1 = (int *)realloc(ptr1, n1 * sizeof(int));  // reduced the allocated memory to n1 elements

            printf("Array split!");
        }else
            printf("Position must be between 1 to %d", n1 - 1);
    }
}

void mergeArray(){
    // the function is for merge the split array into one array
    int temp, option;
    if (n1 == 0 && n2 == 0){
        printf("\nArray not created yet, you may want to create first!");
        return;
    }
    else if (n2 == 0 || ptr2 == NULL){
        printf("\nArray not split yet, you may want to split first or create a new array!");
        printf("\nChoose a option. Press 1) Split array else Create new array: ");
        scanf("%d", &option);
        if (option == 1)
            splitArray();
        else
            createSecondArray();
        showArray();
        mergeArray();
    }
    else{
        temp = n1;
        n1 += n2;
        ptr1 = (int *)realloc(ptr1, n1 * sizeof(int));  // allocate extra memory for additional n2 elements

        for (int i = temp, j = 0; i < n1; i++, j++) // assigning extra value to the 1st array from the 2nd array
            ptr1[i] = ptr2[j];

        free(ptr2); // deallocate assigned memory for 2nd array
        n2 = 0;
        ptr2 = NULL;
        printf("\nArray merged!");
    }
}

void sortArray(){
    // this function is for sort the array (uses bubble sort)
    int temp;
    if (n1 == 0 && n2 == 0)
        printf("\nArray not created yet, you may want to create first!");
    else{
        for (int i = 0; i < n1; i++)    // for 1st array
            for (int j = i + 1; j < n1; j++)
                if (ptr1[j] < ptr1[i]){
                    temp = ptr1[i];
                    ptr1[i] = ptr1[j];
                    ptr1[j] = temp;
                }

        for (int i = 0; i < n2; i++)    // for 2nd array
            for (int j = i + 1; j < n2; j++)
                if (ptr2[j] < ptr2[i]){
                    temp = ptr2[i];
                    ptr2[i] = ptr2[j];
                    ptr2[j] = temp;
                }

        printf("\nArray sorted!");
    }
}

void searchElement(){
    // this function is for search the element from the array (uses linear search)
    int search, option, *source = ptr1, source_count = n1, i;
    if (n1 == 0 && n2 == 0)
        printf("\nArray not created yet, you may want to create first!");
    else{
        if (ptr2 != NULL){
            printf("\nArray split, choose source array. Press 1) 1st array else 2nd array: ");
            scanf("%d", &option);

            if (option != 1)    // defining source array (either 1st or 2nd array)
                source = ptr2;
                source_count = n2;
        }

        printf("\nEnter the element to be searched: ");
        scanf("%d", &search);
        for (i = 0; i < source_count; i++){
            if (source[i] == search){
                printf("Element found at the index no %d", i);
                break;
            }
        }
        if (i == source_count)
            printf("Element not present in the array");
    }     
}

int main(){
    char choice;
    int temp;
    printf("\n-------------------- Menu driven program [Array Operations] --------------------");
    do{
        printf("\n\n\ta) Create\t\tb) Count\t\tc) Indexed Element\n\td) Insert\t\te) Delete\t\tf) Merge\n");
        printf("\tg) Split\t\th) Sort\t\t\ti) Search\n\tj) Show\t\t\tk) Exit\n");
        printf("Enter you choice: ");
        scanf(" %c", &choice);

        switch (choice){
        case 'a':
            createFirstArray();
            break;

        case 'b':
            countArray();
            break;

        case 'c':
            indexedElement();
            break;

        case 'd':
            insertElement();
            break;

        case 'e':
            deleteElement();
            break;

        case 'f':
            mergeArray();
            break;

        case 'g':
            splitArray();
            break;

        case 'h':
            sortArray();
            break;

        case 'i':
            searchElement();
            break;

        case 'j':
            showArray();
            break;

        case 'k':
            printf("\nExiting from the program!!\n\n");
            break;

        default:
            printf("\nWrong entered!, Please choose from the above options!");
            break;
        }
    }while(choice != 'k' && choice != 'K');
    return 0;
}