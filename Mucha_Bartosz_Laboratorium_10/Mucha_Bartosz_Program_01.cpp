#include "Mucha_Bartosz_Program_01.h"

Wezel* budowaDrzewa(Kolejka litery) {
    //Układanie małych drzew w kolejności rosnącej
    std::priority_queue<Wezel*, std::vector<Wezel*>, RosnacoWezly> drzewa;

    //Dopóki mamy z czego brać to dorzucamy nowe liście (od najmniejszego ze względu na konstrukcję tego naszego using Kolejka)
    while (!litery.empty()) {
        auto para = litery.top();
        litery.pop();
        drzewa.push(new Wezel(para.first, para.second));
    }

    //Dopóki są mniejsze drzewa, czyli dopóki nie mamy jednego korzenia całego drzewa
    while (drzewa.size() > 1) {
        //Drzewo o najmniejszej wadze
        Wezel* t1 = drzewa.top();
        drzewa.pop();
        //Drugie drzeo o najmniejszej wadze
        Wezel* t2 = drzewa.top();
        drzewa.pop();

        //\0 to odpowiednik nulla, ale jako znak
        //Tworzenie węzła z dwóch drzew o najmniejszym prawdopodobieństwu
        Wezel* rodzic = new Wezel(t1->waga + t2->waga,'\0' );
        rodzic->lewy = t1;
        rodzic->prawy = t2;
        //wypchnięcie nowego drzewa do kolejki
        drzewa.push(rodzic);
    }

    return drzewa.top();
}

void generowanieKodu(Wezel* wezel, std::string kod) {
if (wezel->lewy == nullptr && wezel->prawy == nullptr) {
    std::cout<<wezel->litera<< " ";
    if (kod.empty())
        std::cout<<"0";
    else
        std::cout<<kod;
    std::cout<<std::endl;
    return;
}

    generowanieKodu(wezel->lewy, kod+"0");
    generowanieKodu(wezel->prawy, kod+"1");
}

void huffman(Kolejka litery) {
    Wezel* korzen = budowaDrzewa(litery);
    generowanieKodu(korzen,"");
    std::cout<<std::endl;
}

int main() {
    try {
        //Z jakiegoś powodu nie chce dać przypisać kolejki jako vector
        std::vector<std::pair<float,char>> temp_a = {
            {12,'A'},
            {7,'B'},
            {18,'I'},
            {10,'M'},
            {9, 'S'},
            {5, 'X'},
            {2,'Z'}
        };
        Kolejka litery_a(temp_a.begin(), temp_a.end());

        std::vector<std::pair<float,char>> temp_b = {
            {0.11,'c'},
            {0.22,'e'},
            {0.16,'i'},
            {0.12,'r'},
            {0.15,'s'},
            {0.10,'t'},
            {0.14,'x'}};
        Kolejka litery_b(temp_b.begin(), temp_b.end());

        WalidacjaPrawdopodobienstwa(litery_b);

        // DEBUG
        show_pq(litery_a);
        show_pq(litery_b);
        std::cout<<std::endl;

        huffman(litery_a);
        huffman(litery_b);


    }
    catch (const std::exception &e) {
        std::cout << e.what() << "\n";
        return -1;
    }

    return 0;
}