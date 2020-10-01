#include <iostream>

using namespace std;

void reverse(char *s)
{
    char *end = s;
    char tmp;
    if (s)
    {
        while (*(++end))
            ;

        --end; //ignore last char;
        while (s < end)
        {
            tmp = *s;
            *s++ = *end;
            *end-- = tmp;
        }
    }
}

int main()
{
    char stringTest[20];
    cin >> stringTest;
    reverse(stringTest);
    cout << stringTest;
    return 0;
}