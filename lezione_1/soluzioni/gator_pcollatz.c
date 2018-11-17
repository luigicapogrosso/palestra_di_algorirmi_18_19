#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int collatz(int n) {
    int res = 1;

    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = (n * 3) + 1;
        }
        res++;
    }

    return res;
}

bool pollatz(int n) {
    /* Chiamo la funzione che restituisce la dimensione della
     * sequenza Collatz con l'n attuale
     */
    int len_collatz = collatz(n);
    int res = 1;

    /* Finché la sequenza pollatz ha dimensione minore della
     * sequenza collatz, e la sequenza non è terminata
     */
    while (n != 1 && res < len_collatz) {
        // Se è pari
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = (n * 5) + 1;
        }
        // Aggiorno la dimensione della sequenza
        res++;
    }

    /* Ritorno vero se la sequenza pollatz è minore
     * di collatz, e se la sequenza pollatz è terminata
     * (ovvero quando n è uguale a 1)
     */
    if (n == 1 && res < len_collatz) {
        return true;
    } else {
        return false;
    }
}

int main(int argc, char *argv[]) {

    FILE *fd_in, *fd_out;
    int i, A, B, res = 0;

    // Apertura del file di input
    fd_in = fopen("./input.txt", "r");
    if (fd_in == NULL) {
        fprintf(stderr, "Impossibile aprire il file di input!\n");
    }

    // Leggo i valori A e B
    fscanf(fd_in, "%d", &A);
    fscanf(fd_in, "%d", &B);

    for (i = A; i <= B; i++) {
        // Chiamo la funzione per tutti i numeri da A a B compresi
        if (pollatz(i) == true) {
            res++;
        }
    }

    // Scrittura sul file di output
    fd_out = fopen("./output.txt", "w");
    if (fd_out == NULL) {
        fprintf(stderr, "Impossibile creare il file di output!\n");
        exit(1);
    }
    fprintf(fd_out, "%d\n", res);

    // Chiusura del file di input
    fclose(fd_in);
    // Chiusura del file di output
    fclose(fd_out);

    return 0;
}
