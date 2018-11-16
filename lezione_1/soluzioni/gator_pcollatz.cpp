#include <fstream>
#include <cstdlib>

using namespace std;

int collatz(int n){
	int r = 1;
	while(n != 1){
		if(n%2 == 0){
			n = n/2;
		}else{
			n = n*3 + 1;
		}
		r++;
	}
	return r;
}

bool pollatz(int n){
	
	// Chiamo la funzione che restituisce la dimensione della
	// sequenza Collatz con l'n attuale
	int threshold = collatz(n);
	
	// Risultato finale, ha almeno un numero
	int r = 1;
	
	// Finche la sequenza pollatz ha dimensione minore della
	// sequenza collatz, e la sequenza non e' terminata
	while( r < threshold && n != 1){
		
		// Se e' pari
		if(n%2 == 0){
			n = n/2;
		}else{
			n = n*5 + 1;
		}
		// Aggiorno la dimensione della sequenza
		r++;
	}
	
	// Ritorno vero se la sequenza pollatz e' minore
	// di collatz, e se la sequenza pollatz e' terminata
	// (ovvero quando n e' uguale a 1)
	return (r < threshold) && (n == 1);
}

int main(){
	
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	int A, B;
	
	// Leggo i vaori A e B
	in >> A >> B;
	
	// Risultato finale
	int result = 0;
	
	for (int i=A; i<=B; i++){
		
		// Chiamo la funzione per tutti i numeri da A a B compresi
		if (pollatz(i)){
			result++;
		}
	}
	
	
	
	// Stampo il risultato nel file di output
	out << result << endl;
	
	in.close();
	out.close();
	return 0;
}
