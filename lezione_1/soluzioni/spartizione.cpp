#include<fstream>
#include<iostream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int gomme, persone;
    
    // Salvo il numero di gomme e persone
    in >> gomme >> persone;
    
    // Gomme (correnti) dovute a toto'
    int dovute = 1;
    
    // Gomme finali di toto'
    int gommeToto = 0;
    
    // Finche le gomme sono abbastanza da spartirle fra tutti.
    // Questo lo decido controllando togliendo le gomme dovute
    // e le gomme per ogni altra persona (oltre toto) dalle
    // gomme totali. Se sono maggiori di 0 allora sono abbastanza
    while(gomme - dovute - (persone - 1) >= 0) {
    	// Aggiorno le gomme rimaste, togliendo quelle dovute
    	// a toto' (i) e quelle dovute alle persone p - 1
    	// Togliamo 1 da p perche' in p e' compreso anche toto',
    	// per il quale ho gia' considerato le gomme date usando i
        gomme = gomme - dovute - (persone - 1);
        
        // Aggiorniamo le gomme totali di toto'
        gommeToto += dovute;
        
        // Aggiorniamo le gomme dovute a toto' nel prossimo turno
        dovute++;
    }
    
    // Aggiungiamo le eventuali gomme rimaste che andranno tutte a toto'
    gommeToto += gomme;
    
    out << gommeToto << endl;
    
    in.close();
    out.close();
    
    return 0;
}
