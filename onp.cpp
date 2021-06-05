
// 1.Program prosi o wprowadzenie wyrażenia składającego się z cyfr od 0 do 9
// oraz znaków +-*/ z zwykłej notacji
// 2.Program wczytuje wprowadzone przez użytkownika wyrażenie.
// 3.Program konwertuje wyrażenie na ONP.
// 4.Program oblicza wynik wyrażenia z wykorzystaniem stosu
// i wyświetla wynik.

#include <iostream>
#include <bits/stdc++.h>

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
private:
    Stapel stapel;
public:
};

int main(int argc, char *argv[]) {
  //beispiel
    //Stapel_nutzen_beispiel();
    //argc_und_argv_arbeiten_beispiel(argc, argv);
  //die Beispiel enden

    class Umgekehrte_polnische_notation upn;

    return 0;
}
