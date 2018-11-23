# Guida C per le Olimpiadi Italiane dell'Informatica

## Indice:
* [I/O su file](#I/O-su-file)
* [Operatore % (modulo)](#operatore-%-(modulo))
* [Funzioni max / min](#funzioni-max/min)
* [Funzione abs](#funzione-abs)
* [Funzione qsort](#funzione-qsort)

## I/O su file
Questo è il template che userete più spesso:

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int num;
    FILE *fd_in, *fd_out;

    // Apertura del file di input
    fd_in = fopen("input.txt", "r");
    if (fd_in == NULL) {
        fprintf(stderr, "Impossibile aprire il file di input!\n");
        exit(1);
    }

    // Lettura di una variabile
    fscanf(fd_in, "%d", &num);

    // Scrittura sul file di output
    fd_out = fopen("output.txt", "w");
    if (fd_out == NULL) {
        fprintf(stderr, "Impossibile creare il file di output!\n");
        exit(1);
    }
    fprintf(fd_out,"%d", num);

    // Chiusura del file di input
    fclose(fd_in);
    // Chiusura del file di output
    fclose(fd_out);

    return 0;
}
```

## Operatore % (modulo)
L'operatore ```%``` mi restituisce il resto di una divisione:
```c
int a = 5;
int b = 2;
int c = a % b;
```
A fine esecuzione c varrà 1.

## Funzioni max / min
Le funzioni ```max``` e ```min``` non sono presenti nel linguaggio C, ma non spaventatevi! Basta inserire le seguenti righe
prima della funzione ```main```:
```c
#ifndef max
    #define max(a, b) ((a) > (b) ? (a) : (b))
#endif

#ifndef min
    #define min(a, b) ((a) > (b) ? (b) : (a))
#endif
```
Le funzioni ```max``` e ```min``` restituiscono rispettivamente il massimo e il minimo di due numeri:
```c
int a = 5;
int b = 2;
int c = max(a, b);
int d = min(a, b);
```
A fine esecuzione c varrà 5 e d varrà 2.

## Funzione abs
Le funzione ```abs``` restituisce il valore assoluto di un numero:
```c
int a = -5;
int b = 5;
int c = abs(a); 
int d = abs(b); 
```
A fine esecuzione c varrà 5 e d varrà 5.

## Funzione qsort
La funzione ```qsort``` è stata sviluppata per ordinare un array con l'algoritmo Quick-Sort. Quest'ultimo è un algoritmo di ordinamento per confronti che nel caso medio ha una complessità di O(n*log(n)). 

La funzione, per come è stata implementata:
* Non sa a priori su quale tipo di dato dovrà operare;
* Non sa a priori su quanti elementi dovrà operare;
* Non sa a priori la dimensione di un singolo elemento.

Tutti questi dati infatti vengono forniti alla funzione ```qsort```. La firma della funzione è quindi:
```c
void qsort (void* base, size_t num, size_t size,  
            int (*comparator)(const void*,const void*));
 ```

L'unica cosa che "sa" è questa: in base all'algoritmo Quick-Sort dovrà chiamare ogni volta la funzione di comparazione e in base al risultato di questa comparazione, dovrà scambiare (oppure no) i 2 elementi. La funzione di comparazione ritorna:
* n < 0 se l'elemento p1 precede l'elemento p2
* n = 0 se l'elemento p1 è equivalente all'elemento p2
* n > 0 se l'elemento p1 segue l'elemento p2
