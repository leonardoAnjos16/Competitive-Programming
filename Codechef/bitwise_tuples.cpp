#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

long exp(long b, int n) {
    if (!n) return 1LL;

    long ans = exp(b, n >> 1);
    ans = (ans * ans) % MOD;

    if (!(n & 1)) return ans;
    return (ans * b) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        long ans = (exp(2LL, N) - 1LL + MOD) % MOD;
        ans = exp(ans, M);

        cout << ans << "\n";
    }
}