#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int n; scanf("%d", &n);

    int p[MAX]; int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        sum += p[i];
    }

    double ans = (double) sum / n;
    printf("%.5lf\n", ans);
}