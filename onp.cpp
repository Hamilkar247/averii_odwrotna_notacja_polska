
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
#include <cstring>

using namespace std;

#define MAXIMUM 1000

class Stapel {    //stos

    int scheitel; //wierzchołek/top

public:
    string a[MAXIMUM];

    Stapel() { scheitel = -1; }
    bool zustossen(string x); //push/pchać
    string aufziehen(); //pop/ciągnąć
    string aussehen();  //spojrzeć/look
    bool istLeer();
};

bool Stapel::zustossen(string x) //pchać push
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

string Stapel::aufziehen() //ciąnąć pop
{
    if (scheitel < 0) {
        cout << "Stapel Unterlauf"; //
        return 0;
    }
    else {
       string x = a[scheitel--];
       return x;
    }
}

string Stapel::aussehen()  //spojrzec /peek/look
{
    if(scheitel < 0) {
        cout << "Stapel ist Leer";
        return 0;
    }
    else {
        string x = a[scheitel];
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
    stapel.zustossen("10"); //push/pchać
    stapel.zustossen("20");//push/pchać
    stapel.zustossen("30");
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
    string* tafle_string_upn;
    int nummer_tafle_string;
    int anzahl_Elementen;       //liczba/number
    char *elementen[];
    bool elementen_ist_Zahl_nicht_Buchstache(char zahl);
    void zulegen_Zahl_Tafel(int argc , char *argv[]);
    void ordung_fur_upn();
    int komponent_Lange(char argv[]);
};

int Umgekehrte_polnische_notation::komponent_Lange(char argv[]){
    cout <<"zeiche_Lange"<<endl;
    cout << argv << endl;
    int kalkulieren = 1;        //zliczaj/count
    int zahn = 0;
    while ( argv[zahn] != '\0' )
    {
       cout<<argv[zahn]<<endl;
       if (isdigit(argv[zahn]) == false) {
           kalkulieren++;// fur zahn
           kalkulieren++;// fur operator
       }
       zahn++;
    }
    cout<< "die Nummer dem Komponnent " << kalkulieren <<endl;
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
              int komponent = komponent_Lange(argv[i]); //zeichen - znak symbol
              cout<< "zahn lang auf den Worte: " << komponent << endl;
              string* tafle_string = new string[komponent+1];
              int nummer_dem_tafle = 0;
              string kette_zahn = "";
              int zahn=0;
              int nummer_komponent = 0;
              while (komponent  > nummer_komponent){
                 if (isdigit(argv[i][zahn]) == true){
                     kette_zahn.push_back(argv[i][zahn]);
                 }
                 else {
                     tafle_string[nummer_komponent] = kette_zahn;
                     nummer_komponent++;
                     kette_zahn.clear();
                     tafle_string[nummer_komponent].push_back(argv[i][zahn]);
                     nummer_komponent++;
                 }
                 zahn++;
              }

              cout<<"komponent " << komponent <<endl;
              for ( int j = 0; j < komponent; j++){
                  cout <<" "<<tafle_string[j] <<" ";
              }
              cout<<endl;

              //Przypisanie wartości atrybutom
              nummer_tafle_string=komponent;
              tafle_string_upn=tafle_string;
         }
     }
     else {
         cout<< "Gib die Argumenten nicht!" <<endl;
     }
}

bool istNummer(const string& str){
    for (char const &c : str){
        if (isdigit(c) == 0){
            return false;
        }
    }
    return true;
}

void Umgekehrte_polnische_notation::ordung_fur_upn(){
     string* finish_ordung = new string[nummer_tafle_string];
     //tafle_string_upn
     //nummer_tafle_string
     string minus="-";
     string plus="+";
     string mnozenie="*";
     string dzielenie="/";
     int finish_ordung_komponent=0;
     Stapel stapel;
     for( int i = 0; i < nummer_tafle_string ; i++){
         //0 oznacza że stringi są sobie równe)
         if( istNummer(tafle_string_upn[i]) == true ){
              finish_ordung_komponent++;
              finish_ordung[i] == tafle_string_upn[i];
         }
         else {
             if(tafle_string_upn[i].compare(plus) == 0){
                 cout<<"wrzucilem plus na stos"<<endl;
                 stapel.zustossen(tafle_string_upn[i]);
             }
             if(tafle_string_upn[i].compare(plus) == 0){
                 cout<<"wrzucilem plus na stos"<<endl;
                 stapel.zustossen(tafle_string_upn[i]);
             }
             if(tafle_string_upn[i].compare(mnozenie) == 0){
                 cout<<"wrzucilem mnozenie na stos"<<endl;
                 stapel.zustossen(tafle_string_upn[i]);
             }
             if(tafle_string_upn[i].compare(dzielenie) == 0){
                 cout<<"wrzucilem mnozenie na stos"<<endl;
                 stapel.zustossen(tafle_string_upn[i]);
             }
         }
     }
}


int main(int argc, char *argv[]) {
  //beispiel
    //Stapel_nutzen_beispiel();
    //argc_und_argv_arbeiten_beispiel(argc, argv);
  //die Beispiel enden

    class Umgekehrte_polnische_notation upn;
    upn.zulegen_Zahl_Tafel(argc, argv);
    upn.ordung_fur_upn();
    return 0;
}
