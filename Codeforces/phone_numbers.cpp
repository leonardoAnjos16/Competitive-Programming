#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int n; scanf("%d", &n);
    char s[MAX]; scanf("%s", s);

    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '8') cnt++;

    int ans = min(n / 11, cnt);
    printf("%d\n", ans);
}