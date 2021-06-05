#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<vector<long double>>> memo;

long double expected_rolls(int q1, int q2, int q3) {
    if (!q1 && !q2 && !q3) return 0.0;

    long double &ans = memo[q1][q2][q3];
    if (ans >= 0.0) return ans;

    ans = 1.0;
    if (q1) ans += (q1 + .0) / N * expected_rolls(q1 - 1, q2, q3);
    if (q2) ans += (q2 + .0) / N * expected_rolls(q1 + 1, q2 - 1, q3);
    if (q3) ans += (q3 + .0) / N * expected_rolls(q1, q2 + 1, q3 - 1);

    return ans = ans / ((q1 + q2 + q3 + .0) / N);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(10) << fixed;

    cin >> N;

    int q1 = 0, q2 = 0, q3 = 0;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        if (a == 1) q1++;
        else if (a == 2) q2++;
        else if (a == 3) q3++;
    }

    memo.assign(N + 5, vector<vector<long double>>(N + 5, vector<long double>(N + 5, -1.0)));

    long double ans = expected_rolls(q1, q2, q3);
    cout << ans << "\n";
}