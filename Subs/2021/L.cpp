#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int LOG = 20;
const int MOD = 1e9 + 7;

struct DSU {
private:
    int n;
    vector<int> ds, sz;

public:
    DSU() {}
    DSU(int n) {
        this->n = n;
        sz.assign(n, 1);

        ds.resize(n);
        iota(ds.begin(), ds.end(), 0);
    }

    int find(int i) {
        if (ds[i] == i) return i;
        return ds[i] = find(ds[i]);
    }

    void join(int i, int j) {
        i = find(i); j = find(j);
        if (sz[i] > sz[j]) swap(i, j);
        if (i != j) sz[j] += sz[i];
        ds[i] = j;
    }
};

DSU ds[LOG];

void update(int i, int l1, int r1, int l2, int r2, int N) {
    if (ds[i].find(l1) == ds[i].find(i ? l2 : 2 * N - l2 - 1)) return;
    ds[i].join(l1, i ? l2 : 2 * N - l2 - 1);

    if (i) {
        int m1 = (l1 + r1) / 2;
        int m2 = (l2 + r2) / 2;

        update(i - 1, l1, m1, l2, m2, N);
        update(i - 1, m1 + 1, r1, m2 + 1, r2, N);
    }
}

void update(int l1, int r1, int l2, int r2, int N) {
    int idx = __lg(r1 - l1 + 1);
    int nl1 = l1 + (1 << idx);
    int nl2 = l2 + (1 << idx);

    update(idx, l1, nl1 - 1, l2, nl2 - 1, N);
    if (nl1 < r1) update(nl1, r1, nl2, r2, N);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    string s; cin >> s;

    ds[0] = DSU(N);
    for (int i = 1; i < LOG; i++)
        ds[i] = DSU(2 * N);

    for (int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;
        update(l - 1, r - 1, 2 * N - r, 2 * N - l, N);
    }

    vector<vector<int>> groups(N, vector<int>());
    for (int i = 0; i < N; i++)
        groups[ds[0].find(i)].push_back(i);

    int ans = 1;
    for (int i = 0; i < N; i++) {
        if (groups[i].empty()) continue;

        bool zero = false, one = false, unknown = false;
        for (int j: groups[i]) {
            if (s[j] == '0') zero = true;
            else if (s[j] == '1') one = true;
            else unknown = true;
        }

        if (zero && one) ans = 0;
        else if (!zero && !one) ans = (2LL * ans) % MOD;
    }

    cout << ans << "\n";
}