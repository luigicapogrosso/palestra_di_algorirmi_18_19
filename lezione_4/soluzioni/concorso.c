#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define LUN 30

int main(int argc, char const *argv[]) {

    int qta;
    char dir;
    // n è la dimensione dei vettori prodotti[] e quantita[]
    int i, trovato, n = 0;
    char prod[LUN];
    int quantita[MAX];
    char prodotti[MAX][LUN];

    do {
        // Acquisisci un comando dall’utente
        /* NOTA: non si può usare il costrutto
         * scanf("%s %c %d", prod, &dir, &qta);
         * in quanto non funziona per l’ultima riga (FINE)
         */
        printf("Comando: ");
        scanf("%s", prod);

        if (strcmp(prod, "FINE") != 0) {
            scanf(" %c %d", &dir, &qta);
            // Entrata
            if (dir == 'E') {
                // Trova la posizione del prodotto nel vettore prodotti[]
                trovato = -1;
                for (i = 0; i < n; i++) {
                    if (strcmp(prodotti[i], prod) == 0) {
                        trovato = i;
                    }
                }
                // Il prodotto esiste già
                if (trovato != -1) {
                    /* Incrementa la posizione corrispondente del vettore
                     * quantita[]
                     */
                    quantita[trovato] = quantita[trovato] + qta;
                // Prodotto nuovo
                } else {
                    // Aggiungi il prodotto al magazzino in posizione nuova
                    strcpy(prodotti[n], prod);
                    quantita[n] = qta;
                    n++;
                }
            }
        // Uscita
        } else {
            // Trova la posizione del prodotto nel vettore prodotti[]
            trovato = -1;
            for (i = 0; i < n; i++) {
                if (strcmp(prodotti[i], prod) == 0) {
                    trovato = i;
                }
            }
            if (trovato == -1) {
                printf("Prodotto %s non trovato in magazzino\n", prod);
            } else {
                /* Decrementa la posizione corrispondente del vettore
                 * quantita[]
                 */
                quantita[trovato] = quantita[trovato] - qta ;
            }
        }
    }

    while (strcmp(prod, "FINE") != 0);

    for (i = 0; i < n; i++) {
        printf("%s %d\n", prodotti[i], quantita[i]);
    }

    return 0;
}
