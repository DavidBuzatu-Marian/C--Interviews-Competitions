#include <iostream>
#include <algorithm>
int counter[128];
int permutation(std::string s, std::string t)
{

    if (s.length() != t.length())
    {
        return 0;
    }

    for (char c : s)
    {
        counter[c]++;
    }
    for (char c : t)
    {
        counter[c]--;
        if (counter[c] < 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    std::cout << permutation("abcdefg", "fdeabsc");
}