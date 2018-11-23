#include <fstream>
#include <algorithm>
using namespace std;

int interroga(int N, int K, int D[]) {

  // Ordino le domande dalla piu facile alla piu difficile
  sort(D, D + N);

  // Imposto come differenza di difficolta massima (piu difficile - piu facile)
  int difficoltaMax = D[N - 1] - D[0];

  // L'idea del for e' far scorrere una finestra di dimensione K
  // sull'array delle difficolta', dunque avremo le difficolta massime
  // e minime per ogni finestra. Prenderemo la minima differenza fra queste difficolta
  for (int i = 0; i <= N - K; i++) {
    difficoltaMax = min(difficoltaMax, D[i + K - 1] - D[i]);
  }
  return difficoltaMax;
}

const int MAX = 10000;
int D[MAX];

int main() {
  int N, K;

  ifstream in("input.txt");
  ofstream out("output.txt");
  // N sono le domande, K sono gli interrogati
  in >> N >> K;

  // Salvo le difficolta di ogni domanda
  for (int i = 0; i < N; i++) {
    in >> D[i];
  }


  out << interroga(N, K, D);
  in.close();
  out.close();
  return 0;
}