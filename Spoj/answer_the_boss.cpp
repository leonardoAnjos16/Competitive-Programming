#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

const int MAX = 1e3 + 5;

vector<vector<int>> g;
vector<int> ranks;

void bfs() {
    vector<int> in_degree(size(g), 0);
    for (auto vec: g)
        for (auto v: vec)
            in_degree[v]++;

    queue<int> aux;
    for (int i = 0; i < size(g); i++)
        if (!in_degree[i]) {
            aux.push(i);
            ranks[i] = 1;
        }

    while (!aux.empty()) {
        int v = aux.front(); aux.pop();
        for (auto u: g[v]) {
            aux.push(u);
            ranks[u] = ranks[v] + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, R;
        cin >> N >> R;

        g.assign(N, vector<int>());
        for (int i = 0; i < R; i++) {
            int R1, R2;
            cin >> R1 >> R2;
            g[R2].push_back(R1);
        }

        ranks.assign(N, 0); bfs();
        map<int, set<int>> ans;

        for (int i = 0; i < N; i++)
            ans[ranks[i]].insert(i);

        cout << "Scenario #" << t << ":\n";
        for (auto p: ans)
            for (auto e: p.snd)
                cout << p.fst << " " << e << "\n";

        g.clear();
        ranks.clear();
    }
}