#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const long double EPS = 1e-6;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int a, b, c;
    cin >> a >> b >> c;

    if (a >= b + c || b >= a + c || c >= a + b) cout << "Impossible\n";
    else {
        long double x = (1.0L * a * a - 1.0L * b * b + 1.0L * c * c) / (2.0L * a);

        assert(x - c < EPS);
        long double y = sqrt(1.0L * c * c - x * x);

        cout << "0 0\n";
        cout << a << " 0\n";
        cout << x << " " << y << "\n";
    }
}