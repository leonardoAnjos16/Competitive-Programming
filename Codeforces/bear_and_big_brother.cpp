#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b; scanf("%d %d", &a, &b);

    int ans = 0;
    while (a <= b) a *= 3, b *= 2, ans++;

    printf("%d\n", ans);
}