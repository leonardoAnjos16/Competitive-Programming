#include <bits/stdc++.h>

using namespace std;

const int MAX_M = 15;
const int MAX_N = 105;
const int INF = 1e9;

int m, n, A[MAX_M][MAX_N];
int memo[MAX_M][MAX_N];
bool vis[MAX_M][MAX_N];

int cost(int i, int j) {
    if (j >= n) return 0;

    int &ans = memo[i][j];
    if (vis[i][j]) return ans;

    ans = INF;
    for (int k = -1; k <= 1; k++)
        ans = min(ans, A[i][j] + cost((i + m + k) % m, j + 1));

    vis[i][j] = true;
    return ans;
}

void path(int rows[]) {
    rows[0] = 0;
    for (int i = 1; i < m; i++)
        if (memo[i][0] < memo[rows[0]][0]) rows[0] = i;

    for (int i = 1; i < n; i++) {
        int next_rows[3];
        for (int j = -1; j <= 1; j++)
            next_rows[j + 1] = (rows[i - 1] + m + j) % m;

        sort(next_rows, next_rows + 3);

        rows[i] = next_rows[0];
        for (int j = 1; j < 3; j++)
            if (memo[next_rows[j]][i] < memo[rows[i]][i])
                rows[i] = next_rows[j];
    }
}

int main() {
    while (scanf("%d %d", &m, &n) != EOF) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &A[i][j]);
                vis[i][j] = false;
            }
        }

        int ans = INF;
        for (int i = 0; i < m; i++)
            ans = min(ans, cost(i, 0));

        int rows[MAX_N]; path(rows);
        for (int i = 0; i < n; i++) {
            if (i) printf(" ");
            printf("%d", rows[i] + 1);
        }

        printf("\n%d\n", ans);
    }
}