#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

int T, M, N;
vector<vector<int>> memo;

int count(int i, int last) {
    if (i >= T) return 1;

    int &ans = memo[i][last];
    if (~ans) return ans;

    ans = 0;
    if (last - 1 >= M)
        ans = (ans + count(i + 1, last - 1)) % MOD;

    if (last + 1 <= N)
        ans = (ans + count(i + 1, last + 1)) % MOD;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T >> M >> N;

    memo.assign(T + 5, vector<int>(N + 5, -1));

    int ans = 0;
    for (int i = M; i <= N; i++)
        ans = (ans + count(1, i)) % MOD;

    cout << ans << "\n";
}