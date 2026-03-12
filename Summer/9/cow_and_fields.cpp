#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int n;
vector<vector<int>> g;

vector<int> get_dists(int start) {
    vector<int> dists(n, -1);
    dists[start] = 0;

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u: g[v])
            if (dists[u] == -1) {
                q.push(u);
                dists[u] = dists[v] + 1;
            }
    }

    return dists;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, k;
    cin >> n >> m >> k;

    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        a[i]--;
    }

    g.assign(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }

    vector<int> forward = get_dists(0);
    vector<int> backward = get_dists(n - 1);

    vector<pair<int, int>> diffs(k);
    for (int i = 0; i < k; i++)
        diffs[i] = make_pair(forward[a[i]] - backward[a[i]], a[i]);

    sort(diffs.begin(), diffs.end());

    int ans = INT_MIN, mx = forward[diffs[0].second];
    for (int i = 1; i < k; i++) {
        int special = diffs[i].second;
        ans = max(ans, mx + backward[special] + 1);
        mx = max(mx, forward[special]);
    }

    ans = min(ans, forward[n - 1]);
    cout << ans << "\n";
}