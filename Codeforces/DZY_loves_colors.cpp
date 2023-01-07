#include <bits/stdc++.h>

using namespace std;

#define llong long long int

struct SegmentTree {
private:
    int n;
    vector<llong> tree, lazy;

public:
    SegmentTree(int n) {
        this->n = n;
        tree.assign(4 * n, 0LL);
        lazy.assign(4 * n, 0LL);
    }

    void update(int l, int r, int v) {
        update(1, 1, n, l, r, v);
    }

    llong query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void update_lazy(int node, int l, int r, llong v) {
        lazy[node] += v;
        tree[node] += v * (r - l + 1LL);
    }

    void push_down(int node, int l, int r) {
        int m = (l + r) / 2;
        update_lazy(2 * node, l, m, lazy[node]);
        update_lazy(2 * node + 1, m + 1, r, lazy[node]);
        lazy[node] = 0LL;
    }

    void update(int node, int l, int r, int ul, int ur, int v) {
        if (r < ul || l > ur) return;
        if (ul <= l && r <= ur) {
            update_lazy(node, l, r, v);
            return;
        }

        push_down(node, l, r);

        int m = (l + r) / 2;
        update(2 * node, l, m, ul, ur, v);
        update(2 * node + 1, m + 1, r, ul, ur, v);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    llong query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0LL;
        if (ql <= l && r <= qr) return tree[node];

        push_down(node, l, r);

        int m = (l + r) / 2;
        return query(2 * node, l, m, ql, qr) + query(2 * node + 1, m + 1, r, ql, qr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    set<pair<int, int>> intervals;
    for (int i = 1; i <= n; i++)
        intervals.emplace(i, i);

    SegmentTree tree(n);
    while (m--) {
        int type, l, r;
        cin >> type >> l >> r;

        if (type == 1) {
            int x; cin >> x;

            auto begin = intervals.upper_bound(make_pair(l, INT_MAX)); begin--;
            auto end = intervals.upper_bound(make_pair(r, INT_MAX));

            auto it = begin;
            auto [curr_l, color] = *it;

            while (it != end) {
                int curr_r = n + 1, new_color = -1;
                if (++it != intervals.end())
                    tie(curr_r, new_color) = *it;

                tree.update(max(curr_l, l), min(curr_r - 1, r), abs(x - color));
                color = new_color;
                curr_l = curr_r;
            }

            int idx_begin, color_begin;
            tie(idx_begin, color_begin) = *begin;

            int idx_end = n + 1;
            if (end != intervals.end())
                idx_end = end->first;

            int color_end = (--end)->second;
            intervals.erase(begin, ++end);

            intervals.emplace(l, x);
            if (idx_begin < l)
                intervals.emplace(idx_begin, color_begin);

            if (idx_end > r + 1) intervals.emplace(r + 1, color_end);
        } else {
            llong ans = tree.query(l, r);
            cout << ans << "\n";
        }
    }
}