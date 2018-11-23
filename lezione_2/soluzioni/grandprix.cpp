using namespace std;

#include <fstream>

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");
  int posizioni[30];
  int n, m;

  // Leggo i gareggiantori e il numero di sorpassi
  in >> n >> m;
  // Leggo le posizioni di partenza
  for (int i = 0; i < n; i++) {
    in >> posizioni[i];
  }
  // Si esegue una simulazione di cosa succede per ogni sorpasso
  int sorpassante, sorpassato;

  int indiceSorpassante, indiceSorpassato;

  // Per ogni sorpasso che ci e' stato
  for (int i = 0; i < m; i++) {

    // Leggo il sorpassante e sorpassato correnti
    in >> sorpassante >> sorpassato;

    // Salvo gli indici dei gareggiatori coinvolti
    for (int j = 0; j < n; j++) {
      if (posizioni[j] == sorpassante) {
        indiceSorpassante = j;
      } else if (posizioni[j] == sorpassato) {
        indiceSorpassato = j;
      }
    }
    
    // Effettuo lo swap delle posizioni
    posizioni[indiceSorpassante] = posizioni[indiceSorpassante] + posizioni[indiceSorpassato];
    posizioni[indiceSorpassato] = posizioni[indiceSorpassante] - posizioni[indiceSorpassato];
    posizioni[indiceSorpassante] = posizioni[indiceSorpassante] - posizioni[indiceSorpassato];

  }
  // Stampo la soluzione
  out << posizioni[0];

  in.close();
  out.close();
  return 0;
}