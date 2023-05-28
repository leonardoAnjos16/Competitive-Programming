#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong INF = 1e18 + 5;

int n, k;
vector<int> s, intersection, t;
vector<vector<pair<int, int>>> g;
vector<vector<llong>> dists;
vector<llong> memo;

void get_dists(int start) {
    dists[start].assign(n, INF);
    dists[start][start] = 0LL;

    priority_queue<pair<llong, int>, vector<pair<llong, int>>, greater<pair<llong, int>>> heap;
    heap.emplace(0LL, start);

    while (!heap.empty()) {
        auto [d, v] = heap.top(); heap.pop();
        if (d > dists[start][v]) continue;

        for (auto [u, w]: g[v])
            if (dists[start][v] + w < dists[start][u]) {
                dists[start][u] = dists[start][v] + w;
                heap.emplace(dists[start][u], u);
            }
    }
}

llong greatest_time(llong max_waiting_time, int i = 0) {
    if (i >= k) return INF;

    llong &ans = memo[i];
    if (ans != -INF) return ans;

    ans = -1LL;
    llong T = INF, sum = 0LL, mx = 0LL;

    for (int j = i; j < k; j++) {
        mx = max(mx, 1LL * t[j]);
        sum += j == i ? dists[0][intersection[i]] : dists[intersection[j - 1]][intersection[j]];
        T = min(T, max_waiting_time - sum + s[j]);

        llong aux = min(T, greatest_time(max_waiting_time, j + 1) - sum - dists[intersection[j]][0]);
        if (aux >= mx) ans = max(ans, aux);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> n >> m;

    g.assign(n, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;

        g[u - 1].emplace_back(v - 1, d);
        g[v - 1].emplace_back(u - 1, d);
    }

    dists.resize(n);
    for (int i = 0; i < n; i++)
        get_dists(i);

    cin >> k;

    s.resize(k);
    intersection.resize(k);
    t.resize(k);

    for (int i = 0; i < k; i++) {
        cin >> s[i] >> intersection[i] >> t[i];
        intersection[i]--;
    }

    llong l = 0LL, r = INF, ans = -1LL;
    while (l <= r) {
        llong mid = (l + r) / 2LL;

        memo.assign(k + 5, -INF);

        if (greatest_time(mid) < 0LL) l = mid + 1LL;
        else r = mid - 1LL, ans = mid;
    }

    cout << ans << "\n";
}