#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e5 + 5;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; long s;
        scanf("%d %lld", &n, &s);

        int a[MAX];
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i - 1]);

        long sum = 0LL;

        int idx = 0, max_idx = 0;
        while (idx < n) {
            if (a[idx] > a[max_idx])
                max_idx = idx;

            sum += a[idx++];
            if (sum > s) break;
        }

        if (sum <= s) printf("0\n");
        else printf("%d\n", ++max_idx);
    }
}