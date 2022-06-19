#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 3;
const int MOD = 1e9 + 7;

template<typename T = long>
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

Matrix<long> exp(Matrix<long> &A, int n) {
    if (n == 1) return A;

    Matrix ans = exp(A, n >> 1);
    ans = ans * ans;

    if (!(n & 1)) return ans;
    return ans * A;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long b[MAX][MAX] = {
        { 1LL, 2LL, 3LL },
        { 4LL, 5LL, 6LL },
        { 7LL, 8LL, 9LL },
    };

    Matrix<long> B(b, 3, 3);

    long a[MAX][MAX] = {
        { 1LL }, { 1LL }, { 1LL }
    };

    Matrix<long> A(a, 3, 1);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;

        if (n == 1) cout << "3\n";
        else {
            Matrix flowers = exp(B, n - 1) * A;

            int ans = (flowers[0][0] + flowers[1][0]) % MOD;
            ans = (ans + flowers[2][0]) % MOD;
            cout << ans << "\n";
        }
    }
}