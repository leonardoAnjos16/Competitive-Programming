#include <bits/stdc++.h>

using namespace std;

const int MAX = 305;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        int b[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &b[i]);

        int ans[MAX], l = 0, r = n - 1;
        bool init = true;

        for (int i = 0; i < n; i++) {
            if (init) ans[i] = b[l++];
            else ans[i] = b[r--];

            init = !init;
        }

        for (int i = 0; i < n; i++)
            printf("%d ", ans[i]);

        printf("\n");
    }
}