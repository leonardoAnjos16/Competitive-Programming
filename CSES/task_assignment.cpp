#include <bits/stdc++.h>

using namespace std;

const int INF = 1e6 + 5;

/* 
 * n <= m
 * O(n^2 * m)
 * C is 0-based
 */
template<typename T>
T min_cost_assignment(int n, int m, vector<vector<T>> &C, vector<int> &assignment) {
    vector<T> u(n + 1), v(m + 1);
    vector<int> p(m + 1), way(m + 1);

    for (int i = 1; i <= n; i++) {
        p[0] = i;
        int j0 = 0;

        vector<T> minv(m + 1, INF);
        vector<bool> used(m + 1, false);

        do {
            used[j0] = true;

            T delta = INF;
            int i0 = p[j0], j1;

            for (int j = 1; j <= m; j++)
                if (!used[j]) {
                    T curr = C[i0 - 1][j - 1] - u[i0] - v[j];
                    if (curr < minv[j]) minv[j] = curr, way[j] = j0;
                    if (minv[j] < delta) delta = minv[j], j1 = j;
                }

            for (int j = 0; j <= m; j++) {
                if (!used[j]) minv[j] -= delta;
                else u[p[j]] += delta, v[j] -= delta;
            }

            j0 = j1;
        } while (p[j0]);

        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }

    assignment.resize(n);
    for (int i = 1; i <= m; i++) {
        if (!p[i]) continue;
        assignment[p[i] - 1] = i - 1;
    }

    return -v[0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> c[i][j];

    vector<int> assignment;
    int cost = min_cost_assignment(n, n, c, assignment);

    cout << cost << "\n";
    for (int i = 0; i < n; i++)
        cout << (i + 1) << " " << (assignment[i] + 1) << "\n";
}