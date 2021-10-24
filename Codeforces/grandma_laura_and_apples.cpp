#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p;
    cin >> n >> p;

    vector<string> buyers(n);
    for (int i = 0; i < n; i++)
        cin >> buyers[i];

    reverse(buyers.begin(), buyers.end());

    long apples = 0LL, ans = 0LL;
    for (int i = 0; i < n; i++) {
        if (buyers[i] == "half") apples *= 2LL;
        else apples = (apples * 2LL) + 1LL;

        ans += apples / 2LL * p;
        if (apples & 1LL) ans += p / 2;
    }

    cout << ans << "\n";
}