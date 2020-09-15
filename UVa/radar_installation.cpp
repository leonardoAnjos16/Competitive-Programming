#include <bits/stdc++.h>

using namespace std;

#define interval pair<double, double>
#define l first
#define r second

const int MAX = 1e3 + 5;

int main() {
    int n, d, num_case = 1;
    while (scanf("%d %d", &n, &d), n | d) {
        interval A[MAX];
        bool possible = true;

        for (int i = 0; i < n; i++) {
            int x, y; scanf("%d %d", &x, &y);
            if (y > d) possible = false;

            if (possible) {
                double ext = sqrt(d * d - y * y);
                A[i].l = x - ext; A[i].r = x + ext;
            }
        }

        if (!possible) printf("Case %d: -1\n", num_case++);
        else {
            sort(A, A + n);

            double pos = A[0].r;
            int idx = 0, ans = 0;

            while (idx < n) {
                while (idx < n && A[idx].l <= pos) pos = min(pos, A[idx++].r);
                pos = A[idx].r; ans++;
            }

            printf("Case %d: %d\n", num_case++, ans);
        }
    }
}