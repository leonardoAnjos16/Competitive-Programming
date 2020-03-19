#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; scanf("%d", &n);
    while (n--) {
        int px, py, qx, qy;
        scanf("%d %d %d %d", &px, &py, &qx, &qy);

        int rx = qx + (qx - px);
        int ry = qy + (qy - py);

        printf("%d %d\n", rx, ry);
    }
}