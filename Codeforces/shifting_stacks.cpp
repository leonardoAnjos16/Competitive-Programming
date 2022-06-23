#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<long> h(n);
        for (int i = 0; i < n; i++)
            cin >> h[i];

        bool possible = true;
        if (n > 1) {
            h[1] += h[0];
            h[0] = 0;
        }

        for (int i = 1; i < n && possible; i++) {
            if (h[i] <= h[i - 1]) possible = false;
            if (i + 1 < n) {
                h[i + 1] += h[i] - (h[i - 1] + 1);
                h[i] = h[i - 1] + 1;
            }
        }

        cout << (possible ? "YES" : "NO") << "\n";
    }
}