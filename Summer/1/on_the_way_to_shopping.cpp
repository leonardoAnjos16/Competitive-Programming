#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e9 + 5;

struct SegmentTree {
private:
    struct Node {
        llong sum;
        Node *left, *right;

        Node(llong sum): sum(sum), left(NULL), right(NULL) {}
    };

    int mn, mx;
    vector<Node*> roots;

public:
    SegmentTree(int mn, int mx) {
        this->mn = mn;
        this->mx = mx;

        Node *root = new Node(0LL);
        roots.push_back(root);
    }

    void update(int i, int v) {
        roots.push_back(update(roots.back(), mn, mx, i, v));
    }

    llong query(int i, int l, int r) {
        return query(roots[i], mn, mx, l, r);
    }

private:
    Node* update(Node *node, int l, int r, int i, int v) {
        llong sum = node ? node->sum : 0LL;
        Node *new_node = new Node(sum + v);

        if (l == r) return new_node;

        int m = (l + r) / 2;
        if (i <= m) {
            new_node->left = update(node ? node->left : NULL, l, m, i, v);
            if (node) new_node->right = node->right;
        } else {
            if (node) new_node->left = node->left;
            new_node->right = update(node ? node->right : NULL, m + 1, r, i, v);
        }

        return new_node;
    }

    llong query(Node *node, int l, int r, int ql, int qr) {
        if (!node || r < ql || l > qr) return 0LL;
        if (ql <= l && r <= qr) return node->sum;

        int m = (l + r) / 2;
        return query(node->left, l, m, ql, qr) + query(node->right, m + 1, r, ql, qr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    SegmentTree tree(0, MAX);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        tree.update(a, a);
    }

    llong ans = 0LL;
    while (q--) {
        int x, y; llong z;
        cin >> x >> y >> z;

        int l = (x + ans - 1LL) % n + 1;
        int r = (y + ans - 1LL) % n + 1;
        llong d = z + ans;

        int lo = 0, hi = MAX;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            llong sum = tree.query(r, 0, mid);
            sum -= tree.query(l - 1, 0, mid);

            if (sum > d) hi = mid - 1;
            else lo = mid + 1, ans = sum;
        }

        cout << ans << "\n";
    }
}