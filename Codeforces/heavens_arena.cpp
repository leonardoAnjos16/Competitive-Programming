#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    double n, a, p;
    cin >> n >> a >> p;

    p /= 100;

    double ans = n + a * p - a * (1 - p);
    cout << ans << "\n";
}