#include <bits/stdc++.h>

using namespace std;

#define llong long long int

llong sum(int l, int r) {
    if (l > r) return 0LL;

    int n = r - l + 1;
    return n * (n - 1LL) / 2LL + 1LL * n * l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        llong ans = 4LL * n;
        int l = 3, r = n - 1;

        if (n == 4) ans += 10LL;
        else ans += 10LL + l + r + 2LL * sum(l + 1, r - 1);

        cout << ans << "\n";
    }
}