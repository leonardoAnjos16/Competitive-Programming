#include <bits/stdc++.h>

using namespace std;

#define long long long int

const long INF = 1e18;
const int MAX_V = 1e5 + 5;

int N;
vector<pair<int, int>> items;
vector<vector<long>> memo;

long weight(int v, int i = 0) {
    if (v <= 0) return 0LL;
    if (i >= N) return INF;

    long &ans = memo[v][i];
    if (~ans) return ans;

    return ans = min(weight(v, i + 1), weight(v - items[i].second, i + 1) + items[i].first);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int W;
    cin >> N >> W;

    items.resize(N);
    for (int i = 0; i < N; i++) {
        int w, v;
        cin >> w >> v;
        items[i] = make_pair(w, v);
    }

    memo.assign(MAX_V, vector<long>(N + 5, -1));

    int l = 0, r = MAX_V - 1, ans;
    while (l <= r) {
        int mid = (l + r) / 2;

        if (weight(mid) > W) r = mid - 1;
        else l = mid + 1, ans = mid;
    }

    cout << ans << "\n";
}