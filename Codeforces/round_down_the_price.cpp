#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        string m; cin >> m;

        string aux = string(1, m[0] - 1) + m.substr(1);
        int ans = stoi(aux);
        cout << ans << "\n";
    }
}