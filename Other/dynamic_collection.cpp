#include <bits/stdc++.h>

using namespace std;

#define llong long long int

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
        if (!i) tree[i] += v;
        else {
            while (i < n) {
                tree[i] += v;
                i += LSO(i);
            }
        }
    }

    int upper_bound(int k) {
        int cnt = sum(k);
        int l = k, r = n, ans = n;

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (sum(mid) <= cnt) l = mid + 1;
            else r = mid - 1, ans = mid;
        }

        return ans;
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

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> updates;
    vector<pair<int, int>> queries;
    vector<bool> update(q, false);

    vector<int> order = a;
    for (int i = 0; i < q; i++) {
        int op; cin >> op;
        if (op == 1) {
            int k; cin >> k;

            update[i] = true;
            updates.push_back(k);
            order.push_back(k);
        } else {
            int l, r;
            cin >> l >> r;

            queries.emplace_back(l, r);
            order.push_back(l);
            order.push_back(r);
        }
    }

    sort(order.begin(), order.end());
    order.erase(unique(order.begin(), order.end()), order.end());
    int sz = order.size();

    FenwickTree tree(sz);
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(order.begin(), order.end(), a[i]) - order.begin();
        tree.add(idx, 1);
    }

    int iu = 0, iq = 0;
    for (int i = 0; i < q; i++) {
        if (update[i]) {
            int k = updates[iu++];
            k = lower_bound(order.begin(), order.end(), k) - order.begin();

            if (tree.sum(k, k)) continue;

            int ub = tree.upper_bound(k);
            if (ub < sz) tree.add(ub, -1);
            tree.add(k, 1);
        } else {
            auto [l, r] = queries[iq++];
            l = lower_bound(order.begin(), order.end(), l) - order.begin();
            r = lower_bound(order.begin(), order.end(), r) - order.begin();

            int ans = tree.sum(l, r);
            cout << ans << "\n";
        }
    }
}