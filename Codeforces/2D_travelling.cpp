#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k, a, b;
        cin >> n >> k >> a >> b;

        vector<llong> x(n), y(n);
        for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i];

        llong ans = abs(x[a - 1] - x[b - 1]) + abs(y[a - 1] - y[b - 1]);
        if (k == 0) cout << ans << "\n";
        else {
            llong best_from_a = LLONG_MAX, best_to_b = LLONG_MAX;
            for (int i = 0; i < k; i++) {
                best_from_a = min(best_from_a, abs(x[i] - x[a - 1]) + abs(y[i] - y[a - 1]));
                best_to_b = min(best_to_b, abs(x[i] - x[b - 1]) + abs(y[i] - y[b - 1]));
            }

            ans = min(ans, best_from_a + best_to_b);
            cout << ans << "\n";
        }
    }
}