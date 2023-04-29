#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 105;
const int MOD = 1e9 + 7;

template<typename T>
struct Matrix {
    int rows, cols;
    T m[MAX][MAX];

    Matrix(int rows, int cols): rows(rows), cols(cols) {
        memset(m, 0, sizeof m);
    }

    Matrix(T m[MAX][MAX], int rows, int cols): rows(rows), cols(cols) {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                this->m[i][j] = m[i][j];
    }

    Matrix operator *(Matrix &other) {
        Matrix ans(rows, other.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.cols; j++)
                for (int k = 0; k < cols; k++) {
                    ans.m[i][j] += m[i][k] * other.m[k][j];
                    ans.m[i][j] %= MOD;
                }

        return ans;
    }

    T* operator [](int row) {
        return m[row];
    }
};

template<typename T>
Matrix<T> exp(Matrix<T> &A, int n) {
    if (n == 1) return A;

    Matrix<T> ans = exp(A, n >> 1);
    ans = ans * ans;

    if (!(n & 1)) return ans;
    return ans * A;
}

int exp(int a, int n) {
    if (!n) return 1;

    int ans = exp(a, n >> 1);
    ans = (1LL * ans * ans) % MOD;

    if (!(n & 1)) return ans;
    return (1LL * ans * a) % MOD;
}

int mod_mult_inv(int n, int m) {
    return exp(n, m - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    llong a[MAX][MAX] = {0LL};
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
            a[i][j] = (1LL * a[i][j] * mod_mult_inv(1000000, MOD)) % MOD;
        }

    Matrix<llong> A(a, N, N);
    Matrix<llong> P = exp(A, K);

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int aux = ((i + 1LL) * P[0][i]) % MOD;
        ans = (ans + aux) % MOD;
    }

    cout << ans << "\n";
}