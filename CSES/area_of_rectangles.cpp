#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e6 + 5;

struct SegmentTree {
private:
    int n;
    vector<int> mn, cnt;
    vector<int> lazy;

public:
    SegmentTree(int n) {
        this->n = n;

        mn.assign(4 * n, 0);
        cnt.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        build(1, 1, n);
    }

    void update(int l, int r, int v) {
        update(1, 1, n, l, r, v);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void build(int node, int l, int r) {
        if (l == r) cnt[node] = 1;
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            cnt[node] = cnt[2 * node] + cnt[2 * node + 1];
        }
    }

    void update_lazy(int node, int v) {
        mn[node] += v;
        lazy[node] += v;
    }

    void push_down(int node) {
        update_lazy(2 * node, lazy[node]);
        update_lazy(2 * node + 1, lazy[node]);
        lazy[node] = 0;
    }

    void update(int node, int l, int r, int ul, int ur, int v) {
        if (ur < l || ul > r) return;
        if (ul <= l && r <= ur) {
            update_lazy(node, v);
            return;
        }

        push_down(node);

        int m = (l + r) / 2;
        update(2 * node, l, m, ul, ur, v);
        update(2 * node + 1, m + 1, r, ul, ur, v);

        mn[node] = min(mn[2 * node], mn[2 * node + 1]);
        if (mn[2 * node] == mn[2 * node + 1]) cnt[node] = cnt[2 * node] + cnt[2 * node + 1];
        else if (mn[2 * node] < mn[2 * node + 1]) cnt[node] = cnt[2 * node];
        else cnt[node] = cnt[2 * node + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) {
            int ans = r - l + 1;
            if (!mn[node]) ans -= cnt[node];

            return ans;
        }

        push_down(node);

        int m = (l + r) / 2;
        return query(2 * node, l, m, ql, qr) + query(2 * node + 1, m + 1, r, ql, qr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<tuple<int, int, int, int>> events(2 * n);
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        events[2 * i] = make_tuple(x1, MAX + y1, MAX + y2, 1);
        events[2 * i + 1] = make_tuple(x2, MAX + y1, MAX + y2, -1);
    }

    sort(events.begin(), events.end());

    int last_x = 0;
    llong ans = 0LL;
    SegmentTree tree(2 * MAX);

    for (auto [x, y1, y2, v]: events) {
        int sum = tree.query(1, 2 * MAX);
        ans += 1LL * (x - last_x) * sum;
        tree.update(y1, y2 - 1, v);
        last_x = x;
    }

    cout << ans << "\n";
}