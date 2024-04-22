#pragma once
#include "iostream"
using namespace std ;



bool lettura(const string& fileName,double& S,
              size_t& n,double*& w,double*& r);
/*funzione che legge i dati da data.csv,usando due riferimenti a puntatore w ed r
 * restituisce un booleano per dare errore se il file non si apre
 * inoltre i dati vengono modificati perchè creo alias con "&" e con *&
 *  vado a modificare il puntatore
*/
double computeReturn(size_t n,const double*w,const double*r);
//calcolo semplicemente il rendimento del portafoglio come sommatoria w[i]*r[i]

void exportResults(const string& fileName,double S,size_t n,
                   const double*w,const double*r,
                   double rendimentototale,double Sfinale);
/*questa funzione esporta il risultato in un file "result.txt"
 * stampa i vari pesi degli asset e il valore finale del portafoglio e rendimento*/
