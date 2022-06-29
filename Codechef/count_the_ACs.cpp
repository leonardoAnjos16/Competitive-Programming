#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int P; cin >> P;

        int ans = P / 100 + P % 100;
        if (ans > 10) cout << "-1\n";
        else cout << ans << "\n";
    }
}