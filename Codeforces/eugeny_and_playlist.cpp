#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int main() {
    int n, m; scanf("%d %d", &n, &m);

    int minutes[MAX] = {0};
    for (int i = 1; i <= n; i++) {
        int c, t; scanf("%d %d", &c, &t);
        minutes[i] = minutes[i - 1] + (c * t);
    }

    while (m--) {
        int v; scanf("%d", &v);

        int song = lower_bound(minutes, minutes + n + 1, v) - minutes;
        printf("%d\n", song);
    }
}