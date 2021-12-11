#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int LOG = 20;

vector<vector<int>> tree;
vector<int> parent, dist;

void get_parent_and_dist(int v = 0, int p = 0, int d = 0) {
    parent[v] = p;
    dist[v] = d;

    for (auto u: tree[v])
        if (u != p)
            get_parent_and_dist(u, v, d + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    tree.assign(N, vector<int>());
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;

        tree[u - 1].push_back(v - 1);
        tree[v - 1].push_back(u - 1);
    }

    dist.resize(N);
    parent.resize(N);
    get_parent_and_dist();

    vector<vector<int>> up(N, vector<int>(LOG));
    for (int i = 0; i < N; i++)
        up[i][0] = parent[i];

    for (int i = 1; i < LOG; i++)
        for (int j = 0; j < N; j++)
            up[j][i] = up[up[j][i - 1]][i - 1];

    while (Q--) {
        int r, d;
        cin >> r >> d;

        if (dist[r - 1] <= d) cout << r << "\n";
        else {
            int ans = r - 1;
            for (int i = LOG - 1; i >= 0; i--)
                if (dist[up[ans][i]] > d)
                    ans = up[ans][i];

            ans = parent[ans] + 1;
            cout << ans << "\n";
        }
    }
}