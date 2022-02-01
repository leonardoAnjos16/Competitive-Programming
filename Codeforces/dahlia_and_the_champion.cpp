#include <bits/stdc++.h>

using namespace std;

long long int square_dist(int x1, int y1, int x2, int y2) {
    long long int dx = x2 - x1;
    long long int dy = y2 - y1;
    return dx * dx + dy * dy;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x0, y0, R, N;
    cin >> x0 >> y0 >> R >> N;

    set<pair<int, int>> pulled;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        if (square_dist(x0, y0, x, y) <= 1LL * R * R) {
            int dx = x - x0, dy = y - y0, g = gcd(dx, dy);
            pulled.insert(make_pair(dx / g, dy / g));
        }
    }

    int ans = pulled.size();
    cout << ans << "\n";
}