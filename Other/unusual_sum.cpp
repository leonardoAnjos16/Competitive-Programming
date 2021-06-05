#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(10) << fixed;

    int n; cin >> n;
    while (n--) {
        long double l, r;
        cin >> l >> r;

        long double ans = 1 / l - 1 / (r + 1);
        cout << ans << "\n";
    }
}