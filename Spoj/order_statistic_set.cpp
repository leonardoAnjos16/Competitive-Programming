#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int INVALID = 1e9 + 5;

struct SegmentTree {
private:
    int n;
    vector<int> a;
    vector<int> tree;

public:
    SegmentTree(vector<int> &a, int n) {
        this->n = n;
        this->a = a;
        tree.assign(4 * n, 0);
    }

    void add(int x) {
        update(1, 1, n, index(x), 1);
    }

    void remove(int x) {
        update(1, 1, n, index(x), -1);
    }

    int kth(int k) {
        if (tree[1] < k) return INVALID;
        return a[kth(1, 1, n, k) - 1];
    }

    int count(int x) {
        int i = index(x);
        if (i == 1) return 0;
        return count(1, 1, n, i - 1);
    }

private:
    int index(int x) {
        return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
    }

    void update(int node, int l, int r, int i, int v) {
        if (l == r) tree[node] = v < 0 ? max(tree[node] + v, 0) : min(tree[node] + v, 1);
        else {
            int m = (l + r) / 2;
            if (i <= m) update(2 * node, l, m, i, v);
            else update(2 * node + 1, m + 1, r, i, v);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int kth(int node, int l, int r, int k) {
        if (l == r) return l;

        int m = (l + r) / 2;
        if (tree[2 * node] >= k) return kth(2 * node, l, m, k);
        return kth(2 * node + 1, m + 1, r, k - tree[2 * node]);
    }

    int count(int node, int l, int r, int i) {
        if (r <= i) return tree[node];

        int m = (l + r) / 2;
        int left = count(2 * node, l, m, i);
        if (i <= m) return left;

        int right = count(2 * node + 1, m + 1, r, i);
        return left + right;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q; cin >> Q;

    vector<int> numbers;
    vector<pair<char, int>> queries(Q);

    for (int i = 0; i < Q; i++) {
        char c; cin >> c;
        queries[i].first = c;

        if (c == 'I') {
            int x; cin >> x;
            numbers.push_back(x);
            queries[i].second = x;
        } else if (c == 'D') {
            int x; cin >> x;
            numbers.push_back(x);
            queries[i].second = x;
        } else if (c == 'K') {
            int k; cin >> k;
            queries[i].second = k;
        } else {
            int x; cin >> x;
            numbers.push_back(x);
            queries[i].second = x;
        }
    }

    sort(numbers.begin(), numbers.end());
    numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());

    int n = numbers.size();
    SegmentTree tree(numbers, n);

    for (int i = 0; i < Q; i++) {
        if (queries[i].first == 'I') tree.add(queries[i].second);
        else if (queries[i].first == 'D') tree.remove(queries[i].second);
        else if (queries[i].first == 'K') {
            int ans = tree.kth(queries[i].second);
            if (ans == INVALID) cout << "invalid\n";
            else cout << ans << "\n";
        } else {
            int ans = tree.count(queries[i].second);
            cout << ans << "\n";
        }
    }
}