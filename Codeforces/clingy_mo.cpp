#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; scanf("%d", &n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int E; scanf("%d", &E);
        if (i > 0 && i < n - 1) sum += E;
    }

    printf("%d\n", sum);
}