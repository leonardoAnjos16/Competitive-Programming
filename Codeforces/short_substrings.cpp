#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        char b[MAX]; scanf("%s", b);
        int n = strlen(b);

        char a[MAX]; a[0] = b[0];
        int cnt = 1;

        for (int i = 1; i < n; i += 2)
            a[cnt++] = b[i];

        a[cnt] = '\0';
        printf("%s\n", a);
    }
}