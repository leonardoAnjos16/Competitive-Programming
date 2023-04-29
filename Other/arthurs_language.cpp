#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

string S, w;
vector<vector<int>> memo;

int count(int i = 0, int j = 0) {
    if (j >= (int) w.size()) return 1;
    if (i >= (int) S.size()) return 0;

    int &ans = memo[i][j];
    if (~ans) return ans;

    ans = count(i + 1, j);
    if (S[i] == w[j])
        ans = (ans + count(i + 1, j + 1)) % MOD;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> S >> w;

    memo.assign((int) S.size() + 5, vector<int>((int) w.size() + 5, -1));

    int ans = count();
    cout << ans << "\n";
}