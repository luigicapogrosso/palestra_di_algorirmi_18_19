#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifndef min
    #define min(a, b) ((a) < (b) ? (a) : (b))
#endif

int p_scooter, p_car4, p_car5, p_car7;
int result = INT_MAX;

void calcola(int persone, int s, int m4, int m5, int m7, int prezzo)
{
    if (persone <= 0)
        result = min(prezzo, result);
    else
    {
        // Se ho scooter disponibili, calcolo cosa succede con uno scooter in meno
        if (s > 0)
            calcola(persone - 2, s - 1, m4, m5, m7, prezzo + p_scooter);

        // Se ho macchine da 4 disponibili, calcolo cosa succede senza quella macchina
        if (m4 > 0)
            calcola(persone - 4, s, m4 - 1, m5, m7, prezzo + p_car4);

        // Se ho macchine da 5 disponibili, calcolo cosa succede senza quella macchina
        if (m5 > 0)
            calcola(persone - 5, s, m4, m5 - 1, m7, prezzo + p_car5);

        // Se ho macchine da 7 disponibili, calcolo cosa succede senza quella macchina
        if (m7 > 0)
            calcola(persone - 7, s, m4, m5, m7 - 1, prezzo + p_car7);
    }
}

int main(int argc, char *argv[]) {

    FILE *fd_in, *fd_out;
    int N, n_scooter, n_car4, n_car5, n_car7;

    // Apertura del file di input
    fd_in = fopen("./input.txt", "r");
    if (fd_in == NULL) {
        fprintf(stderr, "Impossibile aprire il file!\n");
        exit(1);
    }

    // Salvo il numero di persone
    fscanf(fd_in, "%d", &N);

    // Salvo il numero di scooter
    fscanf(fd_in, "%d", &n_scooter);
    // Salvo il prezzo per lo scooter
    fscanf(fd_in, "%d", &p_scooter);

    // Salvo il numero della macchina a 4 posti
    fscanf(fd_in, "%d", &n_car4);
    // Salvo il prezzo della macchina a 4 posti
    fscanf(fd_in, "%d", &p_car4);

    // Salvo il numero della macchina a 5 posti
    fscanf(fd_in, "%d", &n_car5);
    // Salvo il prezzo della macchina a 5 posti
    fscanf(fd_in, "%d", &p_car5);

    // Salvo il numero della macchina a 7 posti
    fscanf(fd_in, "%d", &n_car7);
    // Salvo il prezzo della macchina a 7 posti
    fscanf(fd_in, "%d", &p_car7);

    calcola(N, n_scooter, n_car4, n_car5, n_car7, 0);

    // Scrittura sul file di output
    fd_out = fopen("./output.txt", "w");
    if (fd_out == NULL) {
        fprintf(stderr, "Impossibile creare il file di output!\n");
        exit(1);
    }
    fprintf(fd_out,"%d", result);

    // Chiusura del file di input
    fclose(fd_in);
    // Chiusura del file di output
    fclose(fd_out);

    return 0;
}
