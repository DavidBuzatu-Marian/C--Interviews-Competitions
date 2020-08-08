#include <iostream>

int nrBitsSwapped(int A, int B) {
    int C = A ^ B;
    int counter = 0;
    while (C != 0) {
        ++counter;
        C = (C & (C - 1)); // flip least significant bit of 1
    }
    return counter;
}


int main() {
    std::cout << nrBitsSwapped(6, 10);
}