#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            if (!l || !r) {
                if (a % 2 && !l) l = i + 1;
                else if (a % 2) r = i + 1;
                else l = r = i + 1;
            }
        }

        if (!l || !r) printf("-1\n");
        else {
            int size = (l != r) + 1;
            printf("%d\n", size);

            if (size == 1) printf("%d\n", l);
            else printf("%d %d\n", l, r);
        }
    }
}