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