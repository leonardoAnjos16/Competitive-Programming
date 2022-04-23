#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct FenwickTree {
private:
    int n;
    vector<int> tree;

public:
    FenwickTree(int n) {
        this->n = n + 1;
        tree.assign(n + 1, 0);
    }

    void add(int i, int v) {
        if (!i) tree[0] += v;
        else {
            while (i < n) {
                tree[i] += v;
                i += LSO(i);
            }
        }
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

private:
    int LSO(int i) {
        return i & -i;
    }

    int sum(int i) {
        if (i < 0) return 0;

        int ans = tree[0];
        while (i) {
            ans += tree[i];
            i -= LSO(i);
        }

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long k; int h, q;
    cin >> k >> h >> q;

    vector<long> edges;
    vector<tuple<int, long, long>> queries;

    while (q--) {
        int op; long i, j;
        cin >> op >> i >> j;

        edges.push_back(i);
        edges.push_back(j);

        if (i > j) swap(i, j);
        queries.emplace_back(op, i, j);
    }

    sort(edges.begin(), edges.end());
    edges.erase(unique(edges.begin(), edges.end()), edges.end());

    int n = edges.size();
    FenwickTree tree(n);

    for (auto edge: edges) {
        int i = lower_bound(edges.begin(), edges.end(), edge) - edges.begin();
        tree.add(i, 1);
    }

    for (auto [op, i, j]: queries) {
        int l = lower_bound(edges.begin(), edges.end(), i) - edges.begin();
        int r = lower_bound(edges.begin(), edges.end(), j) - edges.begin();

        if (op == 1) {
            long forward = tree.sum(l, r - 1) == r - l ? j - i : LLONG_MAX;

            long backward = LLONG_MAX;
            if ((l == 0 || tree.sum(0, l - 1) == l) && tree.sum(r, n - 1) == n - r)
                backward = i + k - j;

            long ans = min(forward, backward);
            if (ans == LLONG_MAX) cout << "-1\n";
            else cout << ans << "\n";
        } else {
            if (i == 0 && j == k - 1) swap(l, r);
            tree.add(l, op == 2 ? -1 : 1);
        }
    }
}