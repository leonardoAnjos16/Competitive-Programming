#include <bits/stdc++.h>

using namespace std;

const int MAX = 55;

int main() {
    int n; scanf("%d", &n);
    char s[MAX]; scanf("%s", s);

    int cnt = 1, ans = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) cnt++;
        else ans += cnt - 1, cnt = 1;
    }

    ans += cnt - 1;
    printf("%d\n", ans);
}