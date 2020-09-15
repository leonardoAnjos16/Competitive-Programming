#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int s; scanf("%d", &s);

        int max = 0;
        while (s >= 10) {
            int div = s / 10;
            int mult = div * 10;

            max += mult;
            s -= mult; s += div;
        }

        max += s;
        printf("%d\n", max);
    }
}