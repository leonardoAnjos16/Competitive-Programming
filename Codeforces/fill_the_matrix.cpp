#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int LOG = 20;

struct SparseTable {
private:
    int n;
    vector<vector<pair<int, int>>> table;

public:
    SparseTable(int n, vector<int> &a) {
        this->n = n;

        table.assign(LOG, vector<pair<int, int>>(n));
        for (int i = 0; i < n; i++)
            table[0][i] = make_pair(a[i], i);

        for (int i = 1; i < LOG; i++)
            for (int j = 0; j < n; j++) {
                int jump = 1 << (i - 1);
                table[i][j] = table[i - 1][j];

                if (j + jump < n)
                    table[i][j] = max(table[i][j], table[i - 1][j + jump]);
            }
    }

    pair<int, int> query(int l, int r) {
        int idx = __lg(r - l + 1), jump = 1 << idx;
        return max(table[idx][l], table[idx][r - jump + 1]);
    }
};

void count(SparseTable &table, vector<llong> &cnt, int row, int l, int r) {
    if (!row || l > r) return;

    auto [mx, idx] = table.query(l, r);
    if (mx < row) {
        int lo = 1, hi = row, rows = 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (table.query(l, r).first >= row - mid) hi = mid - 1;
            else lo = mid + 1, rows = mid;
        }

        cnt[r - l + 1] += rows;
        count(table, cnt, row - rows, l, r);
    } else {
        count(table, cnt, row, l, idx - 1);
        count(table, cnt, row, idx + 1, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        llong m; cin >> m;

        SparseTable table(n, a);
        vector<llong> cnt(n + 1, 0LL);
        count(table, cnt, n, 0, n - 1);

        int sz = n;
        llong ans = m;

        while (m && sz) {
            while (sz && !cnt[sz]) sz--;
            assert(sz);

            if (cnt[sz] * sz >= m) {
                ans -= (m + sz - 1) / sz;
                m = 0LL;
            } else {
                ans -= cnt[sz];
                m -= cnt[sz] * sz;
                cnt[sz] = 0;
            }
        }

        cout << ans << "\n";
    }
}