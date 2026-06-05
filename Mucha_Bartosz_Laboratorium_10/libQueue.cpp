#include "libQueue.h"
#include <iostream>

void show_pq(Kolejka pq) {
    while (!pq.empty()){
        std::cout << pq.top().first << " ";
        std::cout << pq.top().second << "\t \t";
        pq.pop();
    }
    std::cout << std::endl;
}
