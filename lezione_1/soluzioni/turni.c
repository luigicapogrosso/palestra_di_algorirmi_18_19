#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct persona_t {
    int inizio;
    int fine;
};

int confronta_tempo_inizio(const void *p1, const void *p2) {
    struct persona_t persona_1 = *((struct persona_t *) p1);
    struct persona_t persona_2 = *((struct persona_t *) p2);

    if (persona_1.inizio < persona_2.inizio) {
        return -1;
    } else if (persona_1.inizio > persona_2.inizio) {
        return  1;
    }

    return 0;
}

int main(int argc, char *argv[]) {

    FILE *fd_in, *fd_out;
    int i, giorni_viaggio, n_persone;

    // Apertura del file di input
    fd_in = fopen("./input.txt", "r");
    if (fd_in == NULL) {
        fprintf(stderr, "Impossibile aprire il file di input!\n");
        exit(1);
    }

    // Salvo gli interi K (giorni_viaggio) ed N (n_persone)
    fscanf(fd_in, "%d", &giorni_viaggio);
    fscanf(fd_in, "%d", &n_persone);

    // Array di persone dove salvero' tutte le persone
    struct persona_t persone[n_persone];

    for (i = 0; i < n_persone; i++) {
        // Acquisizione dei tempi di inizio e fine
        int temp_inizio;
        int temp_fine;
        fscanf(fd_in, "%d", &temp_inizio);
        fscanf(fd_in, "%d", &temp_fine);

        // Assegnazione alla i-esima persona corrispondente
        persone[i].inizio = temp_inizio;
        persone[i].fine = temp_fine;
    }

    // Ordino l'array in base al loro tempo di inizio
    qsort(persone, n_persone, sizeof(struct persona_t), confronta_tempo_inizio);

    /* Variabile che salva il tempo di fine della persona che è
     * attualemente ultima nel turno di sorveglianza
     */
    int fine = 0;

    // Variabile per tener conto della fine corrente che è piu vicina a K
    int max_fine = 0;

    // Regali dovuti
    int regali = 0;

    while (fine < giorni_viaggio) {
        max_fine = 0;

        for (i = 0; i < n_persone; i++) {
            if (persone[i].inizio <= fine && persone[i].fine > max_fine) {
                max_fine = persone[i].fine;
            }
        }

        // Aggiorno la fine massima corrente
        max_fine++;

        // Aggiorno la variabile per il controllo fine < giorni_viaggio
        fine = max_fine;

        // Aggiungo un regalo
        regali++;
    }

    // Scrittura sul file di output
    fd_out = fopen("./output.txt", "w");
    if (fd_out == NULL) {
        fprintf(stderr, "Impossibile creare il file di output!\n");
        exit(1);
    }
    fprintf(fd_out,"%d", regali);

    // Chiusura del file di input
    fclose(fd_in);
    // Chiusura del file di output
    fclose(fd_out);

    return 0;
}
