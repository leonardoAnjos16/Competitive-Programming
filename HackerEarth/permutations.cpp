#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 2e5 + 5;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long facts[MAX] = {1LL};
    for (int i = 1; i < MAX; i++)
        facts[i] = (facts[i - 1] * i) % MOD;

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string S; cin >> S;

        vector<vector<int>> cnt(n + 1);
        cnt[0].assign(26, 0);

        for (int i = 1; i <= n; i++) {
            cnt[i] = cnt[i - 1];
            cnt[i][S[i - 1] - 'a']++;
        }

        int Q; cin >> Q;
        while (Q--) {
            int l, r;
            cin >> l >> r;

            long ans = 1LL;
            for (int i = 0; i < 26; i++) {
                int aux = cnt[r][i] - cnt[l - 1][i];
                ans = (ans * facts[aux]) % MOD;
            }

            cout << ans << "\n";
        }
    }
}