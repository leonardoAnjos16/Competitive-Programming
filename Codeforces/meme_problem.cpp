#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        double d; scanf("%lf", &d);

        double l = 0.0, r = d, a;
        while ((r - l) > 1e-9) {
            a = (l + r) / 2;
            if (a * (d - a) < d) r = a;
            else l = a;
        }

        a = (l + r) / 2;

        if (abs((a * (d - a)) - d) > 1e-6) printf("N\n");
        else printf("Y %.9lf %.9lf\n", a, d - a);
    }
}