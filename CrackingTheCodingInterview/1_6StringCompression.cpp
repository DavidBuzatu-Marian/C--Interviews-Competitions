#include <iostream>
#include <math.h>

int get_digits_count(int n)
{
    int digits = 0;
    while (n > 0)
    {
        digits++;
        n /= 10;
    }
    return digits;
}

int get_compressed_len(std::string s)
{
    int len = s.length();
    int comp_len = 0;
    int char_occ = 0;
    for (int i = 0; i < len; ++i)
    {
        ++char_occ;
        if (i + 1 == len || s[i] != s[i + 1])
        {
            comp_len += get_digits_count(char_occ) + 1;
            char_occ = 0;
        }
    }
    return comp_len;
}

char *compress_string(std::string s1)
{
    int compressed_length = get_compressed_len(s1);
    int len = s1.length(), char_occur = 0, counter = 0;
    char *comp_s = (char *)malloc(compressed_length < len ? compressed_length : len);
    if (compressed_length > len)
    {
        for (int i = 0; i < len; ++i)
        {
            comp_s[i] = s1[i];
        }
        return comp_s;
    }
    for (int i = 0; i < len; ++i)
    {
        ++char_occur;
        if (i + 1 == compressed_length || s1[i] != s1[i + 1])
        {
            int nr_digits = get_digits_count(char_occur);
            int p = pow(10, nr_digits - 1);
            comp_s[counter++] = s1[i];
            for (int j = 0; j < nr_digits; ++j)
            {
                comp_s[counter++] = (char_occur / p) % 10 + '0';
            }
            char_occur = 0;
        }
    }
    return comp_s;
}

int main()
{
    std::cout << compress_string("aabcccccaaa");
}