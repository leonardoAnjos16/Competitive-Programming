#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        long last;
        cin >> last;

        long ans = 0LL;
        for (int i = 1; i < n; i++) {
            long a; cin >> a;
            ans = max(ans, last * a);
            last = a;
        }

        cout << ans << "\n";
    }
}