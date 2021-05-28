#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int mn = INT_MAX;
        vector<int> a(n), cnt(105, 0);

        for (auto &ai: a) {
            cin >> ai;
            cnt[ai]++;
            mn = min(mn, ai);
        }

        int ans = n - cnt[mn];
        cout << ans << "\n";
    }
}