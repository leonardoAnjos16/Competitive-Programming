#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C, P, X, L;
    cin >> C >> P >> X >> L;

    vector<int> partners(C, 0);
    vector<vector<int>> g(C, vector<int>());

    for (int i = 0; i < P; i++) {
        int A, B;
        cin >> A >> B;

        partners[A - 1]++;
        partners[B - 1]++;

        g[A - 1].push_back(B - 1);
        g[B - 1].push_back(A - 1);
    }

    vector<int> left(C, 0);
    vector<bool> stay(C, true);
    stay[L - 1] = false;

    vector<bool> vis(C, false);
    vis[L - 1] = true;

    queue<int> q;
    q.push(L - 1);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto u: g[v]) {
            left[u]++;
            if (!vis[u] && 2 * left[u] >= partners[u]) {
                q.push(u);
                vis[u] = true;
                stay[u] = false;
            }
        }
    }

    cout << (stay[X - 1] ? "stay" : "leave") << "\n";
}