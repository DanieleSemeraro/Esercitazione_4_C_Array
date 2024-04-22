#include "Utils.hpp"
#include "iostream"
#include "fstream"
#include "sstream"
#include <iomanip>

using namespace std;
bool lettura(const string& fileName,double& S,size_t& n,
              double*& w,double*& r) {
    ifstream file(fileName);
    if (!file.is_open()) {//verifica file aperto correttamente
        return false;
    }
    string line;
    string dato;
    getline(file, line);//legge prima riga
    istringstream iss(line);//converte la riga in istringstream
    getline(iss, dato, ';'); // Legge tutto fino al ';' e assegna a dato
    getline(iss,dato); // Legge il numero dopo il ';'e assegna a dato
    S = stod(dato); // Converte la stringa dato in double
    getline(file, line);//legge la seconda riga
    iss.clear();// cancella iss precedente per evitare errori
    iss.str(line);
    getline(iss,dato, ';');
    getline(iss,dato);
    n = stoi(dato); // Converte la stringa dato in size_t
    w = new double[n];//crea due nuovi puntatori ad arrey di double lunghezza n
    r = new double[n];
    getline(file, line);// Salta l'intestazione "w;r"
    size_t i= 0;
    //lettura dati
    while (getline(file, line)) {//finchè ci sono righe nel file
        istringstream lineStream(line);
        string weights,returns;
        getline(lineStream, weights, ';');  // Legge il peso fino al ;
        getline(lineStream, returns);    // Legge il ritorno
        w[i] = stod(weights);     // Converte e assegna all'arrey w
        r[i] = stod(returns);  // Converte e assegna
        i++;
    }
    file.close();
    return true;//ritorna vero se il file è stato letto correttamente
}
double computeReturn(size_t n,const double*w,const double*r){
    double rendimentototale = 0.0;//azzera per evitare errori
    for (size_t i = 0; i < n; ++i) {//pre incrementa i per evitare di fare una copia
        rendimentototale += w[i] * r[i];//sommatoria prodotto pesi*rendimenti
    }
    return rendimentototale;
}
//funzione che stampa i risultati in un file
void exportResults(const string& fileName,double S,size_t n,const double* w,
                   const double* r,double rendimentototale,double Sfinale) {
    ofstream file(fileName);
    if (!file.is_open()) {//verifica se il file è cretao correttamente
        cerr << "Could not open file for writing." << endl;
        return;
    }
    file << "S = "<<fixed<< setprecision(2)<<S<< ", n = " << n << "\n";
    //stampa aset e rendimenti formato arrey
    file << "w = [ ";
    for (size_t i = 0; i < n; ++i) {
        file << w[i] << (i < n-1 ? " " : " ]\n");
    }//questo è un if-else breve,se i<n-1 stampa lo spazio else stampa ] cioè sono arrivato a fine arrey
    file << "r = [ ";
    for (size_t i = 0; i < n; ++i) {
        file << r[i] << (i < n-1 ? " " : " ]\n");
    }
    file << "Rate of return of the portfolio: " << fixed << setprecision(4)<<rendimentototale<< "\n";
    file << "V: " << fixed << setprecision(2)<<Sfinale<< "\n";

    file.close();
}

