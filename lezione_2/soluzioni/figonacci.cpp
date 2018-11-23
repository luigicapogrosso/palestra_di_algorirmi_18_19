#include <fstream>
#include <iostream>
using namespace std;
int N, M;
int S[1000002];
int G[1000002];

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");
  in >> N >> M;
  G[0] = -1;
  G[1] = 0;

  // Salvo la somma parziale attuale, dove
  // S[n] = (G[n] + G[n-1] + ... + G[1] + G[0])
  S[0] = G[0] % M;
  for (int n = 1; n <= N; n++) {

    // La formula originale di Figonacci e':
    // G[n+1] = (G[n]-G[n-1]) + (G[n]-G[n-2]) + ... + (G[n]-G[2]) + (G[n]-G[1])
    // + (G[n]-G[0]) Con un po' di algebra si puo' ritrasformare in G[n+1] =
    // n*G[n] - (G[n-1] + G[n-2] + ... + G[0]) = G[n+1], quindi (per come
    // abbiamo definito S[n]): G[n+1] = n*G[n] - (S[n-1]) Aggiungendo i moduli:
    // G[n+1] % M = (((n % M) * G[n]) % M - S[n-1]) % M
    G[n + 1] = ((((n % M) * G[n]) % M) - S[n - 1]) % M;

	// Calcolo l'S[n] corrente, facendo la somma S[n-1] + G[n] 
	// e successivamente eseguendo il modulo
    S[n] = (S[n - 1] + G[n]) % M;
  }

  
  out << ((G[N] % M) + M) % M << endl;
  in.close();
  out.close();
}
