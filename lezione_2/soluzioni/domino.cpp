#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

std::vector<bool> tessereUsate;
vector<pair<int, int>> tessere;

int N;
int lunghezzaMassima = 0;

// Questa funzione ricorsiva viene richiamata in modo da controllare
// tutte le combinazioni possibili delle tessere che abbiamo in input
// e salva in una variabile la lunghezza massima che e' comparsa
void calcola(int facciaTesseraAttuale, int lunghezzaCatenaAttuale) {
  // Se la lunghezza attuale e' maggiore della lunghezza massima
  // aggiorno la lunghezza massima
  if (lunghezzaCatenaAttuale > lunghezzaMassima)
    lunghezzaMassima = lunghezzaCatenaAttuale;

  // Per ogni tessera che abbiamo vedo se non e' stata usata
  // e calcolo cosa succede se e' possibile concatenarla a alla
  // faccia attuale. Se e' possibile allora calcolo cosa succede collegando
  // la tessera attuale (mettendola usata=true) alla faccia attuale e aumentando
  // la lunghezza della catena di 1
  for (int i = 0; i < N; i++) {
    // Se la tessera attuale non e' stata usata
    if (!tessereUsate[i]) {
      // Controllo se la faccia attuale si puo' collegare alla tessera
      // attuale tramite la prima faccia
      if (facciaTesseraAttuale == tessere[i].first) {
        // Se si puo' collegare con la prima faccia, metto la tessera attuale
        // come usata
        tessereUsate[i] = true;

        // Calcolo cosa succede cercando di collegare la seconda faccia
        // della tessera attuale a qualcos altro e aumentando la lunghezza
        // della catena
        calcola(tessere[i].second, lunghezzaCatenaAttuale + 1);

        // Rimetto la tessera attuale come non usata
        tessereUsate[i] = false;
      }

      // Controllo se la faccia attuale si puo' collegare alla tessera
      // attuale tramite la seconda faccia (tessera ruotata)
      else if (facciaTesseraAttuale == tessere[i].second) {
        // Se si puo' collegare con la seconda faccia, metto la tessera attuale
        // come usata
        tessereUsate[i] = true;

        // Calcolo cosa succede cercando di collegare la prima
        // faccia della tessera atttuale a qualcos altro e aumento la lunghezza
        // della catena
        calcola(tessere[i].first, lunghezzaCatenaAttuale + 1);

        // Rimetto la tessera attuale come non usata
        tessereUsate[i] = false;
      }
    }
  }
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");
  in >> N;
  tessereUsate.resize(N);
  tessere.resize(N);
  int primaFaccia, secondaFaccia;

  // Salvo le tessere in un vettore di coppie
  // Ogni coppia contiene i due numeri che rappresentano
  // le facce della tessera
  for (int i = 0; i < N; i++) {
    in >> primaFaccia >> secondaFaccia;
    tessere[i] = make_pair(primaFaccia, secondaFaccia);

    // Metto la tessera che salvo attualmente come non usata
    tessereUsate[i] = false;
  }

  // Per ogni tessera, calcolo la catena che puo' essere generata
  // a partire dalla tessera corrente
  for (int i = 0; i < N; i++) {
    // Metto la tessera attuale come usata
    tessereUsate[i] = true;

    // Chiamo la funzione che calcola la soluzione passando come
    // faccia la prima faccia della tessera attuale, e come lunghezza
    // della catena 1, dato che sto usando solo una tessera
    calcola(tessere[i].first, 1);

    // Faccio la stessa cosa di prima passando pero' la seconda faccia
    // della tessera attuale, dato che la tessera puo' essere
    // ruotata.
    calcola(tessere[i].second, 1);

    // Metto la tessera attuale come non usata, dato che potra' essere usata
    // nella catena che inizia usando la prossima tessera
    tessereUsate[i] = false;
  }
  out << lunghezzaMassima << endl;

  in.close();
  out.close();
  return 0;
}
