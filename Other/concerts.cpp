#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 30;
const int MOD = 1e9 + 7;

int k, n, hb[MAX];
string attend, schedule;
vector<vector<int>> memo;

int ways(int i = 0, int j = 0) {
    if (i >= k) return 1;
    if (j >= n) return 0;

    int &ans = memo[i][j];
    if (~ans) return ans;

    ans = ways(i, j + 1);
    if (attend[i] == schedule[j])
        ans = (ans + ways(i + 1, j + hb[attend[i] - 'A'] + 1)) % MOD;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k >> n;

    for (char c = 'A'; c <= 'Z'; c++)
        cin >> hb[c - 'A'];

    cin >> attend >> schedule;

    memo.assign(k + 5, vector<int>(n + 5, -1));

    int ans = ways();
    cout << ans << "\n";
}