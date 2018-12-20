#include <stdio.h>
#include <stdlib.h>

#ifndef max
    #define max(a, b) ((a) > (b) ? (a) : (b))
#endif

int N;
int gradazioni_alcoliche[100];

int assaggia(int i, int assaggiati, int ultimo) {
    if (i >= N) {
        // Se ho terminato la sequenza
        return assaggiati;
    } else {
        if (gradazioni_alcoliche[i] >= ultimo) {
            // Prendo il massimo calcolato fra assaggiare il vino corrente e saltarlo
            return max(assaggia(i + 2, assaggiati + 1, gradazioni_alcoliche[i]),
                       assaggia(i + 1, assaggiati, ultimo));
        } else {
            // Se non posso assaggiare il vino
            return assaggia(i + 1, assaggiati, ultimo);
        }
    }
}

int main(int argc, char *argv[]) {
    int i, result;
    FILE *fd_in, *fd_out;

    // Apertura del file di input
    fd_in = fopen("./input.txt", "r");
    if (fd_in == NULL) {
        fprintf(stderr, "Impossibile aprire il file di input!\n");
        exit(1);
    }

    // Acquisisco il numero di vini
    fscanf(fd_in, "%d", &N);

    // Acquisisco le gradazioni alcoliche di ogni vino
    for (i = 0; i < N; i++) {
        fscanf(fd_in, "%d", &gradazioni_alcoliche[i]);
    }

    // Scrittura sul file di output
    fd_out = fopen("./output.txt", "w");
    if (fd_out == NULL) {
        fprintf(stderr, "Impossibile creare il file di output!\n");
        exit(1);
    }
    result = assaggia(0, 0, 0);
    fprintf(fd_out, "%d", result);

    // Chiusura del file di input
    fclose(fd_in);
    // Chiusura del file di output
    fclose(fd_out);

    return 0;
}
