#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int h, m; scanf("%d %d", &h, &m);

        int ans = (24 - h) * 60 - m;
        printf("%d\n", ans);
    }
}