#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int n, v, u;
    cin >> n >> v >> u;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long double l = 0.0L, r = 1e9 + 5.0L;
    for (int i = 0; i < 100; i++) {
        long double mid = (l + r) / 2.0L;

        long double available = 0.0L;
        for (int j = 0; j < n; j++)
            available += max(a[j] - v * mid, 0.0L);

        if (available > u * mid) l = mid;
        else r = mid;
    }

    long double t = (l + r) / 2.0L;
    long double ans = u * t;
    cout << ans << "\n";
}