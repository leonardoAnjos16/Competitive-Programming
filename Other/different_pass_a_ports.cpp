#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 105;
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

    int N, M, K;
    cin >> N >> M >> K;

    long g[MAX][MAX] = {0LL};
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;

        g[A - 1][B - 1]++;
        g[B - 1][A - 1]++;
    }

    Matrix G(g, N, N);
    Matrix cnt = exp(G, K);

    int ans = 0;
    for (int i = 0; i < N; i++)
        ans = (ans + cnt[0][i]) % MOD;

    cout << ans << "\n";
}