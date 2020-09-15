#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        n <<= 1;
        
        double ans = 1.0 / tan(PI / n);
        printf("%lf\n", ans);
    }
}