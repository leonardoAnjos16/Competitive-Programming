#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 2e5 + 5;

int main() {
    int n; scanf("%d", &n);

    long d[MAX];
    for (int i = 0; i < n; i++)
        scanf("%lld", &d[i]);

    int l = 0, r = n - 1;
    long sum_1 = d[l], sum_3 = d[r];

    long max_sum = 0;
    while (l < r) {
        while (l + 1 < r && sum_1 + d[l + 1] <= sum_3) sum_1 += d[++l];
        if (sum_1 == sum_3) max_sum = sum_1;

        while (r - 1 > l && sum_3 + d[r - 1] <= sum_1) sum_3 += d[--r];
        if (sum_1 == sum_3) max_sum = sum_1;

        sum_1 += d[++l];
        sum_3 += d[--r];
    }

    printf("%lld\n", max_sum);
}