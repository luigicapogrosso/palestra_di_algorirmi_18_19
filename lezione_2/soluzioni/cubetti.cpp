#include <queue>
#include <bitset>

using namespace std;
void Vernicia(int indice, int colore);

void Diversifica(int N, int colore[]) {

  // Coda che verra' utilizzata per il calcolo
  queue<int> coda;
  // Vettore di booleani che indica se il colore dell'iesimo cubetto e' presente
  bitset<1000001> coloriPresi;

  // Metto a true i colori che sono presenti
  for (int i = 0; i < N; i++) {
    coloriPresi[colore[i]] = true;
  }

  for (int i = 1; i <= N; i++) {

    // Metto nella coda i colori che sono gia' stati visti
    if (!coloriPresi[i]) {
      coda.push(i);
    }
  }

  // Rimetto coloriPresi tutto a false
  coloriPresi.reset();

  // Per tutti i cubetti
  for (int i = 0; i < N; i++) {
    // Se il colore non e' stato visto
    if (!coloriPresi[colore[i]]) {
      // Mettiamo il colore come visto
      coloriPresi[colore[i]] = true;
    } else {
      // Se il colore dell'iesimo cubetto esiste gia', rivernico il cubetto
      // che c'e' nella coda dandogli il colore i
      Vernicia(i, coda.front());
      // Tolgo il cubetto appena riverniciato dalla coda
      coda.pop();
    }
  }
}