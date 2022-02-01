#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct SegmentTree {
private:
    const int NOP = -1005;

    int n;
    vector<int> a;
    vector<long> ass, add;
    vector<long> sum, ssum;

public:
    SegmentTree(vector<int> &a, int n) {
        this->n = n;
        this->a = a;

        ass.assign(4 * n, NOP);
        add.assign(4 * n, NOP);
        sum.resize(4 * n);
        ssum.resize(4 * n);

        build(1, 1, n);
    }

    void assignment(int l, int r, long v) {
        assignment(1, 1, n, l, r, v);
    }

    void addition(int l, int r, long v) {
        addition(1, 1, n, l, r, v);
    }

    long query(int l, int r) {
        return query(1, 1, n, l, r);
    }

private:
    void build(int node, int l, int r) {
        if (l == r) sum[node] = a[l], ssum[node] = a[l] * a[l];
        else {
            int m = (l + r) / 2;
            build(2 * node, l, m);
            build(2 * node + 1, m + 1, r);
            sum[node] = sum[2 * node] + sum[2 * node + 1];
            ssum[node] = ssum[2 * node] + ssum[2 * node + 1];
        }
    }

    void update_ass(int node, int l, int r, long v) {
        sum[node] = v * (r - l + 1LL);
        ssum[node] = v * v * (r - l + 1LL);
        add[node] = NOP;
        ass[node] = v;
    }

    void update_add(int node, int l, int r, long v) {
        ssum[node] += 2LL * v * sum[node] + v * v * (r - l + 1LL);
        sum[node] += v * (r - l + 1LL);

        if (add[node] == NOP) add[node] = v;
        else add[node] += v;
    }

    void push_down(int node, int l, int r) {
        int m = (l + r) / 2;
        if (ass[node] != NOP) {
            update_ass(2 * node, l, m, ass[node]);
            update_ass(2 * node + 1, m + 1, r, ass[node]);
        }

        if (add[node] != NOP) {
            update_add(2 * node, l, m, add[node]);
            update_add(2 * node + 1, m + 1, r, add[node]);
        }

        ass[node] = add[node] = NOP;
    }

    void assignment(int node, int l, int r, int ul, int ur, long v) {
        if (r < ul || l > ur) return;
        if (ul <= l && r <= ur) {
            update_ass(node, l, r, v);
            return;
        }

        push_down(node, l, r);

        int m = (l + r) / 2;
        assignment(2 * node, l, m, ul, ur, v);
        assignment(2 * node + 1, m + 1, r, ul, ur, v);
        sum[node] = sum[2 * node] + sum[2 * node + 1];
        ssum[node] = ssum[2 * node] + ssum[2 * node + 1];
    }

    void addition(int node, int l, int r, int ul, int ur, long v) {
        if (r < ul || l > ur) return;
        if (ul <= l && r <= ur) {
            update_add(node, l, r, v);
            return;
        }

        push_down(node, l, r);

        int m = (l + r) / 2;
        addition(2 * node, l, m, ul, ur, v);
        addition(2 * node + 1, m + 1, r, ul, ur, v);
        sum[node] = sum[2 * node] + sum[2 * node + 1];
        ssum[node] = ssum[2 * node] + ssum[2 * node + 1];
    }

    long query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0LL;
        if (ql <= l && r <= qr) return ssum[node];

        push_down(node, l, r);

        int m = (l + r) / 2;
        long left = query(2 * node, l, m, ql, qr);
        long right = query(2 * node + 1, m + 1, r, ql, qr);
        return left + right;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, Q;
        cin >> N >> Q;

        vector<int> a(N + 1);
        for (int i = 1; i <= N; i++)
            cin >> a[i];

        SegmentTree tree(a, N);
        cout << "Case " << t << ":\n";

        while (Q--) {
            int op, st, nd;
            cin >> op >> st >> nd;

            if (!op) {
                int x; cin >> x;
                tree.assignment(st, nd, x);
            } else if (op == 1) {
                int x; cin >> x;
                tree.addition(st, nd, x);
            } else {
                long ans = tree.query(st, nd);
                cout << ans << "\n";
            }
        }
    }
}