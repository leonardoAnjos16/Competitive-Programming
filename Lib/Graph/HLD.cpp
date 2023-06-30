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