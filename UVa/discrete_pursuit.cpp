#include <bits/stdc++.h>

using namespace std;

#define pair pair<int, int>
#define x first
#define y second

int main() {
    int a;
    while (scanf("%d", &a) != EOF) {
        int u; scanf("%d", &u);
        int v; scanf("%d", &v);

        if (!a) {
            printf("0\n");
            continue;
        }

        pair thief = {a, 0}, cop = {0, 0}, speed = {0, 0};

        int cnt = 0;
        while (cop.x < thief.x) {
            cop.x += ++speed.x;
            thief.x += u; cnt++;
        }

        int ans = cnt; cnt = 0;
        do {
            cop.y += ++speed.y;
            thief.y += v; cnt++;
        } while (cop.y < thief.y);

        ans = max(ans, cnt);
        printf("%d\n", ans);
    }
}