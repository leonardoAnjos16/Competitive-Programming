#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, z; scanf("%d %d %d", &n, &m, &z);

    int ans = 0, artists = 0;
    for (int i = 1; i <= z; i++) {
        artists = max(0, artists - 1);
        if (i % m == 0) artists++;

        if (i % n == 0 && artists) {
            ans += artists;
            artists = 0;
        }
    }

    printf("%d\n", ans);
}