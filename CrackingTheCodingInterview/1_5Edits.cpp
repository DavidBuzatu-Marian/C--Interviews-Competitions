#include <iostream>
bool isOneAway(std::string string1, std::string string2)
{
    int l1 = string1.length();
    int l2 = string2.length();

    if (abs(l1 - l2) > 1)
    {
        return false;
    }

    std::string s1 = l1 < l2 ? string1 : string2;
    std::string s2 = l1 < l2 ? string2 : string1;

    int i = 0, j = 0, found_diff = 0;
    while (i < l1 && j < l2)
    {
        if (s1[i] != s2[j])
        {
            if (!found_diff)
            {
                found_diff = 1;
            }
            else
            {
                return false;
            }
            if (l1 == l2)
            {
                i++; // increase shorter string because we add something
            }
        }
        else
        {
            i++;
        }
        j++;
    }

    return true;
}

int main()
{
    std::cout << isOneAway("pale", "ple") << "\n";
    std::cout << isOneAway("pales", "pale") << "\n";
    std::cout << isOneAway("pale", "bale") << "\n";
    std::cout << isOneAway("pale", "bake") << "\n";

    return 0;
}