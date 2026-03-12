#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int n;
vector<vector<pair<int, char>>> g;
vector<int> dists, path;

void get_dists() {
    dists.assign(n, -1);
    dists[n - 1] = 0;

    queue<int> q;
    q.push(n - 1);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto [u, c]: g[v])
            if (dists[u] == -1) {
                dists[u] = dists[v] + 1;
                q.push(u);
            }
    }
}

string solve() {
    string ans = "";
    queue<int> q;
    q.push(0);

    vector<bool> vis(n, false);
    vis[0] = true;

    int traveled = 0;
    while (!q.empty()) {
        char letter = '-';
        vector<pair<int, char>> edges;

        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (auto [u, c]: g[v])
                if (dists[u] == dists[0] - traveled - 1) {
                    edges.emplace_back(u, c);
                    if (letter == '-' || c < letter)
                        letter = c;
                }
        }

        for (auto [u, c]: edges)
            if (!vis[u] && c == letter) {
                q.push(u);
                vis[u] = true;
            }

        traveled++;
        if (letter != '-')
            ans += letter;
    }

    return ans;
}

bool get_path(vector<bool> &vis, string &letters, int v = 0, int traveled = 0) {
    if (vis[v]) return false;
    if (v + 1 >= n) return true;

    vis[v] = true;
    for (auto [u, c]: g[v])
        if (dists[u] == dists[0] - traveled - 1 && c == letters[traveled]) {
            path.push_back(u + 1);
            if (get_path(vis, letters, u, traveled + 1))
                return true;

            path.pop_back();
        }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> n >> m;

    g.assign(n, vector<pair<int, char>>());
    for (int i = 0; i < m; i++) {
        int u, v; char c;
        cin >> u >> v >> c;

        g[u - 1].emplace_back(v - 1, c);
        g[v - 1].emplace_back(u - 1, c);
    }

    get_dists();

    cout << dists[0] << "\n";

    string ans = solve();
    vector<bool> vis(n, false);
    assert(get_path(vis, ans));

    cout << "1";
    for (int v: path)
        cout << " " << v;

    cout << "\n";
    cout << ans << "\n";
}