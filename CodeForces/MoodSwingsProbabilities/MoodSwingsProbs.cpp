#include <iostream>

#define MODULO 1000000007

#define FOR(i, n) for (int i = 0; i < (n); i++)

struct Matrix
{
    long long mat[2][2];

    Matrix operator*(Matrix other)
    {
        Matrix product = {{{0, 0}, {0, 0}}};
        FOR(i, 2)
        {
            FOR(j, 2)
            {
                FOR(k, 2)
                {
                    product.mat[i][k] += mat[i][j] * other.mat[j][k];
                    product.mat[i][k] %= MODULO;
                }
            }
        }
    }
};

int main()
{
    long long n;
    double p;
    std::cin >> n >> p;

    double res = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            res = (1 - p) * res + p * (1 - res);
        }
        p = 2 * p * (1 - p);
        n /= 2;
    }

    std::cout << res;
    return 0;
}
