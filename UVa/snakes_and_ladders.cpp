#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double

const ldouble EPS = 1e-9;
const int INF = 1e9 + 5;

int sign(ldouble x) {
    return fabsl(x) < EPS ? 0 : (x < 0 ? -1 : 1);
}

int solve(vector<vector<ldouble>> &A, vector<ldouble> &ans) {
    int rows = A.size();
    int cols = A[0].size() - 1;

    int row = 0;
    vector<int> where(cols, -1);

    for (int col = 0; col < cols; col++) {
        int chosen = row;
        while (chosen < rows && !sign(A[chosen][col])) chosen++;
        if (chosen >= rows) continue;

        where[col] = row;
        A[row].swap(A[chosen]);

        for (int i = 0; i < rows; i++)
            if (i != row) {
                ldouble factor = A[i][col] / A[row][col];
                for (int j = col; j <= cols; j++)
                    A[i][j] -= A[row][j] * factor;
            }

        row++;
    }

    bool freedom = false;
    ans.assign(cols, 0.0L);

    for (int i = 0; i < cols; i++) {
        if (where[i] == -1) freedom = true;
        else ans[i] = A[where[i]][cols] / A[where[i]][i];
    }

    for (int i = 0; i < rows; i++) {
        ldouble sum = 0.0L;
        for (int j = 0; j < cols; j++)
            sum += ans[j] * A[i][j];

        if (sign(sum - A[i][cols]))
            return 0;
    }

    return freedom ? INF : 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(4) << fixed;

    int W, H, S;
    while (cin >> W >> H >> S) {
        vector<int> to(W * H);
        iota(to.begin(), to.end(), 0);

        while (S--) {
            int u, v;
            cin >> u >> v;
            to[u - 1] = v - 1;
        }

        vector<vector<ldouble>> P(W * H, vector<ldouble>(W * H, 0.0L));
        for (int i = 0; i + 1 < W * H; i++)
            for (int j = 1; j <= 6; j++) {
                int v = i + j;
                if (v >= W * H)
                    v = W * H - (v - W * H) - 2;

                v = to[v];
                P[i][v] += 1.0L / 6.0L;
            }

        vector<vector<ldouble>> A(W * H, vector<ldouble>(W * H + 1, 0.0L));
        for (int i = 0; i + 1 < W * H; i++) {
            A[i][i] = A[i][W * H] = 1.0L;
            for (int j = 0; j < W * H; j++)
                A[i][j] -= P[i][j];
        }

        A[W * H - 1][W * H - 1] = 1.0L;

        vector<ldouble> E;
        assert(solve(A, E) == 1);

        ldouble ans = E[0];
        cout << ans << "\n";
    }
}