#include <bits/stdc++.h>

using namespace std;

#define long long long int

int block_size;

struct Query {
    int l, r, idx;

    Query(int l, int r, int idx): l(l), r(r), idx(idx) {}

    bool operator <(Query other) {
        return make_pair(l / block_size, r) < make_pair(other.l / block_size, other.r);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    block_size = sqrt(n);

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int q; cin >> q;

    vector<Query> queries;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries.emplace_back(l - 1, r - 1, i);
    }

    sort(queries.begin(), queries.end());

    int l = 0, r = -1;
    unordered_map<int, int> cnt;

    vector<int> ans(q);
    for (auto [ql, qr, idx]: queries) {
        while (l > ql) cnt[a[--l]]++;
        while (r < qr) cnt[a[++r]]++;

        while (l < ql) {
            if (!(--cnt[a[l]]))
                cnt.erase(a[l]);

            l++;
        }

        while (r > qr) {
            if (!(--cnt[a[r]]))
                cnt.erase(a[r]);

            r--;
        }

        ans[idx] = cnt.size();
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
}