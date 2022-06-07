#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        long ans = 0LL;
        vector<int> a(n);
        multiset<int> mods;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            ans += a[i] / k;
            mods.insert(a[i] % k);
        }

        while (!mods.empty()) {
            auto it = mods.begin();
            int mod = *it;
            mods.erase(it);

            it = mods.lower_bound(k - mod);
            if (it != mods.end()) {
                ans++;
                mods.erase(it);
            } else {
                it = mods.begin();
                mods.erase(it);
            }
        }

        cout << ans << "\n";
    }
}