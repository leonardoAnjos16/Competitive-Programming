#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

int main() {
    int n, m; scanf("%d %d", &n, &m);

    int a[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sort(a, a + n);

    while (m--) {
        int b; scanf("%d", &b);

        int cnt = upper_bound(a, a + n, b) - a;
        printf("%d ", cnt);
    }
}