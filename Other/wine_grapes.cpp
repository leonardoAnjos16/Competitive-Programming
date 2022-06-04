#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int mx = 0;
    long sum = 0LL;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }

    long ans = max((sum + n - 2LL) / (n - 1LL), 1LL * mx);
    cout << ans << "\n";
}