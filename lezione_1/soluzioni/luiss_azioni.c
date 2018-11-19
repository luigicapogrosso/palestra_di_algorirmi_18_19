#include <stdio.h>
#include <stdlib.h>

#ifndef max
    #define max(a, b) ((a) > (b) ? (a) : b)
#endif

int main(int argc, char *argv[]) {

    FILE *fd_in, *fd_out;
    int i, q1, q2, N, max_diff = 0;

    // Apertura del file di input
    fd_in = fopen("./input.txt", "r");
    if (fd_in == NULL) {
        fprintf(stderr, "Impossibile aprire il file di input\n");
        exit(1);
    }

    // Prendo la dimensione
    fscanf(fd_in, "%d", &N);

    // Numero 1
    fscanf(fd_in, "%d", &q1);

    for (i = 0; i < N - 3; i++) {
        // Numero 2
        fscanf(fd_in, "%d", &q2);

        // Aggiorno la differenza massima
        max_diff = max(max_diff, abs(q1 - q2));

        q1 = q2;
    }

    // Scrittura sul file di output
    fd_out = fopen("./output.txt", "w");
    if (fd_out == NULL) {
        fprintf(stderr, "Impossibile creare il file di output!\n");
        exit(1);
    }
    fprintf(fd_out, "%d\n", max_diff);

    // Chiusura del file di input
    fclose(fd_in);
    // Chiusura del file di output
    fclose(fd_out);

    return 0;
}
