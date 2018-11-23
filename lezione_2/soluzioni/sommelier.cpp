#include <fstream>

using namespace std;

int gradazioniAlcoliche[100];
int n;

int assaggia(int i, int assaggiati, int ultimo) {
  if (i >= n) {
    // Se ho finito la sequenza
    return assaggiati;
  } else {
    if (gradazioniAlcoliche[i] >= ultimo) {
      // Prendo il massimo calcolato tra assaggiare il vino corrente e saltarlo
      return max(assaggia(i + 2, assaggiati + 1, gradazioniAlcoliche[i]),
                 assaggia(i + 1, assaggiati, ultimo));
    } else { // Se non posso assaggiare il vino
      return assaggia(i + 1, assaggiati, ultimo);
    }
  }
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  in >> n;
  for (int i = 0; i < n; i++) {
    in >> gradazioniAlcoliche[i];
  }
  // Stampo il risultato partendo dal primo vino, con 0 vini assaggiati e
  // mettendo il primo vino come ultimo
  out << assaggia(0, 0, 0);
  in.close();
  out.close();
  return 0;
}