#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE_1 3
#define SIZE_2 4
#define SIZE_3 5

int main(int argc, char const *argv[]) {
    srand(time(NULL));

    int i, j, k, m1[SIZE_1][SIZE_2], m2[SIZE_2][SIZE_3], m3[SIZE_1][SIZE_3];

    // Popolo la prima matrice con valori casuali
    for (i = 0; i < SIZE_1; i++) {
        for (j = 0; j < SIZE_2; j++) {
            m1[i][j] = 0 + rand() % (10 - 0);
        }
    }

    // Stampa della prima matrice
    printf("Matrice A:\n");
    for (i = 0; i < SIZE_1; i++) {
        for (j = 0; j < SIZE_2; j++) {
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }

    // Popolo la seconda matrice con valori casuali
    for (i = 0; i < SIZE_2; i++) {
        for (j = 0; j < SIZE_3; j++) {
            m2[i][j] = 0 + rand() % (10 - 0);
        }
    }

    // Stampa della seconda matrice
    printf("\nMatrice B:\n");
    for (i = 0; i < SIZE_2; i++) {
        for (j = 0; j < SIZE_3; j++) {
            printf("%d ", m2[i][j]);
        }
        printf("\n");
    }

    // Compongo la matrice prodotto
    for (i = 0; i < SIZE_1; i++) {
        for (j = 0; j < SIZE_3; j++) {
            for (k = 0; k < SIZE_2; k++) {
                m3[i][j] = m1[i][k] + m2[k][j];
            }
        }
    }

    // Stampa della matrice risultato
    printf("\nMatrice A * B:\n");
    for (i = 0; i < SIZE_1; i++) {
        for (j = 0; j < SIZE_3; j++) {
            printf("%d ", m3[i][j]);
        }
        printf("\n");
    }

    return 0;
}
