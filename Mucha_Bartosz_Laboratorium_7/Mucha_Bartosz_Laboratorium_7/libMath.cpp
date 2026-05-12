#include "libMath.h"

std::vector<int> RozkladNaCzynnikiPierwsze(int n) {
    std::vector<int> czynniki;

    int temp = 2;

    while (n>1) {
        while (n%temp==0) {
            czynniki.push_back(temp);
            n/=temp;
        }
        temp++;
    }

    return czynniki;
}

int m_NWDeuklides(int a, int b) {
    int temp;

    while (b!=0) {
        temp = b;
        b = a%b;
        a = temp;
    }

    return a;
}