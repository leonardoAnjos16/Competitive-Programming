#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        long n, m; scanf("%lld %lld", &n, &m);
        printf("%s\n", n * m <= n + m ? "YES" : "NO");
    }
}