#include <bits/stdc++.h>

using namespace std;

const int MAX = 3e4 + 5;

bool cmp(int a, int b, bool less_than) {
    return less_than ? a < b : a > b;
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);

        int F[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &F[i]);

        int ans = 1;
        for (int i = 1; i < n; i++)
            if (cmp(F[i], F[i - 1], ans & 1)) ans++;

        printf("%d\n", ans);
    }
}