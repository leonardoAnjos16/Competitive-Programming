#include <bits/stdc++.h>

using namespace std;

#define long long long int

const long MAX = (1LL << 60) + 5;

struct SegmentTree {
private:
    struct Node {
        long l, r, sum;
        Node *left, *right;

        Node(): l(0LL), r(0LL), sum(0LL), left(nullptr), right(nullptr) {}
        Node(long l, long r, long sum = 0LL) {
            this->l = l;
            this->r = r;
            this->sum = sum;
            left = right = nullptr;
        }
    };

    Node *root;

public:
    SegmentTree() {
        root = new Node(0, MAX);
    }

    void update(long i, long v) {
        update(root, i, v);
    }

    long query(long l, long r) {
        return query(root, l, r);
    }

private:
    void update(Node *node, long i, long v) {
        if (node->l == node->r) node->sum += v;
        else {
            long m = (node->l + node->r) / 2LL;
            if (i <= m) {
                if (!node->left) node->left = new Node(node->l, m);
                update(node->left, i, v);
            } else {
                if (!node->right) node->right = new Node(m + 1, node->r);
                update(node->right, i, v);
            }

            node->sum += v;
        }
    }

    long query(Node *node, long l, long r) {
        if (!node || node->r < l || node->l > r) return 0LL;
        if (l <= node->l && node->r <= r) return node->sum;

        long m = (node->l + node->r) / 2LL;
        return query(node->left, l, r) + query(node->right, l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q; cin >> Q;

    long L = 0LL;
    SegmentTree tree;

    while (Q--) {
        long A, V;
        cin >> A >> V;

        long first = A ^ L;
        tree.update(first, V ^ L);

        long second = tree.query(0, first);
        cout << first << " " << second << "\n";

        L = second;
    }
}