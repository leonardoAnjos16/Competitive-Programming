#include <bits/stdc++.h>

using namespace std;

int main() {
    int a[4];
    for (int i = 0; i < 4; i++)
        scanf("%d", &a[i]);

    bool possible = false;
    for (int i = 0; i < (1 << 4) && !possible; i++) {
        int s1 = 0, s2 = 0;
        for (int j = 0; j < 4; j++) {
            if (i & (1 << j)) s1 += a[j];
            else s2 += a[j];
        }

        possible = s1 == s2;
    }

    printf("%s\n", possible ? "YES" : "NO");
}