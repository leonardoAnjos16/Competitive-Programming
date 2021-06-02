#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        vector<int> g(7);
        for (int i = 1; i <= 6; i++)
            cin >> g[i];

        int ans = g[6] + g[5];
        g[1] -= min(g[1], g[5]);

        ans += g[4];
        int paired = min(g[2], g[4]);
        g[2] -= paired;
        g[1] -= min(g[1], (g[4] - paired) * 2);

        ans += g[3] / 2;
        if (g[3] % 2) {
            ans++;
            if (g[2]) {
                g[2]--;
                if (g[1])
                    g[1]--;
            } else if (g[1]) {
                g[1] -= min(g[1], 3);
            }
        }

        ans += g[2] / 3;
        if (g[2] % 3) {
            ans++;
            int aux = 6 - (g[2] % 3) * 2;
            g[1] -= min(g[1], aux);
        }

        ans += (g[1] + 5) / 6;
        cout << ans << "\n";
    }
}