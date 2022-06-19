#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 2;
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

    Matrix<long> ans = exp(A, n >> 1);
    ans = ans * ans;

    if (!(n & 1)) return ans;
    return ans * A;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int M, N;
        cin >> M >> N;

        if (!N) cout << "0\n";
        else {
            int digits = 0, aux = N;
            while (aux) {
                digits++;
                aux /= 10;
            }

            int K = 1;
            while (digits--)
                K = (K * 10LL) % MOD;

            long b[MAX][MAX] = {
                { K, 1LL },
                { 0LL, 1LL }
            };

            Matrix<long> B(b, 2, 2);

            long a[MAX][MAX] = {
                { 0 }, { N }
            };

            Matrix<long> A(a, 2, 1);

            Matrix<long> ans = exp(B, M) * A;
            cout << ans[0][0] << "\n";
        }
    }
}