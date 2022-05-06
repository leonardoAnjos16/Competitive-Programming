#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        int ans = ((N + 1LL) * (N + 2LL) / 2LL) % MOD;
        ans = (ans * (K + 1LL)) % MOD;
        cout << ans << "\n";
    }
}