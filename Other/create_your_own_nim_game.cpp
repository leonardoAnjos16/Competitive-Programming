#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

int N;
vector<vector<int>> memo;

int games(int stones = 0, int x = 0) {
    if (stones > N) return 0;
    if (stones == N) return x > 0;

    int &ans = memo[stones][x];
    if (~ans) return ans;

    ans = 0;
    for (int i = 1; i <= N; i++)
        ans = (ans + games(stones + i, x ^ i)) % MOD;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        cin >> N;

        memo.assign(N + 5, vector<int>(N + 5, -1));

        int ans = games();
        cout << ans << "\n";
    }
}