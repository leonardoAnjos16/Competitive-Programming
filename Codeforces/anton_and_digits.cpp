#include <bits/stdc++.h>

using namespace std;

int main() {
    int k[4];
    for (int i = 0; i < 4; i++)
        scanf("%d", &k[i]);

    int used = min(k[0], min(k[2], k[3]));
    int ans = 256 * used;

    k[0] -= used; k[2] -= used; k[3] -= used;
    ans += 32 * min(k[0], k[1]);

    printf("%d\n", ans);
}