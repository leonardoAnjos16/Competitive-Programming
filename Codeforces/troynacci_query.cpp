#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    int f[MAX];
    cin >> f[0] >> f[1];

    int a, b;
    cin >> a >> b;

    for (int i = 2; i < n; i++)
        f[i] = (1LL * a * f[i - 2] + 1LL * b * f[i - 1]) % MOD;

    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    vector<int> p(n, 0);
    while (q--) {
        int l, r;
        cin >> l >> r;

        if (l == r) x[l - 1] = (x[l - 1] + f[0]) % MOD;
        else {
            p[l - 1] = (p[l - 1] + f[0]) % MOD;
            p[l] = (((p[l] + f[1]) % MOD) - ((1LL * b * f[0]) % MOD) + MOD) % MOD;
            if (r < n) p[r] = (p[r] - f[r - l + 1] + MOD) % MOD;
            if (r + 1 < n) p[r + 1] = (p[r + 1] - ((1LL * a * f[r - l]) % MOD) + MOD) % MOD;
        }
    }

    p[1] = (p[1] + 1LL * b * p[0]) % MOD;
    for (int i = 2; i < n; i++) {
        p[i] = (p[i] + 1LL * a * p[i - 2]) % MOD;
        p[i] = (p[i] + 1LL * b * p[i - 1]) % MOD;
    }

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        int ans = (x[i] + p[i]) % MOD;
        cout << ans;
    }

    cout << "\n";
}