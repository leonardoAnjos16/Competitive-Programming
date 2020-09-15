#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b; scanf("%d %d %d", &n, &a, &b);

    int l = 1, r = min(a, b), x;
    while (l <= r) {
        int mid = (l + r) / 2;

        if ((a / mid) + (b / mid) >= n) x = mid, l = mid + 1;
        else r = mid - 1;
    }

    printf("%d\n", x);
}