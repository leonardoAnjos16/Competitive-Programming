#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<llong> a(n, 0LL);
        for (int i = 1; i < n; i++)
            cin >> a[i];

        vector<int> cnt(n + 1, 0);
        for (int i = 1; i < n; i++) {
            llong diff = a[i] - a[i - 1];
            if (diff <= n) cnt[diff]++;
        }

        vector<int> missing;
        for (int i = 1; i <= n; i++)
            if (!cnt[i])
                missing.push_back(i);

        bool possible = false;
        for (int i = 1; i < n && !possible; i++) {
            llong diff = a[i] - a[i - 1];
            if (diff <= n && --cnt[diff] == 0)
                missing.push_back(diff);

            if ((int) missing.size() == 2 && missing[0] + missing[1] == diff)
                possible = true;

            if (diff <= n && cnt[diff]++ == 0)
                missing.pop_back();
        }

        if ((int) missing.size() == 1 && a[n - 1] + missing[0] == n * (n + 1LL) / 2LL)
            possible = true;

        cout << (possible ? "YES" : "NO") << "\n";
    }
}