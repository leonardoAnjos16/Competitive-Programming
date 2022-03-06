#include <bits/stdc++.h>

using namespace std;

const long double EPS = 1e-8;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int d, v0, v1, v2, t;
    cin >> d >> v0 >> v1 >> v2 >> t;

    long double p0 = 0.0L, p1 = 1.0L, p2 = 0.0L, time = 0.0L;
    while (t - time > EPS && d - p0 > EPS) {
        long double intersec;
        if (v2 > 0) {
            // p + vt = d
            // vt = d - p
            // t = (d - p) / v

            // p1 + v1t = p2 + v2t
            // (v2 - v1)t = p1 - p2
            // t = (p1 - p2) / (v2 - v1)

            long double rafa_to_d = (d - p1) / v1;
            long double tomi_to_d = (d - p2) / v2;
            if (rafa_to_d < tomi_to_d) intersec = tomi_to_d;
            else intersec = (p1 - p2) / (v2 - v1);
        } else {
            // p0 + v0t = p2 - v2t
            // (v2 + v0)t = p2 - p0
            // t = (p2 - p0) / (v2 + v0)
            intersec = (p2 - p0) / (-v2 + v0);
        }

        if (time + intersec < t) time += intersec;
        else intersec = t - time, time = t;

        p0 = min(p0 + v0 * intersec, 1.0L * d);
        p1 = min(p1 + v1 * intersec, 1.0L * d);
        p2 = min(p2 + v2 * intersec, 1.0L * d);
        v2 = -v2;
    }

    cout << p2 << "\n";
}