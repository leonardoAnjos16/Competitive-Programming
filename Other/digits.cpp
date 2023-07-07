#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 100;
const int LIM = 5e3 + 5;

int sum(int n) {
    int ans = 0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("digits.in", "r", stdin);
    freopen("digits.out", "w", stdout);

    vector<llong> sums[MAX];
    fill(sums, sums + MAX, vector<llong>(1, 0LL));

    for (int i = 1; i < 1000000; i++)
        if (sums[sum(i)].size() < LIM)
            sums[sum(i)].push_back(sums[sum(i)].back() + i);

    int n; cin >> n;

    llong ans = LLONG_MAX;
    for (int i = 0; i < MAX; i++)
        if (n < (int) sums[i].size())
            ans = min(ans, sums[i][n]);

    cout << ans << "\n";
}