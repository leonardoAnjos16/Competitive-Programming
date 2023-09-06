#include <bits/stdc++.h>

using namespace std;

const int ABC = 26;
const int INF = 1e6 + 5;

int n;

void get_dists(vector<vector<pair<int, int>>> &g, vector<int> &dists, char x, char y) {
    int idx = n + (x - 'a') * ABC + (y - 'a');
    dists[idx] = 0;

    deque<int> dq;
    dq.push_back(idx);

    while (!dq.empty()) {
        int v = dq.front(); dq.pop_front();
        for (auto [u, w]: g[v])
            if (dists[u] == INF) {
                dists[u] = dists[v] + w;
                if (!w) dq.push_front(u);
                else dq.push_back(u);
            }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    int m; cin >> m;

    n = s.size();
    vector<vector<pair<int, int>>> g(n + ABC * ABC, vector<pair<int, int>>()), rg(n + ABC * ABC, vector<pair<int, int>>());

    for (int i = 1; i < n; i++) {
        if (i > 1) {
            g[i].emplace_back(i - 1, 1);
            rg[i - 1].emplace_back(i, 1);
        }

        if (i + 1 < n) {
            g[i].emplace_back(i + 1, 1);
            rg[i + 1].emplace_back(i, 1);
        }
    }

    for (char c = 'a'; c <= 'z'; c++)
        for (char d = 'a'; d <= 'z'; d++) {
            vector<int> vertices;
            for (int i = 1; i < n; i++)
                if (s[i - 1] == c && s[i] == d)
                    vertices.push_back(i);

            int idx = n + (c - 'a') * ABC + (d - 'a');
            for (int v: vertices) {
                g[v].emplace_back(idx, 1);
                rg[idx].emplace_back(v, 1);

                g[idx].emplace_back(v, 0);
                rg[v].emplace_back(idx, 0);
            }
        }

    vector<int> f(m), t(m), ans(m);
    for (int i = 0; i < m; i++) {
        cin >> f[i] >> t[i];
        ans[i] = abs(t[i] - f[i]);
    }

    for (char c = 'a'; c <= 'z'; c++)
        for (char d = 'a'; d <= 'z'; d++) {
            vector<int> dists(n + ABC * ABC, INF), rdists(n + ABC * ABC, INF);
            get_dists(g, dists, c, d);
            get_dists(rg, rdists, c, d);

            for (int i = 0; i < m; i++)
                ans[i] = min(ans[i], rdists[f[i]] + dists[t[i]]);
        }

    for (int i = 0; i < m; i++)
        cout << ans[i] << "\n";
}