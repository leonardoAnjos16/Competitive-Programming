#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int odd = 0, even = 0;
        for (int i = 1; i <= 10; i++) {
            int A; cin >> A;
            if (i % 2) odd += A;
            else even += A;
        }

        int ans = odd == even ? 0 : (odd > even ? 1 : 2);
        cout << ans << "\n";
    }
}