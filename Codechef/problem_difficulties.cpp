#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 15;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int cnt[MAX] = {0}, mx = 0;
        for (int i = 0; i < 4; i++) {
            int A; cin >> A;
            mx = max(mx, ++cnt[A]);
        }

        int ans = mx <= 2 ? 2 : (mx <= 3 ? 1 : 0);
        cout << ans << "\n";
    }
}