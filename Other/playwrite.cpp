#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e3 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int cnt[MAX][MAX] = {0};
    vector<pair<int, int>> acts(N);

    for (int i = 0; i < N; i++) {
        int c, t;
        cin >> c >> t;

        cnt[c][t]++;
        acts[i] = make_pair(c, t);
    }

    for (int i = 1; i < MAX; i++)
        for (int j = 1; j < MAX; j++)
            cnt[i][j] += cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];

    long ans = 0LL;
    for (auto [c, t]: acts) {
        int left = cnt[c - 1][t - 1];
        int right = cnt[MAX - 1][MAX - 1] - cnt[c][MAX - 1] - cnt[MAX - 1][t] + cnt[c][t];
        ans += 1LL * left * right;
    }

    cout << ans << "\n";
}