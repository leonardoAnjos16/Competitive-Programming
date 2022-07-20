#include <bits/stdc++.h>

using namespace std;

const long double EPS = 1e-8;

int sign(long double x) {
    return fabsl(x) <= EPS ? 0 : (x < -EPS ? -1 : 1);
}

long double get_y(int x1, int x2, long double y2, int r) {
    long double a = 1.0L;
    long double b = -2.0L * y2;
    long double c = (x1 - x2) * (x1 - x2) + y2 * y2 - 4.0L * r * r;

    long double delta = b * b - 4.0L * a * c;
    if (sign(delta) < 0) return r;

    return (-b + sqrtl(delta)) / (2.0L * a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int n, r;
    cin >> n >> r;

    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    vector<long double> ans(n);
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";

        long double y = r;
        for (int j = 0; j < i; j++)
            y = max(y, get_y(x[i], x[j], ans[j], r));

        ans[i] = y;
        cout << y;
    }

    cout << "\n";
}