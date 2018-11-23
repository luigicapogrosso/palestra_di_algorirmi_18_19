#include <fstream>
using namespace std;

string singola = "[O]";
string doppia = "[OOOO]";

ifstream in("input.txt");
ofstream out("output.txt");


void calcola(int rimaste, string risultato) {

  // Se non rimangono piu piastrelle, stampo il risultato nell'output
  if (rimaste <= 0)
    out << risultato << endl;
  else {
    // Tolgo una piastrella singola e calcolo il risultato,
    // sommare due stringhe significa concatenarle
    calcola(rimaste - 1, risultato + singola);
    if (rimaste >= 2)
      // Se ho abbastanza piastrelle, tolgo due piastrelle, usandone
      // una doppia, e calcolo il risultato
      calcola(rimaste - 2, risultato + doppia);
  }
}

int main() {
  int N;
  in >> N;

  // Chiamo la funzione passandogli N piastrelle e come risultato
  // niente
  calcola(N, "");
  in.close();
  out.close();
}