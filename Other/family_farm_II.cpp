#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<vector<int>> memo;

int ops(string &s, char letter, int node, int i, int jump) {
    if (i + jump >= (int) s.size()) return letter != s[i];

    int &ans = memo[letter - 'a'][node];
    if (~ans) return ans;

    ans = INT_MAX;
    for (char c = 'a'; c <= 'z'; c++)
        ans = min(ans, ops(s, c, 2 * node, i, 2 * jump) + ops(s, c, 2 * node + 1, i + jump, 2 * jump) + (c != letter));

    return ans;
}

int ops(string &last, string &curr) {
    int m = last.size(), n = curr.size();
    int size = n / m, ans = 0;

    for (int i = 0; i < m; i++) {
        memo.assign(26, vector<int>(4 * size, -1));
        ans += ops(curr, last[i], 1, i, m);
    }

    while (size > 1) {
        ans++;
        size >>= 1;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int ans = 0;
    string last;
    cin >> last;

    while (--n) {
        string curr; cin >> curr;
        ans += ops(last, curr);
        last = curr;
    }

    cout << ans << "\n";
}