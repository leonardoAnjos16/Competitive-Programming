#include <bits/stdc++.h>

using namespace std;

#define ldouble long double

const ldouble MAX = 1e18 + 5;

int N;
vector<int> x, y;

ldouble dist(int i, int j) {
    int dx = x[i] - x[j];
    int dy = y[i] - y[j];

    return sqrtl(dx * dx + dy * dy);
}

ldouble min_cost(int available = 0) {
    if (available + 1 >= 1 << (2 * N)) return 0.0L;

    int i = 0;
    while (i < 2 * N && (available & (1 << i))) i++;

    int j = i;
    ldouble ans = MAX;

    while (++j < 2 * N) {
        if (available & (1 << j)) continue;
        ans = min(ans, dist(i, j) + min_cost(available ^ (1 << i) ^ (1 << j)));
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(2) << fixed;

    int t = 1;
    while (cin >> N, N) {
        x.resize(2 * N);
        y.resize(2 * N);

        for (int i = 0; i < 2 * N; i++) {
            string _s; cin >> _s;
            cin >> x[i] >> y[i];
        }

        ldouble ans = min_cost();
        cout << "Case " << t++ << ": " << ans << "\n";
    }
}