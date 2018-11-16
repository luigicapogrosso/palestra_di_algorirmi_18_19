#include <fstream>
#include <utility>
#include <climits>

using namespace std;

int ps, pm4, pm5, pm7;
int result = INT_MAX;

void calcola(int persone, int s, int m4, int m5, int m7, int prezzo)
{
    if (persone <= 0)
        result = min(prezzo, result);
    else
    {
        // Se ho scooter disponibili, calcolo cosa succede con uno scooter in meno
        if (s > 0)
            calcola(persone - 2, s - 1, m4, m5, m7, prezzo + ps);

        // Se ho macchine da 4 disponibili, calcolo cosa succede senza quella macchina
        if (m4 > 0)
            calcola(persone - 4, s, m4 - 1, m5, m7, prezzo + pm4);

        // Se ho macchine da 5 disponibili, calcolo cosa succede senza quella macchina
        if (m5 > 0)
            calcola(persone - 5, s, m4, m5 - 1, m7, prezzo + pm5);

        // Se ho macchine da 7 disponibili, calcolo cosa succede senza quella macchina
        if (m7 > 0)
            calcola(persone - 7, s, m4, m5, m7 - 1, prezzo + pm7);
    }
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N, s, m4, m5, m7;

    // Salvo il numero di persone
    in >> N;

    // Salvo il numero di scooter e prezzo dello scooter
    in >> s >> ps;

    // Salvo il numero della macchina a 4 posti (m4) e prezzo (pm4)
    in >> m4 >> pm4;

    // Salvo il numero della macchina a 5 posti (m5) e prezzo (pm5)
    in >> m5 >> pm5;

    // Salvo il numero della macchina a 7 posti (m7) e prezzo (pm7)
    in >> m7 >> pm7;

    calcola(N, s, m4, m5, m7, 0);

    out << result << endl;

    in.close();
    out.close();
    return 0;
}
