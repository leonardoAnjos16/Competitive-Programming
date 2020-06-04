#include <bits/stdc++.h>

using namespace std;

#define edge pair<int, double>
#define vertex first
#define weight second

#define opera pair<int, double>
#define store first
#define diff second

typedef vector<edge> ve;

const int MAX = 55;
const int INF = 1e6;

int N, M, P;
opera A[15];
vector<ve> g;
double d[MAX][MAX];
double memo[1 << 15][15];

void fill_memo() {
    for (int i = 0; i < 1 << 15; i++)
        for (int j = 0; j < 15; j++)
            memo[i][j] = INF;
}

void get_dists() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            d[i][j] = INF;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < (int) g[i].size(); j++)
            d[i][g[i][j].vertex] = min(d[i][g[i][j].vertex], g[i][j].weight);

    for (int i = 0; i < N; i++)
        d[i][i] = 0.0;

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

double savings(int vis = 1, int last = 0) {
    if (vis == (1 << P) - 1) return -d[A[last].store][0];
    if (memo[vis][last] < INF) return memo[vis][last];

    memo[vis][last] = savings((1 << P) - 1, last);
    for (int i = 1; i < P; i++)
        if (!(vis & (1 << i)))
            memo[vis][last] = max(memo[vis][last], A[i].diff - d[A[last].store][A[i].store] + savings(vis | (1 << i), i));

    return memo[vis][last];
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &N, &M);
        g.assign(++N, ve());

        for (int i = 0; i < M; i++) {
            int v1, v2; double w;
            scanf("%d %d %lf", &v1, &v2, &w);

            g[v1].push_back({v2, w});
            g[v2].push_back({v1, w});
        }

        get_dists();
        scanf("%d", &P);

        A[0] = {0, 0.0};
        for (int i = 1; i <= P; i++)
            scanf("%d %lf", &A[i].store, &A[i].diff);

        fill_memo(); P++;
        double ans = savings();

        if (ans <= 1e-3) printf("Don't leave the house\n");
        else printf("Daniel can save $%.2lf\n", ans);
    }
}