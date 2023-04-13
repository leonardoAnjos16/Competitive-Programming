#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    llong sum = 0LL;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    llong ans = 0LL;
    map<llong, int> cnt;

    for (int i = 0; i < n; i++) {
        ans += cnt[2LL * sum - 1LL * a[i] * n];
        cnt[1LL * a[i] * n]++;
    }

    cout << ans << "\n";
}