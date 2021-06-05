
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

class Umgekehrte_polnische_notation
{
    Stapel stapel;
public:
    Umgekehrte_polnische_notation() { anzahl_Elementen = -1; }
    int anzahl_Elementen;       //liczba/number
    char *elementen[];
    bool elementen_ist_Zahl_nicht_Buchstache(char zahl);
    void zulegen_Zahl_Tafel(int argc , char *argv[]);
    int zeichen_Lange(char argv[]);
};

int Umgekehrte_polnische_notation::zeichen_Lange(char argv[]){
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

bool Umgekehrte_polnische_notation::elementen_ist_Zahl_nicht_Buchstache(char zahl){
    return false;
}

void Umgekehrte_polnische_notation::zulegen_Zahl_Tafel(int argc , char *argv[])
{
     if(argc > 1){
         //vorinkrementierung, also - erste `i` in Schleife 'for' hast zwei
         for ( int i = 1; i < argc; ++i ){
              cout<<i <<": "<<argv[i]<<endl;
              //Wenn Ingress hat Leerzeichen nicht /nie ma spacji
              //Wir brauchen zweite Schleife 'for'
              int zahn = zeichen_Lange(argv[i]); //zeichen - znak symbol
              cout<< "zahn lang auf den Worte: " << zahn << endl;
              //string tafle_string*;
              string kette_zahn = "";
              for ( int j = 0; j <= zahn; ++j){
                  if (isdigit(argv[i][j]) == true){
                      kette_zahn.push_back(argv[i][j]);
                  }
                  else {
                      cout<<kette_zahn<<endl;

                      cout<<"----------"<<endl;
                      kette_zahn="";
                      if ( argv[i][j] == '+' || argv[i][j] == '-'
                        || argv[i][j] == '*' || argv[i][j] == '/' ){
                          cout << argv[i][j] <<endl;
                      }
                  }
             }
         }
     }
     else {
         cout<< "Gib die Argumenten nicht!" <<endl;
     }
}


int main(int argc, char *argv[]) {
  //beispiel
    //Stapel_nutzen_beispiel();
    //argc_und_argv_arbeiten_beispiel(argc, argv);
  //die Beispiel enden

    // beispiel
    // 4      zahn dem Set
    // 4 + 3 + 14 + 20
    // 3 - 3 + 1 + 4
    int n, m;
    cin >> n;
    cin >> m;
    string ** tafle = new string*[n];
    //deklaracja
    for ( int i = 0; i<n; i++){
         tafle[i] = new string[m];
    }

    //
    for (int i = 0; i<n; i++)
    for (int j = 0; j<n; j++)
    cin >> tafle[i][j];

    for (int i = 0; i<n; i++)
    for (int j = 0; j<n; j++)
    cin >> tafle[i][j];

    class Umgekehrte_polnische_notation upn;

//    for (int i = 0; i<n; i++){
//        class Umgekehrte_polnische_notation upn;
//        upn.zulegen_Zahl_Tafel(argc, argv);
//    }
    return 0;
}
