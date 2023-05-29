#include <bits/stdc++.h>

using namespace std;

#define llong long long int

struct SegmentTree {
private:
    struct Node {
        llong sum;
        Node *left, *right;

        Node(llong sum = 0LL, Node *left = NULL, Node *right = NULL): sum(sum), left(left), right(right) {}
    };

    int n;
    vector<Node*> roots;

public:
    SegmentTree(int n) {
        this->n = n;
        roots.push_back(new Node());
    }

    void update(int l, int r, int v) {
        roots.push_back(update(roots.back(), 1, n, l, r, v));
    }

    llong query(int root, int i) {
        return query(roots[root], 1, n, i);
    }

private:
    Node* update(Node *node, int l, int r, int ul, int ur, int v) {
        if (r < ul || l > ur) return node;
        if (ul <= l && r <= ur) {
            if (!node) return new Node(v);
            return new Node(node->sum + v, node->left, node->right);
        }

        int m = (l + r) / 2;
        Node *left = update(node ? node->left : NULL, l, m, ul, ur, v);
        Node *right = update(node ? node->right : NULL, m + 1, r, ul, ur, v);
        Node *new_node = new Node(node ? node->sum : 0, left, right);

        return new_node;
    }

    llong query(Node *node, int l, int r, int i) {
        if (!node) return 0;
        if (l == r) return node->sum;

        int m = (l + r) / 2;
        if (i <= m) return node->sum + query(node->left, l, m, i);
        return node->sum + query(node->right, m + 1, r, i);
    }
};

int t = 1;
vector<vector<int>> tree;
vector<int> sz, tin, tout;

void flatten(int node) {
    sz[node] = 1;
    tin[node] = t++;

    for (int child: tree[node]) {
        flatten(child);
        sz[node] += sz[child];
    }

    tout[node] = t++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    vector<int> deg(N, 0);
    tree.assign(N, vector<int>());

    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;

        deg[v - 1]++;
        tree[u - 1].push_back(v - 1);
    }

    sz.resize(N);
    tin.resize(N);
    tout.resize(N);

    for (int i = 0; i < N; i++)
        if (!deg[i])
            flatten(i);

    SegmentTree sum(t - 1);
    for (int i = 0; i < Q; i++) {
        int x, b;
        cin >> x >> b;

        sum.update(tin[x - 1], tout[x - 1], b / sz[x - 1]);
        sum.update(tin[x - 1], tin[x - 1], b % sz[x - 1]);
    }

    for (int i = 0; i < N; i++) {
        int l = 1, r = Q, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (sum.query(2 * mid, tin[i]) < a[i]) l = mid + 1;
            else r = mid - 1, ans = mid;
        }

        cout << ans << "\n";
    }
}