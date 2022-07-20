#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define Vector Point

int sign(long x) {
    return !x ? 0 : (x < 0 ? -1 : 1);
}

template<typename T = long>
struct Point {
    T x, y;

    Point(): x(0), y(0) {}
    Point(T x, T y): x(x), y(y) {}

    Vector<T> operator -() {
        return Vector<T>(-x, -y);
    }

    Point<T> operator +(Vector<T> v) {
        return Point<T>(x + v.x, y + v.y);
    }

    Vector<T> operator -(Point<T> other) {
        return Point<T>(x - other.x, y - other.y);
    }

    Vector<T> operator *(T k) {
        return Vector<T>(x * k, y * k);
    }

    T operator *(Vector<T> other) {
        return x * other.x + y * other.y;
    }

    T operator /(Vector<T> other) {
        return x * other.y - y * other.x;
    }

    bool operator <(const Point<T> &other) const {
        if (!sign(x - other.x))
            return sign(y - other.y) < 0;

        return sign(x - other.x) < 0;
    }
};

template<typename T = long>
bool left_turn(Vector<T> u, Vector<T> v) {
    return sign(u / v) > 0;
}

template<typename T = long>
vector<pair<Point<T>, int>> half_hull(vector<pair<Point<T>, int>> &points, int l, int r, int d) {
    vector<pair<Point<T>, int>> hull;
    for (int i = l; i != r; i += d) {
        int size = hull.size();
        while (size > 1 && left_turn(hull[size - 1].first - hull[size - 2].first, points[i].first - hull[size - 2].first))
            hull.pop_back(), size--;

        hull.push_back(points[i]);
    }

    return hull;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c; cin >> c;
    while (c--) {
        int n; cin >> n;

        vector<pair<Point<int>, int>> points(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            points[i] = make_pair(Point<int>(x, y), i);
        }

        sort(points.begin(), points.end());

        vector<pair<Point<int>, int>> upper_hull = half_hull(points, 0, n, 1);

        vector<int> ans;
        vector<bool> in_hull(n, false);

        for (auto [P, idx]: upper_hull) {
            ans.push_back(idx);
            in_hull[idx] = true;
        }

        for (int i = n - 1; i >= 0; i--)
            if (!in_hull[points[i].second])
                ans.push_back(points[i].second);

        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << ans[i];
        }

        cout << "\n";
    }
}