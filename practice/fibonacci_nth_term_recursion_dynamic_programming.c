#include<stdio.h>
#include<stdlib.h>

long long int* ptr;

long long int fibonacci(long long int n){
    if(n <= 1)
        return n;
    if (ptr[n] != 0)
        return ptr[n];
    ptr[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return ptr[n];
}

int main()
{
    long long int n;
    printf("\nEnter the term no: ");
    scanf("%lld", &n);
    ptr = (long long int*)calloc(n + 1, sizeof(long long int));
    printf("The %lld no term is: %lld\n\n", n, fibonacci(n));
    free(ptr);
    return 0;
}
