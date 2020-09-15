#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        char str[10];
        long time = 0;

        for (int i = 0; i < n; i++) {
            scanf("%s", str);
            if (!strcmp(str, "MOOK"))
                time += (1LL << i);
        }

        printf("%lld\n", time);
    }
}