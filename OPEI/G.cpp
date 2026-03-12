#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int xr, yr, zr;
    cin >> xr >> yr >> zr;

    int n; cin >> n;

    llong best_square_dist = LLONG_MAX;
    tuple<int, int, int> ans = make_tuple(-1, -1, -1);

    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        int dx = xr - x, dy = yr - y, dz = zr - z;
        llong square_dist = 1LL * dx * dx + 1LL * dy * dy + 1LL * dz * dz;

        if (square_dist < best_square_dist) {
            best_square_dist = square_dist;
            ans = make_tuple(x, y, z);
        }
    }

    auto [x, y, z] = ans;
    cout << "Cooper, a coordenada mais proxima e: " << x << " " << y << " " << z << "\n";
}