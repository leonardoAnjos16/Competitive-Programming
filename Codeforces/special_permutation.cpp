#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        if (n < 4) printf("-1\n");
        else {
            deque<int> ans;
            for (int i = 1; i <= n; i++) {
                if (i & 1) ans.push_back(i);
                else ans.push_front(i);
            }

            int even = n / 2;
            swap(ans[even - 2], ans[even - 1]);

            for (int i = 0; i < n; i++) {
                if (i) printf(" ");
                printf("%d", ans[i]);
            }

            printf("\n");
        }
    }
}