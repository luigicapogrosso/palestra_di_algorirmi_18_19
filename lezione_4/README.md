# Lezione 4

Nota: tutti i problemi possono essere risolti attraverso l'utilizzo di un linguaggio a piacere.

### Riscaldamento

* __Somma di due matrici__.

    Scrivere un programma che, generate due matrici all'interno delle quali sono presenti
    numeri casuali, crei una terza matrice che sia la somma delle due.
    Stampare a video il risultato.

    Si definisca attraverso una variabile globale ```SIZE``` la dimensione della matrice.

    La somma di due matrici è così definita:

    C[i][j] = A[i][j] + B[i][j]

* __Prodotto di due matrici__.

    Scrivere un programma che, generate due matrici all'interno delle quali sono presenti
    numeri casuali, crei una terza matrice che sia il prodotto delle due.
    Stampare a video il risultato.

    Due matrici possono essere moltiplicate fra loro solo se il numero di colonne della prima è uguale al numero di righe della seconda, ed il prodotto tra due matrici non è commutativo.
    Si definiscano la dimensione delle righe e delle colonne nel modo più opportuno quindi.

    Il prodotto di due matrici è così [definito](https://it.wikipedia.org/wiki/Moltiplicazione_di_matrici "definizione del prodotto di due matrici")

* __Concorso di intelligenza__.
    In un concorso di intelligenza, N giudici esprimono il loro giudizio su K candidati. Il giudizio è un valore numerico tra 0 e 5.

    Si scriva un programma per determinare il candidato più intelligente, ed il giudice più severo.

* __Gestione magazzino__.
    Un’azienda deve tenere traccia dei beni presenti in un magazzino. L’utente inserisce da tastiera dei “comandi” nel seguente formato:

    bene [E | U] quantità

    dove:
    * bene è il nome di un bene;
    * EU è la lettera ’E’ per entrata, ’U’ per uscita;
    * quantità è la quantità di bene entrata o uscita.

    L’utente termina il caricamento inserendo un comando pari a FINE. In tal caso il programma deve stampare le quantità di beni presenti a magazzino.

    Esempio:
    viti E 10
    dadi E 50
    viti U 5
    viti E 3
    FINE
