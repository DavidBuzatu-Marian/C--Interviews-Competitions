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
    Matrix matrix_fib, matrix_res;
    long long n;

    std::cin >> n;

    matrix_fib.mat[0][0] = 0;
    matrix_fib.mat[0][1] = 1;
    matrix_fib.mat[1][0] = 1;
    matrix_fib.mat[1][1] = 1;

    matrix_res.mat[0][0] = 0;
    matrix_res.mat[0][1] = 1;
    matrix_res.mat[1][0] = 1;
    matrix_res.mat[1][1] = 1;

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            matrix_res = matrix_res * matrix_fib;
        }
        matrix_fib = matrix_fib * matrix_fib;
        n /= 2;
    }

    std::cout << matrix_res.mat[0][0];
    return 0;
}