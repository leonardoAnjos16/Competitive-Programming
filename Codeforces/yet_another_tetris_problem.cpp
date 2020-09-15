#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        bool all_even = true, all_odd = true;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            all_even &= (a % 2) == 0;
            all_odd &= (a % 2) == 1;
        }

        if (all_even || all_odd) printf("YES\n");
        else printf("NO\n");
    }
}