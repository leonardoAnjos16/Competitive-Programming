#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e3 + 5;
const int MAX_W = 3e3 + 5;
const int INF = 1e9;

int N, W[MAX_N], ML[MAX_N];
int memo[MAX_W][MAX_N];

int boxes(int w, int i) {
    if (w < 0) return -INF;
    if (!w || i >= N) return 0;

    int &ans = memo[w < MAX_W ? w : 0][i];
    if (ans != -1) return ans;

    return ans = max(boxes(w, i + 1), 1 + boxes(min(w - W[i], ML[i]), i + 1));
}

int main() {
    while (scanf("%d", &N), N) {
        for (int i = 0; i < N; i++)
            scanf("%d %d", &W[i], &ML[i]);

        memset(memo, -1, sizeof memo);

        int ans = boxes(INF, 0);
        printf("%d\n", ans);
    }
}