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

const int MAX = 3;
const int MOD = 1e9 + 9;

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
                this->mat[i][j] = mat[i][j];
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

Matrix exp(Matrix mat, long b) {
    if (b == 1) return mat;

    Matrix ans = exp(mat, b >> 1LL);
    ans = ans * ans;

    if (b & 1) ans = ans * mat;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long mat[MAX][MAX] = {
        { 1LL, 1LL, 1LL },
        { 1LL, 0LL, 0LL },
        { 0LL, 1LL, 0LL }
    };

    Matrix T(mat, 3, 3);

    long aux[MAX][MAX] = { {2LL}, {1LL}, {0LL} };
    Matrix first(aux, 3, 1);

    long n;
    while (cin >> n, n--) {
        if (n < 3) cout << aux[3 - n - 1][0] << "\n";
        else {
            Matrix ans = exp(T, n - 2) * first;
            cout << ans.mat[0][0] << "\n";
        }
    }
}