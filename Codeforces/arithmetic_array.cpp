#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int sum = 0;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            sum += a;
        }

        int ans = sum < n ? 1 : sum - n;
        cout << ans << "\n";
    }
}