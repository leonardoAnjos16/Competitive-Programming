#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

struct Matrix {
    int rows, cols;
    vector<vector<long>> m;

    Matrix(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        m.assign(rows, vector<long>(cols, 0LL));
    }

    Matrix(vector<vector<long>> &m) {
        this->rows = m.size();
        this->cols = m[0].size();

        this->m.assign(rows, vector<long>(cols));
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                this->m[i][j] = m[i][j];
    }

    Matrix operator *(Matrix other) {
        Matrix ans(rows, other.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.cols; j++)
                for (int k = 0; k < cols; k++) {
                    ans.m[i][j] += m[i][k] * other.m[k][j];
                    ans.m[i][j] %= MOD;
                }

        return ans;
    }
};

Matrix exp(Matrix m, long n) {
    if (n == 1) return m;

    Matrix ans = exp(m, n >> 1);
    ans = ans * ans;

    if (!(n & 1)) return ans;
    return ans * m;
}

long to_long(string &s, int m) {
    long ans = 0LL;
    for (int i = 0, n = s.size(); i < n; i++) {
        ans *= 10LL;
        ans += s[i] - '0';
        ans %= m;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<long>> mat = { { 1, 1 }, { 1, 0 } };
    Matrix Tr(mat);

    mat = { { 1 }, { 1 } };
    Matrix A(mat);

    int T; cin >> T;
    while (T--) {
        string n; long m;
        cin >> n >> m;

        long g = __gcd(m, to_long(n, m));
        if (g < 3LL) cout << "1\n";
        else {
            long ans = (exp(Tr, g - 2LL) * A).m[0][0];
            cout << ans << "\n";
        }
    }
}