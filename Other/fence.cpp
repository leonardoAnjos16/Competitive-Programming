#include <bits/stdc++.h>

using namespace std;

#define Vector Point

int sign(long long int x) {
    return !x ? 0 : (x < 0 ? -1 : 1);
}

template<typename T = long long int>
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

template<typename T = long long int>
bool right_turn(Vector<T> u, Vector<T> v) {
    return sign(u / v) < 0;
}

template<typename T = long long int>
vector<Point<T>> half_hull(vector<Point<T>> &points, int l, int r, int d) {
    vector<Point<T>> hull;
    for (int i = l; i != r; i += d) {
        int size = hull.size();
        while (size > 1 && !right_turn(hull[size - 1] - hull[size - 2], points[i] - hull[size - 2]))
            hull.pop_back(), size--;

        hull.push_back(points[i]);
    }

    return hull;
}

template<typename T = long long int>
vector<Point<T>> convex_hull(vector<Point<T>> &points) {
    int n = points.size();
    sort(points.begin(), points.end());

    vector<Point<T>> hull = half_hull(points, 0, n, 1);
    vector<Point<T>> lower = half_hull(points, n - 1, -1, -1);

    for (int i = 1; i < (int) lower.size() - 1; i++)
        hull.push_back(lower[i]);

    return hull;
}

long double dist(Point<long long int> P, Point<long long int> Q) {
    Vector<long long int> v = Q - P;
    return sqrtl(1.0L * v.x * v.x + 1.0L * v.y * v.y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int n, l;
    cin >> n >> l;

    vector<Point<long long int>> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        points.emplace_back(x - l, y);
        points.emplace_back(x + l, y);
        points.emplace_back(x, y - l);
        points.emplace_back(x, y + l);
    }

    vector<Point<long long int>> hull = convex_hull(points);
    n = hull.size();

    long double ans = 0.0L;
    for (int i = 0; i < n; i++)
        ans += dist(hull[i], hull[(i + 1) % n]);

    cout << ans << "\n";
}