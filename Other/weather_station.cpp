#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

int n;
string s;
vector<int> memo;

int solutions(int i = 0) {
    if (i + 1 >= n) return 1;

    int &ans = memo[i];
    if (~ans) return ans;

    ans = solutions(i + 1);
    if (s[i] == 'N' || s[i] == 'S')
        if (s[i + 1] == 'E' || s[i + 1] == 'W') {
            ans += solutions(i + 2);
            ans %= MOD;
        }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> s;
    n = s.size();

    memo.assign(n + 5, -1);

    int ans = solutions();
    cout << ans << "\n";
}