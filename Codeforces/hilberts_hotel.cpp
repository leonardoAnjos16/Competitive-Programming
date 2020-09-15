#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        int a[MAX];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            a[i] += i;
        }

        bitset<MAX> used;
        bool possible = true;

        for (int i = 0; i < n && possible; i++) {
            int m = ((a[i] % n) + n) % n;
            if (used[m]) possible = false;
            used[m] = true;
        }

        printf("%s\n", possible ? "YES" : "NO");
    }
}