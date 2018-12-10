#include <stdio.h>
#include <stdlib.h>

int fattoriale(int n);

int main(int argc, char *argv[]) {

    int num;

    printf("Inserire il numero = ");
    scanf("%d", &num);

    printf("Il fattoriale di %d è %d\n", num, fattoriale(num));

    return 0;
}

int fattoriale(int n) {

    // Il fattoriale non è definito per interi negativi!
    if (n < 0) {
        return -1;
    }

    if (n == 0) {
        return 1;
    } else {
        return n * fattoriale(n - 1);
    }
}
