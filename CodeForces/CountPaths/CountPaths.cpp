#include <iostream>

#define MODULO 1000000007
#define N 101

#define FOR(i, n) for (int i = 0; i < (n); i++)

struct Matrix
{
    long long mat[N][N];
    Matrix operator*(Matrix other)
    {
        Matrix product{{{}}};
        FOR(i, N)
        {
            FOR(j, N)
            {
                FOR(k, N)
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
    Matrix matrix_aux, matrix_res;
    long long n, m, k, res = 0;
    std::cin >> n >> m >> k;

    FOR(i, N)
    {
        matrix_res.mat[i][i] = 1;
    }

    FOR(i, m)
    {
        long long a, b;
        std::cin >> a >> b;
        matrix_aux.mat[a - 1][b - 1] = 1;
    }

    while (k > 0)
    {
        if (k % 2 == 1)
        {
            matrix_res = matrix_res * matrix_aux;
        }
        matrix_aux = matrix_aux * matrix_aux;
        k /= 2;
    }

    FOR(i, n)
    {
        FOR(j, n)
        {
            if (matrix_res.mat[i][j] != 0)
            {
                res += matrix_res.mat[i][j];
                res %= MODULO;
            }
        }
    }

    std::cout << res;
    return 0;
}