#include <bits/stdc++.h>

using namespace std;

const long double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(6) << fixed;

    int n; cin >> n;

    long double ans = 0.0L;
    while (n--) {
        int h, w;
        cin >> h >> w;
        if (h > w) swap(h, w);

        long double hh = h / 2.0L;
        long double hw = w / 2.0L;

        long double r = sqrt(hh * hh + hw * hw);
        ans += PI * r * r;
    }

    cout << ans << "\n";
}