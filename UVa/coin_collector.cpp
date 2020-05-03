#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e3 + 5;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);

        int C[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &C[i]);

        long sum = 1LL;
        int ans = 1;

        for (int i = 1; i < n - 1; i++) {
            if (sum + C[i] < C[i + 1]) {
                sum += C[i];
                ans++;
            }
        }

        if (n > 1) ans++;
        printf("%d\n", ans);
    }
}