#include <bits/stdc++.h>

using namespace std;

#define coord pair<int, int>
#define x first
#define y second

const int MAX = 12;

int n; coord beepers[MAX];
int memo[1 << MAX][MAX];

int dist(coord a, coord b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int TSP(int vis, int last) {
    if (vis == (1 << n) - 1) return dist(beepers[last], beepers[0]);
    if (memo[vis][last] != -1) return memo[vis][last];

    memo[vis][last] = INT_MAX;
    for (int i = 1; i < n; i++)
        if (!(vis & (1 << i)))
            memo[vis][last] = min(memo[vis][last], dist(beepers[last], beepers[i]) + TSP(vis | (1 << i), i));

    return memo[vis][last];
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int x_size, y_size;
        scanf("%d %d", &x_size, &y_size);

        scanf("%d %d", &beepers[0].x, &beepers[0].y);
        scanf("%d", &n);

        for (int i = 1; i <= n; i++)
            scanf("%d %d", &beepers[i].x, &beepers[i].y);

        memset(memo, -1, sizeof memo); n++;
        int ans = TSP(1, 0);

        printf("The shortest path has length %d\n", ans);
    }
}