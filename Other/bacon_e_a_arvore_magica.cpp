#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int LOG = 20;

struct SegmentTree {
private:
    int n;
    vector<int> tree, lazy;

public:
    SegmentTree(int n) {
        this->n = n;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, -1);
    }

    void update(int l, int r, bool v) {
        update(1, 1, n, l, r, v);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void update_lazy(int node, int l, int r, bool v) {
        lazy[node] = v;
        tree[node] = v ? r - l + 1 : 0;
    }

    void push_down(int node, int l, int r) {
        if (lazy[node] == -1) return;

        int m = (l + r) / 2;
        update_lazy(2 * node, l, m, lazy[node]);
        update_lazy(2 * node + 1, m + 1, r, lazy[node]);
        lazy[node] = -1;
    }

    void update(int node, int l, int r, int ul, int ur, bool v) {
        if (r < ul || l > ur) return;
        if (ul <= l && r <= ur) {
            update_lazy(node, l, r, v);
            return;
        }

        push_down(node, l, r);

        int m = (l + r) / 2;
        update(2 * node, l, m, ul, ur, v);
        update(2 * node + 1, m + 1, r, ul, ur, v);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) return tree[node];

        push_down(node, l, r);

        int m = (l + r) / 2;
        return query(2 * node, l, m, ql, qr) + query(2 * node + 1, m + 1, r, ql, qr);
    }
};

struct HLD {
private:
    int n;
    vector<vector<int>> tree;
    vector<int> depth, head, heavy, parent;
    vector<int> tin, tout;

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

        int t = 1;
        head.resize(n);
        tin.resize(n);
        tout.resize(n);

        decompose(root, root, t);
    }

    vector<pair<int, int>> get_path(int u, int v) {
        vector<pair<int, int>> ranges;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            ranges.emplace_back(tin[head[v]], tin[v]);
            v = parent[head[v]];
        }

        if (depth[u] > depth[v]) swap(u, v);
        ranges.emplace_back(tin[u], tin[v]);

        return ranges;
    }

    pair<int, int> get_subtree(int node) {
        return make_pair(tin[node], tout[node] - 1);
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

    void decompose(int node, int h, int &t) {
        head[node] = h;
        tin[node] = t++;

        if (heavy[node] != -1)
            decompose(heavy[node], h, t);

        for (int child: tree[node])
            if (child != parent[node] && child != heavy[node])
                decompose(child, child, t);

        tout[node] = t;
    }
};

vector<vector<int>> tree;
vector<int> p, depth, sz;
vector<vector<int>> up;

void init(int node = 0, int parent = -1) {
    sz[node] = 1;
    for (int child: tree[node])
        if (child != parent) {
            p[child] = node;
            depth[child] = depth[node] + 1;

            init(child, node);
            sz[node] += sz[child];
        }
}

void build_up(int N) {
    up.assign(LOG, vector<int>(N));
    for (int i = 0; i < N; i++)
        up[0][i] = p[i];

    for (int i = 1; i < LOG; i++)
        for (int j = 0; j < N; j++)
            up[i][j] = up[i - 1][up[i - 1][j]];
}

int kth_ancestor(int v, int k) {
    for (int i = 0; i < LOG; i++)
        if (k & (1 << i))
            v = up[i][v];

    return v;
}

int lift(int v, function<bool(int)> check) {
    int l = 0, r = depth[v], ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (!check(mid)) r = mid - 1;
        else l = mid + 1, ans = mid;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    HLD solver(N);
    tree.assign(N, vector<int>());

    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;

        tree[a - 1].push_back(b - 1);
        tree[b - 1].push_back(a - 1);
        solver.add_edge(a - 1, b - 1);
    }

    p.assign(N, 0);
    depth.assign(N, 0);
    sz.resize(N);

    init();
    build_up(N);
    solver.set_root(0);

    int Q; cin >> Q;

    SegmentTree helper(N);
    while (Q--) {
        int t, v;
        cin >> t >> v;

        if (t == 1) {
            auto [l, r] = solver.get_subtree(v - 1);
            helper.update(l, r, true);

            int k = lift(v - 1, [&](int k) {
                int ancestor = kth_ancestor(v - 1, k);
                auto [l, r] = solver.get_subtree(ancestor);
                return helper.query(l, r) >= sz[ancestor];
            });

            v = kth_ancestor(v - 1, k);
            k = lift(v, [&](int k) {
                int ancestor = kth_ancestor(v, k);
                auto [l, r] = solver.get_subtree(ancestor);
                return helper.query(l, r) >= sz[ancestor] - k;
            });

            v = kth_ancestor(v, k);
            tie(l, r) = solver.get_subtree(v);
            helper.update(l, r, true);
        } else if (t == 2) {
            auto [l, r] = solver.get_subtree(v - 1);
            helper.update(l, r, false);

            vector<pair<int, int>> ranges = solver.get_path(0, v - 1);
            for (auto [l, r]: ranges) helper.update(l, r, false);
        } else {
            auto [l, r] = solver.get_subtree(v - 1);
            int ans = helper.query(l, r);
            cout << ans << "\n";
        }
    }
}