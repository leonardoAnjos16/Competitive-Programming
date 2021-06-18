#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int LOG = 20;

int n;
vector<int> parent, depth;
vector<vector<int>> g, up;

void get_depths() {
    vector<bool> vis(n, false);
    depth.resize(n);
    depth[0] = 0;

    queue<int> aux;
    aux.push(0);

    while (!aux.empty()) {
        int v = aux.front(); aux.pop();
        for (auto u: g[v]) {
            if (!vis[u]) {
                depth[u] = depth[v] + 1;
                aux.push(u);
            }
        }
    }
}

int get_lca(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);

    int diff = depth[u] - depth[v];
    for (int i = 0; i <= LOG; i++)
        if (diff & (1 << i))
            u = up[u][i];

    assert(depth[u] == depth[v]);
    if (u == v) return u;

    for (int i = LOG; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }

    return parent[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    parent.resize(n);
    parent[0] = 0;

    for (int i = 1; i < n; i++) {
        cin >> parent[i];
        parent[i]--;
    }

    vector<int> IC(n);
    for (int i = 0; i < n; i++)
        cin >> IC[i];

    up.assign(n, vector<int>(LOG + 1));
    for (int i = 0; i < n; i++)
        up[i][0] = parent[i];

    for (int i = 1; i <= LOG; i++)
        for (int j = 0; j < n; j++)
            up[j][i] = up[up[j][i - 1]][i - 1];

    g.assign(n, vector<int>());
    for (int i = 1; i < n; i++)
        g[parent[i]].push_back(i);

    get_depths();

    int m; cin >> m;
    vector<vector<int>> diseases(m, vector<int>());

    for (int i = 0; i < m; i++) {
        int cm; cin >> cm;
        diseases[i].resize(cm);

        for (int j = 0; j < cm; j++) {
            cin >> diseases[i][j];
            diseases[i][j]--;
        }
    }

    int nq; cin >> nq;
    for (int i = 0; i < nq; i++) {
        int cq; cin >> cq;
        vector<int> patient(cq);

        for (int j = 0; j < cq; j++) {
            cin >> patient[j];
            patient[j]--;
        }

        int mx_sum = INT_MIN, disease = -1;
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int k = 0; k < cq; k++) {
                int mx_IC = INT_MIN;
                for (int l = 0; l < (int) diseases[j].size(); l++) {
                    int lca = get_lca(patient[k], diseases[j][l]);
                    mx_IC = max(mx_IC, IC[lca]);
                }

                sum += mx_IC;
            }

            if (sum > mx_sum) {
                mx_sum = sum;
                disease = j + 1;
            }
        }

        cout << disease << "\n";
    }
}