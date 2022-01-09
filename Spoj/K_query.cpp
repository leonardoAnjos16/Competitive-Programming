#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    struct Node {
        int zeroes;
        Node *left, *right;

        Node(int zeroes): zeroes(zeroes), left(nullptr), right(nullptr) {}
        Node(Node *left, Node *right): left(left), right(right) {
            zeroes = 0;
            if (left) zeroes += left->zeroes;
            if (right) zeroes += right->zeroes;
        }
    };

    int n;
    vector<int> a;
    vector<Node*> roots;

public:
    SegmentTree(int n, vector<int> &a) {
        this->n = n;
        roots.push_back(build(1, n));

        map<int, vector<int>> pos;
        for (int i = 0; i < n; i++)
            pos[a[i]].push_back(i + 1);

        for (auto [value, positions]: pos)
            for (auto p: positions)
                update(p);

        sort(a.begin(), a.end());
        this->a = a;
    }

    void update(int i) {
        roots.push_back(update(roots.back(), 1, n, i));
    }

    int query(int l, int r, int k) {
        int idx = upper_bound(a.begin(), a.end(), k) - a.begin();
        return query(roots[idx], 1, n, l, r);
    }

private:
    Node *build(int l, int r) {
        if (l == r) return new Node(1);

        int mid = (l + r) / 2;
        Node *left = build(l, mid);
        Node *right = build(mid + 1, r);
        return new Node(left, right);
    }

    Node *update(Node *node, int l, int r, int i) {
        if (l == r) return new Node(node->zeroes - 1);

        int mid = (l + r) / 2;
        if (i <= mid) return new Node(update(node->left, l, mid, i), node->right);
        return new Node(node->left, update(node->right, mid + 1, r, i));
    }

    int query(Node *node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) return node->zeroes;

        int mid = (l + r) / 2;
        return query(node->left, l, mid, ql, qr) + query(node->right, mid + 1, r, ql, qr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int q; cin >> q;
    SegmentTree tree(n, a);

    while (q--) {
        int i, j, k;
        cin >> i >> j >> k;

        int ans = tree.query(i, j, k);
        cout << ans << "\n";
    }
}