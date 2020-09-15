#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4 + 5;

int main() {
    int L, G;
    while (scanf("%d %d", &L, &G), L | G) {
        pair<int, int> area[MAX];
        for (int i = 0; i < G; i++) {
            int x, r; scanf("%d %d", &x, &r);
            area[i].first = x - r;
            area[i].second = x + r;
        }

        sort(area, area + G);

        int max_covered = 0, idx = 0, ans = 0;
        while (idx < G) {
            int aux = INT_MIN;
            while (idx < G && area[idx].first <= max_covered)
                aux = max(aux, area[idx++].second), ans++;

            if (--ans < 0) break;

            max_covered = aux;
            if (max_covered >= L) ans += G - idx, idx = G;
        }

        if (max_covered < L) printf("-1\n");
        else printf("%d\n", ans);
    }
}