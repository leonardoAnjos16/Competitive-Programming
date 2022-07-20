#include <bits/stdc++.h>

using namespace std;

#define Vector Point

const long double EPS = 1e-6;

int sign(long double x) {
    return fabsl(x) <= EPS ? 0 : (x < -EPS ? -1 : 1);
}

template<typename T = long long int>
struct Point {
    T x, y;

    Point(): x(0), y(0) {}
    Point(T x, T y): x(x), y(y) {}

    T abs() {
        return *this * *this;
    }

    void norm() {
        long double size = sqrtl(abs());
        x /= size;
        y /= size;
    }

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
struct Line {
    Point<T> P;
    Vector<T> v;

    Line(Point<T> P, Point<T> Q) {
        if (Q < P) swap(P, Q);
        this->P = P;
        v = Q - P;
    }

    pair<Point<T>, bool> intersection(Line<T> other) {
        T den = v / other.v;
        if (!sign(den)) return make_pair(Point<T>(), false);

        T t = ((other.P - P) / other.v) / den;
        return make_pair(P + v * t, true);
    }

    bool contains(Point<T> Q) {
        return !sign((Q - P) / v);
    }
};

template<typename T = long long int>
bool left_turn(Vector<T> u, Vector<T> v) {
    return sign(u / v) > 0;
}

template<typename T = long long int>
bool right_turn(Vector<T> u, Vector<T> v) {
    return sign(u / v) < 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int n; cin >> n;

    vector<Point<long double>> vertices(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vertices[i] = Point<long double>(x, y);
    }

    vector<Vector<long double>> normal(n);
    for (int i = 0; i < n; i++) {
        Vector<long double> v = vertices[(i + 1) % n] - vertices[i];
        normal[i] = Vector<long double>(-v.y, v.x);
        normal[i].norm();
    }

    long double l = 0, r = 1e8;
    for (int i = 0; i < 60; i++) {
        long double mid = (l + r) / 2.0L;

        vector<Point<long double>> polygon;
        polygon.emplace_back(1e9, 1e9);
        polygon.emplace_back(-1e9, 1e9);
        polygon.emplace_back(-1e9, -1e9);
        polygon.emplace_back(1e9, -1e9);

        for (int j = 0; j < n; j++) {
            Point<long double> A = vertices[j] + normal[j] * mid;
            Point<long double> B = vertices[(j + 1) % n] + normal[j] * mid;

            int size = polygon.size();
            vector<Point<long double>> new_polygon;

            for (int k = 0; k < (int) polygon.size(); k++) {
                Point<long double> C = polygon[k];
                Point<long double> D = polygon[(k + 1) % size];

                if (left_turn(B - A, C - A)) {
                    new_polygon.push_back(C);
                    if (!left_turn(B - A, D - A)) {
                        Line s(A, B), t(C, D);
                        auto [P, has_intersection] = s.intersection(t);
                        new_polygon.push_back(P);
                    }
                } else if (!right_turn(B - A, D - A)) {
                    Line s(A, B), t(C, D);
                    auto [P, has_intersection] = s.intersection(t);
                    new_polygon.push_back(P);
                }
            }

            polygon = new_polygon;
        }

        int size = polygon.size();
        if (!size) r = mid;
        else l = mid;
    }

    long double ans = (l + r) / 2.0L;
    cout << ans << "\n";
}