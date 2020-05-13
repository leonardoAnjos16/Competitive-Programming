#include <bits/stdc++.h>

using namespace std;

const int MAX = 205;

int main() {
    int q; scanf("%d", &q);
    while (q--) {
        int n; scanf("%d", &n);

        int p[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &p[i]);

        bool possible = true;
        for (int i = 0; i < n && possible; i++) {
            int diff = abs(p[i] - p[(i + 1) % n]);
            if (diff != 1 && diff != n - 1) possible = false;
        }

        printf("%s\n", possible ? "YES" : "NO");
    }
}