#include <bits/stdc++.h>

using namespace std;

int N;
vector<long double> p;
vector<vector<long double>> memo;

long double prob(int i = 0, int heads = 0) {
    if (heads > N / 2) return 1.0;
    if (i >= N) return 0.0;

    long double &ans = memo[i][heads];
    if (ans >= 0.0) return ans;

    return ans = p[i] * prob(i + 1, heads + 1) + (1 - p[i]) * prob(i + 1, heads);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(10) << fixed;

    cin >> N;

    p.resize(N);
    for (int i = 0; i < N; i++)
        cin >> p[i];

    memo.assign(N + 5, vector<long double>(N + 5, -1.0));

    long double ans = prob();
    cout << ans << "\n";
}