#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m) {
        int ans = 1;
        while (m--) {
            int w, u, v;
            cin >> w >> u >> v;
            if (w & 1) ans *= w;
        }

        cout << ans << "\n";
    }
}