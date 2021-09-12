#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;
        string S; cin >> S;

        int idx = -1;
        char last = '-';

        long ans = 0LL;
        for (int i = 0; i < N; i++) {
            if (last == 'X' && S[i] == 'O') {
                ans += (idx + 1LL) * (N - i);
                ans %= MOD;
            } else if (last == 'O' && S[i] == 'X') {
                ans += (idx + 1LL) * (N - i);
                ans %= MOD;
            }

            if (S[i] == 'X' || S[i] == 'O')
                idx = i, last = S[i];
        }

        cout << "Case #" << t << ": " << ans << "\n";
    }
}