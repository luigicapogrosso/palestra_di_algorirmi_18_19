#include <stdio.h>

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

int main() 
{ 
	int n;
	printf("Inserire il numero di dischi: ");
    scanf("%d", &n);
    printf("\nEcco le mosse da seguire per risolvere il rompicapo con %d dischi:", n);
    
    // A, B e C sono i nomi dei pioli. 
	// A e' il piolo di partenza, 
	// B e' il piolo dove dovranno trovarsi tutti i dischi alla fine, 
	// C viene usata come piolo ausiliario iniziale
    hanoi(n, 'A', 'B', 'C');  
    return 0; 
} 
