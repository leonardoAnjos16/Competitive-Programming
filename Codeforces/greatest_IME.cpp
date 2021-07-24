#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

long pow(int a, int b) {
    if (!b) return 1LL;

    long ans = pow(a, b >> 1);
    ans = (ans * ans) % MOD;

    if (!(b & 1)) return ans;
    return (ans * a) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    cin >> n >> c;

    long ans = pow(6, n);
    for (int i = c - 3 * n + 1; i <= c - 2 * n; i++)
        ans = (ans * i) % MOD;

    cout << ans << "\n";
}