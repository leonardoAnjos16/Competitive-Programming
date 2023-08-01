#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define Vector Point

template<typename T>
struct Point {
    T x, y;

    Point(T x = 0, T y = 0): x(x), y(y) {}

    Vector<T> operator -(Point<T> other) {
        return Vector<T>(x - other.x, y - other.y);
    }

    T operator *(Vector<T> other) {
        return x * other.x + y * other.y;
    }

    T operator /(Vector<T> other) {
        return x * other.y - other.x * y;
    }

    bool operator <(Point<T> const &other) const {
        if (x == other.x)
            return y < other.y;

        return x < other.x;
    }

    bool operator ==(Point<T> const &other) const {
        return x == other.x && y == other.y;
    }
};

template<typename T>
ldouble abs(Vector<T> v) {
    return sqrtl(v * v);
}

template<typename T>
bool right_turn(Vector<T> u, Vector<T> v) {
    return u / v < 0;
}

template<typename T>
vector<pair<Point<T>, int>> half_hull(vector<pair<Point<T>, int>> &points, int l, int r, int d) {
    vector<pair<Point<T>, int>> hull;
    for (int i = l; i != r; i += d) {
        int size = hull.size();
        while (size > 1 && !right_turn(hull[size - 1].first - hull[size - 2].first, points[i].first - hull[size - 2].first))
            hull.pop_back(), size--;

        hull.push_back(points[i]);
    }

    return hull;
}

template<typename T>
vector<pair<Point<T>, int>> convex_hull(vector<pair<Point<T>, int>> &points) {
    int n = points.size();
    sort(points.begin(), points.end());

    vector<pair<Point<T>, int>> hull = half_hull(points, 0, n, 1);
    vector<pair<Point<T>, int>> lower = half_hull(points, n - 1, -1, -1);

    for (int i = 1; i < (int) lower.size() - 1; i++)
        hull.push_back(lower[i]);

    return hull;
}

template<typename T>
T double_area(Point<T> A, Point<T> B, Point<T> C) {
    return (B - A) / (C - A);
}

template<typename T>
T double_area(vector<pair<Point<T>, int>> &points) {
    Point<T> O;
    int n = points.size();

    T ans = 0;
    for (int i = 0; i < n; i++) {
        Point<T> P = points[i].first, Q = points[(i + 1) % n].first;
        ans += double_area(O, P, Q);
    }

    return ans;
}

template<typename T>
istream& operator >>(istream &cin, Point<T> &P) {
    T x, y;
    cin >> x >> y;
    P = Point<T>(x, y);
    return cin;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(15) << fixed;

    int n; cin >> n;

    vector<pair<Point<llong>, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first;
        points[i].second = i;
    }

    vector<pair<Point<llong>, int>> hull = convex_hull(points);
    reverse(hull.begin(), hull.end());
    n = hull.size();

    cout << n << "\n";

    ldouble perimeter = 0.0L;
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << (hull[i].second + 1);
        perimeter += abs(hull[(i + 1) % n].first - hull[i].first);
    }

    cout << "\n";

    llong darea = double_area(hull);
    cout << perimeter << "\n" << (darea / 2) << (darea & 1LL ? ".5" : "") << "\n";
}