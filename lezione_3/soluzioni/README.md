# Soluzioni lezione 2

## Torri Hanoi
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