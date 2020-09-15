#include <bits/stdc++.h>

using namespace std;

#define pair pair<int, int>
#define p first
#define t second

const int MAX = 55;

bool comp(pair a, pair b) {
    return a.p > b.p || (a.p == b.p && a.t < b.t);
}

int main() {
    int n, k; scanf("%d %d", &n, &k);

    pair teams[MAX];
    int cnt[MAX][MAX] = {0};

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &teams[i].p, &teams[i].t);
        cnt[teams[i].p][teams[i].t]++;
    }

    sort(teams, teams + n, comp);
    printf("%d\n", cnt[teams[k - 1].p][teams[k - 1].t]);
}