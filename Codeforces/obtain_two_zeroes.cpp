#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int a, b; scanf("%d %d", &a, &b);
        if (a > b) swap(a, b);

        printf("%s\n", 2 * a >= b && (a + b) % 3 == 0 ? "YES" : "NO");
    }
}