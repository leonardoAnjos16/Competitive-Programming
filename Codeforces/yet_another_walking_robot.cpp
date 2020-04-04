#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        char path[MAX]; scanf("%s", path);

        map<pair<int, int>, int> last_pos;
        last_pos[{0, 0}] = 0;

        int x = 0, y = 0;
        int l = -1, r = n;

        for (int i = 0; i < n; i++) {
            if (path[i] == 'L') x -= 1;
            else if (path[i] == 'R') x += 1;
            else if (path[i] == 'U') y -= 1;
            else y += 1;

            if (last_pos.count({x, y}) && (r - l) > (i - last_pos[{x, y}]))
                l = last_pos[{x, y}] + 1, r = i + 1;
            
            last_pos[{x, y}] = i + 1;
        }

        if (l == -1) printf("-1\n");
        else printf("%d %d\n", l, r);
    }
}