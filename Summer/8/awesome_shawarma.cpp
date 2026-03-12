#include <bits/stdc++.h>

using namespace std;

#define llong long long int

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

int N;
vector<vector<int>> tree;
vector<int> depth, nodes;
FenwickTree cnt;

void get_depth_and_nodes(int node = 0, int parent = -1) {
    nodes[node] = 1;
    for (int child: tree[node])
        if (child != parent) {
            depth[child] = depth[node] + 1;
            get_depth_and_nodes(child, node);
            nodes[node] += nodes[child];
        }
}

void add(int node, int parent, int v) {
    cnt.add(depth[node], v);
    for (int child: tree[node])
        if (child != parent)
            add(child, node, v);
}

llong count(int dist, int node, int parent) {
    llong ans = cnt.sum(0, min(dist - depth[node], N));
    for (int child: tree[node])
        if (child != parent)
            ans += count(dist, child, node);

    return ans;
}

llong solve(int dist, int node = 0, int parent = -1, bool keep = false) {
    int mx = 0, big = -1;
    for (int child: tree[node])
        if (child != parent && nodes[child] > mx) {
            big = child;
            mx = nodes[child];
        }

    llong ans = 0LL;
    for (int child: tree[node])
        if (child != parent && child != big)
            ans += solve(dist, child, node);

    if (big != -1) ans += solve(dist, big, node, true);

    for (int child: tree[node])
        if (child != parent && child != big) {
            ans += count(dist + 2 * depth[node], child, node);
            add(child, node, 1);
        }

    ans += cnt.sum(depth[node], min(depth[node] + dist, N));

    cnt.add(depth[node], 1);
    if (!keep) add(node, parent, -1);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("awesome.in", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int L, R;
        cin >> N >> L >> R;

        tree.assign(N, vector<int>());
        for (int i = 1; i < N; i++) {
            int X, Y;
            cin >> X >> Y;

            tree[X - 1].push_back(Y - 1);
            tree[Y - 1].push_back(X - 1);
        }

        nodes.resize(N);
        depth.assign(N, 0);
        get_depth_and_nodes();

        cnt = FenwickTree(N);
        llong ans = solve(N - L - 1);
        assert(cnt.sum(0, N) == 0);
        ans -= solve(N - R - 2);

        cout << ans << "\n";
    }
}