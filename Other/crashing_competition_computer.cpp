#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double

const ldouble EPS = 1e-9;
const ldouble INF = 1e18 + 5;

ldouble p;
int c, t, r;
vector<ldouble> expected;
vector<ldouble> memo;

int sign(ldouble x) {
    return fabsl(x) < EPS ? 0 : (x < 0 ? -1 : 1);
}

ldouble min_expected(int n) {
    if (!n) return 0;

    ldouble &ans = memo[n];
    if (sign(ans) >= 0) return ans;

    ans = expected[n] + t;
    for (int i = 1; i < n; i++)
        ans = min(ans, min_expected(i) + expected[n - i] + t);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    cin >> c >> t >> r >> p;

    expected.assign(c + 1, 0.0L);
    for (int i = 1; i <= c; i++)
        expected[i] = (expected[i - 1] + p * r + 1.0L) / (1.0L - p);

    memo.assign(c + 5, -1.0L);

    ldouble ans = min_expected(c);
    cout << ans << "\n";
}