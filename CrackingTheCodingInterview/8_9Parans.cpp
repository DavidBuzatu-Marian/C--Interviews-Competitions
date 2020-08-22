#include <iostream>
#include <vector>
#include <string>

void addParans(std::vector<std::string> &res, int leftRem, int rightRem, char *str, int pos)
{
    if (leftRem < 0 || rightRem < leftRem)
    {
        return;
    }

    if (leftRem == 0 && rightRem == 0)
    {
        str[pos] = '\0';
        std::string newStr(str);
        res.push_back(newStr);
    }
    else
    {
        str[pos] = '(';
        addParans(res, leftRem - 1, rightRem, str, pos + 1);
        str[pos] = ')';
        addParans(res, leftRem, rightRem - 1, str, pos + 1);
    }
}

std::vector<std::string> generateParans(int n)
{
    char str[n * 2];
    std::vector<std::string> res;
    addParans(res, n, n, str, 0);
    return res;
}

int main()
{
    std::vector<std::string> result = generateParans(3);
    for (std::string s : result)
    {
        std::cout << s << "\n";
    }
    return 0;
}