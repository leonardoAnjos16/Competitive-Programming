#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, x, y;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &a);
            if (a) x = i, y = j;
        }
    }

    int ans = abs(x - 2) + abs(y - 2);
    printf("%d\n", ans);
}