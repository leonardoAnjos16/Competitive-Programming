#include <bits/stdc++.h>

using namespace std;

const long double PI = acos(-1.0);

complex<int> point(pair<int, int> a, pair<int, int> b) {
    return { b.first - a.first, b.second - a.second };
}

int cross(complex<int> u, complex<int> v) {
    return u.real() * v.imag() - v.real() * u.imag();
}

int dot(complex<int> u, complex<int> v) {
    return u.real() * v.real() + u.imag() * v.imag();
}

bool left_turn(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    complex<int> u = point(a, b);
    complex<int> v = point(b, c);
    return cross(u, v) > 0;
}

bool right_turn(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    complex<int> u = point(a, b);
    complex<int> v = point(b, c);
    return cross(u, v) < 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    int L; cin >> L;

    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;
        points[i] = make_pair(X, Y);
    }

    sort(points.begin(), points.end());

    int cnt = 0;
    vector<pair<int, int>> uhull;

    for (int i = 0; i < N; i++) {
        uhull.push_back(points[i]); cnt++;
        while (cnt >= 3 && !right_turn(uhull[cnt - 3], uhull[cnt - 2], uhull[cnt - 1])) {
            uhull[cnt - 2] = uhull[cnt - 1];
            uhull.pop_back(); cnt--;
        }
    }

    cnt = 0;
    vector<pair<int, int>> lhull;

    for (int i = 0; i < N; i++) {
        lhull.push_back(points[i]); cnt++;
        while (cnt >= 3 && !left_turn(lhull[cnt - 3], lhull[cnt- 2], lhull[cnt - 1])) {
            lhull[cnt - 2] = lhull[cnt - 1];
            lhull.pop_back(); cnt--;
        }
    }

    reverse(uhull.begin(), uhull.end());
    cnt = (int) uhull.size() + (int) lhull.size() - 2;

    vector<pair<int, int>> hull;
    for (auto p: lhull)
        hull.push_back(p);

    for (int i = 1, sz = uhull.size(); i + 1 < sz; i++)
        hull.push_back(uhull[i]);

    long double length = 2 * PI * L;
    for (int i = 0; i < cnt; i++) {
        complex<int> v = point(hull[i], hull[(i + 1) % cnt]);
        length += sqrt(dot(v, v));
    }

    int ans = round(length);
    cout << ans << "\n";
}