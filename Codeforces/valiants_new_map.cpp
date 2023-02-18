#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int LOG = 25;

struct SparseTable {
private:
    vector<vector<vector<int>>> table;

public:
    SparseTable(int n, int m, vector<vector<int>> &a) {
        table.assign(LOG, vector<vector<int>>(n, vector<int>(m)));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                table[0][i][j] = a[i][j];

        for (int i = 1; i < LOG; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < m; k++) {
                    int &mn = table[i][j][k];
                    mn = table[i - 1][j][k];

                    int jump = 1 << (i - 1);
                    int nj = j + jump, nk = k + jump;

                    if (nj < n) mn = min(mn, table[i - 1][nj][k]);
                    if (nk < m) mn = min(mn, table[i - 1][j][nk]);
                    if (nj < n && nk < m) mn = min(mn, table[i - 1][nj][nk]);
                }
    }

    int query(int r, int c, int size) {
        int idx = __lg(size);
        int jump = 1 << idx;

        int ans = table[idx][r][c];
        ans = min(ans, table[idx][r + size - jump][c]);
        ans = min(ans, table[idx][r][c + size - jump]);
        ans = min(ans, table[idx][r + size - jump][c + size - jump]);

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];

        SparseTable table(n, m, a);
        int l = 1, r = min(n,  m), ans = -1;

        while (l <= r) {
            int mid = (l + r) / 2;

            bool possible = false;
            for (int i = mid - 1; i < n && !possible; i++)
                for (int j = mid - 1; j < m && !possible; j++)
                    if (table.query(i - mid + 1, j - mid + 1, mid) >= mid)
                        possible = true;

            if (!possible) r = mid - 1;
            else l = mid + 1, ans = mid;
        }

        cout << ans << "\n";
    }
}