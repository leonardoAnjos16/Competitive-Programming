#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int main() {
    int n, m; scanf("%d %d", &n, &m);

    int a[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    bitset<MAX> seen;

    int cnt[MAX];
    cnt[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
        cnt[i] = cnt[i + 1] + (seen[a[i]] ? 0 : 1);
        seen[a[i]] = true;
    }

    while (m--) {
        int l; scanf("%d", &l);
        printf("%d\n", cnt[l - 1]);
    }
}