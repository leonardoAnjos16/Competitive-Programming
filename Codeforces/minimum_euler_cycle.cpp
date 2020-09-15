#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e5 + 5;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n; long l, r;
        scanf("%d %lld %lld", &n, &l, &r);

        long pos[MAX] = {0};
        for (int i = 1; i < n; i++)
            pos[i] = pos[i - 1] + ((n - i) << 1);

        int v = lower_bound(pos, pos + n, l) - pos;

        bool odd = l & 1LL;
        int u = v + 1 + ((l - pos[v - 1] - 1) >> 1LL);

        long cnt = r - l + 1;
        while (v < n && cnt) {
            while (u <= n && cnt) {
                if (odd) printf("%d ", v);
                else printf("%d ", u++);

                odd = !odd; cnt--;
            }

            u = ++v + 1;
            odd = true;
        }

        if (cnt) printf("1\n");
        else printf("\n");
    }
}