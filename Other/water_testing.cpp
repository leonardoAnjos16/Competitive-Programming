#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<pair<int, int>> corners(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        corners[i] = make_pair(x, y);
    }

    long double_area = 0LL, inside_edge = n;
    for (int i = 0; i < n; i++) {
        auto [ax, ay] = corners[i];
        auto [bx, by] = corners[(i + 1) % n];

        double_area += 1LL * ax * by;
        double_area -= 1LL * ay * bx;
        inside_edge += gcd(abs(bx - ax), abs(by - ay)) - 1LL;
    }

    if (double_area < 0LL) double_area = -double_area;

    long ans = (double_area - inside_edge + 2LL) / 2LL;
    cout << ans << "\n";
}