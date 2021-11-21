#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e6 + 5;

int block_size;

struct Query {
    int l, r, idx;

    Query(int l, int r, int idx) {
        this->l = l;
        this->r = r;
        this->idx = idx;
    }

    bool operator <(Query other) {
        return make_pair(l / block_size, r) < make_pair(other.l / block_size, other.r);
    }
};

long mult(int *cnt, int v) {
    return 1LL * cnt[v] * cnt[v] * v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    block_size = sqrt(n);

    vector<Query> queries;
    for (int i = 0; i < t; i++) {
        int l, r;
        cin >> l >> r;
        queries.emplace_back(l - 1, r - 1, i);
    }

    sort(queries.begin(), queries.end());

    long sum = 0LL;
    int l = 0, r = -1;
    int cnt[MAX] = {0};

    vector<long> ans(t);
    for (auto [ql, qr, idx]: queries) {
        while (l > ql) {
            l--;
            sum -= mult(cnt, a[l]);
            cnt[a[l]]++;
            sum += mult(cnt, a[l]);
        }

        while (r < qr) {
            r++;
            sum -= mult(cnt, a[r]);
            cnt[a[r]]++;
            sum += mult(cnt, a[r]);
        }

        while (l < ql) {
            sum -= mult(cnt, a[l]);
            cnt[a[l]]--;
            sum += mult(cnt, a[l]);
            l++;
        }

        while (r > qr) {
            sum -= mult(cnt, a[r]);
            cnt[a[r]]--;
            sum += mult(cnt, a[r]);
            r--;
        }

        ans[idx] = sum;
    }

    for (int i = 0; i < t; i++)
        cout << ans[i] << "\n";
}