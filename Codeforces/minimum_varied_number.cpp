#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int INF = 1e9 + 5;

int s;
vector<vector<llong>> memo;

int digits(int x) {
    int ans = 0;
    while (x) {
        ans++;
        x /= 10;
    }

    return ans;
}

llong pow(int a, int n) {
    if (!n) return 1LL;
    return a * pow(a, n - 1);
}

llong number(int sum = 0, int used = 0) {
    if (sum == s) return 0LL;
    if (sum > s || used == (1 << 10) - 1) return INF;

    llong &ans = memo[sum][used];
    if (~ans) return ans;

    ans = INF;
    for (int d = 1; d < 10; d++)
        if (!(used & (1 << d))) {
            llong suffix = number(sum + d, used | (1 << d));
            ans = min(ans, d * pow(10, digits(suffix)) + suffix);
        }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> s;

        memo.assign(s + 5, vector<llong>((1 << 10) + 5, -1));

        llong ans = number();
        cout << ans << "\n";
    }
}