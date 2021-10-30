#include <bits/stdc++.h>

using namespace std;

#define long long long int

int M;
vector<vector<int>> g;

vector<int> gossip(int s) {
    vector<bool> vis(M, false);
    vis[s] = true;

    vector<int> dist(M, -1);
    dist[s] = 0;

    queue<int> aux;
    aux.push(s);

    int days = 0;
    while (!aux.empty()) {
        int v = aux.front(); aux.pop();
        for (auto u: g[v])
            if (!vis[u]) {
                vis[u] = true;
                dist[u] = dist[v] + 1;
                days = max(days, dist[u]);
                aux.push(u);
            }
    }

    vector<int> cnt(days + 1, 0);
    for (int i = 0; i < M; i++)
        if (~dist[i]) cnt[dist[i]]++;

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M;

    g.resize(M);
    for (int i = 0; i < M; i++) {
        int A; cin >> A;
        g[i].resize(A);

        for (int j = 0; j < A; j++)
            cin >> g[i][j];
    }

    int T; cin >> T;
    while (T--) {
        int s; cin >> s;

        vector<int> cnt = gossip(s);
        int days = cnt.size();

        if (days <= 1) cout << "0\n";
        else {
            int mx = INT_MIN, idx = -1;
            for (int i = 1; i < days; i++)
                if (cnt[i] > mx) {
                    mx = cnt[i];
                    idx = i;
                }

            cout << mx << " " << idx << "\n";
        }
    }
}