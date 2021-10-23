#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        long n, m, r, c;
        cin >> n >> m >> r >> c;

        // top left
        long ans = r + c - 2;

        // top right
        ans = max(ans, r + m - c - 1);

        // bottom left
        ans = max(ans, n - r + c - 1);

        // bottom right
        ans = max(ans, n - r + m - c);

        cout << ans << "\n";
    }
}