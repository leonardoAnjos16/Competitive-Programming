#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int MAX = 5;
const int MOD = 1e9 + 7;

struct Matrix {
    long mat[MAX][MAX];
    int rows, cols;

    Matrix() {
        rows = cols = MAX;
        memset(mat, 0, sizeof mat);
    }

    Matrix(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        memset(mat, 0, sizeof mat);
    }

    Matrix(long mat[MAX][MAX], int rows, int cols) {
        this->rows = rows;
        this->cols = cols;

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                this->mat[i][j] = mat[i][j] % MOD;
    }

    Matrix operator *(Matrix other) {
        if (cols != other.rows) return Matrix();

        Matrix ans(rows, other.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.cols; j++)
                for (int k = 0; k < cols; k++) {
                    ans.mat[i][j] += mat[i][k] * other.mat[k][j];
                    ans.mat[i][j] %= MOD;
                }

        return ans;
    }
};

Matrix exp(Matrix a, long b) {
    if (b == 1LL) return a;

    Matrix ans = exp(a, b >> 1LL);
    ans = ans * ans;

    if (b & 1LL) ans = ans * a;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long A[MAX][MAX] = { {3}, {2}, {1}, {0}, {1} };
    Matrix first(A, 5, 1);

    int T; cin >> T;
    while (T--) {
        long a, b, c, d, e, N;
        cin >> a >> b >> c >> d >> e >> N;

        long B[MAX][MAX] = {
            { a, b, c, d, e },
            { 1, 0, 0, 0, 0 },
            { 0, 1, 0, 0, 0 },
            { 0, 0, 1, 0, 0 },
            { 0, 0, 0, 0, 1 }
        };

        Matrix transform(B, 5, 5);

        if (--N < 4) cout << A[3 - N][0] << "\n";
        else {
            Matrix ans = exp(transform, N - 3) * first;
            cout << ans.mat[0][0] << "\n";
        }
    }
}