#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int k; cin >> k;

        int cnt = 1, ans = 1;
        while (cnt < k) {
            cnt++;
            do ans++;
            while (!(ans % 3) || ans % 10 == 3);
        }

        cout << ans << "\n";
    }
}