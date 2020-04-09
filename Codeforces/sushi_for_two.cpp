#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int main() {
    int n; scanf("%d", &n);

    int t[MAX];
    for (int i = 1; i <= n; i++)
        scanf("%d", &t[i]);

    t[0] = t[1];
    t[n + 1] = 0;

    int cnt[2] = {0}, longest = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (t[i] != t[i - 1]) {
            longest = max(longest, 2 * min(cnt[0], cnt[1]));
            cnt[0] = cnt[1]; cnt[1] = 1;
        } else cnt[1]++;
    }

    printf("%d\n", longest);
}