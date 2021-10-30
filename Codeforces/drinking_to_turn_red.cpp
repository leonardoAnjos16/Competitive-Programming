#include <bits/stdc++.h>

using namespace std;

long double dist(int x1, int y1, int x2, int y2) {
    long long int dx = x2 - x1, dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

bool comp(pair<long double, int> &a, pair<long double, int> &b) {
    return a.first - a.second < b.first - b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int N, x, y;
    cin >> N >> x >> y;

    vector<pair<long double, int>> rings(N);
    for (int i = 0; i < N; i++) {
        int X, Y, R;
        cin >> X >> Y >> R;

        long double d = dist(X, Y, x, y);
        rings[i] = make_pair(d, R);
    }

    sort(rings.begin(), rings.end(), comp);

    long double l = 0.0, r = 1e18, ans;
    for (int i = 0; i < 100; i++) {
        long double mid = (l + r) / 2.0;

        bool possible = true;
        long double radius = mid;

        for (int j = 0; j < N; j++) {
            auto [d, r] = rings[j];
            if (d > r + radius) possible = false;
            else radius += r;
        }

        if (!possible) l = mid;
        else r = mid, ans = mid;
    }

    cout << ans << "\n";
}