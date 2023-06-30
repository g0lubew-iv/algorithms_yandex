#include <iostream>
#include <vector>

using mat2 = std::vector<std::vector<int>>;

// Binet's formula:

// const double phi = (1. + std::sqrt(5)) / 2.;
// std::cout << static_cast<int>((std::pow(phi, n) - std::pow(-phi, -n)) / (2 * phi - 1));

// or... Matrices:

/*  |   F_n   |   |0   1| ^ n   |F_0|
 *  |         | = |     |     * |   |
 *  | F_{n+1} |   |1   1|       |F_1|
 */

// O(2*log(n))
int exp(int x, int n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        return exp(x, n / 2) * exp(x, n / 2);
    }
    return exp(x, (n - 1) / 2) * exp(x, (n - 1) / 2) * x;
}

mat2 mul(const mat2 &A, const mat2 &B, int m) {
    mat2 C = A;

    C[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % m;
    C[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % m;
    C[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % m;
    C[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % m;

    for (int i = 0; i < A[0].size(); i++) {
        for (int j = 0; j < A.size(); j++) {
            std::cout << C[i][j] << " ";
        }
        std::cout << "\n";
    }

    return C;
}

mat2 exp_m(const mat2 &D, int n, int m) {
    if (n == 0) {
        return {{1, 0},
                {0, 1}};
    }
    if (n % 2 == 0) {
        return mul(exp_m(D, n / 2, m), exp_m(D, n / 2, m), m);
    }
    return mul(mul(exp_m(D, (n - 1) / 2, m), exp_m(D, (n - 1) / 2, m), m), D, m);
}

int main() {
    int n;
    std::cin >> n;
    mat2 S = {{1, 0},
              {0, 1}};

    std::cout << exp_m(S, n, 10)[0][1];
    return 0;
}