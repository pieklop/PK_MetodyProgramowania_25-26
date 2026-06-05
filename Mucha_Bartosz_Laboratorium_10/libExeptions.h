#ifndef LIBEXEPTIONS_H
#define LIBEXEPTIONS_H
#include "libQueue.h"
#include<stdexcept>


namespace Walidacja {
    class Prawdopodobienstwo : public std::invalid_argument {
        public:
            Prawdopodobienstwo() : std::invalid_argument("Łączne prawdopodobieństwo powinno być równe 1") {}
            Prawdopodobienstwo(std::string msg) : std::invalid_argument(msg.c_str()) {}
    };
}

/*
 * Sprawdza czy łączne prawdopodobieństwo jest poprawne (równe 1)
 * @param litery - vektor par z przypisanymi literami i ich prawdopodobieństwem
 */
void WalidacjaPrawdopodobienstwa(Kolejka litery);

#endif //LIBEXEPTIONS_H