#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 10;
const int MOD = 1e9;

struct Polynomial {
    int deg;
    vector<int> p;

    Polynomial(int deg = 0) {
        this->deg = deg;
        p.assign(deg + 1, 0);
    }

    int& operator [](int index) {
        return p[index];
    }

    Polynomial operator +(Polynomial other) {
        Polynomial ans(max(deg, other.deg));
        for (int i = 0; i <= min(deg, other.deg); i++)
            ans[i] = (p[i] + other[i]) % MOD;

        for (int i = min(deg, other.deg) + 1; i <= max(deg, other.deg); i++)
            ans[i] = i > deg ? other[i] : p[i];

        return ans;
    }

    Polynomial operator *(Polynomial other) {
        Polynomial ans(max(deg, other.deg));
        for (int i = 0; i <= deg; i++)
            for (int j = 0; j <= other.deg && i + j <= max(deg, other.deg); j++)
                ans[i + j] = (ans[i + j] + 1LL * p[i] * other[j]) % MOD;

        return ans;
    }
};

template<typename T>
struct Matrix {
    int rows, cols;
    T m[MAX][MAX];

    Matrix(int rows, int cols): rows(rows), cols(cols) {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                m[i][j] = T();
    }

    Matrix<T> operator *(Matrix<T> &other) {
        Matrix<T> ans(rows, other.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.cols; j++)
                for (int k = 0; k < cols; k++)
                    ans[i][j] = ans[i][j] + m[i][k] * other[k][j];

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    vector<Polynomial> jumps(10, Polynomial(K));
    for (int i = 0; i < M; i++) {
        int d, p;
        cin >> d >> p;
        jumps[d - 1][p]++;
    }

    if (N == 1) cout << "1\n";
    else {
        Matrix<Polynomial> A(10, 10);
        for (int i = 0; i < 10; i++)
            A[0][i] = jumps[i];

        for (int i = 1; i < 10; i++)
            for (int j = 0; j < 10; j++) {
                A[i][j] = Polynomial();
                A[i][j][0] = (j + 1 == i);
            }

        A = exp(A, N - 1);

        int ans = 0;
        for (int i = 0; i <= K; i++)
            ans = (ans + A[0][0][i]) % MOD;

        cout << ans << "\n";
    }
}