#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> power(N);
    for (int i = 0; i < N; i++)
        cin >> power[i];
    
    int block_size = sqrt(N);
    vector<pair<int, int>> dp(N);

    int blocks = (N + block_size - 1) / block_size;
    for (int i = 0; i < blocks; i++) {
        int last = min((i + 1) * block_size, N) - 1;
        dp[last] = make_pair(last, 0);
        
        while (--last >= i * block_size) {
            if (last + power[last] >= min((i + 1) * block_size, N))
                dp[last] = make_pair(last, 0);
            else
                dp[last] = make_pair(dp[last + power[last]].first, dp[last + power[last]].second + 1);
        }
    }

    while (M--) {
        int op, a;
        cin >> op >> a;

        if (!op) {
            int b; cin >> b;
            power[a - 1] = b;

            int block = (a - 1) / block_size;
            int last = min((block + 1) * block_size, N) - 1;
            dp[last] = make_pair(last, 0);

            while (--last >= block * block_size) {
                if (last + power[last] >= min((block + 1) * block_size, N))
                    dp[last] = make_pair(last, 0);
                else
                    dp[last] = make_pair(dp[last + power[last]].first, dp[last + power[last]].second + 1);
            }
        } else {
            int last = a - 1, jumps = 0;
            while (true) {
                int block = last / block_size;
                jumps += dp[last].second + 1;
                last = dp[last].first;

                if (last + power[last] >= N) break;
                last += power[last];
            }

            cout << ++last << " " << jumps << "\n";
        }
    }
}