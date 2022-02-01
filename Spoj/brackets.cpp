#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    struct Node {
        int left, right;

        Node(): left(0), right(0) {}
        Node(char c): left(c == ')'), right(c == '(') {}
        Node(int left, int right): left(left), right(right) {}

        Node operator +(Node other) {
            int new_left = left + max(other.left - right, 0);
            int new_right = other.right + max(right - other.left, 0);
            return Node(new_left, new_right);
        }
    };

    int n;
    string s;
    vector<Node> tree;

public:
    SegmentTree(string &s, int n) {
        this->n = n;
        this->s = s;
        tree.resize(4 * n);
        build(1, 1, n);
    }

    void update(int i) {
        update(1, 1, n, i);
    }

    bool query() {
        return !tree[1].left && !tree[1].right;
    }

private:
    void build(int node, int l, int r) {
        if (l == r) tree[node] = Node(s[l - 1]);
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void update(int node, int l, int r, int i) {
        if (l == r) tree[node] = Node(s[i - 1] = s[i - 1] == '(' ? ')' : '(');
        else {
            int m = (l + r) / 2;
            if (i <= m) update(2 * node, l, m, i);
            else update(2 * node + 1, m + 1, r, i);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, num_cases = 0;
    while (cin >> n) {
        cout << "Test " << ++num_cases << ":\n";
        string s; cin >> s;

        int m; cin >> m;
        SegmentTree tree(s, n);

        while (m--) {
            int k; cin >> k;
            if (k) tree.update(k);
            else {
                bool valid = tree.query();
                cout << (valid ? "YES" : "NO") << "\n";
            }
        }
    }
}