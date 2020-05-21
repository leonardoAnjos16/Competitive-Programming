#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int main() {
    int a[10];
    for (int i = 0; i < 4; i++)
        scanf("%d", &a[i]);

    char s[MAX]; scanf("%s", s);
    int n = strlen(s);

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += a[s[i] - '1'];

    printf("%d\n", ans);
}