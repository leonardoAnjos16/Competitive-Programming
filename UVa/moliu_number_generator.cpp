#include <bits/stdc++.h>

using namespace std;

#define long long long int

long last_one(long n) {
    return n & -n;
}

int main() {
    long S;
    while (scanf("%lld", &S) != EOF) {
        int ans = 0;
        while (S) {
            if (!(S & 1LL)) S >>= 1LL;
            else if (S > 3LL && last_one(S + 1LL) > last_one(S - 1LL)) S++;
            else S--; ans++;
        }

        printf("%d\n", ans);
    }
}