#include <bits/stdc++.h>

using namespace std;

#define city pair<double, int>

const int MAX = 1e3 + 5;

int main() {
    int n, s; scanf("%d %d", &n, &s);

    city dists[MAX];
    dists[0] = {0.0, s};

    for (int i = 1; i <= n; i++) {
        int x, y, k; scanf("%d %d %d", &x, &y, &k);

        double dist = sqrt((x * x) + (y * y));
        dists[i] = {dist, k};
    }

    sort(dists + 1, dists + n + 1);
    for (int i = 1; i <= n; i++)
        dists[i].second += dists[i - 1].second;

    int l = 1, r = n, i = -1;
    while (l <= r) {
        int mid = (l + r) / 2;

        if (dists[mid].second < 1e6) l = mid + 1;
        else i = mid, r = mid - 1;
    }

    if (i == -1) printf("-1\n");
    else printf("%lf\n", dists[i].first);
}