#include <climits>
#include <iostream>
using namespace std;

int *stworzTablice(int rozmiarTablicy){
    //Funkcja tworzaca tablice dynamiczna o rozmiarze podanym w zmiennej
    //Zwraca adres do pierwszego elementu tablicy
    int *tab = nullptr;

    try{
        tab =  new int[rozmiarTablicy];
    }
    catch(const std::bad_alloc){
        cerr << "Bledny zakres tablicy";
        exit(0);
    }
    return tab;
}

int pobierzWartosc(int zakresMinimalny, int zakresMaksymalny){
    //Pobiera wartosc wczytywana z klawiatury z zakredu domknietego od pierwszej zmiennej do dugiej zmiennej
    //Zwraca wartosc ktora miesci sie w podanym przedziale
    int temp=0;
    do{
        cin>>temp;
    }while(temp<zakresMinimalny || temp>zakresMaksymalny);
    return temp;
}

void uzupelnijTablice(int iloscWartosci, int *tablica){
	//Pobiera wiele wartosci, ilosc podana w pierwszej zmiennej, a nastepnie zapisuje je do tablicy podanej w drugiej zmiennej o rozmiarze ilosci tych wartosci
    for (int i=0;i<iloscWartosci;i++) {
        tablica[i] = pobierzWartosc(-200,200);
    }
}

void wypiszTablice(int iloscWartosci, int *tablica) {
    //Wypisuje zawartość dynamicznej tablicy jednowymiarowej o określonej wartości elementów
    for (int i=0;i<iloscWartosci;i++) {
        cout << tablica[i] << endl;
    }
}

void maksymalnaPodtablica(int iloscWartosci, int *tablica) {
    //Wypisuje początek i koniec maksymalnej podtablicy o największej sumie w myśl zasady suma (i,j) = 3*DODATNIA + 2*UJEMNA, a następnie podaje tą sumę
    int max_suma = 0;
    int aktualna_suma = 0;
    int poczatek=0,koniec=0;

    for (int i=0;i<iloscWartosci;i++) {
        //suma (i,j) = 3*DODATNIA + 2*UJEMNA
        if (tablica[i] > 0) {
            aktualna_suma += 3 * tablica[i];
        }
        else {
            aktualna_suma += 2 * tablica[i];
        }

        if (aktualna_suma > max_suma) {
            max_suma = aktualna_suma;
            koniec = i;
        }

        //Przesuwanie wskaźnika startu gdy suma będzie zbyt mała
        if (aktualna_suma < 0) {
            aktualna_suma = 0;
            poczatek=i+1;
        }


    }
    cout<<poczatek<<" "<<koniec<<" "<<max_suma<<endl;
}





int main() {
    int liczbaZestawow;
    liczbaZestawow = pobierzWartosc(1,INT_MAX);

    int rozmiarTablicy;
    rozmiarTablicy=pobierzWartosc(1,1000000);

    int *dane = nullptr;
    dane = stworzTablice(rozmiarTablicy);

    uzupelnijTablice(rozmiarTablicy,dane);

    // wypiszTablice(rozmiarTablicy,dane);

    maksymalnaPodtablica(rozmiarTablicy,dane);

    delete[] dane;

    return 0;
}