#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong INF = 1e18 + 5;

string s;
vector<vector<vector<llong>>> memo;

int score(char c) {
    if (c == 'A') return 1;
    if (c == 'B') return 10;
    if (c == 'C') return 100;
    if (c == 'D') return 1000;
    return 10000;
}

llong max_value(int i, int changed = 0, char greatest = 'A') {
    if (changed > 1) return -INF;
    if (i < 0) return 0LL;

    llong &ans = memo[changed][greatest - 'A'][i];
    if (~ans) return ans;

    ans = -INF;
    for (char c = 'A'; c <= 'E'; c++)
        ans = max(ans, max_value(i - 1, changed + (c != s[i]), max(greatest, c)) + (c >= greatest ? score(c) : -score(c)));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> s;

        int n = s.size();
        memo.assign(2, vector<vector<llong>>(5, vector<llong>(n + 5, -1LL)));

        llong ans = max_value(n - 1);
        cout << ans << "\n";
    }
}