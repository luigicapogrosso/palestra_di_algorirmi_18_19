#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n);

int main(int argc, char *argv[]) {

    int num;

    printf("Inserire il numero = ");
    scanf("%d", &num);

    printf("La serie di Fibonacci di %d è: %d\n", num, fibonacci(num));

    return 0;
}

int fibonacci(int n) {

    if (n < 0) {
        return -1;
    }

    if (n == 0 || n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
