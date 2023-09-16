#include<stdio.h>

int fibonacci(int n){
    if(n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    printf("\nEnter the term no: ");
    scanf("%d", &n);
    printf("The %d no term is: %d\n\n", n, fibonacci(n));
    return 0;
}
