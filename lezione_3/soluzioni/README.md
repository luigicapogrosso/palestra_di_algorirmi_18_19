# Soluzioni lezione 3

## Fattoriale
### Idee generali per risolvere l'esercizio
Il programma che calcola il fattoriale di un numero, come si nota chiaramente, non fa altro che esprimere utilizzando le caratteristiche del linguaggio di programmazione, la definizione di fattoriale. La funzione chiama sé stessa passando come parametro il valore, decrementato di una unità, del parametro ricevuto e in questo modo ci si approssima, come richiesto dalle proprietà espresse precedentemente, al valore 0 (valore base). Tale ultimo valore, in dipendenza della verità della condizione espressa in blocca il processo ricorsivo.

Nota: il fattoriale di un numero cresce molto velocemente. Per calcolare il
fattoriale di numeri grandi, modificare la funzione sostituendo ```int``` con ```long```

## Fibonacci
### Idee generali per risolvere l'esercizio
Il programma che calcola il valore della serie di Fibonacci di un numero, è realizzato con lo stesso principio di quello del fattoriale. Ovvero, viene espressa, utilizzando le caratteristiche del linguaggio di programmazione, la definizione della serie di Fibonacci. 


## Torri Hanoi
### Idee generali per risolvere l'esercizio
Per risolvere questo problema si usa la ricorsione. La funzione hanoi prende come parametro l'n-esimo disco da muovere, ovvero il piu' grande. In piu' prende altri 3 parametri, che sono:  
- Piolo di partenza: Il piolo attuale in cui un determinato numero di dischi risiede  
- Piolo di arrivo: Il piolo attuale dove un numero determinato di dischi dovra' essere spostato  
- Piolo ausiliario: Viene utilizzato come tappa per spostare un numero determinato di dischi  
 
Se noi vogliamo far arrivare tutti i dischi dal piolo A al piolo B, possiamo chiamare la funzione passandogli gli n dischi che abbiamo e passandogli come Piolo di partenza A, piolo di arrivo B e piolo ausiliario C.  
Prendiamo come esempio n = 5 dischi  
Intuitivamente possiamo risolvere il problema dividendolo in 3 passi logici:
1) Muovere i 4 dischi (che sono appoggiati sopra il disco 5) nel piolo ausiliario C. Questa procedura non puo' essere fatta in un colpo solo, infatti viene richiamata la funzione ricorsivamente, che si arrangera' a farlo.
2) Una volta che la chiamata ricorsiva ha fatto il suo lavoro (ovvero spostato i 4 dischi dal piolo A al piolo C) possiamo spostare il disco 5 al piolo di arrivo B in un colpo solo.
3) Successivamente, dobbiamo spostare i 4 dischi dal piolo ausiliario C al piolo di arrivo B. Ancora una volta questa procedura non puo' essere fatta in un colpo solo, ma viene richiamata la funzione ricorsivamente che si arrangia a farlo.

Una volta seguiti questi passi, possiamo notare che tutti i dischi si sono spostati dal piolo A al piolo B senza violare le regole del gioco.

Ecco la funzione hanoi scritta in c:
```c
void hanoi(int n, char piolo_partenza, char piolo_arrivo, char piolo_ausiliario) 
{ 
    if (n == 1) 
    { 
    	// Il disco 1 e' il piu' piccolo, posso spostarlo dove voglio senza problemi
        printf("\n Muovi il disco 1 dal piolo %c al piolo %c", piolo_partenza, piolo_arrivo); 
        return; 
    }
    // Sposta gli n-1 dischi dal piolo attuale al piolo ausiliario
    hanoi(n-1, piolo_partenza, piolo_ausiliario, piolo_arrivo);
    
    // Sposta il disco rimasto n (il piu grande) dal piolo di partenza attuale al piolo di arrivo attuale
    printf("\n Muovi il disco %d dal piolo %c al piolo %c", n, piolo_partenza, piolo_arrivo);
    
    //Sposta gli n-1 dischi dal piolo ausiliario attuale al piolo di arrivo attuale
    hanoi(n-1, piolo_ausiliario, piolo_arrivo, piolo_partenza); 
} 
```
Ad occhio non e' molto facile capire come fa la chiamata ricorsiva ad "arrangiarsi" spostando i dischi da una parte all'altra, ma seguendo le chiamate passo dopo passo prendendo un n qualsiasi come esempio (iniziando con un n piccolo) si riesce a capire meglio.

## Festa di laurea (laurea)
### Breve spiegazione del testo
Il problema richiede di minimizzare il costo del trasporto di N persone da un punto A ad un punto B potendo utilizzare 4 tipologie di veicoli, che possono trasportare 2, 4, 5 o 7 persone. Il veicolo V<sub>i</sub> avrà costo P<sub>i</sub> e disponibilità D<sub>i</sub>, dati in input.

