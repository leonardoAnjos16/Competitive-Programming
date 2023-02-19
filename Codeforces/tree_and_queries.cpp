#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e5 + 5;

struct FenwickTree {
private:
    int n;
    vector<int> tree;

public:
    FenwickTree() {}
    FenwickTree(int n) {
        this->n = n + 1;
        tree.assign(n + 1, 0);
    }

    void add(int i, int v) {
        if (!i) tree[0] += v;
        else {
            while (i < n) {
                tree[i] += v;
                i += LSO(i);
            }
        }
    }

    int sum(int i, int j) {
        return sum(j) - sum(i - 1);
    }

private:
    int LSO(int i) {
        return i & -i;
    }

    int sum(int i) {
        if (i < 0) return 0;

        int ans = tree[0];
        while (i) {
            ans += tree[i];
            i -= LSO(i);
        }

        return ans;
    }
};

int n;
vector<int> c;
vector<vector<int>> tree;
vector<vector<pair<int, int>>> queries;
vector<int> nodes, ans;
FenwickTree colors;
int cnt[MAX];

void get_nodes(int node = 0, int parent = -1) {
    nodes[node] = 1;
    for (int child: tree[node])
        if (child != parent) {
            get_nodes(child, node);
            nodes[node] += nodes[child];
        }
}

void add(int node, int parent, int big, int v) {
    colors.add(cnt[c[node]], -1);
    cnt[c[node]] += v;
    colors.add(cnt[c[node]], 1);

    for (int child: tree[node])
        if (child != parent && child != big)
            add(child, node, big, v);
}

void solve(int node = 0, int parent = -1, bool keep = true) {
    int mx = 0, big = -1;
    for (int child: tree[node])
        if (child != parent && nodes[child] > mx) {
            big = child;
            mx = nodes[child];
        }

    for (int child: tree[node])
        if (child != parent && child != big)
            solve(child, node, false);

    if (big != -1) solve(big, node);

    add(node, parent, big, 1);
    for (auto [k, idx]: queries[node])
        ans[idx] = k <= n ? colors.sum(k, n) : 0;

    if (!keep) add(node, parent, -1, -1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> n >> m;

    c.resize(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    tree.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;

        tree[a - 1].push_back(b - 1);
        tree[b - 1].push_back(a - 1);
    }

    queries.assign(n, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int v, k;
        cin >> v >> k;
        queries[v - 1].emplace_back(k, i);
    }

    nodes.resize(n);
    get_nodes();

    memset(cnt, 0, sizeof cnt);
    colors = FenwickTree(n);
    ans.resize(m);

    solve();
    for (int i = 0; i < m; i++)
        cout << ans[i] << "\n";
}