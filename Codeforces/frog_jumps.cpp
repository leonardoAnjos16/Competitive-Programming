#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        char str[MAX];
        scanf("%s", str);

        int max_dist = 0;
        int n = strlen(str);

        int last_R = 0;
        for (int i = 1; i <= n; i++) {
            if (str[i - 1] == 'R') {
                max_dist = max(max_dist, i - last_R);
                last_R = i;
            }
        }

        max_dist = max(max_dist, n - last_R + 1);
        printf("%d\n", max_dist);
    }
}