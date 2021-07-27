#include <bits/stdc++.h>

using namespace std;

#define long long long int

long cross(complex<long> u, complex<long> v) {
    return u.real() * v.imag() - v.real() * u.imag();
}

bool left_turn(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    complex<long> u = { b.first - a.first, b.second - a.second };
    complex<long> v = { c.first - b.first, c.second - b.second };
    return cross(u, v) > 0;
}

bool right_turn(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    complex<long> u = { b.first - a.first, b.second - a.second };
    complex<long> v = { c.first - b.first, c.second - b.second };
    return cross(u, v) < 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        A[i] = make_pair(x, y);
    }

    int m; cin >> m;
    sort(A.begin(), A.end());

    vector<pair<int, int>> points(n + m);
    for (int i = 0; i < n; i++) points[i] = A[i];

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        points[n + i] = make_pair(x, y);

        if (binary_search(A.begin(), A.end(), points[n + i])) {
            cout << "NO\n";
            return 0;
        }
    }

    sort(points.begin(), points.end());

    int cnt = 0;
    vector<pair<int, int>> upper_hull;

    for (int i = 0; i < n + m; i++) {
        upper_hull.push_back(points[i]); cnt++;
        while (cnt >= 3 && left_turn(upper_hull[cnt - 3], upper_hull[cnt - 2], upper_hull[cnt - 1])) {
            auto last = upper_hull[--cnt];
            upper_hull.pop_back();
            upper_hull.pop_back();
            upper_hull.push_back(last);
        }
    }

    cnt = 0;
    vector<pair<int, int>> lower_hull;

    for (int i = 0; i < n + m; i++) {
        lower_hull.push_back(points[i]); cnt++;
        while (cnt >= 3 && right_turn(lower_hull[cnt - 3], lower_hull[cnt - 2], lower_hull[cnt - 1])) {
            auto last = lower_hull[--cnt];
            lower_hull.pop_back();
            lower_hull.pop_back();
            lower_hull.push_back(last);
        }
    }

    vector<pair<int, int>> convex_hull;
    for (auto p: upper_hull) convex_hull.push_back(p);
    for (auto p: lower_hull) convex_hull.push_back(p);

    sort(convex_hull.begin(), convex_hull.end());

    bool ans = (int) convex_hull.size() == (int) A.size() + 2;
    for (int i = 1; i <= n && ans; i++)
        if (A[i - 1] != convex_hull[i])
            ans = false;

    cout << (ans ? "YES" : "NO") << "\n";
}