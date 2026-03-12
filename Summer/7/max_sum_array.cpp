#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e6 + 5;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int facts[MAX] = {1};
    for (int i = 1; i < MAX; i++)
        facts[i] = (1LL * facts[i - 1] * i) % MOD;

    int m; cin >> m;

    llong n = 0LL;
    int cnt[MAX] = {0};

    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;

        n += c;
        cnt[c]++;
    }

    int mx = 0, ans = 1, idx = MAX - 1;
    while (idx > 1) {
        while (idx > 1 && !cnt[idx]) idx--;

        if (idx == 1) ans = (1LL * ans * facts[cnt[idx]]) % MOD;
        else {
            int aux = cnt[idx] * (n - cnt[idx]) % MOD;
            aux = (aux * (idx - 1LL)) % MOD;
            mx = (mx + aux) % MOD;

            aux = (1LL * facts[cnt[idx]] * facts[cnt[idx]]) % MOD;
            ans = (1LL * ans * aux) % MOD;

            n -= 2 * cnt[idx];
            cnt[idx - 2] += cnt[idx];
            cnt[idx] = 0;
        }
    }

    cout << mx << " " << ans << "\n";
}