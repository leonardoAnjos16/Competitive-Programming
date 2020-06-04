#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 5;
const int INF = 1e6;

int X, wind[10][MAX];
int memo[10][MAX];

int fuel(int alt = 0, int pos = 0) {
    if (!alt && pos >= X) return 0;
    if (alt < 0 || alt >= 10 || pos >= X) return INF;
    if (memo[alt][pos] != -1) return memo[alt][pos];

    int climb = 60 + fuel(alt + 1, pos + 1);
    int hold = 30 + fuel(alt, pos + 1);
    int sink = 20 + fuel(alt - 1, pos + 1);

    return memo[alt][pos] = min(climb, min(hold, sink)) - wind[alt][pos];
}

int main() {
    int N; scanf("%d", &N);
    while (N--) {
        scanf("%d", &X); X /= 100;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < X; j++)
                scanf("%d", &wind[9 - i][j]);

        memset(memo, -1, sizeof memo);
        int ans = fuel();

        printf("%d\n\n", ans);
    }
}