#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int xa, xb, Xa, Xb;
        cin >> xa >> xb >> Xa >> Xb;

        int ans = Xa / xa + Xb / xb;
        cout << ans << "\n";
    }
}