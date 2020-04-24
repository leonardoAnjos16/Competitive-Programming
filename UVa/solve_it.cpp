#include <bits/stdc++.h>

using namespace std;

int p, q, r, s, t, u;

double calc(double x) {
    return (p * exp(-x)) + (q * sin(x)) + (r * cos(x)) + (s * tan(x)) + (t * x * x) + u;
}

int main() {
    while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
        double lo = 0.0, hi = 1.0;
        while ((hi - lo) > 1e-9) {
            double x = (lo + hi) / 2;
            
            double v = calc(x);
            if (v >= 0) lo = x;
            else hi = x;
        }

        double x = (lo + hi) / 2;

        if (fabs(calc(x)) > 1e-5) printf("No solution\n");
        else printf("%.4lf\n", x);
    }
}