#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e3 + 5;
const int MAX_W = 35;
const int INF = 1e9;

int N, P[MAX_N], W[MAX_N];
int memo[MAX_W][MAX_N];

int value(int w, int i = 0) {
    if (w < 0) return -INF;
    if (i >= N) return 0;

    int &ans = memo[w][i];
    if (ans != -1) return ans;

    return ans = max(value(w, i + 1), P[i] + value(w - W[i], i + 1));
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            scanf("%d %d", &P[i], &W[i]);

        memset(memo, -1, sizeof memo);

        int G; scanf("%d", &G);

        int ans = 0;
        while (G--) {
            int MW; scanf("%d", &MW);
            ans += value(MW);
        }

        printf("%d\n", ans);
    }
}