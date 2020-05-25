#include <bits/stdc++.h>

using namespace std;

const int MAX = 55;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        char mtx[MAX][MAX];
        for (int i = 0; i < n; i++)
            scanf("%s", mtx[i]);

        bool possible = true;
        for (int i = 0; i < n - 1 && possible; i++)
            for (int j = 0; j < n - 1 && possible; j++)
                if (mtx[i][j] == '1' && mtx[i + 1][j] == '0' && mtx[i][j + 1] == '0')
                    possible = false;

        printf("%s\n", possible ? "YES" : "NO");
    }
}