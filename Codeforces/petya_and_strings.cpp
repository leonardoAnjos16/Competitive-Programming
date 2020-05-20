#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    char s[MAX], t[MAX];
    scanf("%s", s);
    scanf("%s", t);

    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        s[i] = tolower(s[i]);
        t[i] = tolower(t[i]);
    }

    int ans = strcmp(s, t);
    if (ans > 0) ans = 1;
    if (ans < 0) ans = -1;

    printf("%d\n", ans);
}