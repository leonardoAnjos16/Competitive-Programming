#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        long N, S;
        cin >> N >> S;

        long sum = N * (N + 1) / 2;
        int l = 1, r = N, ans = -1;

        while (l <= r) {
            long m = (l + r) / 2;
            if (sum - m < S) r = m - 1;
            else l = m + 1, ans = m;
        }

        if (sum - ans != S) cout << "-1\n";
        else cout << ans << "\n";
    }
}