#include <bits/stdc++.h>

using namespace std;

const int MAX = 45;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        
        int a[MAX], cnt[2] = {0};
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (i % 2 != a[i] % 2) cnt[i % 2]++;
        }

        if (cnt[0] == cnt[1]) printf("%d\n", cnt[0]);
        else printf("-1\n");
    }
}