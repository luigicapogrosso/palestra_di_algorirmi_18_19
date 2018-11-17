#include <stdio.h>
#include <stdlib.h>

#ifndef max
    #define max(a, b) ((a) > (b) ? (a) : (b))
#endif

int main(int argc, char *argv[]) {

    FILE *fd_in, *fd_out;
    int i, N, max = 0;

    // Apertura del file di input
    fd_in = fopen("./input.txt", "r");
    if (fd_in == NULL) {
        fprintf(stderr, "Impossibile aprire il file!\n");
        exit(1);
    }

    // Prendo la dimensione
    fscanf(fd_in, "%d", &N);

    for (i = 0; i < N; i++) {
        // Variabile temporanea
        int temp;
        fscanf(fd_in, "%d", &temp);

        // Aggiorno il massimo
        max = max(max, temp);
    }

    // Scrittura sul file di output
    fd_out = fopen("./output.txt", "w");
    if (fd_out == NULL) {
        fprintf(stderr, "Impossibile creare il file di output!\n");
        exit(1);
    }
    fprintf(fd_out,"%d", max);

    // Chiusura del file di input
    fclose(fd_in);
    // Chiusura del file di output
    fclose(fd_out);

    return 0;
}
