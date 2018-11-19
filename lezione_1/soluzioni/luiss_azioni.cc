#include <fstream>
#include <cstdlib>
using namespace std;


int main(){
	
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	// N: dimensione della sequenza
	// max: differenza massima in valore assoluto
	int N;
	int max = -1;
	
	// Salvo la dimensione della sequenza
	in >> N;
	
	// Variabili dove salvo i valori consecutivi
	int tmp1, tmp2;
	
	// Prendo i primi due valori consecutivi
	in >> tmp1 >> tmp2;
	
	// Salvo la prima differenza in valore assoluto come massima
	max = abs(tmp1-tmp2);
	for(int i=1; i<N; i++){
		
		// Aggiorno i valori consecutivi
		tmp1 = tmp2;
		in >> tmp2;
		
		// Aggiorno la differenza massima in valore assoluto
		if(abs(tmp1-tmp2)>max){
			max = abs(tmp1-tmp2);
		}
	}
	
	// Stampo il risultato nel file di output
	out << max;
	return 0;
}
