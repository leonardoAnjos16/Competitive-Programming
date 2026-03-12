#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int n, k;
vector<llong> a;
vector<vector<vector<pair<int, llong>>>> memo;

pair<int, llong> average(int i, int j, int guesses = 0) {
    if (guesses > k) return make_pair(false, -1LL);
    if (i == j) return make_pair(true, a[i] * guesses);

    auto [possible, ans] = memo[i][j][guesses];
    if (~possible) return make_pair(possible, ans);

    ans = LLONG_MAX;
    possible = false;

    for (int m = i; m < j; m++) {
        auto [p1, a1] = average(i, m, guesses + 1);
        auto [p2, a2] = average(m + 1, j, guesses + 1);

        if (p1 && p2) {
            possible = true;
            ans = min(ans, a1 + a2);
        }
    }

    return memo[i][j][guesses] = make_pair(possible, ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    a.resize(n);
    llong sum = 0LL;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a.rbegin(), a.rend());

    memo.assign(n + 5, vector<vector<pair<int, llong>>>(n + 5, vector<pair<int, llong>>(k + 5, make_pair(-1, -1))));

    auto [possible, ans] = average(0, n - 1);
    if (!possible) cout << "No solution\n";
    else {
        llong g = gcd(ans, sum);
        ans /= g; sum /= g;
        cout << ans << "/" << sum << "\n";
    }
}