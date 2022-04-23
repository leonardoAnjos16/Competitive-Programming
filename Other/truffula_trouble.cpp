#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, k;
    cin >> N >> k;

    int mx = 0;
    vector<int> t(N);

    for (int i = 0; i < N; i++) {
        cin >> t[i];
        mx = max(mx, t[i]);
    }

    int l = 1, r = mx + N, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;

        set<int> aux;
        aux.insert(0);

        vector<int> dp(N);
        dp[0] = t[0] <= mid;

        for (int i = 1; i < N; i++) {
            dp[i] = dp[i - 1];

            auto it = aux.upper_bound(mid - t[i]);
            if (it != aux.begin())
                dp[i] = max(dp[i], *(--it) + 1);

            aux.insert(dp[i - 1]);
        }

        if (dp[N - 1] < k) l = mid + 1;
        else r = mid - 1, ans = mid;
    }

    cout << ans << "\n";
}