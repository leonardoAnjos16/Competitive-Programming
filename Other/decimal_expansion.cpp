#include <bits/stdc++.h>

using namespace std;

#define llong long long int

pair<int, int> factor(llong n) {
    int l = 0, r = 1e9, x = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (mid * (3LL * mid - 1LL) / 2LL < n) l = mid + 1;
        else r = mid - 1, x = mid;
    }

    if (x * (3LL * x - 1LL) / 2LL == n)
        return make_pair(-1, x);

    l = 0; r = 1e9; x = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (mid * (3LL * mid + 1LL) / 2LL < n) l = mid + 1;
        else r = mid - 1, x = mid;
    }

    if (x * (3LL * x + 1LL) / 2LL == n)
        return make_pair(1, x);

    return make_pair(0, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        llong n; cin >> n;

        auto [sign, x] = factor(n);
        int d = !sign ? 0 : (x & 1 ? 9 : 1);

        if (!sign && (x & 1)) d = 9;
        else if (sign < 0 && (x & 1)) d = 8;
        else if (sign > 0 && !(x & 1)) d = 0;

        cout << d;
        if (t) cout << " ";
    }

    cout << "\n";
}