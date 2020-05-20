#include <bits/stdc++.h>

using namespace std;

const int MAX = 15;

int n;
char grid[MAX][MAX];

bool check(char letter, int i, int j) {
    if (i > 0 && grid[i - 1][j] == letter) return false;
    if (j > 0 && grid[i][j - 1] == letter) return false;
    if (i < n - 1 && grid[i + 1][j] == letter) return false;
    if (j < n - 1 && grid[i][j + 1] == letter) return false;
    return true;
}

int main() {
    int t; scanf("%d", &t);
    int case_num = 1;

    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%s", grid[i]);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (char c = 'A'; c <= 'Z' && grid[i][j] == '.'; c++)
                    if (check(c, i, j)) grid[i][j] = c;

        printf("Case %d:\n", case_num++);
        for (int i = 0; i < n; i++)
            printf("%s\n", grid[i]);
    }
}