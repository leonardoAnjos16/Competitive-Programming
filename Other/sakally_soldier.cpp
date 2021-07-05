#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("alimagde.in", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        int l = 1, r = N, k = 1;
        while (l <= r) {
            int m = (l + r) / 2;
            long aux = m * (m + 1LL) / 2LL;

            if (aux > N) r = m - 1;
            else l = m + 1, k = m;
        }

        int ans = N - k;
        cout << ans << "\n";
    }
}