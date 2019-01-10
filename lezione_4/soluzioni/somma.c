#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main(int argc, char const *argv[]) {
    srand(time(NULL));

    int i, j, m1[SIZE][SIZE], m2[SIZE][SIZE], m3[SIZE][SIZE];

    // Popolo la prima matrice con valori casuali
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            m1[i][j] = 0 + rand() % (100 - 0);
        }
    }

    // Stampa della prima matrice
    printf("Matrice A:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }

    // Popolo la seconda matrice con valori casuali
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            m2[i][j] = 0 + rand() % (100 - 0);
        }
    }

    // Stampa della seconda matrice
    printf("\nMatrice B:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", m2[i][j]);
        }
        printf("\n");
    }

    // Compongo la matrice somma
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }

    // Stampa della matrice risultato
    printf("\nMatrice A + B:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", m3[i][j]);
        }
        printf("\n");
    }

    return 0;
}
