#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong INF = 1e18 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = make_tuple(a - 1, b - 1, c);
    }

    vector<int> prev(n, -1);
    vector<llong> dist(n, INF);
    dist[0] = 0;

    for (int i = 1; i < n; i++)
        for (auto [u, v, w]: edges)
            if (dist[u] + w < dist[v]) {
                prev[v] = u;
                dist[v] = dist[u] + w;
            }

    int end = -1;
    for (auto [u, v, w]: edges)
        if (dist[u] + w < dist[v]) {
            end = v;
            prev[v] = u;
            dist[v] = dist[u] + w;
        }

    if (end == -1) cout << "NO\n";
    else {
        int v = end;
        vector<int> ans;
        vector<bool> seen(n, false);

        while (!seen[v]) {
            seen[v] = true;
            ans.push_back(v + 1);
            v = prev[v];
            assert(v != -1);
        }

        cout << "YES\n";
        cout << (v + 1);

        seen.assign(n, false);
        seen[v] = true;

        int idx = (int) ans.size() - 1;
        while (idx >= 0 && !seen[ans[idx] - 1]) {
            cout << " " << ans[idx];
            seen[ans[idx--] - 1] = true;
        }

        cout << " " << ans[idx] << "\n";
    }
}