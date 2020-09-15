#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
    int n, m; scanf("%d %d", &n, &m);

    vector<vi> matrix(n, vi(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &matrix[i][j]);

    int ans = 0;
    for (int i = 0; i < m; i++) {
        vi cnt(n, 0);
        for (int j = 0; j < n; j++) {
            int row = --matrix[j][i] / m;
            if (row < n && matrix[j][i] % m == i)
                cnt[(j - row + n) % n]++;
        }

        int min_moves = INT_MAX;
        for (int i = 0; i < n; i++)
            min_moves = min(min_moves, n - cnt[i] + i);

        ans += min_moves;
    }

    printf("%d\n", ans);
}