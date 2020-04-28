#include <bits/stdc++.h>

using namespace std;

bool all_diff(int n) {
    bitset<10> used;
    while (n) {
        if (used[n % 10]) return false;
        used[n % 10] = true;
        n /= 10;
    }

    return true;
}

int main() {
    int l, r; scanf("%d %d", &l, &r);

    for (int i = l; i <= r; i++) {
        if (all_diff(i)) {
            printf("%d\n", i);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}