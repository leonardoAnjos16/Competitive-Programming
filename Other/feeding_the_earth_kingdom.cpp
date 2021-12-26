#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<vector<int>> g;
vector<bool> vis;

void visit(int v) {
    if (vis[v]) return;

    vis[v] = true;
    for (auto u: g[v])
        visit(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    g.assign(N, vector<int>());
    while (M--) {
        int A, B;
        cin >> A >> B;

        g[A - 1].push_back(B - 1);
        g[B - 1].push_back(A - 1);
    }

    int ans = 0;
    vis.assign(N, false);

    for (int i = 0; i < N; i++)
        if (!vis[i]) {
            ans++;
            visit(i);
        }

    cout << ans << "\n";
}