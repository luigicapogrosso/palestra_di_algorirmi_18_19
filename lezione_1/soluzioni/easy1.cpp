#include <fstream>

using namespace std;

int main() {

  ifstream in("input.txt");
  ofstream out("output.txt");

  // N: dimensione della sequenza
  // max: numero massimo attuale
  int N, max;

  // Prendo la dimensione
  in >> N;

  // Scelgo il primo numero come massimo
  in >> max;

  // Variabile temporanea
  int tmp;

  for (int i = 0; i < N - 1; i++) {
    in >> tmp;

    // Aggiorno il massimo
    if (tmp > max)
      max = tmp;
  }

  // Stampo il risultato nel file di output
  out << max;

  in.close();
  out.close();
  return 0;
}
