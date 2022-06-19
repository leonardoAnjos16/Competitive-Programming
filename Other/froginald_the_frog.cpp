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
};

Matrix<long> exp(Matrix<long> &a, int n) {
    if (n == 1) return a;

    Matrix ans = exp(a, n >> 1);
    ans = ans * ans;

    if (!(n & 1)) return ans;
    return ans * a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long a[MAX][MAX] = {
        { 1LL, 1LL },
        { 1LL, 0LL }
    };

    Matrix A(a, 2, 2);

    int N, M;
    cin >> N >> M;

    vector<int> holes(M + 1, -1);
    for (int i = 1; i <= M; i++)
        cin >> holes[i];

    holes.push_back(N + 1);
    sort(holes.begin(), holes.end());
    
    long init[MAX][MAX] = {{ 1LL }, { 0LL }};
    Matrix ans(init, 2, 1);

    bool zero = false;
    for (int i = 0; i <= M && !zero; i++) {
        int dist = holes[i + 1] - holes[i] - 1;
        if (!dist) zero = true;
        else if (dist > 1) {
            ans = exp(A, dist - 1) * ans;
            ans.m[1][0] = 0;
        }
    }

    if (zero) cout << "0\n";
    else cout << ans.m[0][0] << "\n";
}