#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    struct Node {
        long sum;
        Node *left, *right;

        Node(long sum): sum(sum), left(nullptr), right(nullptr) {}
        Node(Node *left, Node *right): left(left), right(right) {
            sum = 0LL;
            if (left) sum += left->sum;
            if (right) sum += right->sum;
        }
    };

    int n;
    vector<int> a;
    vector<Node*> roots;

public:
    SegmentTree(int n, vector<int> &a) {
        this->n = n;
        roots.push_back(build(1, n));

        map<int, vector<int>> positions;
        for (int i = 0; i < n; i++)
            positions[a[i]].push_back(i + 1);

        for (auto [value, pos]: positions)
            for (auto p: pos) update(p, value);

        sort(a.begin(), a.end());

        int l = 0, r = 0;
        while (r < n) {
            while (r + 1 < n && a[r + 1] == a[r]) r++;
            a[l] = a[r]; roots[l + 1] = roots[r + 1];
            l++; r++;
        }

        a.erase(a.begin() + l, a.end());
        roots.erase(roots.begin() + l + 1, roots.end());

        this->a = a;
    }

    void update(int i, int v) {
        roots.push_back(update(roots.back(), 1, n, i, v));
    }

    long query(int l, int r, long d) {
        long ans = -1LL;
        int lo = 0, hi = roots.size() - 1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            long aux = query(roots[mid], 1, n, l, r);
            
            if (aux > d) hi = mid - 1;
            else ans = aux, lo = mid + 1;
        }

        return ans;
    }

private:
    Node *build(int l, int r) {
        if (l == r) return new Node(0LL);

        int mid = (l + r) / 2;
        Node *left = build(l, mid);
        Node *right = build(mid + 1, r);
        return new Node(left, right);
    }

    Node *update(Node *node, int l, int r, int i, int v) {
        if (l == r) return new Node(v);

        int mid = (l + r) / 2;
        if (i <= mid) return new Node(update(node->left, l, mid, i, v), node->right);
        return new Node(node->left, update(node->right, mid + 1, r, i, v));
    }

    long query(Node *node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0LL;
        if (ql <= l && r <= qr) return node->sum;

        int mid = (l + r) / 2;
        return query(node->left, l, mid, ql, qr) + query(node->right, mid + 1, r, ql, qr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long ans = 0LL;
    SegmentTree tree(n, a);

    while (q--) {
        int x, y; long z;
        cin >> x >> y >> z;

        int l = 1 + (x + ans - 1) % n;
        int r = 1 + (y + ans - 1) % n;
        long d = z + ans;

        ans = tree.query(l, r, d);
        cout << ans << "\n";
    }
}