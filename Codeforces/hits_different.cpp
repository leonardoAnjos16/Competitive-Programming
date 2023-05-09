#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e6 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int idx = 1, nrow[MAX], ncol[MAX];
    vector<vector<llong>> ps(1, vector<llong>(1, 0LL));

    while (idx < MAX) {
        vector<llong> row(1, 0LL);
        while (idx < MAX && (int) row.size() < (int) ps.back().size() + 1) {
            nrow[idx] = ps.size();
            ncol[idx] = row.size();
            row.push_back(row.back() + 1LL * idx * idx);
            idx++;
        }

        ps.push_back(row);
    }

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        llong ans = 0LL;
        int row = nrow[n], l = ncol[n], r = ncol[n];

        while (row) {
            ans += ps[row][r] - ps[row][l - 1];
            l = max(l - 1, 1);
            r = min(r, (int) ps[--row].size() - 1);
        }

        cout << ans << "\n";
    }
}