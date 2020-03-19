#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int l, b; scanf("%d %d", &l, &b);
        int max_size = gcd(l, b);

        max_size *= max_size;

        int num_squares = (l * b) / max_size;
        printf("%d\n", num_squares);
    }
}