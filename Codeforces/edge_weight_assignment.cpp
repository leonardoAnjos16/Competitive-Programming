#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vector<vi> g; int n;
vector<int> leaves;

void get_leaves() {
    for (int i = 0; i < n; i++)
        if (g[i].size() == 1)
            leaves.push_back(i);
}

int get_min_k() {
    queue<int> q;
    vector<bool> vis(n, false);
    vector<int> dists(n, 0);

    int l = leaves[0];
    vis[l] = true;
    q.push(l);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int i = 0; i < (int) g[v].size(); i++) {
            if (!vis[g[v][i]]) {
                q.push(g[v][i]);
                vis[g[v][i]] = true;
                dists[g[v][i]] = dists[v] + 1;
            }
        }
    }

    bool all_even = true;
    for (int i = 0; i < (int) leaves.size() && all_even; i++)
        if (dists[leaves[i]] % 2) all_even = false;

    return all_even ? 1 : 3;
}

int main() {
    scanf("%d", &n);

    g.assign(n, vi());
    for (int i = 1; i < n; i++) {
        int a, b; scanf("%d %d", &a, &b);
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    get_leaves();

    int min_k = get_min_k();
    int num_leaves = leaves.size();

    set<int> leaf_parents;
    for (int i = 0; i < num_leaves; i++)
        leaf_parents.insert(g[leaves[i]][0]);

    int max_k = n - 1 - num_leaves + ((int) leaf_parents.size());
    printf("%d %d\n", min_k, max_k);
}