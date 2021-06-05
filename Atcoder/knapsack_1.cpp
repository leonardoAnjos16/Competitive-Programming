#include <bits/stdc++.h>

using namespace std;

#define long long long int

const long INF = 1e18;

int N, W;
vector<pair<int, int>> items;
vector<vector<long>> memo;

long value(int i = 0, int w = 0) {
    if (w > W) return -INF;
    if (i >= N) return 0;

    long &ans = memo[i][w];
    if (~ans) return ans;

    return ans = max(value(i + 1, w), items[i].second + value(i + 1, w + items[i].first));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> W;

    items.resize(N);
    for (int i = 0; i < N; i++) {
        int w, v;
        cin >> w >> v;
        items[i] = make_pair(w, v);
    }

    memo.assign(N + 5, vector<long>(W + 5, -1));

    long ans = value();
    cout << ans << "\n";
}