#include <bits/stdc++.h>

using namespace std;

const int MAX = 20;

bool in(int n, int a, int b) {
    return n >= a && n <= b;
}

int main() {
    int n, l, r, x;
    scanf("%d %d %d %d", &n, &l, &r, &x);

    int c[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);

    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        int mn = INT_MAX, mx = INT_MIN, cnt = 0, sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                mn = min(mn, c[j]);
                mx = max(mx, c[j]);
                sum += c[j]; cnt++;
            }
        }

        int diff = mx - mn;
        if (cnt >= 2 && diff >= x && in(sum, l, r)) ans++;
    }

    printf("%d\n", ans);
}