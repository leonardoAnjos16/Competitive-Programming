#include <bits/stdc++.h>

using namespace std;

#define llong long long int
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
        if (x == other.x) return y < other.y;
        return x < other.x;
    }
};

template<typename T>
bool left_turn(Vector<T> u, Vector<T> v) {
    return u / v > 0;
}

template<typename T = llong>
vector<Point<T>> half_hull(vector<Point<T>> &points, int l, int r, int d) {
    vector<Point<T>> hull;
    for (int i = l; i != r; i += d) {
        int size = hull.size();
        while (size > 1 && left_turn(hull[size - 1] - hull[size - 2], points[i] - hull[size - 2]))
            hull.pop_back(), size--;

        hull.push_back(points[i]);
    }

    return hull;
}

template<typename T = llong>
vector<Point<T>> convex_hull(vector<Point<T>> &points) {
    int n = points.size();
    sort(points.begin(), points.end());

    vector<Point<T>> hull = half_hull(points, 0, n, 1);
    vector<Point<T>> lower = half_hull(points, n - 1, -1, -1);

    for (int i = 1; i < (int) lower.size() - 1; i++)
        hull.push_back(lower[i]);

    return hull;
}

template<typename T = llong>
T area(Point<T> A, Point<T> B, Point<T> C) {
    return (B - A) / (C - A);
}

template<typename T = llong>
T double_area(vector<Point<T>> &points) {
    Point<T> O(0, 0);
    int n = points.size();

    T ans = 0;
    for (int i = 0; i < n; i++) {
        Point<T> P = points[i], Q = points[(i + 1) % n];
        ans += area(O, P, Q);
    }

    return ans;
}

template<typename T>
T lattice_points(Point<T> A, Point<T> B) {
    return gcd(abs(B.x - A.x), abs(B.y - A.y));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<Point<llong>> points(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = Point<llong>(x, y);
    }

    vector<Point<llong>> vertices = convex_hull(points);
    llong darea = -double_area(vertices);

    if (!darea) cout << "0\n0\n";
    else {
        llong border = 0;
        int adults = vertices.size();

        for (int i = 0; i < adults; i++)
            border += lattice_points(vertices[i], vertices[(i + 1) % adults]);

        int inside = n - adults;
        llong children = (darea - border) / 2LL - inside + 1;
        cout << children << "\n" << adults << "\n";
    }
}