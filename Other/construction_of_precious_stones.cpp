#include <bits/stdc++.h>

using namespace std;

#define long long long int

const long INF = 1e18 + 5;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<long> a(max(n, k), INF);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long sum = a[0], value = a[0];
    for (int i = 1; i < k; i++) {
        a[i] = min(a[i], value);
        sum += a[i]; value += sum;
    }

    int ans = a[k - 1] % MOD;
    cout << ans << "\n";
}