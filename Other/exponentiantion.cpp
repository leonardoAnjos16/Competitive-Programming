#include <bits/stdc++.h>

using namespace std;

#define llong unsigned __int128

const int MAX = 2;

istream& operator >>(istream &cin, llong &x) {
    string sx;
    cin >> sx;

    x = 0;
    for (char c: sx) {
        x *= 10;
        x += c - '0';
    }

    return cin;
}

ostream& operator <<(ostream &cout, llong x) {
    if (!x) {
        cout << "0";
        return cout;
    }

    string sx = "";
    while (x) {
        int d = x % 10;
        char c = '0' + d;
        sx += c;
        x /= 10;
    }

    reverse(sx.begin(), sx.end());

    cout << sx;
    return cout;
}

template<typename T>
struct Matrix {
    int rows, cols;
    T m[MAX][MAX], mod;

    Matrix(int rows, int cols, T mod): rows(rows), cols(cols), mod(mod) {
        memset(m, 0, sizeof m);
    }

    Matrix operator *(Matrix &other) {
        Matrix ans(rows, other.cols, mod);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.cols; j++)
                for (int k = 0; k < cols; k++) {
                    ans[i][j] += m[i][k] * other[k][j];
                    ans[i][j] %= mod;
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

    Matrix<T> ans = exp(A, n >> 1);
    ans = ans * ans;

    if (!(n & 1)) return ans;
    return ans * A;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    llong a, b, m;
    cin >> a >> b >> m;

    Matrix<llong> T(2, 2, m);
    T[0][0] = a % m;
    T[0][1] = m - 1;
    T[1][0] = 1 % m;

    Matrix<llong> A(2, 1, m);
    A[0][0] = a % m;
    A[1][0] = 2 % m;

    if (b == 0) cout << (2 % m) << "\n";
    else if (b == 1) cout << (a % m) << "\n";
    else {
        llong ans = (exp(T, b - 1) * A)[0][0];
        cout << ans << "\n";
    }
}