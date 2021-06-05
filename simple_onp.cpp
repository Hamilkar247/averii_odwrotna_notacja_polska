
// 1.Program prosi o wprowadzenie wyrażenia składającego się z cyfr od 0 do 9
// oraz znaków +-*/ z zwykłej notacji
// 2.Program wczytuje wprowadzone przez użytkownika wyrażenie.
// 3.Program konwertuje wyrażenie na ONP.
// 4.Program oblicza wynik wyrażenia z wykorzystaniem stosu
// i wyświetla wynik.

#include <iostream>
#include <bits/stdc++.h>
#include <ctype.h>
#include <string>

using namespace std;

#define MAXIMUM 1000

class Stapel {    //stos

    int scheitel; //wierzchołek/top

public:
    int a[MAXIMUM];

    Stapel() { scheitel = -1; }
    bool zustossen(int x); //push/pchać
    int aufziehen(); //pop/ciągnąć
    int aussehen();  //spojrzeć/look
    bool istLeer();
};

bool Stapel::zustossen(int x) //pchać push
{
    if (scheitel >= (MAXIMUM - 1)) {
        cout << "Stapel Uberlauf!"; //stack overflow / stos przepełniony
        return false;
    }
    else {
        a[++scheitel] = x;
        cout << x << " hat zu Stapel gezustossen"; //pushed into stack // pchniete na stos
        return true;
    }
}

int Stapel::aufziehen() //ciąnąć pop
{
    if (scheitel < 0) {
        cout << "Stapel Unterlauf"; //
        return 0;
    }
    else {
       int x = a[scheitel--];
       return x;
    }
}

int Stapel::aussehen()  //spojrzec /peek/look
{
    if(scheitel < 0) {
        cout << "Stapel ist Leer";
        return 0;
    }
    else {
        int x = a[scheitel];
        return x;
    }
}

bool Stapel::istLeer()    //jest pusty/is Empty
{
    return (scheitel < 0); //wierzcholek
}

void Stapel_nutzen_beispiel() {
    std::cout << "Hallo, Welt!\n" <<endl;
    class Stapel stapel;
    stapel.zustossen(10); //push/pchać
    stapel.zustossen(20);//push/pchać
    stapel.zustossen(30);
    cout << stapel.aufziehen() << " aufziehen von stapel"<<endl; //ciągniemy element z stosu
    //drucken alles die Komponenten auf dem Stapel :
    cout<<"die Komponnenten auf Stapel : "<<endl;
    while(!stapel.istLeer())
    {
        //druck scheitel komponnente auf dem Stapel
        cout<<stapel.aussehen()<<" ";
        // loschen scheitel komponnente auf Stapel
        stapel.aufziehen();
        cout<<"\n--------drucken den Strich -------------\n"<<endl;
    }
}

void argc_und_argv_arbeiten_beispiel(int argc, char *argv[]){

    //probe argc und argv
    cout << "Du hast betreten variabel " << argc << " die Argumenten: " << "\n";
    //erste Argumente ist vorname dem Program
    //anderer ist schreiben die Argumenten
    for ( int i = 0; i < argc; ++i){
        cout << argv[i] << "\n";
    }
}

class Odwrotna_notacja_polska
{
    Stapel stapel;
public:
    Odwrotna_notacja_polska() { anzahl_Elementen = -1; }
    int anzahl_Elementen;       //liczba/number
    char *elementen[];
    bool elementen_ist_Zahl_nicht_Buchstache(char zahl);
    void zaladuj_tablice_symboli(string *name, int liczba_elementow);
    int zeichen_Lange(char argv[]);
};

int Odwrotna_notacja_polska::zeichen_Lange(char argv[]){
    cout <<"zeiche_Lange"<<endl;
    cout << argv << endl;
    int kalkulieren = 0;        //zliczaj/count
    while ( *argv != '\0' )
    {
       kalkulieren++;
       argv++;
    }
    return kalkulieren;
}

bool Odwrotna_notacja_polska::elementen_ist_Zahl_nicht_Buchstache(char zahl){
    return false;
}

void Odwrotna_notacja_polska::zaladuj_tablice_symboli(string *tablica, int liczba_elementow)
{
    cout << tablica[0] << tablica[1] << endl;
    //vorinkrementierung, also - erste `i` in Schleife 'for' hast zwei
    for ( int i = 0; i < liczba_elementow; i++ ){
         cout<<i <<": "<<tablica[i]<<endl;
         ////Wenn Ingress hat Leerzeichen nicht /nie ma spacji
         ////Wir brauchen zweite Schleife 'for'
         //int zahn = zeichen_Lange(tablica[i]); //zeichen - znak symbol
         //cout<< "zahn lang auf den Worte: " << zahn << endl;
         ////string tafle_string*;
         //string kette_zahn = "";
         //for ( int j = 0; j <= zahn; ++j){
         //    if (isdigit(tablica[i][j]) == true){
         //        kette_zahn.push_back(tablica[i][j]);
         //    }
         //    else {
         //        cout<<kette_zahn<<endl;

         //        cout<<"----------"<<endl;
         //        kette_zahn="";
         //        if ( tablica[i][j] == '+' || tablica[i][j] == '-'
         //          || tablica[i][j] == '*' || tablica[i][j] == '/' ){
         //            cout << tablica[i][j] <<endl;
         //        }
         //    }
    }
}


int main(int argc, char *argv[]) {
  //beispiel
    //Stapel_nutzen_beispiel();
    //argc_und_argv_arbeiten_beispiel(argc, argv);
  //die Beispiel enden

    // beispiel
    // 4      zahn dem Set
    // erste set
    // 4 elementy
    // 4 + 3 +
    // zwer
    int n, m;
    cout << "ile zbiorow" << endl;
    cin >> n;
    cout << "ile elementow będzie w kazdym zestawie np. 4 + 4 x 4 - to 5 elementow"<< endl;
    cin >> m;
    string ** tablica = new string*[n];
    //deklaracja
    cout << " a teraz po spacjach wpisujemy kolejne elementy dzialania" <<endl;
    for ( int i = 0; i<n; i++){
         tablica[i] = new string[m];
    }

    for (int i = 0; i<n; i++)
    for (int j = 0; j<n; j++)
    cin >> tablica[i][j];

    class Odwrotna_notacja_polska onp;

    for (int i = 0; i<n; i++){
        onp.zaladuj_tablice_symboli(tablica[i], m);
    }
    return 0;
}
