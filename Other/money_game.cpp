#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int n; cin >> n;

    llong sum = 0LL;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    ldouble x = sum / (n + 1.0L);
    cout << (2.0L * x);

    for (int i = 1; i < n; i++)
        cout << " " << x;

    cout << "\n";
}