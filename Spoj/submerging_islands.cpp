#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e4 + 5;

vector<vector<int>> g;
vector<int> in, low, p;
bitset<MAX> ap;
int rc, idx;

void get_ap(int v = 0) {
    in[v] = low[v] = idx++;
    for (auto u: g[v]) {
        if (~in[u] && u != p[v]) low[v] = min(low[v], in[u]);
        else if (in[u] == -1) {
            p[u] = v;
            get_ap(u);
            if (!v) rc++;

            if (low[u] >= in[v]) ap[v] = true;
            low[v] = min(low[v], low[u]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    while (cin >> N >> M, N || M) {
        g.assign(N, vector<int>());
        while (M--) {
            int U, V;
            cin >> U >> V;

            g[U - 1].push_back(V - 1);
            g[V - 1].push_back(U - 1);
        }

        in.assign(N, -1);
        low.resize(N);
        p.resize(N);
        ap.reset();
        rc = idx = 0;
        
        get_ap();

        int ans = rc > 1;
        for (int i = 1; i < N; i++)
            ans += ap[i];

        cout << ans << "\n";
    }
}