#include <stdio.h>
#include <stdlib.h>

// Massimo numero di candidati
#define MAXK 100
// Massimo numero di giudici
#define MAXN 10

int main(int argc, char const *argv[]) {

    int voti[MAXK][MAXN];
    // Somma dei voti per ogni candidato
    int tot[MAXK];
    // Somma dei voti di ogni giudice
    int totg[MAXN];
    int i, j, k, n, min, max, pos_min, pos_max;

    printf("Indicare il numero di giudici: ");
    scanf("%d", &k);
    printf("Indicare il numero di candidati: ");
    scanf("%d", &n);

    for (i = 0; i < k; i++) {
        printf("Indicare i giudizi per il candidato %d\n", i + 1);
        for (j = 0; j < n; j++) {
            printf("Giudice %d cosa pensi del candidato? ", j + 1);
            scanf("%d", &voti[i][j]);
        }
    }

    for (i = 0; i < k; i++) {
        tot[i] = 0;
    }
    for (j = 0; j < n; j++) {
        totg[j] = 0;
    }

    for (i = 0; i < k; i++) {
        for (j = 0; j < n; j++) {
            tot[i] = tot[i] + voti[i][j];
            totg[j] = totg[j] + voti[i][j];
        }
    }

    max = tot[0];
    pos_max = 0;
    for (i = 1; i < k; i++) {
        if (tot[i] > max) {
            max = tot[i];
            pos_max = i;
        }
    }

    printf("Il vincitore è il candidato numero: %d\n", pos_max + 1);

    min = totg[0];
    pos_min = 0;

    for (i = 1; i < n; i++) {
        if (totg[i] < min) {
            min = totg[i];
            pos_min = i ;
        }
    }
    printf("Il giudice più severo è il numero %d\n", pos_min + 1);

    return 0;
}
