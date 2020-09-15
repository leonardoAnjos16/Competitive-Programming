#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    char s[MAX]; scanf("%s", s);
    int n = strlen(s);

    int ans = 0; char let = 'a';
    for (int i = 0; i < n; i++) {
        int dist = max(s[i], let) - min(s[i], let);
        ans += min(dist, 26 - dist); let = s[i];
    }

    printf("%d\n", ans);
}