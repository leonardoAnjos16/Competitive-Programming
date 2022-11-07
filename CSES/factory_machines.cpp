#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;

    vector<int> k(n);
    for (int i = 0; i < n; i++)
        cin >> k[i];

    llong l = 1, r = 1e18 + 5, ans = -1;
    while (l <= r) {
        llong mid = (l + r) / 2;

        llong products = 0LL;
        for (int i = 0; i < n && products < t; i++)
            products += mid / k[i];

        if (products < t) l = mid + 1;
        else r = mid - 1, ans = mid;
    }

    cout << ans << "\n";
}