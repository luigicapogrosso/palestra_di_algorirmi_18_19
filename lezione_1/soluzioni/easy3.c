#include <stdio.h>
#include <stdlib.h>

#ifndef max
    #define max(a, b) ((a) > (b) ? (a) : (b))
#endif

#define INT_MIN -1000001

int main(int argc, char *argv[]) {

    FILE *fd_in, *fd_out;
    int i, N, max = -1;

    // Primo numero pari maggiore di tutti
    int e1 = INT_MIN;
    // Secondo numero pari maggiore
    int e2 = INT_MIN;

    // Primo numero dispari maggiore di tutti
    int o1 = INT_MIN;
    // Secondo numero dispari maggiore
    int o2 = INT_MIN;

    // Apertura del file di input
    fd_in = fopen("./input.txt", "r");
    if (fd_in == NULL) {
        fprintf(stderr, "Impossibile aprire il file di input!\n");
        exit(1);
    }

    // Prendo la dimensione
    fscanf(fd_in, "%d", &N);

    for (i = 0; i < N; i++) {
        // Variabile temporanea
        int temp;
        fscanf(fd_in, "%d", &temp);

        if (temp % 2 == 0) {
            printf("P: %d\n", temp);
            // Caso e2 <= e1 <= temp
            if (temp >= e1) {
                e2 = e1;
                e1 = temp;
            } else if (temp > e2) {
                e2 = temp;
            }
        } else {
            printf("D: %d\n", temp);
            // Caso e2 <= e1 <= temp
            if (temp >= o1) {
                o2 = o1;
                o1 = temp;
            } else if (temp > o2) {
                o2 = temp;
            }
        }
    }

    /* Scelgo fra il maggiore pari calcolato
     * ed il maggiore dispari calcolato
     */
    if ((e1 + e2) > (o1 + o2)) {
        max = e1 + e2;
    } else {
        max = o1 + o2;
    }

    if (max < 0) {
        max = -1;
    }

    // Scrittura sul file di output
    fd_out = fopen("./output.txt", "w");
    if (fd_out == NULL) {
        fprintf(stderr, "Impossibile creare il file di output!\n");
        exit(1);
    }
    fprintf(fd_out, "%d\n", max);

    // Chiusura del file di input
    fclose(fd_in);
    // Chiusura del file di output
    fclose(fd_out);

    return 0;
}
