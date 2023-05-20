#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int SQRT = 300;
const int MAXA = 1e6 + 5;
const int MAXN = 5e4 + 5;

int last_prime[MAXA];

struct Query {
    int l, r, block, idx;

    Query() {}
    Query(int l, int r, int idx): l(l), r(r), block(l / SQRT), idx(idx) {}

    pair<int, int> to_pair() const {
        return make_pair(block, block & 1 ? -r : r);
    }

    bool operator <(Query const &other) const {
        if (to_pair() == other.to_pair())
            return idx < other.idx;

        return to_pair() < other.to_pair();
    }
};

void add(int *freq, int *cnt, int &ans, int x, int v) {
    while (x > 1) {
        int p = last_prime[x];

        cnt[freq[p]]--;
        freq[p] += v;
        cnt[freq[p]]++;

        if (v == -1 && ans == freq[p] + 1 && cnt[freq[p] + 1] == 0) ans--;
        else if (v == 1 && ans == freq[p] - 1) ans++;

        while (last_prime[x] == p)
            x /= p;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i < MAXA; i++)
        last_prime[i] = i;

    for (int i = 2; i * i < MAXA; i++)
        if (last_prime[i] == i)
            for (int j = 2 * i; j < MAXA; j += i)
                last_prime[j] = i;

    int freq[MAXA] = {0};
    int cnt[MAXN] = {0};

    int T; cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<Query> queries(q);
        for (int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;
            queries[i] = Query(l - 1, r - 1, i);
        }

        sort(queries.begin(), queries.end());

        vector<int> ans(q);
        int l = 0, r = -1, last = 0;

        for (auto [ql, qr, _, i]: queries) {
            while (l > ql) add(freq, cnt, last, a[--l], 1);
            while (r < qr) add(freq, cnt, last, a[++r], 1);

            while (l < ql) add(freq, cnt, last, a[l++], -1);
            while (r > qr) add(freq, cnt, last, a[r--], -1);

            ans[i] = last;
        }

        for (int i = 0; i < q; i++)
            cout << ans[i] << "\n";

        while (l <= r) add(freq, cnt, last, a[l++], -1);
    }
}