#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N, Q;
        cin >> N >> Q;

        vector<int> odd(N + 1, 0);
        vector<int> powers(N + 1, 1);

        for (int i = 1; i <= N; i++) {
            int A; cin >> A;
            powers[i] = (2 * powers[i - 1]) % MOD;

            odd[i] = odd[i - 1];
            if (A & 1) odd[i]++;
        }

        while (Q--) {
            int L, R, t;
            cin >> L >> R >> t;

            int odds = odd[R] - odd[L - 1];
            int ans = (powers[odds] + MOD - 1) % MOD;

            if (t == 1) cout << ans << "\n";
            else {
                int all = (powers[R - L + 1] + MOD - 1) % MOD;
                ans = (all - ans + MOD) % MOD;
                cout << ans << "\n";
            }
        }
    }
}