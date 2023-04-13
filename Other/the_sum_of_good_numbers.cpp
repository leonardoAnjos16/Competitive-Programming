#include <bits/stdc++.h>

using namespace std;

#define llong long long int

struct RabinKarp {
private:
    string s;
    int n, base, mod;
    vector<llong> p, h;

public:
    RabinKarp(string &s, int base = 10, int mod = 1e9 + 7) {
        this->s = s;
        this->n = s.size();

        this->base = base;
        this->mod = mod;

        build();
    }

    int hash(int l, int r) {
        if (!l) return h[r];
        return (h[r] - ((h[l - 1] * p[r - l + 1]) % mod) + mod) % mod;
    }

    int sum(int l1, int r1, int l2, int r2) {
        return (hash(l1, r1) + hash(l2, r2)) % mod;
    }

private:
    void build() {
        p.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
            p[i] = (p[i - 1] * base) % mod;

        h.assign(n, s[0] - '0');
        for (int i = 1; i < n; i++)
            h[i] = (h[i - 1] * base + s[i] - '0') % mod;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, x;
    cin >> s >> x;

    RabinKarp shasher(s), xhasher(x);

    int m = s.size(), n = x.size();
    int l1 = -1, r1 = -1, l2 = -1, r2 = -1;

    for (int rb = n - 2; rb < m; rb++) {
        int lb = rb - n + 2, rs = lb - 1, ls = rs - n + 2;
        if (ls >= 0 && shasher.sum(ls, rs, lb, rb) == xhasher.hash(0, n - 1))
            l1 = ls, r1 = rs, l2 = lb, r2 = rb;

        ls = rb + 1;
        rs = ls + n - 2;

        if (rs < m && shasher.sum(lb, rb, ls, rs) == xhasher.hash(0, n - 1))
            l1 = lb, r1 = rb, l2 = ls, r2 = rs;

        if (rb + 1 >= n) {
            lb = rb - n + 1;
            int lo = 1, hi = n, lcp = 0;

            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (shasher.hash(lb, lb + mid - 1) != xhasher.hash(0, mid - 1)) hi = mid - 1;
                else lo = mid + 1, lcp = mid;
            }

            if (lcp < n) {
                rs = lb - 1;
                ls = rs - (n - lcp) + 1;

                if (ls >= 0 && shasher.sum(ls, rs, lb, rb) == xhasher.hash(0, n - 1))
                    l1 = ls, r1 = rs, l2 = lb, r2 = rb;

                ls = rb + 1;
                rs = ls + n - lcp - 1;

                if (rs < m && shasher.sum(lb, rb, ls, rs) == xhasher.hash(0, n - 1))
                    l1 = lb, r1 = rb, l2 = ls, r2 = rs;
            }

            if (lcp + 1 < n) {
                rs = lb - 1;
                ls = rs - (n - lcp - 1) + 1;

                if (ls >= 0 && shasher.sum(ls, rs, lb, rb) == xhasher.hash(0, n - 1))
                    l1 = ls, r1 = rs, l2 = lb, r2 = rb;

                ls = rb + 1;
                rs = ls + n - lcp - 2;

                if (rs < m && shasher.sum(lb, rb, ls, rs) == xhasher.hash(0, n - 1))
                    l1 = lb, r1 = rb, l2 = ls, r2 = rs;
            }
        }
    }

    assert(l1 != -1 && r1 != -1 && l2 != -1 && r2 != -1);

    cout << ++l1 << " " << ++r1 << "\n";
    cout << ++l2 << " " << ++r2 << "\n";
}