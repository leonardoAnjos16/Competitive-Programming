#include <bits/stdc++.h>

using namespace std;

int main() {
    int a; scanf("%d", &a);
    int b; scanf("%d", &b);

    if (a > b) swap(a, b);

    int dist = b - a;
    int half = dist / 2;

    int ans = half * (half + 1);
    if (dist & 1) ans += half + 1;

    printf("%d\n", ans);
}