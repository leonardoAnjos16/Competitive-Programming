#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e5 + 5;

int main() {
    int n;
    while (scanf("%d", &n), n) {
        long a[MAX];
        for (int i = 0; i < n; i++)
            scanf("%lld", &a[i]);

        stack<int> buyers;
        long ans = 0LL;

        for (int i = 0; i < n; i++) {
            if (a[i] > 0) buyers.push(i);
            else {
                while (!buyers.empty() && a[i] < 0LL) {
                    int buyer = buyers.top(); buyers.pop();
                    long sold = min(a[buyer], -a[i]);

                    a[buyer] -= sold; a[i] += sold;
                    if (a[buyer]) buyers.push(buyer);
                    ans += (i - buyer) * sold;
                }

                if (a[i]) {
                    ans += -a[i];
                    a[i + 1] += a[i];
                }
            }
        }

        printf("%lld\n", ans);
    }
}