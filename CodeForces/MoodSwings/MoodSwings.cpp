#include <iostream>

#define MODULO 1000000007

#define FOR(i, n) for (int i = 0; i < (n); i++)

struct Matrix
{
    long long mat[2][2];
    Matrix operator*(Matrix other)
    {
        Matrix product{{{0, 0}, {0, 0}}};
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
        return product;
    }
};

int main()
{
    long long n;
    Matrix matrix_aux{{{19, 7}, {6, 20}}}, matrix_res{{{1, 0}, {0, 1}}};

    std::cin >> n;

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            matrix_res = matrix_res * matrix_aux;
        }
        matrix_aux = matrix_aux * matrix_aux;
        n /= 2;
    }

    std::cout << matrix_res.mat[0][0];

    return 0;
}