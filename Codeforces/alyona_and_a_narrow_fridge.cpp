#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e3 + 5;

int main() {
    int n, h; scanf("%d %d", &n, &h);

    int a[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int k = 1;
    while (++k <= n) {
        sort(a, a + k, greater<int>());

        long sum = 0;
        for (int i = 0; i < k; i += 2)
            sum += a[i];

        if (sum > h) break;
    }

    printf("%d\n", --k);
}