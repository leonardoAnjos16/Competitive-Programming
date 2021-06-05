#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

int N;
vector<vector<int>> a;
vector<vector<int>> memo;

int ways(int i = 0, int paired = 0) {
    if (i >= N) return 1;

    int &ans = memo[i][paired];
    if (~ans) return ans;

    ans = 0;
    for (int j = 0; j < N; j++)
        if (a[i][j] && !(paired & (1 << j)))
            ans = (ans + ways(i + 1, paired | (1 << j))) % MOD;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    a.assign(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> a[i][j];

    memo.assign(N + 5, vector<int>((1 << N) + 5, -1));

    int ans = ways();
    cout << ans << "\n";
}