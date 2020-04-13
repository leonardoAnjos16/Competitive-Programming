#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592653589793;

int main() {
    int n, r; scanf("%d %d", &n, &r);

    double a = 2 * PI / n;
    double y = sqrt(1 - cos(a));

    double R = r * y / (sqrt(2.0) - y);
    printf("%.9lf\n", R);
}