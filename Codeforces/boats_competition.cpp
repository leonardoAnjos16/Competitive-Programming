#include <bits/stdc++.h>

using namespace std;

const int MAX = 55;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        int w[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &w[i]);

        sort(w, w + n);

        int ans = INT_MIN;
        for (int s = 2; s <= 100; s++) {
            int l = 0, r = n - 1, cnt = 0;
            while (l < r) {
                while (l < r && w[l] + w[r] < s) l++;
                while (l < r && w[l] + w[r] > s) r--;
                if (l < r && w[l] + w[r] == s) cnt++, l++, r--;
            }

            ans = max(ans, cnt);
        }

        printf("%d\n", ans);
    }
}