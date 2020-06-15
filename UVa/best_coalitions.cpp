#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 105;
const int MAX_P = 1e4 + 5;
const double INF = 1e9;

int n, x, P[MAX_N];
double memo[MAX_P][MAX_N];

int to_int(string input) {
    string num = "";
    for (int i = 0; i < (int) input.size(); i++)
        if (input[i] != '.') num += input[i];

    return stoi(num);
}

double round(double v) {
    return floor((v * 100) + .5) / 100;
}

double percentage(int p, int i = 1) {
    if (p > 5000) return round(100.0 * P[x] / p);
    if (i > n) return -INF;

    double &ans = memo[p][i];
    if (fabs(ans) > 1e-9) return ans;

    ans = percentage(p, i + 1);
    if (i != x) ans = max(ans, percentage(p + P[i], i + 1));

    return ans;
}

int main() {
    while (scanf("%d %d", &n, &x), n || x) {
        memset(memo, 0, sizeof memo);
        for (int i = 1; i <= n; i++) {
            string stock; cin >> stock;
            P[i] = to_int(stock);
        }

        double ans = percentage(P[x]);
        printf("%.2lf\n", ans);
    }
}