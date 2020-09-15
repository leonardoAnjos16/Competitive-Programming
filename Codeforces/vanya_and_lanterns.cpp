#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 5;

int main() {
    int n, l; scanf("%d %d", &n, &l);

    int A[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    sort(A, A + n);

    int max_dist = 2 * A[0];
    for (int i = 1; i < n; i++)
        max_dist = max(max_dist, A[i] - A[i - 1]);

    max_dist = max(max_dist, 2 * (l - A[n - 1]));
    
    double d = max_dist / 2.0;
    printf("%lf\n", d);
}