#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int n, m, r, c;
    while (scanf("%d %d %d %d", &n, &m, &r, &c), n | m | r | c) {
        char curr[MAX][MAX];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                curr[i][j] = '0';

        char goal[MAX][MAX];
        for (int i = 0; i < n; i++)
            scanf("%s", goal[i]);

        int ans = 0;
        for (int i = 0; i < n - r + 1; i++) {
            for (int j = 0; j < m - c + 1; j++) {
                if (curr[i][j] != goal[i][j]) {
                    ans++;
                    for (int k = 0; k < r; k++)
                        for (int l = 0; l < c; l++)
                            curr[i + k][j + l] = curr[i + k][j + l] == '0' ? '1' : '0';
                }
            }
        }
        
        for (int i = 0; i < n && ans >= 0; i++)
            for (int j = 0; j < m && ans >= 0; j++)
                if (curr[i][j] != goal[i][j]) ans = -1;

        printf("%d\n", ans);
    }
}