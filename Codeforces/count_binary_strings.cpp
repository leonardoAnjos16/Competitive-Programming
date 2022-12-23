#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MOD = 998244353;

int n;
vector<vector<int>> a;
vector<vector<vector<int>>> memo;

int count(int last, int start = 0, int i = 1) {
    if (i >= n) return 1;

    int &ans = memo[last][start][i];
    if (~ans) return ans;

    ans = 0;
    for (int j = 0; j < 2; j++) {
        bool possible = true;
        for (int k = 0; k < i && possible; k++) {
            if (a[k][i] == 1 && (j != last || start > k)) possible = false;
            if (a[k][i] == 2 && j == last && start <= k) possible = false;
        }

        if (possible) ans = (ans + count(j, j == last ? start : i, i + 1)) % MOD;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    bool possible = true;
    a.assign(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            cin >> a[i][j];
            if (i == j && a[i][j] == 2)
                possible = false;
        }

    if (!possible) cout << "0\n";
    else {
        memo.assign(2, vector<vector<int>>(n + 5, vector<int>(n + 5, -1)));

        int ans = (count(0) + count(1)) % MOD;
        cout << ans << "\n";
    }
}