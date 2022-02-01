#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int INF = 1e9 + 5;

int n, P, Q;
vector<int> bombs;
vector<int> nxt1, nxt2;
vector<vector<int>> memo;

int destroyers(int w, int i = 0, int p = 0) {
    if (p > P) return INF;
    if (i >= n) return 0;

    int &ans = memo[i][p];
    if (~ans) return ans;

    return ans = min(destroyers(w, nxt1[i], p + 1), destroyers(w, nxt2[i], p) + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> P >> Q;

    bombs.resize(n);
    for (int i = 0; i < n; i++)
        cin >> bombs[i];

    sort(bombs.begin(), bombs.end());
    nxt1.resize(n);
    nxt2.resize(n);

    int l = 1, r = bombs.back(), ans = -1;
    while (l <= r) {
        int w = (l + r) / 2;
        for (int i = 0; i < n; i++) {
            nxt1[i] = lower_bound(bombs.begin(), bombs.end(), bombs[i] + w) - bombs.begin();
            nxt2[i] = lower_bound(bombs.begin(), bombs.end(), bombs[i] + 2 * w) - bombs.begin();
        }

        memo.assign(n + 5, vector<int>(P + 5, -1));

        int cnt = destroyers(w);
        if (cnt > Q) l = w + 1;
        else r = w - 1, ans = w;
    }

    cout << ans << "\n";
}