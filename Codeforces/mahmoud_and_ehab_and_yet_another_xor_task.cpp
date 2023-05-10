#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 20;
const int MOD = 1e9 + 7;

int exp(int a, int n) {
    if (!n) return 1;

    int ans = exp(a, n >> 1);
    ans = (1LL * ans * ans) % MOD;

    if (!(n & 1)) return ans;
    return (1LL * ans * a) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<tuple<int, int, int>> queries(q);
    for (int i = 0; i < q; i++) {
        int l, x;
        cin >> l >> x;
        queries[i] = make_tuple(l, x, i);
    }

    sort(queries.begin(), queries.end());

    vector<int> ans(q, 0);
    int basis[MAX] = {0}, sz = 0, processed = 0;

    for (auto [l, x, idx]: queries) {
        while (processed < l) {
            bool done = false;
            for (int i = 0; i < MAX && !done; i++) {
                if (!(a[processed] & (1 << i))) continue;

                if (basis[i]) a[processed] ^= basis[i];
                else basis[i] = a[processed], sz++, done = true;
            }

            processed++;
        }

        bool independent = false;
        for (int i = 0; i < MAX && !independent; i++) {
            if (!(x & (1 << i))) continue;

            if (basis[i]) x ^= basis[i];
            else independent = true;
        }

        if (!independent)
            ans[idx] = exp(2, l - sz);
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
}