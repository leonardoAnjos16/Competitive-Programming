#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K; cin >> K;

    if (K == 1) cout << "1\n";
    else {
        vector<int> ss(K + 2, 0);
        ss[K] = 1;

        for (int i = K - 1; i > 0; i--) {
            int l = i + 1, r = min(2 * i, K);
            ss[i] = (ss[l] - ss[r + 1] + MOD) % MOD;
            ss[i] = (ss[i] + ss[i + 1]) % MOD;
        }

        int ans = (ss[2] - ss[3] + MOD) % MOD;
        cout << ans << "\n";
    }
}