#include<iostream>
#include<climits>
using namespace std;

int maksymalnaPodtablica(int iloscWartosci, int *tablica) {
    //Zmodyfikowana funkcja z poprzedniego zadania, tym razem nie mnoży wartości, a tylko sumuje
    int max_suma = 0;
    int aktualna_suma = 0;

    for (int i=0;i<iloscWartosci;i++) {
        aktualna_suma += tablica[i];


        if (aktualna_suma > max_suma) {
            max_suma = aktualna_suma;
        }

        if (aktualna_suma < 0) {
            aktualna_suma = 0;
        }
    }
    return max_suma;
}

int **stworzTabliceDwuwymiarowa(int iloscWierszy, int iloscKolumn){
    //Funkcja tworzaca dwuwymiarowa tablice dynamiczna o ilosci wierszy podanych w pierwszej zmiennej oraz ilości kolumn podanych w drugiej zmiennej
    //Zwraca adres do pierwszego elementu tablicy
    int **tab = nullptr;
    try{
        tab =  new int*[iloscWierszy];
        for (int i = 0; i < iloscWierszy; i++) {
            tab[i] = new int[iloscKolumn]();
        }
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

void uzupelnijTabliceDwuwymiarowa(int iloscWierszy, int iloscKolumn, int **tablica){
    //Pobiera wiele wartosci, ilosc podana w pierwszej zmiennej, a nastepnie zapisuje je do tablicy podanej w drugiej zmiennej o rozmiarze ilosci tych wartosci
    for (int i=0;i<iloscWierszy;i++) {
        for (int j=0;j<iloscKolumn;j++) {
            tablica[i][j] = pobierzWartosc(-32768, 32768);
        }
    }
}

void wypiszTabliceDwuwymiarowa(int iloscWierszy, int iloscKolumn, int **tablica) {
    //Funkcja wypisuje tablicę dwuwymiarową dla określonej liczby wierszy
    for (int i=0;i<iloscWierszy;i++) {
        for (int j=0;j<iloscKolumn;j++) {
            cout<<tablica[i][j]<<" ";
        }
        cout<<endl;
    }

}

void usunTabliceDwuwymiarowa(int iloscWierszy, int** tablica) {
    //Funkcja usuwa tablicę dwuwymiarową dla określonej liczby wierszy
    if (tablica!=nullptr) {
        for (int i=0;i<iloscWierszy;i++) {
            delete[] tablica[i];
        }
        delete[] tablica;
    }
}

int maksymalnaPodtablicaDwuwymiarowa(int iloscWierszy, int iloscKolumn, int **tablica) {
    //Funkcja wyszukuje 'macierz' o największej sumie elementów
    int maksymalna_suma=0;
    int* temp = new int[iloscWierszy];

    for (int i = 0; i < iloscKolumn; ++i) {
        for (int k = 0; k < iloscWierszy; ++k) temp[k] = 0;

        for (int j = i; j < iloscKolumn; ++j) {
            for (int k = 0; k < iloscWierszy; ++k) {
                temp[k] += tablica[k][j];
            }
            int aktualna_suma = maksymalnaPodtablica(iloscWierszy,temp);
            if (aktualna_suma > maksymalna_suma) maksymalna_suma = aktualna_suma;
        }
    }

    delete[] temp;
    return maksymalna_suma;
}

int main() {
    int liczbaZestawow;
    liczbaZestawow = pobierzWartosc(1,INT_MAX);



    for (int i=0;i<liczbaZestawow;i++) {
        int **dane = nullptr;
        int iloscWierszy, iloscKolumn;
        iloscWierszy=pobierzWartosc(1,100);
        iloscKolumn=pobierzWartosc(1,100);

        dane = stworzTabliceDwuwymiarowa(iloscWierszy,iloscKolumn);

        uzupelnijTabliceDwuwymiarowa(iloscWierszy,iloscKolumn,dane);

        wypiszTabliceDwuwymiarowa(iloscWierszy,iloscKolumn,dane);

        cout<<maksymalnaPodtablicaDwuwymiarowa(iloscWierszy,iloscKolumn,dane);

        usunTabliceDwuwymiarowa(iloscWierszy,dane);
    }
    return 0;
}