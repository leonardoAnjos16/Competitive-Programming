#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int main() {
    int n; scanf("%d", &n);

    int cards[MAX][2];
    map<int, int> cnt_f, cnt_b;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cards[i][0], &cards[i][1]);
        if (cards[i][0] != cards[i][1]) cnt_b[cards[i][1]]++;
        cnt_f[cards[i][0]]++;
    }

    int half = ceil(n / 2.0);

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            if (cnt_f[cards[i][j]] + cnt_b[cards[i][j]] >= half)
                ans = min(ans, max(0, half - cnt_f[cards[i][j]]));

    if (ans == INT_MAX) printf("-1\n");
    else printf("%d\n", ans);
}