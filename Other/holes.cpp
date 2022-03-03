#include <bits/stdc++.h>

using namespace std;

#define long long long int

int N;
vector<vector<int>> g;
vector<vector<int>> dists;
vector<bool> vis, removed;

void get_dist(int v) {
    vector<int> &dist = dists[v];
    dist.assign(N, 0);

    vis.assign(N, false);
    vis[v] = true;

    queue<int> q;
    q.push(v);

    while (!q.empty()) {
        v = q.front(); q.pop();
        for (int u: g[v])
            if (!vis[u]) {
                vis[u] = true;
                dist[u] = dist[v] + 1;
                q.push(u);
            }
    }
}

int count(int v) {
    vis[v] = true;

    int ans = 1;
    for (auto u: g[v])
        if (!removed[u] && !vis[u])
            ans += count(u);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, K;
    cin >> N >> M >> K;

    g.assign(N, vector<int>());
    while (M--) {
        int x, y;
        cin >> x >> y;

        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }

    int root = 0;
    dists.resize(N);
    
    for (int i = 0; i < N; i++) {
        get_dist(i);
        if ((int) g[i].size() > 2)
            root = i;
    }

    int l = 0, r = N, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;

        int cnt = N;
        for (int i = 0; i < N; i++)
            if (dists[i][root] <= mid) {
                removed.assign(N, false);
                for (int j = 0; j < N; j++)
                    if (dists[i][j] <= mid)
                        removed[j] = true;

                vis.assign(N, false);
                int curr = 1, aux = 2 * mid + 1;

                for (int j = 0; j < N; j++)
                    if (!removed[j] && !vis[j])
                        curr += (count(j) + aux - 1) / aux;

                cnt = min(cnt, curr);
            }

        if (cnt > K) l = mid + 1;
        else r = mid - 1, ans = mid;
    }

    cout << ans << "\n";
}