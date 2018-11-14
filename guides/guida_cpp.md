# Guida C++ per le Olimpiadi Italiane dell'Informatica

## Indice:
* [I/O su file](#I/O-su-file)
* [Operatore % (modulo)](#operatore-%-(modulo))
* [Funzioni max / min](#funzioni-max/min)
* [Funzione abs](#funzione-abs)

## I/O su file
Questo è il template che userete più spesso:

```cpp
#include<fstream>
using namespace std;

int main() {

    // Specifica del file di input
    ifstream in("input.txt");
    // Specifica del file di output
    ofstream out("output.txt"); 
  
    // Lettura di una variabile
    int a;
    in>>a;
  
    // Soluzione
   
    // Output della variabile
    out<<a;
    
    // Chiusura del file di input
    in.close();
    // Chiusura del file di output
    out.close(); 
    return 0;
}
```

## Operatore % (modulo)
L'operatore ```%``` mi restituisce il resto di una divisione:
```cpp
int a = 5;
int b = 2;
int c = a % b;
```
A fine esecuzione c varrà 1.

## Funzioni max / min
Le funzioni ```max``` e ```min``` restituiscono rispettivamente il massimo e il minimo di due numeri:
```cpp
int a = 5;
int b = 2;
int c = max(a,b);
int d = min(a,b);
```
A fine esecuzione c varrà 5 e d varrà 2.

## Funzione abs
Le funzione ```abs``` restituisce il valore assoluto di un numero:
```cpp
int a = -5;
int b = 5;
int c = abs(a); 
int d = abs(b); 
```
A fine esecuzione c varrà 5 e d varrà 5.
