#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<int> memo;

int steps(int n) {
    if (!n) return 0;

    int &ans = memo[n];
    if (~ans) return ans;

    int aux = n;
    ans = INT_MAX;

    while (aux) {
        int d = aux % 10;
        if (d) ans = min(ans, steps(n - d) + 1);
        aux /= 10;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    memo.assign(n + 5, -1);

    int ans = steps(n);
    cout << ans << "\n";
}