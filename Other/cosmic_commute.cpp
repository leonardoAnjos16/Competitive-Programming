#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int n;
vector<vector<int>> g;

vector<int> get_dists(int s) {
    vector<int> dist(n, -1);
    dist[s] = 0;

    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u: g[v])
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, k;
    cin >> n >> m >> k;

    vector<int> wormholes(k);
    for (int i = 0; i < k; i++) {
        cin >> wormholes[i];
        wormholes[i]--;
    }

    g.assign(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    vector<int> from = get_dists(0);
    vector<int> to = get_dists(n - 1);

    llong sum = 0LL;
    for (int v: wormholes)
        sum += to[v];

    llong a = from[n - 1], b = 1LL;
    for (int v: wormholes) {
        llong na = (k - 1LL) * from[v] + sum - to[v];
        llong nb = k - 1LL;

        llong g = gcd(na, nb);
        na /= g; nb /= g;

        if (na * b < nb * a) {
            a = na;
            b = nb;
        }
    }

    cout << a << "/" << b << "\n";
}