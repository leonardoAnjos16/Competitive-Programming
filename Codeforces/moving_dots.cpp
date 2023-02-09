#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MOD = 1e9 + 7;

int pow(int a, int n) {
    if (!n) return 1;

    int ans = pow(a, n >> 1);
    ans = (1LL * ans * ans) % MOD;

    if (!(n & 1)) return ans;
    return (1LL * ans * a) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int diff = x[j] - x[i];
            int l = lower_bound(x.begin(), x.end(), x[i] - diff) - x.begin() - 1;
            int r = lower_bound(x.begin(), x.end(), x[j] + diff) - x.begin();

            int size = l + 1 + n - r;
            ans = (ans + pow(2, size)) % MOD;
        }

    cout << ans << "\n";
}