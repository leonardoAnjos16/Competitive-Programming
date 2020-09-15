#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 2e5 + 5;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        long a[MAX];
        for (int i = 0; i < n; i++)
            scanf("%lld", &a[i]);

        long sum = 0LL;
        int aux = a[0] > 0 ? 1 : -1;

        int i = 0;
        while (i < n) {
            long max_a = INT_MIN;
            while (i < n && a[i] * aux > 0)
                max_a = max(max_a, a[i++]);

            sum += max_a;
            aux *= -1;
        }

        printf("%lld\n", sum);
    }
}