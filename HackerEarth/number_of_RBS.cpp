#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

int n;
string S;
vector<vector<int>> memo;

int count(int i = 0, int sum = 0) {
    if (sum < 0) return 0;
    if (i >= n) return !sum;

    int &ans = memo[i][sum];
    if (~ans) return ans;

    ans = 0;
    if (S[i] != '(') ans = (ans + count(i + 1, sum - 1)) % MOD;
    if (S[i] != ')') ans = (ans + count(i + 1, sum + 1)) % MOD;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        cin >> n;
        cin >> S;

        memo.assign(n + 5, vector<int>(n + 5, -1));

        int ans = count();
        cout << ans << "\n";
    }
}