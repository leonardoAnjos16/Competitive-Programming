#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int n; scanf("%d", &n);

    char cake[MAX][MAX];
    for (int i = 0; i < n; i++)
        scanf("%s", cake[i]);

    int row[MAX] = {0}, col[MAX] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cake[i][j] == 'C') {
                row[i]++;
                col[j]++;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += row[i] * (row[i] - 1) / 2;
        ans += col[i] * (col[i] - 1) / 2;
    }

    printf("%d\n", ans);
}