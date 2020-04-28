#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 5;

int main() {
    int n; scanf("%d", &n);

    char bus[MAX][10];
    for (int i = 0; i < n; i++)
        scanf("%s", bus[i]);

    bool possible = false;
    for (int i = 0; i < n && !possible; i++) {
        for (int j = 0; j < 2 && !possible; j++) {
            if (bus[i][3 * j] == 'O' && bus[i][(3 * j) + 1] == 'O') {
                possible = true;
                bus[i][3 * j] = bus[i][(3 * j) + 1] = '+';
            }
        }
    }

    if (!possible) printf("NO\n");
    else {
        printf("YES\n");
        for (int i = 0; i < n; i++)
            printf("%s\n", bus[i]);
    }
}