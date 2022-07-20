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
bool right_turn(Vector<T> u, Vector<T> v) {
    return sign(u / v) < 0;
}

template<typename T = long>
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<Point<long>> points(n);
    for (int i = 0; i < n; i++) {
        int y; cin >> y;
        points[i] = Point<long>(i, y);
    }

    int cnt = 2;
    Line l(points[1], points[2]);

    for (int i = 3; i < n; i++)
        if (l.contains(points[i]))
            cnt++;

    bool possible = cnt + 1 >= n && !l.contains(points[0]);
    for (int i = 1; i < n && !possible; i++) {
        possible = true;
        vector<int> free;
        vector<bool> used(n, false);
        Line r(points[0], points[i]);

        for (int j = 0; j < n; j++) {
            if (r.contains(points[j]))
                used[j] = true;
            else
                free.push_back(j);
        }

        if (free.empty()) possible = false;
        else if ((int) free.size() > 1) {
            Line s(points[free[0]], points[free[1]]);
            for (int j = 0; j < n && possible; j++)
                if (!used[j] && !s.contains(points[j]))
                    possible = false;

            if (left_turn(r.v, s.v) || right_turn(r.v, s.v))
                possible = false;
        }
    }

    cout << (possible ? "Yes" : "No") << "\n";
}