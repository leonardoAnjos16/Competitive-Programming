#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int ans = 1;
    for (int i = 2; i <= N; i++) {
        int comb = (i * (i - 1LL) / 2LL) % MOD;
        ans = (1LL * ans * comb) % MOD;
    }

    cout << ans << "\n";
}