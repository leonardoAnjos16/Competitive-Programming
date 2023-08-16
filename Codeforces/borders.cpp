#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 4e5 + 5;

struct SegmentTree {
private:
    struct Node {
        int mx;
        llong sum;

        Node(int mx = 0, llong sum = 0LL): mx(mx), sum(sum) {}

        Node operator +(Node other) {
            return Node(max(mx, other.mx), sum + other.sum);
        }
    };

    int n;
    vector<Node> tree;
    vector<int> lazy;

public:
    SegmentTree(int n) {
        this->n = n;
        tree.resize(4 * n);
        lazy.assign(4 * n, -1);
    }

    llong sum(int l, int r) {
        return sum(1, 1, n, l, r);
    }

    int upper_bound(int l, int r, int v) {
        return upper_bound(1, 1, n, l, r, v);
    }

    void update(int l, int r, int v) {
        update(1, 1, n, l, r, v);
    }

private:
    void update_lazy(int node, int l, int r, int v) {
        tree[node].sum = v * (r - l + 1LL);
        tree[node].mx = lazy[node] = v;
    }

    void push_down(int node, int l, int r) {
        if (lazy[node] == -1) return;

        int m = (l + r) / 2;
        update_lazy(2 * node, l, m, lazy[node]);
        update_lazy(2 * node + 1, m + 1, r, lazy[node]);
        lazy[node] = -1;
    }

    llong sum(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0LL;
        if (ql <= l && r <= qr) return tree[node].sum;

        push_down(node, l, r);

        int m = (l + r) / 2;
        return sum(2 * node, l, m, ql, qr) + sum(2 * node + 1, m + 1, r, ql, qr);
    }

    int upper_bound(int node, int l, int r, int ql, int qr, int v) {
        if (l == r) return tree[node].mx > v ? l : l + 1;

        push_down(node, l, r);

        int m = (l + r) / 2;
        if (tree[2 * node].mx > v)
            return upper_bound(2 * node, l, m, ql, qr, v);

        return upper_bound(2 * node + 1, m + 1, r, ql, qr, v);
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
};

struct SuffixArray {
private:
    const int SEP = 300;

    int n, sep, text[MAX];
    vector<int> p, c, lcp;

public:
    SuffixArray(): n(0), sep(SEP) {}

    void add(string &s) {
        if (n) text[n++] = sep++;
        for (char c: s) text[n++] = c;
    }

    void build() {
        text[n++] = 0;

        p.resize(n);
        c.resize(n);

        for (int i = 0; i < n; i++) {
            p[i] = i;
            c[i] = text[i];
        }

        sort();
        get_classes(0);

        for (int len = 1; c[p[n - 1]] + 1 < n; len <<= 1) {
            for (int i = 0; i < n; i++) {
                p[i] -= len;
                p[i] = (p[i] % n + n) % n;
            }

            sort();
            get_classes(len);
        }

        build_lcp();
    }

    llong count_borders() {
        llong ans = 0LL;
        SegmentTree tree(n);

        for (int i = 1; i < n; i++) {
            ans += n - p[i] - 1;
            ans += tree.sum(1, n);

            int idx = min(tree.upper_bound(1, i, lcp[i]), i);
            tree.update(idx, i, lcp[i]);
        }

        return ans;
    }

private:
    void sort() {
        int mx = *max_element(c.begin(), c.end());
        vector<int> cnt(mx + 1, 0);

        for (int i = 0; i < n; i++)
            cnt[c[p[i]]]++;

        for (int i = 1; i <= mx; i++)
            cnt[i] += cnt[i - 1];

        vector<int> np(n);
        for (int i = n - 1; i >= 0; i--)
            np[--cnt[c[p[i]]]] = p[i];

        p.swap(np);
    }

    void get_classes(int len) {
        vector<int> nc(n, 0);
        for (int i = 1; i < n; i++)
            nc[p[i]] = c[p[i]] == c[p[i - 1]] && c[(p[i] + len) % n] == c[(p[i - 1] + len) % n] ? nc[p[i - 1]] : nc[p[i - 1]] + 1;

        c.swap(nc);
    }

    void build_lcp() {
        int pref = 0;
        lcp.assign(n - 1, 0);

        for (int i = 0; i < n; i++) {
            if (c[i] + 1 >= n) {
                pref = 0;
                continue;
            }

            int nxt = p[c[i] + 1];
            while (text[i + pref] == text[nxt + pref]) pref++;

            lcp[c[i]] = pref;
            if (pref) pref--;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;

    SuffixArray solver;
    solver.add(s);
    solver.build();

    llong ans = solver.count_borders();
    cout << ans << "\n";
}