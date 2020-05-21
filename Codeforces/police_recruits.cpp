#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; scanf("%d", &n);

    int cops = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        if (a > 0) cops += a;
        else if (cops > 0) cops--;
        else ans++;
    }

    printf("%d\n", ans);
}