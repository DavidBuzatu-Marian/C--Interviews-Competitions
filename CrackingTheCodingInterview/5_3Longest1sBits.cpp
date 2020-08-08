#include <iostream>

int longest1sSequence(int n) {
    if (~n == 0) {
        return sizeof(n) * 8; // nr bits
    }
    int curLen = 0;
    int prevLen = 0;
    int maxLen = 1;
    while (n != 0) {
        if ((n & 1) == 1) {
            ++curLen;
        }
        else {
            prevLen = (n & 2) == 0 ? 0 : curLen; // if 2 zeros, reset prevLen
            curLen = 0;
        }
        maxLen = std::max(curLen + prevLen + 1, maxLen);
        n >>= 1;
    }
    return maxLen;
}

int main() {
    std::cout << longest1sSequence(1775);
    return 0;
}