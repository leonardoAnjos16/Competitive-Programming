#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 5;
const int MOD = 1e9 + 7;

int memo[MAX][MAX];

int F(int N, int K) {
    if (K <= 0) return 1;
    if (N <= 0) return 0;

    int &ans = memo[N][K];
    if (~ans) return ans;

    return ans = (F(N - 1, K) + F(N - 1, K - 1)) % MOD;
}

int main() {
    int T; cin >> T;
    memset(memo, -1, sizeof memo);

    while (T--) {
        int N, P;
        cin >> N >> P;
        
        int ans = 0;
        for (int i = 0; i <= P; i++) {
            ans += F(N, i);
            ans %= MOD;
        }
            
        cout << ans << "\n";
    }
}
