#include <bits/stdc++.h>

using namespace std;

const int MAX = 4e5 + 5;

int main() {
    int q, x; scanf("%d %d", &q, &x);
    int mods[MAX] = {0};

    set< pair<int, int> > cnt;
    for (int i = 0; i < x; i++)
        cnt.insert({0, i});

    while (q--) {
        int y; scanf("%d", &y);
        y %= x;

        cnt.erase({mods[y], y});
        cnt.insert({++mods[y], y});

        int MEX = cnt.begin()->first * x + cnt.begin()->second;
        printf("%d\n", MEX);
    }
}