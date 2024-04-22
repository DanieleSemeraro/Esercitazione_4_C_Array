#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include "Utils.hpp"

using namespace std;


int main() {
    string inputFileName = "data.csv";
    string outputFileName = "result.txt";
    double S=0;
    size_t n=0;
    //size_t è usato quando la lunghezza di un indice non è conosciuta a priori
    //e potrebbe avere un valore molto grande
    double* w = nullptr;//w ed r sono due puntatori nulli
    double* r = nullptr;
//lettura dati dal file
    if (!lettura(inputFileName, S, n, w, r)) {//quando leggo correttamente ritorno falso e salto l'if
        cerr << "Failed to read data from file." << endl;
        return -1;
    }
    double rendimentototale= computeReturn(n, w, r);
    double Sfinale = S * (1 +rendimentototale);
    //il valore del portafoglio dato rendimento totale
//stampa risultati su file txt
    exportResults(outputFileName, S, n, w, r,rendimentototale,Sfinale);

    delete[] w;//cancello gli arrey per evitare problemi di memoria
    delete[] r;

    return 0;
}


