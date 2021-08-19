#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int T; cin >> T;
    while (T--) {
        long long int N, Q;
        cin >> N >> Q;

        long double ans = Q + N * Q / (Q + 1.0);
        cout << ans << "\n";
    }
}