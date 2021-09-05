#include <bits/stdc++.h>

using namespace std;

bool triangle(int a, int b, int c) {
    return a + b > c && a + c > b && b + c > a;
}

bool right_triangle(int a, int b, int c, int k) {
    return a * a <= b * b + c * c && (a + k) * (a + k) >= b * b + c * c;
}

long double area(long double a, long double b, long double c) {
    long double sp = (a + b + c) / 2.0;
    return sqrt(sp * (sp - a) * (sp - b) * (sp - c));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("sticks.in", "r", stdin);

    cout << setprecision(8) << fixed;

    int T; cin >> T;
    while (T--) {
        int a, b, c, k;
        cin >> a >> b >> c >> k;

        long double ans = 0.0;
        if (triangle(a, b, c)) ans = max(ans, area(a, b, c));

        if (right_triangle(a, b, c, k)) ans = max(ans, b * c / (long double) 2.0);
        if (right_triangle(b, a, c, k)) ans = max(ans, a * c / (long double) 2.0);
        if (right_triangle(c, a, b, k)) ans = max(ans, a * b / (long double) 2.0);

        if (triangle(a + k, b, c)) ans = max(ans, area(a + k, b, c));
        if (triangle(a, b + k, c)) ans = max(ans, area(a, b + k, c));
        if (triangle(a, b, c + k)) ans = max(ans, area(a, b, c + k));

        cout << ans << "\n";
    }
}