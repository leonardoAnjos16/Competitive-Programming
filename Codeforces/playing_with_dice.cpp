#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b; scanf("%d %d", &a, &b);

    int ans[3] = {0};
    for (int i = 1; i <= 6; i++) {
        if (abs(a - i) < abs(b - i)) ans[0]++;
        else if (abs(a - i) == abs(b - i)) ans[1]++;
        else ans[2]++;
    }

    printf("%d %d %d\n", ans[0], ans[1], ans[2]);
}