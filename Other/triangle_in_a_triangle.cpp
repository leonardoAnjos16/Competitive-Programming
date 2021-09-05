#include <bits/stdc++.h>

using namespace std;

long double area(long double a, long double b, long double c) {
    long double sp = (a + b + c) / 2.0;
    return sqrt(sp * (sp - a) * (sp - b) * (sp - c));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    complex<long double> corners[3];
    for (int i = 0; i < 3; i++) {
        long double x, y;
        cin >> x >> y;
        corners[i] = { x, y };
    }

    vector<complex<long double>> lampposts[3];
    for (int i = 0; i < 3; i++) {
        int n; cin >> n;
        lampposts[i].resize(n);

        complex<long double> p1 = corners[i];
        complex<long double> p2 = corners[(i + 1) % 3];

        complex<long double> v = p2 - p1;
        long double l = abs(v);

        for (int j = 0; j < n; j++) {
            long double d; cin >> d;
            complex<long double> u = v * (d / l);
            lampposts[i][j] = p1 + u;
        }
    }

    vector<complex<long double>> good[3];
    for (int i = 0; i < 3; i++) {
        if (!lampposts[i].empty()) good[i].push_back(lampposts[i].front());
        if (!lampposts[(i + 2) % 3].empty()) good[i].push_back(lampposts[(i + 2) % 3].back());
    }

    long double ans = 0.0;
    for (int i = 0; i < (int) good[0].size(); i++)
        for (int j = 0; j < (int) good[1].size(); j++)
            for (int k = 0; k < (int) good[2].size(); k++) {
                complex<long double> p1 = good[0][i];
                complex<long double> p2 = good[1][j];
                complex<long double> p3 = good[2][k];

                if (p1 == p2 || p2 == p3 || p1 == p3)
                    continue;

                complex<long double> u = p2 - p1;
                complex<long double> v = p3 - p2;
                complex<long double> w = p1 - p3;

                long double d1 = abs(u);
                long double d2 = abs(v);
                long double d3 = abs(w);

                long double a = area(d1, d2, d3);
                ans = max(ans, a);
            }

    cout << ans << "\n";
}