#include <bits/stdc++.h>

using namespace std;

#define long long long int

int n, m;
string s, t;
vector<vector<int>> memo;

int distance(int i = 0, int j = 0) {
    if (i >= n) return m - j;
    if (j >= m) return n - i;

    int &ans = memo[i][j];
    if (~ans) return ans;

    ans = min(distance(i, j + 1), distance(i + 1, j)) + 1;
    if (s[i] == t[j]) ans = min(ans, distance(i + 1, j + 1));
    else ans = min(ans, distance(i + 1, j + 1) + 1);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> t;

    n = s.size();
    m = t.size();

    memo.assign(n + 5, vector<int>(m + 5, -1));

    int ans = distance();
    cout << ans << "\n";
}