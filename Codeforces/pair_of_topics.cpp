#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

int main() {
    int n; scanf("%d", &n);

    int diffs[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &diffs[i]);

    for (int i = 0; i < n; i++) {
        int b; scanf("%d", &b);
        diffs[i] -= b;
    }

    sort(diffs, diffs + n);

    long long int num_good = 0;
    for (int i = 0; i < n; i++) {
        if (diffs[i] <= 0) {
            int index = upper_bound(diffs + i + 1, diffs + n, abs(diffs[i])) - diffs;
            num_good += n - index;
        } else num_good += n - i - 1;
    }

    printf("%lld\n", num_good);
}