#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 55;
const int MOD = 1e9 + 7;

template<typename T>
struct Matrix {
    int rows, cols;
    T m[MAX][MAX];

    Matrix(int rows, int cols): rows(rows), cols(cols) {
        memset(m, 0, sizeof m);
    }

    Matrix operator *(Matrix &other) {
        Matrix ans(rows, other.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.cols; j++)
                for (int k = 0; k < cols; k++) {
                    ans[i][j] += m[i][k] * other[k][j];
                    ans[i][j] %= MOD;
                }

        return ans;
    }

    T* operator [](int row) {
        return m[row];
    }
};

template<typename T>
Matrix<T> exp(Matrix<T> &A, llong n) {
    if (n == 1LL) return A;

    Matrix<T> ans = exp(A, n >> 1LL);
    ans = ans * ans;

    if (!(n & 1LL)) return ans;
    return ans * A;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; llong K;
    cin >> N >> K;

    Matrix<llong> a(N, N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> a[i][j];

    Matrix<llong> paths = exp(a, K);

    int ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            ans = (ans + paths[i][j]) % MOD;

    cout << ans << "\n";
}