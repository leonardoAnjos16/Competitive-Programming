#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong NO_ANS = LLONG_MIN;
const int MAX_BAD = 30;

int n, k;
vector<int> a;
vector<vector<llong>> memo;

llong coins(int bad = 0, int i = 0) {
    if (bad >= MAX_BAD || i >= n) return 0LL;

    llong &ans = memo[bad][i];
    if (ans != NO_ANS) return ans;

    int v = a[i] >> bad;
    ans = v - k + coins(bad, i + 1);
    ans = max(ans, (v >> 1) + coins(bad + 1, i + 1));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> n >> k;

        a.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        memo.assign(MAX_BAD, vector<llong>(n, NO_ANS));

        llong ans = coins();
        cout << ans << "\n";
    }
}