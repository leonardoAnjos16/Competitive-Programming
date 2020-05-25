#include <bits/stdc++.h>

using namespace std;

const int MAX = 55;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        int s[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &s[i]);

        sort(s, s + n);

        int ans = INT_MAX;
        for (int i = 1; i < n; i++)
            ans = min(ans, s[i] - s[i - 1]);

        printf("%d\n", ans);
    }
}