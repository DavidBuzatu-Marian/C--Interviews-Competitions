#include <iostream>

char  * getStringOfDouble(double n) {
    char result[32]; //32 bits imposed by the problem constraints
    int counter = 0;
    if (n >= 1 || n <= 0) {
        return "ERROR";
    }
    result[counter++] = '.';
    while (n > 0) {
        if (counter == 32) {
            return "ERROR";
        }

        double partRes = n * 2; //get over decimal point;
        std::cout << n << "\n";
        if (partRes >= 1) {
            result[counter++] = '1';
            n = partRes - 1.0;
        }
        else {
            result[counter++] = '0';
            n = partRes;
        }
    }
    return result;
}

int main() {
    std::cout << getStringOfDouble(0.101);
    return 0;
}