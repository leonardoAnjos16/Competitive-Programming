#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 35;

long to_base_k(long n, int k) {
    long ans = 0LL;
    int cnt = 0;

    while (n) {
        long rem = n % k;
        if (rem > 1) return -1;

        if (rem) ans |= 1LL << cnt;
        n /= k; cnt++;
    }

    return ans;
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n, k; scanf("%d %d", &n, &k);

        long a[MAX];
        for (int i = 0; i < n; i++)
            scanf("%lld", &a[i]);

        bool possible = true;
        for (int i = 0; i < n && possible; i++) {
            a[i] = to_base_k(a[i], k);
            if (a[i] == -1) possible = false;
        }

        for (int i = 0; i < n && possible; i++)
            for (int j = i + 1; j < n && possible; j++)
                if (a[i] & a[j]) possible = false;

        printf("%s\n", possible ? "YES" : "NO");
    }
}