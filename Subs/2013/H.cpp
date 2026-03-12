#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 2;
const int MOD = 1e6;

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
    if (n == 1) return A;

    Matrix<T> ans = exp(A, n >> 1LL);
    ans = ans * ans;

    if (!(n & 1LL)) return ans;
    return ans * A;
}

string pad(int x) {
    string ans = "";
    while (x) {
        char c = '0' + (x % 10);
        ans += c;
        x /= 10;
    }

    while ((int) ans.size() < 6)
        ans += '0';

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    llong N, K, L;
    cin >> N >> K >> L;

    Matrix<llong> A(2, 2);
    A[0][0] = K % MOD;
    A[0][1] = L % MOD;
    A[1][0] = 1;

    Matrix<llong> init(2, 1);
    init[0][0] = K % MOD;
    init[1][0] = 1;

    int ans = K % MOD;
    if (N > 5LL) {
        N /= 5LL;
        Matrix<llong> aux = exp(A, N - 1LL) * init;
        ans = aux[0][0];
    }

    cout << pad(ans) << "\n";
}