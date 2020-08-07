#include <iostream>

int getBit(int M, int pos) {
    return (M & (1 << pos));
}

void setBit(int &N, int bit, int pos) {
    int mask = bit << pos;
    N |= mask;
}

void resetBit(int &N, int pos) {
    int mask = ~(1 << pos);
    N &= mask;
}

int insertion(int N, int M, int i, int j) {
    int pos = i;
    while (pos <= j) {
        resetBit(N, pos);
        unsigned bit = getBit(M, pos - i);
        setBit(N, bit, i);
        ++pos;
    }
    return N;
}




int main() {
    std::cout << insertion(1024, 19, 2, 6);
    return 0;
}