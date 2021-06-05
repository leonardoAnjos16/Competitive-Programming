#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    long double r, R, h;
    cin >> r >> R >> h;

    long double H = h / (R - r) * R;
    long double theta = atan(H / R) / 2.0;

    long double ans = min(R * tan(theta), h / 2.0);
    cout << ans << "\n";
}