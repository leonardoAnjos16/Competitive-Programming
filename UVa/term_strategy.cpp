#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 15;
const int MAX_M = 105;
const int INF = 1e9;

int N, M, L[MAX_N][MAX_M];
int memo[MAX_M][MAX_N];

int score(int t, int i) {
    if (!t && i <= N) return -INF;
    if (i > N) return 0;

    int &ans = memo[t][i];
    if (ans != -1) return ans;

    ans = -INF;
    for (int j = 1; j <= t; j++) if (L[i][j] >= 5)
        ans = max(ans, L[i][j] + score(t - j, i + 1));

    return ans;
}

double round(double v) {
    int aux = v * 1000;
    if (aux % 10 >= 5) aux += 5;
    return aux / 1000.0;
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                scanf("%d", &L[i][j]);

        memset(memo, -1, sizeof memo);

        double ans = score(M, 1) / (N + .0);
        if (ans < 0) printf("Peter, you shouldn't have played billiard that much.\n");
        else printf("Maximal possible average mark - %.2lf.\n", round(ans));
    }
}