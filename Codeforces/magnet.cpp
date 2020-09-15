#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; scanf("%d", &n);

    char last[5]; scanf("%s", last);
    int ans = 1;

    for (int i = 1; i < n; i++) {
        char dom[5]; scanf("%s", dom);
        if (dom[0] == last[1]) ans++;
        strcpy(last, dom);
    }

    printf("%d\n", ans);
}