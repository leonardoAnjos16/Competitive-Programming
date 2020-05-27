#include <bits/stdc++.h>

using namespace std;

const int MAX = 15;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, m; scanf("%d %d", &n, &m);

        char a[MAX][MAX];
        for (int i = 0; i < n; i++)
            scanf("%s", a[i]);

        bool possible = false;
        for (int i = 0; i < m && !possible; i++) {
            char aux = a[0][i];
            for (char c = 'a'; c <= 'z' && !possible; c++) {
                a[0][i] = c;
                possible = true;

                for (int j = 1; j < n && possible; j++) {
                    int cnt = 0;
                    for (int k = 0; k < m; k++)
                        if (a[j][k] != a[0][k]) cnt++;

                    possible = cnt <= 1;
                }
            }

            if (!possible) a[0][i] = aux;
        }

        if (!possible) printf("-1\n");
        else printf("%s\n", a[0]);
    }
}