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
bool left_turn(Vector<T> u, Vector<T> v) {
    return sign(u / v) > 0;
}

template<typename T = long long int>
bool right_turn(Vector<T> u, Vector<T> v) {
    return sign(u / v) < 0;
}

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

template<typename T = long>
T area(Point<T> A, Point<T> B, Point<T> C) {
    return (B - A) / (C - B);
}

template<typename T = long>
long double area(vector<Point<T>> &points) {
    Point<T> O(0, 0);
    int n = points.size();

    T ans = 0;
    for (int i = 0; i < n; i++) {
        Point<T> P = points[i], Q = points[(i + 1) % n];
        ans += area(O, P, Q);
    }

    return ans / 2.0L;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(4) << fixed;

    int T; cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<Point<long double>> A(N);
        for (int i = 0; i < N; i++) {
            long double x, y;
            cin >> x >> y;
            A[i] = Point(x, y);
        }

        vector<Point<long double>> B(M);
        for (int i = 0; i < M; i++) {
            long double x, y;
            cin >> x >> y;
            B[i] = Point(x, y);
        }

        vector<Point<long double>> intersection = B;
        for (int i = 0; i < N; i++) {
            Point P = A[i], Q = A[(i + 1) % N];

            int size = intersection.size();
            vector<Point<long double>> new_intersection;

            for (int j = 0; j < size; j++) {
                Point R = intersection[j], S = intersection[(j + 1) % size];
                if (left_turn(Q - P, R - Q)) {
                    new_intersection.push_back(R);
                    if (!left_turn(Q - P, S - Q)) {
                        Line l(P, Q), m(R, S);
                        auto [point, has_intersection] = l.intersection(m);

                        assert(has_intersection);
                        new_intersection.push_back(point);
                    }
                } else if (left_turn(Q - P, S - Q) || (right_turn(Q - P, R - Q) && !right_turn(Q - P, S - Q))) {
                    Line l(P, Q), m(R, S);
                    auto [point, has_intersection] = l.intersection(m);

                    assert(has_intersection);
                    new_intersection.push_back(point);
                }
            }

            intersection = new_intersection;
        }

        int size = intersection.size();
        if (size <= 2) cout << "0.0000\n";
        else {
            long double ans = area(intersection);
            cout << ans << "\n";
        }
    }
}