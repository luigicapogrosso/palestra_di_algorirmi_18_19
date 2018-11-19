#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

    FILE *fd_in, *fd_out;
    int i = 1, gemme, persone, gemme_toto = 0;

    // Apertura del file di input
    fd_in = fopen("./input.txt", "r");
    if (fd_in == NULL) {
        fprintf(stderr, "Impossibile aprire il file di input!\n");
        exit(1);
    }

    // Salvo il numero di gemme
    fscanf(fd_in, "%d", &gemme);
    // Salvo il numero di persone
    fscanf(fd_in, "%d", &persone);

    /* Finché le gemme sono abbastanza da spartirle fra tutti.
     * Questo lo decido controllando le gemme dovute a Totò
     * e le gemme per ogni altra persona (oltre Totò) dalle
     * gemme totali. Se maggiori di 0 allora sono abbastanza.
     */
    while ((gemme - i) - (persone - 1) >= 0) {
        /* Aggiorno le gemme rimaste, togliendo quelle dovute
         * a Totò (i) e quelle dovute alle persone p - 1.
         * Togliamo 1 da p perché in p é compreso anche Totò,
         * per il quale ho già considerato le gemme date
         */
        gemme = (gemme - i) - (persone - 1);

        // Aggiorniamo le gemme totali di Totò
        gemme_toto += i;

        // Aggiorniamo le gemme dovute a Totò nel prossimo turno
        i++;
    }

    // Aggiungiamo le eventuali gomme rimaste che andranno tutte a Totò
    gemme_toto += gemme;

    // Scrittura sul file di output
    fd_out = fopen("./output.txt", "w");
    if (fd_out == NULL) {
        fprintf(stderr, "Impossibile creare il file di output!\n");
        exit(1);
    }
    fprintf(fd_out, "%d\n", gemme_toto);

    // Chiusura del file di input
    fclose(fd_in);
    // Chiusura del file di output
    fclose(fd_out);

    return 0;
}
