#include <bits/stdc++.h>

using namespace std;

const int MAX = 35;

int main() {
    int T; scanf("%d", &T);
    int case_num = 1;

    while (T--) {
        int n, P, Q; scanf("%d %d %d", &n, &P, &Q);

        int w[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &w[i]);

        sort(w, w + n);

        int ans = 0, idx = -1, sum = 0;
        while (idx + 1 < n && ans < P && sum + w[idx + 1] <= Q)
            sum += w[++idx], ans++;

        printf("Case %d: %d\n", case_num++, ans);
    }
}