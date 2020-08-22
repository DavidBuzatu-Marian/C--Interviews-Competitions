#include <iostream>
#include <stack>
#include <vector>

class Tower
{
public:
    std::stack<int> t;

    void add(int value)
    {
        if (!t.empty() && t.top() <= value)
        {
            std::cout << "Error placing disk " << value << "\n";
        }
        else
        {
            t.push(value);
        }
    }

    void moveTopTo(Tower &auxT)
    {
        int top = t.top();
        t.pop();
        auxT.add(top);
    }

    void moveDisks(int n, Tower &destination, Tower &buffer)
    {
        if (n > 0)
        {
            moveDisks(n - 1, buffer, destination);
            moveTopTo(destination);
            buffer.moveDisks(n - 1, destination, *this);
        }
    }
};

int main()
{
    int n = 4;
    std::vector<Tower> listT(3);
    for (int i = n - 1; i >= 0; --i)
    {
        listT[0].add(i);
    }
    listT[0].moveDisks(n, listT[1], listT[2]);
    while (!listT[2].t.empty())
    {
        std::cout << listT[2].t.top();
        listT[2].t.pop();
    }
    return 0;
}