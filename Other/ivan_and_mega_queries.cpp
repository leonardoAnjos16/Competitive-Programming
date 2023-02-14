#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int LOG = 25;

struct SparseTable {
private:
    int n;
    vector<vector<int>> mx;

public:
    SparseTable(int n, vector<int> &a) {
        this->n = n;

        mx.assign(LOG, vector<int>(n + 1));
        for (int i = 1; i <= n; i++)
            mx[0][i] = a[i];

        for (int i = 1; i < LOG; i++)
            for (int j = 1; j <= n; j++)
                mx[i][j] = max(mx[i - 1][j], mx[i - 1][min(j + (1 << (i - 1)), n)]);
    }

    int query(int l, int r) {
        int idx = 0;
        while ((1 << (idx + 1)) <= r - l + 1) idx++;
        return max(mx[idx][l], mx[idx][r - (1 << idx) + 1]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    SparseTable table(n, a);

    int q; cin >> q;
    while (q--) {
        int m; cin >> m;

        vector<int> ind(m);
        for (int i = 0; i < m; i++)
            cin >> ind[i];

        int last_mx = -1;
        llong ans = a[ind[0]];

        for (int i = 1; i < m; i++) {
            ans += a[ind[i]];
            int mx = table.query(ind[i - 1], ind[i]);

            int l = 0, r = i - 1, first = -1;
            while (l <= r) {
                int mid = (l + r) / 2;

                if (table.query(ind[mid], ind[i]) > mx) l = mid + 1;
                else r = mid - 1, first = mid;
            }

            l = i; r = m - 1; int last = -1;
            while (l <= r) {
                int mid = (l + r) / 2;

                if (table.query(ind[i - 1], ind[mid]) > mx) r = mid - 1;
                else l = mid + 1, last = mid;
            }

            assert(first != -1 && last != -1);
            if (mx == last_mx) first = i - 1;

            ans += (i - first) * (last - i + 1LL) * mx;
            last_mx = mx;
        }

        cout << ans << "\n";
    }
}