### Idee generali per risolvere l'esercizio
Una semplice idea, che prende 100 / 100, è provare tutti i modi validi per raggiungere B partendo da A e salvare quello che risulta avere il costo minore.
```cpp

M = ∞

void solve(int N, int qa, int qb, int qc, int qd, int prezzo) {
    if (N <= 0) M = min(prezzo, M);
    else {
        if(qa > 0) solve(N - 2, qa-1, qb, qc, qd, prezzo + pa);
        if(qb > 0) solve(N - 4, qa, qb-1, qc, qd, prezzo + pb);
        if(qc > 0) solve(N - 5, qa, qb, qc-1, qd, prezzo + pc);
        if(qd > 0) solve(N - 7, qa, qb, qc, qd-1, prezzo + pd);
    }
}
```

Il codice è abbastanza semplice, se abbiamo la possibilità di usare ancora il veicolo V<sub>i</sub> allora lo usiamo, e chiamiamo la funzione che risolverà il sotto-problema con (N - P<sub>i</sub>) persone, (D<sub>i</sub> - 1) disponibilità e (prezzo + P<sub>i</sub>) costo speso finora. E così via per tutti i veicoli V<sub>i</sub>. Quando vorrò risolvere un problema con N <= 0 persone, allora potrò considerare il costo speso finora come il costo totale, confrontarlo con una variabile che conterrà il miglior risultato ottenuto e prendere il minimo.

### Idee alternative
Ci sono modi migliori per risolverlo, stay tuned.

## Sommelier
### Breve spiegazione del testo
Sono dati in input N numeri interi, ciascuno dei quali rappresenta la gradazione alcolica di un certo vino. Il problema richiede di trovare la lunghezza della massima sottosequenza di questi numeri tale che:
* La sottosequenza è crescente
* Non ci possono essere nella sottosequenza due numeri che sono contigui nella sequenza iniziale dei valori.

### Idee generali per risolvere l'esercizio
Usiamo la tecnica del backtracking (ricorsivo): proviamo tutte le sottosequenza possibili. Per fare ciò, consideriamo per ogni vino la massima sottosequenza che possiamo ottenere
* scegliendo questo vino ```assaggia(i+2,assaggiati+1,a[i])``` (notare come in questo caso ci spostiamo avanti di due posizioni nella sequenza dei vini)
* passando direttamente al prossimo ```assaggia(i+1,assaggiati,ultimo)``` (senza dunque incrementare il numero dei vini assaggiati).

Nel caso in cui il vino che stiamo considerando non possa essere inserito nella sequenza di scelte correnti (ovvero quando ```a[i] < ultimo```), l'unica possibile azione che possiamo effettuare è passare al prossimo vino. Finiti i vini da assaggiare, ritorniamo alla funzione chiamante il numero di vini effettivamente considerati dalla sequenza di scelte che ha portato fino a quel punto; al ritorno dalla ricorsione i-esima viene scelto il valore più alto tra scelgo/non scelgo il vino i.

### Idee alternative
In questo caso, visto il numero ridotto di vini nella sequenza, si può tranquillamente applicare la tecnica del backtracking, che ha costo computazionale _O(2^N)_; tuttavia se la quantità di vini coinvolti fosse maggiore sarebbe conveniente ridurre la complessità con la tecnica di __programmazione dinamica__, o nella forma ricorsiva (_Memoization_) o in quella iterativa: "l'implementazione è lasciata al lettore come esercizio".

## Piastrelle
### Breve spiegazione del testo
Abbiamo 2 diverse tipologia di piastrelle da piazzare, rispettivamente di lunghezza 1 e 2. Dobbiamo stampare tutti i possibili modi di piazzare le piastrelle in modo che la somma delle lunghezze sia uguale ad N (acquisito in input).

### Idee generali per risolvere l'esercizio
Semplicemente proviamo tutti i possibili modi di piazzare le piastrelle (backtrack) e stampiamo i modi validi (lunghezza == N).

## Interrogazioni
### Breve spiegazione del testo
Abbiamo N quesiti diversi ognuno con difficoltà D<sub>i</sub>, dobbiamo selezionare un sottoinsieme S di K quesiti tale che la differenza d tra max(S) e min(S) sia la minore possibile, dobbiamo poi stampare in output d.

### Idee generali per risolvere l'esercizio
Ordiniamo gli N quesiti per difficoltà crescente, facciamo scorrere una finestra di lunghezza K sul vettore delle difficoltà D. In questo modo abbiamo che l'elemento con indice i avrà difficoltà minima e l'elemento con indice i+K-1 avrà difficoltà massima nel sottoinsieme S di K elementi considerato. A questo punto la risposta è ```min(D[i+K-1] - D[i])``` per i compreso tra 0 ed N-K.
