#include <bits/stdc++.h>

using namespace std;

const int MAX = 1005;

int count(int n) {
    int cnt = 0;
    while (n) {
        if (n & 1) cnt++;
        n >>= 1;
    }

    return cnt;
}

int main() {
    int n, m, k; scanf("%d %d %d", &n, &m, &k);

    int x[MAX];
    for (int i = 0; i <= m; i++)
        scanf("%d", &x[i]);

    int ans = 0;
    for (int i = 0; i < m; i++)
        if (count(x[i] ^ x[m]) <= k) ans++;

    printf("%d\n", ans);
}