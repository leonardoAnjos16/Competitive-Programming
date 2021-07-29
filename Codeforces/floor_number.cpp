#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;

        if (n <= 2) cout << "1\n";
        else {
            int ans = (n + x - 3) / x + 1;
            cout << ans << "\n";
        }
    }
}