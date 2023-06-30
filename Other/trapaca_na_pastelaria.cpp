#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int SQRT = 350;

struct Set {
private:
    int n;
    vector<int> cnt;
    vector<int> blocks;

public:
    Set(int n) {
        this->n = n;
        cnt.assign(n, 0);
        blocks.assign((n + SQRT - 1) / SQRT, 0);
    }

    void add(int i, int v) {
        if (cnt[i]) blocks[i / SQRT]--;

        cnt[i] += v;
        if (cnt[i]) blocks[i / SQRT]++;
    }

    int mex() {
        for (int i = 0; i < (n + SQRT - 1) / SQRT; i++) {
            int nxt = (i + 1) * SQRT;
            int sz = min(nxt, n) - i * SQRT;

            if (blocks[i] < sz) {
                int idx = i * SQRT;
                while (idx < n && idx < nxt && cnt[idx]) idx++;

                assert(idx < n && idx < nxt);
                return idx;
            }
        }

        return n;
    }
};

void get_grundy(int N, int M, vector<string> &board, vector<vector<int>> &grundy) {
    Set solver(N + M);
    for (int row = N - 1; row >= 0; row--) {
        int col = M - 1;
        while (col >= 0) {
            while (col >= 0 && board[row][col] == 'x') col--;

            while (col >= 0 && board[row][col] == '.') {
                for (int i = row + 1; i < N && board[i][col] == '.'; i++)
                    solver.add(grundy[i][col], 1);

                grundy[row][col] = solver.mex();
                solver.add(grundy[row][col], 1);

                for (int i = row + 1; i < N && board[i][col] == '.'; i++)
                    solver.add(grundy[i][col], -1);

                col--;
            }

            for (int i = col + 1; i < M && board[row][i] == '.'; i++)
                solver.add(grundy[row][i], -1);
        }
    }
}

template<const char op, class T>
vector<T> FWHT(vector<T> a, const bool inv = false) {
    int n = a.size();
    for (int len = 1; len < n; len += len)
        for (int i = 0; i < n; i += 2 * len)
            for (int j = 0; j < len; j++) {
                T u = a[i + j], v = a[i + j + len];
                if (op == '^') {
                    a[i + j] = u + v;
                    a[i + j + len] = u - v;
                } else if (op == '|') {
                    if (!inv) a[i + j + len] += a[i + j];
                    else a[i + j + len] -= a[i + j];
                } else if (op == '&') {
                    if (!inv) a[i + j] += a[i + j + len];
                    else a[i + j] -= a[i + j + len];
                }
            }

    if (op == '^' && inv)
        for (int i = 0; i < n; i++)
            a[i] = a[i] / n;

    return a;
}

int next_power_of_two(int n) {
    int bits = 0;
    while (n) {
        bits++;
        n >>= 1;
    }

    return 1 << (bits + 1);
}

template<const char op, typename T>
vector<T> bitwise_convolution(vector<T> a, vector<T> b) {
    int na = a.size(), nb = b.size();
    int sz = next_power_of_two(na + nb);

    a.resize(sz, 0);
    b.resize(sz, 0);

    a = FWHT<op, T>(a);
    b = FWHT<op, T>(b);

    vector<T> c(sz, 0);
    for (int i = 0; i < sz; i++)
        c[i] = a[i] * b[i];

    return FWHT<op, T>(c, true);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N[3], M[3];
    vector<string> board[3];
    vector<vector<int>> grundy[3];

    for (int i = 0; i < 3; i++) {
        cin >> N[i] >> M[i];

        board[i].assign(min(N[i], M[i]), string(max(N[i], M[i]), '-'));
        for (int j = 0; j < N[i]; j++)
            for (int k = 0; k < M[i]; k++) {
                if (N[i] < M[i]) cin >> board[i][j][k];
                else cin >> board[i][k][j];
            }

        if (N[i] > M[i]) swap(N[i], M[i]);

        grundy[i].assign(N[i], vector<int>(M[i], -1));
        get_grundy(N[i], M[i], board[i], grundy[i]);

        for (int j = 0; j < N[i]; j++)
            for (int k = 0; k < M[i]; k++)
                assert(grundy[i][j][k] < N[i] + M[i]);
    }

    vector<llong> coeffs[3];
    for (int i = 0; i < 3; i++) {
        coeffs[i].assign(N[i] + M[i], 0);
        for (int j = 0; j < N[i] && board[i][j][0] == '.'; j++)
            coeffs[i][grundy[i][j][0]]++;

        for (int j = 1; j < M[i] && board[i][0][j] == '.'; j++)
            coeffs[i][grundy[i][0][j]]++;
    }

    llong ans = 0LL;
    vector<llong> conv = bitwise_convolution<'^', llong>(coeffs[0], coeffs[1]);

    for (int i = 0; i < N[2] + M[2] && i < (int) conv.size(); i++)
        ans += coeffs[2][i] * conv[i];

    cout << ans << "\n";
}