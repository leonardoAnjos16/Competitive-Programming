#include <bits/stdc++.h>

using namespace std;

const int MAX_M = 1e4 + 205;
const int MAX_N = 105;

int m, n, p[MAX_N], f[MAX_N];
int memo[MAX_M][MAX_N];

int favour(int rem, int i = 0) {
    if (!rem || i >= n) {
        if (m - rem > 2000) return 0;
        else if (m - rem <= (m > 2000 ? m - 200 : m)) return 0;
        else return INT_MIN;
    }

    if (memo[rem][i] != -1) return memo[rem][i];

    if (p[i] > rem) return memo[rem][i] = favour(rem, i + 1);
    else return memo[rem][i] = max(favour(rem, i + 1), f[i] + favour(rem - p[i], i + 1));
}

int main() {
    while (scanf("%d %d", &m, &n) != EOF) {
        if (m > 1800) m += 200;
        for (int i = 0; i < n; i++)
            scanf("%d %d", &p[i], &f[i]);

        memset(memo, -1, sizeof memo);

        int ans = favour(m);
        printf("%d\n", ans);
    }
}