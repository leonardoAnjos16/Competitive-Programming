#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;

        cout << (r < 2 * l ? "YES" : "NO") << "\n";
    }
}