#include <bits/stdc++.h>

using namespace std;

#define llong long long int

struct FenwickTree {
private:
    int n;
    vector<int> tree;

public:
    FenwickTree() {}

    void init(int n) {
        this->n = n + 1;
        tree.assign(n + 1, 0);
    }

    void update(int i, int v) {
        if (!i) tree[0] += v;
        else {
            while (i < n) {
                tree[i] += v;
                i += LSO(i);
            }
        }
    }

    int query(int i, int j) {
        return query(j) - query(i - 1);
    }

private:
    int LSO(int i) {
        return i & -i;
    }

    int query(int i) {
        if (i < 0) return 0;

        int ans = tree[0];
        while (i) {
            ans += tree[i];
            i -= LSO(i);
        }

        return ans;
    }
};

struct HLD {
private:
    int n;
    vector<vector<int>> tree;
    vector<int> depth, head, heavy, parent, pos;
    FenwickTree helper;

public:
    HLD(int n) {
        this->n = n;
        tree.assign(n, vector<int>());
    }

    void add_edge(int u, int v) {
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    void set_root(int root) {
        depth.assign(n, 0);
        heavy.assign(n, -1);
        parent.assign(n, -1);

        init(root);

        int idx = 1;
        head.resize(n);
        pos.resize(n);

        decompose(root, root, idx);

        helper.init(n);
    }

    void update(int node, int v) {
        helper.update(pos[node], v);
    }

    int query(int u, int v) {
        int ans = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            ans += helper.query(pos[head[v]], pos[v]);
            v = parent[head[v]];
        }

        if (depth[u] > depth[v]) swap(u, v);
        ans += helper.query(pos[u], pos[v]);
        return ans;
    }

private:
    int init(int node, int p = -1) {
        int size = 1, mx_size = 0;
        for (int child: tree[node])
            if (child != p) {
                parent[child] = node;
                depth[child] = depth[node] + 1;
                int child_size = init(child, node);

                size += child_size;
                if (child_size > mx_size) {
                    heavy[node] = child;
                    mx_size = child_size;
                }
            }

        return size;
    }

    void decompose(int node, int h, int &idx) {
        head[node] = h;
        pos[node] = idx++;

        if (heavy[node] != -1)
            decompose(heavy[node], h, idx);

        for (int child: tree[node])
            if (child != parent[node] && child != heavy[node])
                decompose(child, child, idx);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;

        vector<int> genies(n);
        for (int i = 0; i < n; i++)
            cin >> genies[i];

        HLD solver(n);
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            solver.add_edge(u, v);
        }

        solver.set_root(0);
        for (int i = 0; i < n; i++)
            solver.update(i, genies[i]);

        cout << "Case " << t << ":\n";

        int q; cin >> q;
        while (q--) {
            int op; cin >> op;
            if (!op) {
                int i, j;
                cin >> i >> j;

                int ans = solver.query(i, j);
                cout << ans << "\n";
            } else {
                int i, v;
                cin >> i >> v;

                solver.update(i, v - genies[i]);
                genies[i] = v;
            }
        }
    }
}