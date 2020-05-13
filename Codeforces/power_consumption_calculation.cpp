#include <bits/stdc++.h>

using namespace std;

#define pair pair<int, int>
#define l first
#define r second

const int MAX = 105;

int main() {
    int n, P[3], T[2];
    scanf("%d", &n);

    for (int i = 0; i < 3; i++)
        scanf("%d", &P[i]);

    for (int i = 0; i < 2; i++)
        scanf("%d", &T[i]);

    pair periods[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &periods[i].l, &periods[i].r);

    int ans = (periods[0].r - periods[0].l) * P[0];
    for (int i = 1; i < n; i++) {
        int time = periods[i].l - periods[i - 1].r;

        ans += min(T[0], time) * P[0]; time -= T[0];
        if (time > 0) ans += min(T[1], time) * P[1], time -= T[1];
        if (time > 0) ans += time * P[2];

        ans += (periods[i].r - periods[i].l) * P[0];
    }

    printf("%d\n", ans);
}