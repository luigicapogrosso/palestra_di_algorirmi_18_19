#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int K, N;

// Struttura persona, dove vengono salvate il tempo di inizio e fine
struct persona
{
    int inizio, fine;
};

// Funzione booleana che verra' passata come argomento
// alla funzione sort.
// Ritorna vero se una persona inizia prima dell'altra
bool confrontaTempoInizio(persona a, persona b)
{
    if (a.inizio < b.inizio)
        return true;
    return false;
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    // Salvo gli interi K ed N
    in >> K >> N;

    // Vettore di persone dove salvero' tutte le persone
    vector<persona> persone;

    // Variabile dove salvo la persona corrente che sto analizzando
    persona person;

    for (int i = 0; i < N; i++)
    {
        // Analizzo la persona e mi segno i suoi tempi di inizio e fine
        in >> person.inizio >> person.fine;

        // Aggiunge la persona corrente al vettore di tutte le persone
        persone.push_back(person);
    }

    // Ordino il vettore di persone in base al loro tempo di inizio
    sort(persone.begin(), persone.end(), confrontaTempoInizio);

    // Variabile che salva il tempo di fine della persona che e'
    // attualemnte ultima nel turno di sorveglianza
    int fine = 0;

    // Variabile per tener conto della fine corrente che e' piu vicina a K
    int maxFine = 0;

    // Regali dovuti
    int regali = 0;

    // Finche non ho coperto tutto il tempo del viaggio
    while (fine < K)
    {
        maxFine = 0;

        // Per ogni persona (procedendo in ordine di tempo di inizio)
        for (int i = 0; i < N; i++)
        {
            // Se la persone corrente inizia prima della persona che e' attualemtne ultima
            // nel turno di sorveglianza
            // e 
			// se la persone corrente finisce dopo la fine corrente piu grande del tempo K
            if (persone[i].inizio <= fine && persone[i].fine > maxFine)
                //Aggiorno la fine massima corrente
                maxFine = persone[i].fine;
        }

        // Aggiorno la fine massima corrente
        maxFine++;

        // Aggiorno la variabile per il controllo fine < K
        fine = maxFine;
        
        // Aggiungo un regalo
        regali++;
    }

    out << regali;
    in.close();
    out.close();
}
