#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; scanf("%d", &n);
    int m; scanf("%d", &m);

    int sum = 0, max_a = INT_MIN;
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        max_a = max(max_a, a);
        sum += a;
    }

    int max_k = max_a + m;
    
    m -= (max_a * n) - sum;
    int min_k = max_a + (m > 0 ? (m / n) + (m % n != 0) : 0);

    printf("%d %d\n", min_k, max_k); 
}