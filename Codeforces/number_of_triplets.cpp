#include <bits/stdc++.h>

using namespace std;

#define point pair<int, int>
#define x first
#define y second

const int MAX = 3e3 + 5;

int main() {
    int n; scanf("%d", &n);

    point p[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &p[i].x, &p[i].y);

    sort(p, p + n);

    int ans = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if ((p[i].x + p[j].x) % 2 == 0 && (p[i].y + p[j].y) % 2 == 0)
                ans += binary_search(p, p + n, make_pair((p[i].x + p[j].x) / 2, (p[i].y + p[j].y) / 2));

    printf("%d\n", ans);
}