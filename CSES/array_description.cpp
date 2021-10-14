#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

int n, m;
vector<int> x;
vector<vector<int>> memo;

int arrays(int last, int i = 1) {
    if (i >= n) return 1;

    int &ans = memo[last][i];
    if (~ans) return ans;

    if (x[i]) {
        if (abs(x[i] - last) > 1) return 0;
        return ans = arrays(x[i], i + 1);
    }

    ans = 0;
    for (int j = -1; j <= 1; j++) {
        int xi = last + j;
        if (xi >= 1 && xi <= m) {
            ans += arrays(xi, i + 1);
            ans %= MOD;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    x.resize(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    memo.assign(m + 5, vector<int>(n + 5, -1));

    if (x[0]) {
        int ans = arrays(x[0]);
        cout << ans << "\n";
    } else {
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            ans += arrays(i);
            ans %= MOD;
        }

        cout << ans << "\n";
    }
}