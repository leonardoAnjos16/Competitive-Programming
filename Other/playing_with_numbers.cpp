#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
private:
    int n;
    string s;
    vector<pair<int, int>> tree;

public:
    SegmentTree(int n, string &s) {
        this->n = n;
        this->s = s;

        tree.resize(4 * n);
        build(1, 1, n);
    }

    pair<int, int> query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    pair<int, int> merge(pair<int, int> left, pair<int, int> right) {
        int first = left.first == -1 ? right.first : (right.first == -1 ? left.first : (s[left.first - 1] <= s[right.first - 1] ? left.first : right.first));
        int second = left.second == -1 ? right.second : (right.second == -1 ? left.second : (s[left.second - 1] >= s[right.second - 1] ? left.second : right.second));
        // cout << first << " " << second << "\n";
        return make_pair(first, second);
    }

    void build(int node, int l, int r) {
        if (l == r) tree[node] = make_pair(l, l);
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            // cout << l << " " << r << ": ";
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    pair<int, int> query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return make_pair(-1, -1);
        if (ql <= l && r <= qr) return tree[node];

        int m = (l + r) / 2;
        pair<int, int> left = query(2 * node, l, m, ql, qr);
        pair<int, int> right = query(2 * node + 1, m + 1, r, ql, qr);
        return merge(left, right);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        string S; int N;
        cin >> S >> N;

        int size = S.size();
        SegmentTree tree(size, S);

        string mn = "";
        int idx = 0, K = N;

        while (K && (int) mn.size() < size - N) {
            int nxt = tree.query(idx + 1, idx + K + 1).first;
            mn += S[nxt - 1];
            K -= nxt - idx - 1;
            idx = nxt;
        }

        if (!K) mn += S.substr(idx);
        cout << mn << "\n";

        string mx = "";
        idx = 0; K = N;

        while (K && (int) mx.size() < size - N) {
            int nxt = tree.query(idx + 1, idx + K + 1).second;
            mx += S[nxt - 1];
            K -= nxt - idx - 1;
            idx = nxt;
        }

        if (!K) mx += S.substr(idx);
        cout << mx << "\n";
    }
}