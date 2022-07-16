#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e6 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int sum = 0;
    vector<int> l(n);

    for (int i = 0; i < n; i++) {
        cin >> l[i];
        sum += l[i];
    }

    bitset<MAX> dp;
    dp[0] = true;

    for (int i = 0; i < n; i++)
        dp |= dp << l[i];

    int cols = 0;
    long ans = 0LL;

    for (int i = 0; i <= sum; i++)
        if (dp[sum - i] && dp[i]) {
            ans += sum - i + 1LL;
            ans += i - cols++;
        }

    cout << ans << "\n";
}