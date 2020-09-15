#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        int num_odd = 0;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            num_odd += a % 2;
        }

        if (num_odd % 2 || (num_odd && num_odd < n)) printf("YES\n");
        else printf("NO\n");
    }
}