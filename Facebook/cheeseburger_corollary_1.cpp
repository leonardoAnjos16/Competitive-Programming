#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int S, D, K;
        cin >> S >> D >> K;

        int buns = 2 * S + 2 * D;
        int burgers = S + 2 * D;
        int cheese = S + 2 * D;

        bool possible = buns >= K + 1 && burgers >= K && cheese >= K;
        cout << "Case #" << t << ": " << (possible ? "YES" : "NO") << "\n";
    }
}