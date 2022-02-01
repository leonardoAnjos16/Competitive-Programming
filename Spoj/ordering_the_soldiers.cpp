#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    int n;
    vector<int> tree;

public:
    SegmentTree(int n) {
        this->n = n;
        tree.resize(4 * n);
        build(1, 1, n);
    }

    void remove(int i) {
        remove(1, 1, n, i);
    }

    int kth(int k) {
        return kth(1, 1, n, k);
    }

private:
    void build(int node, int l, int r) {
        if (l == r) tree[node] = 1;
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void remove(int node, int l, int r, int i) {
        if (l == r) tree[node] = 0;
        else {
            int m = (l + r) / 2;
            if (i <= m) remove(2 * node, l, m, i);
            else remove(2 * node + 1, m + 1, r, i);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int kth(int node, int l, int r, int k) {
        if (l == r) return l;

        int m = (l + r) / 2;
        if (tree[2 * node] >= k) return kth(2 * node, l, m, k);
        return kth(2 * node + 1, m + 1, r, k - tree[2 * node]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> soldiers(n);
        for (int i = 0; i < n; i++)
            cin >> soldiers[i];

        vector<int> ans(n);
        SegmentTree tree(n);

        for (int i = n - 1; i >= 0; i--) {
            int k = i - soldiers[i] + 1;
            assert(k > 0 && k <= i + 1);
            
            ans[i] = tree.kth(k);
            tree.remove(ans[i]);
        }

        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << ans[i];
        }

        cout << "\n";
    }
}