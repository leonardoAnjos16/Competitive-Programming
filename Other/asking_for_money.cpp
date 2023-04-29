#include <bits/stdc++.h>

using namespace std;

#define llong long long int

vector<vector<int>> g;
vector<bool> vis;

void traverse(int v, int rem) {
    vis[v] = true;
    for (int u: g[v])
        if (u != rem && !vis[u])
            traverse(u, rem);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<int> X(N), Y(N);
    g.assign(N, vector<int>());

    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];

        g[--X[i]].push_back(i);
        g[--Y[i]].push_back(i);
    }

    string ans(N, 'N');
    for (int i = 0; i < N; i++) {
        vector<int> cnt(N, 0);
        vector<int> sources = { i, X[i], Y[i] };

        for (int source: sources) {
            vis.assign(N, false);
            traverse(source, i);

            for (int j = 0; j < N; j++)
                cnt[j] += vis[j];
        }

        for (int j = 0; j < N; j++)
            if (cnt[j] == 3)
                ans[i] = 'Y';
    }

    cout << ans << "\n";
}