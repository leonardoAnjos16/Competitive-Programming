#include <bits/stdc++.h>

using namespace std;

#define long long long int

int N, B;
vector<int> p;
vector<vector<int>> g;
vector<long> ans;

void solve() {
    vector<int> deg(N, 0);
    for (int i = 0; i < N; i++)
        for (auto v: g[i])
            deg[v]++;

    queue<int> q;
    ans.assign(N, 0LL);

    for (int i = 0; i < N; i++)
        if (!deg[i]) {
            q.push(i);
            ans[i] = !p[i] ? 0LL : B;
        }

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto u: g[v]) {
            ans[u] = max(ans[u], ans[v] + B);
            if (--deg[u] == 0) q.push(u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> B;

    p.resize(N);
    for (int i = 0; i < N; i++)
        cin >> p[i];

    g.assign(N, vector<int>());
    for (int i = 0; i < N; i++) {
        if (p[i] < p[(i + 1) % N]) g[i].push_back((i + 1) % N);
        if (p[i] < p[(i + N - 1) % N]) g[i].push_back((i + N - 1) % N);
    }

    solve();
    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}