#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, Q;
        cin >> N >> Q;

        string blocks;
        cin >> blocks;

        vector<array<int, 26>> cnt(N + 1);
        for (int i = 1; i <= N; i++) {
            cnt[i] = cnt[i - 1];
            cnt[i][blocks[i - 1] - 'A']++;
        }

        int ans = 0;
        while (Q--) {
            int L, R;
            cin >> L >> R;

            int odd = 0;
            for (char c = 'A'; c <= 'Z'; c++)
                if ((cnt[R][c - 'A'] - cnt[L - 1][c - 'A']) & 1)
                    odd++;

            ans += odd <= 1;
        }

        cout << "Case #" << t << ": " << ans << "\n";
    }
}