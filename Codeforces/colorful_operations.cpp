#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct FenwickTree {
private:
    int n;
    vector<long> tree;

public:
    FenwickTree(int n) {
        this->n = n + 1;
        tree.assign(n + 1, 0LL);
    }

    void add(int l, int r, long v) {
        add(l, v);
        add(r + 1, -v);
    }

    long query(int i) {
        long ans = tree[0];
        while (i) {
            ans += tree[i];
            i -= LSO(i);
        }

        return ans;
    }

private:
    int LSO(int i) {
        return i & -i;
    }

    void add(int i, long v) {
        while (i < n) {
            tree[i] += v;
            i += LSO(i);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    FenwickTree tree(n);
    vector<long> lazy(n + 1, 0LL);

    map<int, int> segs;
    segs[1] = 1;

    while (q--) {
        string op; cin >> op;
        if (op == "Color") {
            int l, r, c;
            cin >> l >> r >> c;

            auto it = segs.lower_bound(l);
            if (it == segs.end() || it->first > l) {
                assert(it != segs.begin());
                segs[l] = (--it)->second;
            }

            it = segs.upper_bound(r);
            if (it == segs.end() || it->first > r + 1) {
                assert(it != segs.begin());
                segs[r + 1] = (--it)->second;
            }

            it = segs.upper_bound(r);
            assert(it != segs.end());
            int curr_r = it->first - 1;

            auto begin = segs.lower_bound(l);
            while (it != begin) {
                it--;
                tree.add(it->first, curr_r, lazy[it->second]);
                tree.add(it->first, curr_r, -lazy[c]);
                curr_r = it->first - 1;
            }

            segs.erase(begin, segs.upper_bound(r));
            segs[l] = c;
        } else if (op == "Add") {
            int c, x;
            cin >> c >> x;
            lazy[c] += x;
        } else {
            int i; cin >> i;

            auto it = segs.upper_bound(i);
            assert(it != segs.begin());
            it--;

            long ans = tree.query(i) + lazy[it->second];
            cout << ans << "\n";
        }
    }
}