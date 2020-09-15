#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int MAX = 2e3 + 5;

ll bit[MAX][MAX];
int N, M;

int LSO(int i) { return (i & -i); }

void update(int x, int y, ll v) {
    for (int i = x; i <= N; i += LSO(i))
        for (int j = y; j <= M; j += LSO(j))
            bit[i][j] += v;
}

ll get_sum(int x, int y) {
    ll sum = 0;
    for (int i = x; i > 0; i -= LSO(i))
        for (int j = y; j > 0; j -= LSO(j))
            sum += bit[i][j];

    return sum;
}

ll get_sum(int x1, int y1, int x2, int y2) {
    return get_sum(x2, y2) - get_sum(x1 - 1, y2) - get_sum(x2, y1 - 1) + get_sum(x1 - 1, y1 - 1);
}

int main() {
    int Q; scanf("%d %d %d", &N, &M, &Q);
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= M; j++)
            bit[i][j] = 0;

    ll bees;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%lld", &bees);
            update(i, j, bees);
        }
    }

    while (Q--) {
        int type; scanf("%d", &type);
        if (type == 1) {
            int x, y; ll v;
            scanf("%d %d %lld", &x, &y, &v);
            update(x, y, v);
        } else {
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

            ll sum = get_sum(x1, y1, x2, y2);
            printf("%lld\n", sum);
        }
    }
}