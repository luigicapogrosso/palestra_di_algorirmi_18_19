#include <climits>
#include <fstream>


using namespace std;

int main() {

  ifstream in("input.txt");
  ofstream out("output.txt");

  // N: dimensione della sequenza
  // max: somma massima pari attuale
  int N;
  int max = -1;

  // Variabili per salvare i 2 numeri pari piu grandi e i 2 numeri dispari piu
  // grandi
  int maxPari1, maxPari2, maxDispari1, maxDispari2;

  // Metto i numeri piu grandi al numero minimo possibile (-infinito)
  maxPari1 = maxPari2 = maxDispari1 = maxDispari2 = INT_MIN;

  // Variabile temporanea dove salvare il numero in input corrente
  int tmp;

  // Prendo la dimensione della sequenza
  in >> N;
  for (int i = 0; i < N; i++) {

    // Prendi in input il numero
    in >> tmp;

    // Controllo che il numero sia pari
    if (tmp % 2 == 0) {

      // Se il numero e' maggiore del piu' grande fra i pari
      if (tmp >= maxPari1) {

        // Metto il vecchio pari maggiore pari come secondo pari maggiore
        maxPari2 = maxPari1;

        // Metto il nuovo pari maggiore come primo pari maggiore
        maxPari1 = tmp;

        // Altrimenti, se il numero e' maggiore del secondo pari maggiore
      } else if (tmp > maxPari2) {

        // Aggiorno il secondo pari maggiore
        maxPari2 = tmp;
      }

      // Se non e' pari, il numero e' per forza dispari
      // In seguito il discorso e' analogo ai vari controlli che faccio
      // con i numeri pari.
    } else {
      if (tmp >= maxDispari1) {
        maxDispari2 = maxDispari1;
        maxDispari1 = tmp;
      } else if (tmp > maxDispari2) {
        maxDispari2 = tmp;
      }
    }
  }

  // Calcolo scelgo il numero pari piu grande
  if (maxPari1 + maxPari2 > maxDispari1 + maxDispari2) {
    max = maxPari1 + maxPari2;
  } else {
    max = maxDispari1 + maxDispari2;
  }

  // La somma pari non esiste se una coppia di numeri pari o dispari.
  // Uno dei due sarebbe INT_MIN che e' un numero negativo molto piccolo
  // quindi max sarebbe minore di zero
  if (max < 0) {
    max = -1;
  }

  // Stampo il risultato nel file di output
  out << max;

  in.close();
  out.close();
  return 0;
}
