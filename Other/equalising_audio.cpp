#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int n, x;
    cin >> n >> x;

    llong ssum = 0LL;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ssum += 1LL * a[i] * a[i];
    }

    if (!ssum) {
        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << a[i];
        }

        cout << "\n";
        return 0;
    }

    ldouble c = sqrtl(1.0L * x * n / ssum);
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";

        ldouble ans = c * a[i];
        cout << ans;
    }

    cout << "\n";
}