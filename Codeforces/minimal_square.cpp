#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int a, b; scanf("%d %d", &a, &b);
        if (a > b) swap(a, b);

        int side = (a << 1) < b ? b : a << 1;
        printf("%d\n", side * side);
    }
}