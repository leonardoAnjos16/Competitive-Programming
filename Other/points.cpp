#include <bits/stdc++.h>

using namespace std;

complex<long long int> get_vector(pair<int, int> a, pair<int, int> b) {
    return { b.first - a.first, b.second - a.second };
}

long long int cross(complex<long long int> u, complex<long long int> v) {
    return u.real() * v.imag() - v.real() * u.imag();
}

bool left_turn(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    auto u = get_vector(a, b);
    auto v = get_vector(b, c);
    return cross(u, v) > 0LL;
}

bool right_turn(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    auto u = get_vector(a, b);
    auto v = get_vector(b, c);
    return cross(u, v) < 0LL;
}

vector<pair<int, int>> get_hull(
    vector<pair<int, int>> points,
    bool (*correct_turn)(pair<int, int>, pair<int, int>, pair<int, int>)
) {
    int n = points.size(), cnt = 0;
    vector<pair<int, int>> hull;

    for (int i = 0; i < n; i++) {
        hull.push_back(points[i]); cnt++;
        while (cnt >= 3 && !correct_turn(hull[cnt - 3], hull[cnt - 2], hull[cnt - 1])) {
            hull[cnt - 2] = hull[cnt - 1];
            hull.pop_back(); cnt--;
        }
    }

    return hull;
}

long double dist(pair<int, int> a, pair<int, int> b) {
    int mn = abs(a.first - b.first);
    int mx = abs(a.second - b.second);
    if (mn > mx) swap(mn, mx);
    return mn * sqrt(2) + mx - mn;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("E.in", "r", stdin);

    cout << setprecision(6) << fixed;

    int N; cin >> N;

    vector<pair<int, int>> points;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        points.push_back(make_pair(x - 1, y));
        points.push_back(make_pair(x + 1, y));
        points.push_back(make_pair(x, y - 1));
        points.push_back(make_pair(x, y + 1));
    }

    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());

    vector<pair<int, int>> uhull = get_hull(points, right_turn);
    vector<pair<int, int>> lhull = get_hull(points, left_turn);

    long double ans = 0.0;
    for (int i = 1, n = uhull.size(); i < n; i++)
        ans += dist(uhull[i - 1], uhull[i]);

    for (int i = 1, n = lhull.size(); i < n; i++)
        ans += dist(lhull[i - 1], lhull[i]);

    cout << ans << "\n";
}