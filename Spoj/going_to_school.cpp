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
        for (int i = row + 1; i < rows; i++)
            if (fabsl(A[i][col]) > fabsl(A[chosen][col]))
                chosen = i;

        if (!sign(A[chosen][col])) continue;

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

    cout << setprecision(5) << fixed;

    int T; cin >> T;
    while (T--) {
        int N, st, en;
        cin >> N >> st >> en;

        vector<int> sum(N, 0);
        vector<vector<pair<int, int>>> tree(N, vector<pair<int, int>>());

        for (int i = 1; i < N; i++) {
            int u, v, c;
            cin >> u >> v >> c;

            sum[u - 1] += c;
            sum[v - 1] += c;
            tree[u - 1].emplace_back(v - 1, c);
            tree[v - 1].emplace_back(u - 1, c);
        }

        vector<vector<ldouble>> A(N, vector<ldouble>(N + 1, 0.0L));
        for (int i = 0; i < N; i++)
            if (i != en - 1) {
                A[i][i] = A[i][N] = 1.0L;
                for (auto [v, c]: tree[i])
                    A[i][v] = -1.0L * c / sum[i];
            }

        A[en - 1][en - 1] = 1.0L;

        vector<ldouble> ans;
        assert(solve(A, ans) == 1);
        cout << ans[st - 1] << "\n";
    }
}