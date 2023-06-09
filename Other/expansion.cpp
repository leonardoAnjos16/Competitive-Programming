#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<llong> ps(n + 1, 0LL);
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        ps[i] = ps[i - 1] + a;
    }

    if (ps[1] < 0LL || ps[n] < 0LL) {
        cout << "-1\n";
        return 0;
    }

    llong resources = 0LL, mx = 0LL, ans = 0LL;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, ps[i]);
        resources += ps[i];

        ans++;
        if (resources < 0LL) {
            if (mx <= 0LL) {
                cout << "-1\n";
                return 0;
            }

            llong t = (-resources + mx - 1LL) / mx;
            resources += t * mx;
            ans += t;
        }
    }

    cout << ans << "\n";
}