#ifndef LIBQUEUE_H
#define LIBQUEUE_H
#include <queue>

struct Rosnaco {
    bool operator()(std::pair<float,char>&a, std::pair<float,char>&b) {
        return a.first > b.first;
    }
};

//Tworzy kolejkę która porównuje parę elementów kolejki korzystając z przeładowania operatora w strukturze 'Rosnaco'
using Kolejka = std::priority_queue<std::pair<float, char>, std::vector<std::pair<float, char>>, Rosnaco>;

/*
 * Funkcja służy do wyświetlenia kolejki priorytetowej
 * @param pq - kolejka priorytetowa do wyświetlenia
 */
void show_pq(Kolejka pq);

#endif //LIBQUEUE_H