#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    string s; cin >> s;

    vector<vector<int>> ps(3, vector<int>(n + 3, 0));
    for (int i = 0; i < 3; i++)
        for (int j = 3; j < n + 3; j++)
            ps[i][j] = ps[i][j - 3] + (s[j - 3] - 'a' == i);

    /* for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n + 3; j++)
            cout << ps[i][j] << " ";

        cout << "\n";
    } */

    while (m--) {
        int l, r;
        cin >> l >> r;
        l += 2; r += 2;

        int ans = INT_MAX;
        string pat = "abc";

        do {
            // l..r
            // abca

            int cnt[3] = {0};
            int sz = r - l + 1;

            for (int i = 0; i < 3 && sz > i; i++) {
                int idx = pat[i] - 'a';
                cnt[i] = ps[idx][r - (sz % 3 + 2 - i) % 3] - ps[idx][l + i - 3];
            }

            int need[3] = {0};
            need[0] = sz / 3 + (sz % 3 > 0);
            need[1] = sz / 3 + (sz % 3 > 1);
            need[2] = sz / 3;

            int change = 0;
            for (int i = 0; i < 3; i++)
                change += max(need[i] - cnt[i], 0);

            ans = min(ans, change);
        } while (next_permutation(pat.begin(), pat.end()));

        cout << ans << "\n";
    }
}