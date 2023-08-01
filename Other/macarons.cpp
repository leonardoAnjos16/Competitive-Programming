#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 260;
const int MOD = 1e9;

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
void fill(int n, Matrix<T> &A, int curr_mask, int i = 0, int next_mask = 0) {
    if (i >= n) A[curr_mask][next_mask]++;
    else if (curr_mask & (1 << i)) fill(n, A, curr_mask, i + 1, next_mask);
    else {
        fill(n, A, curr_mask, i + 1, next_mask);
        fill(n, A, curr_mask, i + 1, next_mask ^ (1 << i));

        if (i + 1 < n && !(curr_mask & (1 << (i + 1))))
            fill(n, A, curr_mask, i + 2, next_mask);
    }
}

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

    int N; llong M;
    cin >> N >> M;

    Matrix<llong> A(1 << N, 1 << N);
    for (int i = 0; i < (1 << N); i++)
        fill(N, A, i);

    int ans = exp(A, M)[0][0];
    cout << ans << "\n";
}