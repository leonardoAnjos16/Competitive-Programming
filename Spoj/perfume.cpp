#include <bits/stdc++.h>

using namespace std;

#define Vector Point

const long double EPS = 1e-6;

int sign(long double x) {
    return fabsl(x) <= EPS ? 0 : (x < -EPS ? -1 : 1);
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

    bool operator ==(const Point<T> &other) const {
        return !sign(x - other.x) && !sign(y - other.y);
    }
};

template<typename T = long>
bool left_turn(Vector<T> u, Vector<T> v) {
    return sign(u / v) > 0;
}

template<typename T = long>
bool right_turn(Vector<T> u, Vector<T> v) {
    return sign(u / v) < 0;
}

template<typename T = long>
bool inside(vector<Point<T>> &vertices, Point<T> P) {
    int n = vertices.size();
    for (int i = 0; i < n; i++)
        if (left_turn(vertices[(i + 1) % n] - vertices[i], P - vertices[i]))
            return false;

    return true;
}

template<typename T = long>
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

template<typename T = long>
vector<Point<T>> convex_hull(vector<Point<T>> &points) {
    int n = points.size();
    sort(points.begin(), points.end());

    vector<Point<T>> hull = half_hull(points, 0, n, 1);
    vector<Point<T>> lower = half_hull(points, n - 1, -1, -1);

    for (int i = 1; i < (int) lower.size() - 1; i++)
        hull.push_back(lower[i]);

    return hull;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        vector<Point<long double>> mixtures(N);
        for (int i = 0; i < N; i++) {
            long double A, B;
            cin >> A >> B;
            mixtures[i] = Point<long double>(A, B);
        }

        vector<Point<long double>> hull = convex_hull(mixtures);

        int Q; cin >> Q;
        while (Q--) {
            long double A, B;
            cin >> A >> B;

            Point<long double> mixture(A, B);
            if (N == 1) cout << (mixture == mixtures[0] ? "Yes" : "No") << "\n";
            else cout << (inside(hull, mixture) ? "Yes" : "No") << "\n";
        }

        if (T) cout << "\n";
    }
}