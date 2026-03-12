#include <bits/stdc++.h>

using namespace std;

#define llong long long int

struct SegmentTree {
private:
    struct Node {
        int odd, lazy;
        Node *left, *right;

        Node(): odd(0), lazy(0), left(NULL), right(NULL) {}
        Node(int odd, int lazy, Node *left = NULL, Node *right = NULL): odd(odd), lazy(lazy), left(left), right(right) {}
    };

    int mn, mx;
    Node *root;

public:
    SegmentTree(int mn, int mx) {
        this->mn = mn;
        this->mx = mx;
        root = new Node();
    }

    void update(int l, int r, int v) {
        root = update(root, mn, mx, l, r, v);
    }

    int query(int l, int r) {
        return query(root, mn, mx, l, r);
    }

private:
    Node* update_lazy(Node *node, int l, int r, int v) {
        if (!node) return new Node(abs(v) & 1 ? r - l + 1 : 0, v);

        node->lazy += v;
        if (abs(v) & 1)
            node->odd = r - l - node->odd + 1;

        return node;
    }

    void push_down(Node *node, int l, int r) {
        int m = (l + r) / 2;
        node->left = update_lazy(node->left, l, m, node->lazy);
        node->right = update_lazy(node->right, m + 1, r, node->lazy);
        node->lazy = 0;
    }

    Node* update(Node *node, int l, int r, int ul, int ur, int v) {
        if (r < ul || l > ur) return node;
        if (ul <= l && r <= ur) return update_lazy(node, l, r, v);
        if (!node) return new Node(abs(v) & 1 ? r - l + 1 : 0, v);

        push_down(node, l, r);

        int m = (l + r) / 2;
        node->left = update(node->left, l, m, ul, ur, v);
        node->right = update(node->right, m + 1, r, ul, ur, v);
        node->odd = (node->left ? node->left->odd : 0) + (node->right ? node->right->odd : 0);
        return node;
    }

    int query(Node *node, int l, int r, int ql, int qr) {
        if (!node || r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) return node->odd;

        push_down(node, l, r);

        int m = (l + r) / 2;
        return query(node->left, l, m, ql, qr) + query(node->right, m + 1, r, ql, qr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int mn = INT_MAX, mx = INT_MIN;
    vector<tuple<int, int, int, int>> events;

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);

        mn = min(mn, y1);
        mx = max(mx, y2 - 1);

        events.emplace_back(x1, y1, y2, 1);
        events.emplace_back(x2, y1, y2, -1);
    }

    sort(events.begin(), events.end());

    llong ans = 0LL;
    int last = get<0>(events[0]);
    SegmentTree tree(mn, mx);

    for (auto [x, y1, y2, v]: events) {
        int odd = tree.query(mn, mx);
        ans += 1LL * odd * (x - last);
        tree.update(y1, y2 - 1, v);
        last = x;
    }

    cout << ans << "\n";
}