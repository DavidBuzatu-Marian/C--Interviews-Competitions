#include <iostream>

int get_bit_vector(std::string string)
{
    int result = 0;
    for (char c : string)
    {
        if (c >= 'A' && c <= 'Z')
        {
            c += 32;
        }
        int value = c - 'a';
        if (value >= 0)
        {
            result ^= (1 << value);
        }
    }
    return result;
}

bool check_contains_one(int bit_vector)
{

    return (bit_vector & (bit_vector - 1)) == 0;
}

bool check_string(std::string string)
{
    int bit_vector = get_bit_vector(string);
    return bit_vector == 0 || check_contains_one(bit_vector);
}

int main()
{
    std::string res = check_string("Tact Coa") == true ? "true" : "false";
    std::cout << res;
    return 0;
}