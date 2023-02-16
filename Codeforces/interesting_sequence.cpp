#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int LOG = 62;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        llong n, x;
        cin >> n >> x;

        bool possible = true;
        llong l = n, r = LLONG_MAX;

        for (int i = 0; i < LOG && possible; i++) {
            if (!(n & (1LL << i)) && (x & (1LL << i))) possible = false;
            else if ((n & (1LL << i)) && !(x & (1LL << i))) l = max(l, (n | ((1LL << i) - 1LL)) + 1LL);
            else if (n & (1LL << i)) r = min(r, n | ((1LL << i) - 1LL));
        }

        possible &= l <= r;
        if (!possible) cout << "-1\n";
        else cout << l << "\n";
    }
}