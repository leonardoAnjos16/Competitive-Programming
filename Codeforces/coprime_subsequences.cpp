#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;

int cnt[MAX] = {0}, pows[MAX] = {1}, memo[MAX];

int subsequences(int d = 1) {
    if (!cnt[d]) return 0;

    int &ans = memo[d];
    if (~ans) return ans;

    ans = (pows[cnt[d]] - 1 + MOD) % MOD;

    int m = 2 * d;
    while (m < MAX) {
        ans = (ans - subsequences(m) + MOD) % MOD;
        m += d;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i < MAX; i++)
        pows[i] = (2LL * pows[i - 1]) % MOD;

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        for (int j = 1; j * j <= a; j++)
            if (!(a % j)) {
                cnt[j]++;
                if (j * j < a)
                    cnt[a / j]++;
            }
    }

    memset(memo, -1, sizeof memo);

    int ans = subsequences();
    cout << ans << "\n";
}