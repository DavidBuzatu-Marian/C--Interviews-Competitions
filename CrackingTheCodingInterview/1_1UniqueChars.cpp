#include <iostream>
#include <algorithm>
// consider ascii as the alphabet
int counter[256];

int check_unique_data_structure(std::string input_string)
{
    for (int i = 0; i < input_string.length(); ++i)
    {
        counter[(int)input_string[i]]++;
    }
    for (int i = 0; i < input_string.length(); ++i)
    {
        if (counter[input_string[i]] > 1)
        {
            return 0;
        }
    }

    return 1;
}

int check_unique_bit_vecotr(std::string string)
{
    if (string.length() > 26)
    {
        return 0;
    }
    int mask = 0;
    for (int i = 0; i < string.length(); ++i)
    {
        int value = string[i] - 'a';
        if ((mask & (1 << value)) > 0)
        {
            return 0;
        }
        mask |= (1 << value);
    }
    return 1;
}

int check_unique_no_ds(std::string string)
{
    std::sort(string.begin(), string.end());
    for (int i = 1; i < string.length(); ++i)
    {
        if (string[i] == string[i - 1])
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    std::string input_string;
    std::cin >> input_string;
    // if (check_unique_data_structure(input_string))
    // {
    //     std::cout << "Unique chars";
    // }
    // else
    // {
    //     std::cout << "Not Unique";
    // }
    // if (check_unique_bit_vecotr(input_string))
    // {
    //     std::cout << "Unique chars";
    // }
    // else
    // {
    //     std::cout << "Not Unique";
    // }
    // std::cout << check_unique_no_ds(input_string);
    return 0;
}