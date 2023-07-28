#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int first = -1, last = -1;
        vector<vector<int>> pos(n, vector<int>());

        for (int i = 0; i < n; i++) {
            int c; cin >> c;

            if (!i) first = c - 1;
            if (i + 1 >= n) last = c - 1;

            pos[c - 1].push_back(i);
        }

        if ((int) pos[first].size() < k || (int) pos[last].size() < k) cout << "NO\n";
        else if (first == last) cout << "YES\n";
        else {
            int rem = pos[last].end() - upper_bound(pos[last].begin(), pos[last].end(), pos[first][k - 1]);
            cout << (rem >= k ? "YES" : "NO") << "\n";
        }
    }
}