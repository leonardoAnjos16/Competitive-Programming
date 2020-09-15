#include <bits/stdc++.h>

using namespace std;

#define coord pair<int, int>
#define x first
#define y second

const int MAX = 1e3 + 5;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        coord p[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d %d", &p[i].x, &p[i].y);

        sort(p, p + n);

        string ans = "";
        coord curr = {0, 0};

        bool possible = true;
        for (int i = 0; i < n && possible; i++) {
            if (curr.y > p[i].y) possible = false;
            else {
                while (curr.x < p[i].x) ans += 'R', curr.x++;
                while (curr.y < p[i].y) ans += 'U', curr.y++;
            }
        }

        if (!possible) printf("NO\n");
        else printf("YES\n%s\n", ans.c_str());
    }
}