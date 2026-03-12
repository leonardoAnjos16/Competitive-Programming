#include <bits/stdc++.h>

using namespace std;

#define ldouble long double

const ldouble EPS = 1e-9;

int sign(ldouble x) {
    return fabsl(x) < EPS ? 0 : (x < 0 ? -1 : 1);
}

int N;
vector<ldouble> p;
vector<vector<ldouble>> memo;

ldouble removed(int i = 0, int balance = 0) {
    if (i >= N) return abs(balance);

    ldouble &ans = memo[i][balance];
    if (sign(ans) >= 0) return ans;

    ans = p[i] * removed(i + 1, balance + 1);
    ans += (1 - p[i]) * (removed(i + 1, max(balance - 1, 0)) + (!balance ? 1 : 0));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    cin >> N;

    p.resize(N);
    for (int i = 0; i < N; i++)
        cin >> p[i];

    memo.assign(N + 5, vector<ldouble>(2 * N + 5, -1.0L));

    ldouble ans = N - removed();
    cout << ans << "\n";
}