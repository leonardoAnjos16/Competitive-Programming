#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<int> memo;

int minutes(int slices) {
    if (slices <= 0) return 0;

    int &ans = memo[slices];
    if (~ans) return ans;

    return ans = min({
        15 + minutes(slices - 6),
        20 + minutes(slices - 8),
        25 + minutes(slices - 10)
    });
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    memo.assign(21, -1);

    while (t--) {
        long n; cin >> n;

        if (n <= 20) {
            int ans = minutes(n);
            cout << ans << "\n";
        } else {
            long ans = LLONG_MAX;

            long aux = (n - 20 + 5) / 6;
            ans = min(ans, aux * 15 + minutes(n - aux * 6));

            aux = (n - 20 + 7) / 8;
            ans = min(ans, aux * 20 + minutes(n - aux * 8));

            aux = (n - 20 + 9) / 10;
            ans = min(ans, aux * 25 + minutes(n - aux * 10));

            cout << ans << "\n";
        }
    }
}