#include <fstream>

using namespace std;

int main() {

  ifstream in("input.txt");
  ofstream out("output.txt");

  // N: dimensione della sequenza di coppie
  // max: somma massima pari attuale
  int N;
  int max = -1;

  // Prendo la dimensione
  in >> N;

  // Variabili temporanea
  int tmp1, tmp2;
  in >> tmp1 >> tmp2;

  // Scelgo la prima coppia come somma massima se pari
  if ((tmp1 + tmp2) & 2 == 0) {
    max = tmp1 + tmp2;
  }

  for (int i = 0; i < N - 1; i++) {
    in >> tmp1 >> tmp2;

    // Aggiorno la somma massima pari
    if ((tmp1 + tmp2 > max) && ((tmp1 + tmp2) % 2 == 0)) {
      max = tmp1 + tmp2;
    }
  }

  // Stampo il risultato nel file di output
  out << max;

  in.close();
  out.close();
  return 0;
}
