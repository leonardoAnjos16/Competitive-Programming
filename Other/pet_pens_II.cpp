#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    long sum = 0LL, mx = 0LL;
    while (n--) {
        int h, w;
        cin >> h >> w;

        sum += min(h, w);
        mx = max(mx, 1LL * max(h, w));
    }

    long ans = max(sum, mx);
    cout << ans << "\n";
}