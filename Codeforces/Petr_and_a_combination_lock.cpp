#include <bits/stdc++.h>

using namespace std;

const int MAX = 20;

int main() {
    int n; scanf("%d", &n);

    int a[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    bool possible = false;
    for (int i = 0; i < (1 << n) && !possible; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) sum += a[j];
            else sum -= a[j];
        }

        if (sum % 360 == 0) possible = true;
    }

    printf("%s\n", possible ? "YES" : "NO");
}