#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, a, b; scanf("%d %d %d", &n, &a, &b);

        for (int i = 0; i < n; i++)
            printf("%c", 'a' + (i % b));

        printf("\n");
    }
}