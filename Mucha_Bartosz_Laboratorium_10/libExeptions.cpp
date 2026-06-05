#include "libExeptions.h"


void WalidacjaPrawdopodobienstwa(Kolejka litery) {
    float prawdopodobienstwo{0};

    while (!litery.empty()) {
        prawdopodobienstwo += litery.top().first;
        litery.pop();
    }

    if (prawdopodobienstwo !=1) {
        throw Walidacja::Prawdopodobienstwo("Łączne prawdopodobieństwo powinno być równe 1");
    }
}
