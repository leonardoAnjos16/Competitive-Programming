#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    int n;
    vector<int> a;
    vector<int> tree;

public:
    void init(int n, vector<int> &a) {
        this->n = n;
        this->a = a;

        tree.resize(4 * n);
        build(1, 1, n);
    }

    void update(int i, int v) {
        update(1, 1, n, i, v);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void build(int node, int l, int r) {
        if (l == r) tree[node] = a[l];
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int l, int r, int i, int v) {
        if (l == r) tree[node] = v;
        else {
            int m = (l + r) / 2;
            if (i <= m) update(2 * node, l, m, i, v);
            else update(2 * node + 1, m + 1, r, i, v);
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return INT_MIN;
        if (ql <= l && r <= qr) return tree[node];

        int m = (l + r) / 2;
        int left = query(2 * node, l, m, ql, qr);
        int right = query(2 * node + 1, m + 1, r, ql, qr);
        return max(left, right);
    }
};

struct HLD {
private:
    int curr_pos;
    vector<vector<pair<int, int>>> tree;
    vector<int> depth, parent, heavy, head, pos, value;
    SegmentTree data;

public:
    HLD(int n, vector<vector<pair<int, int>>> &tree, int root = 0) {
        this->tree = tree;
        this->curr_pos = 1;

        depth.assign(n, 0);
        parent.assign(n, 0);
        heavy.assign(n, -1);
        init(root);

        head.assign(n, 0);
        pos.assign(n, 0);
        value.assign(n + 1, INT_MIN);
        decompose(root, root);

        data.init(n, value);
    }

    void update(int a, int b, int c) {
        if (a == parent[b]) data.update(pos[b], c);
        else if (b == parent[a]) data.update(pos[a], c);
    }

    int query(int a, int b) {
        int ans = INT_MIN;
        while (head[a] != head[b]) {
            if (depth[head[a]] > depth[head[b]]) swap(a, b);
            ans = max(ans, data.query(pos[head[b]], pos[b]));
            b = parent[head[b]];
        }

        if (a == b) return ans;

        if (depth[a] > depth[b]) swap(a, b);
        ans = max(ans, data.query(pos[a] + 1, pos[b]));
        return ans;
    }

private:
    int init(int node, int p = -1) {
        int size = 1, mx_size = 0;
        for (auto [child, weight]: tree[node])
            if (child != p) {
                parent[child] = node;
                depth[child] = depth[node] + 1;

                int subtree_size = init(child, node);
                size += subtree_size;

                if (subtree_size > mx_size) {
                    heavy[node] = child;
                    mx_size = subtree_size;
                }
            }

        return size;
    }

    void decompose(int node, int h) {
        head[node] = h;
        pos[node] = curr_pos++;

        if (heavy[node] != -1)
            decompose(heavy[node], h);

        for (auto [child, weight]: tree[node]) {
            if (child == heavy[node]) value[pos[child]] = weight;
            else if (child != parent[node]) {
                value[curr_pos] = weight;
                decompose(child, child);
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int N; cin >> N;

        vector<pair<int, int>> edges(N);
        vector<vector<pair<int, int>>> tree(N, vector<pair<int, int>>());

        for (int i = 1; i < N; i++) {
            int a, b, c;
            cin >> a >> b >> c;

            edges[i] = make_pair(a - 1, b - 1);
            tree[a - 1].emplace_back(b - 1, c);
            tree[b - 1].emplace_back(a - 1, c);
        }

        string op;
        HLD solver(N, tree);

        while (cin >> op, op != "DONE") {
            if (op == "CHANGE") {
                int i, t;
                cin >> i >> t;
                solver.update(edges[i].first, edges[i].second, t);
            } else {
                int a, b;
                cin >> a >> b;

                int ans = solver.query(a - 1, b - 1);
                if (ans == INT_MIN) cout << "0\n";
                else cout << ans << "\n";
            }
        }
    }
}