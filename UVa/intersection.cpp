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
bool intersect(T a, T b, T c, T d) {
    if (sign(a - b) > 0) swap(a, b);
    if (sign(c - d) > 0) swap(c, d);
    return sign(max(a, c) - min(b, d)) <= 0;
}

template<typename T = long>
bool seg_seg(Point<T> A, Point<T> B, Point<T> C, Point<T> D) {
    Vector<T> CA = A - C, CB = B - C, CD = D - C;
    if (!sign(CA / CD) && !sign(CB / CD))
        return intersect(A.x, B.x, C.x, D.x) && intersect(A.y, B.y, C.y, D.y);

    Vector<T> AB = B - A, AC = C - A, AD = D - A;
    return sign(AB / AC) != sign(AB / AD) && sign(CA / CD) != sign(CB / CD);
}

template<typename T = long>
bool left_turn(Vector<T> u, Vector<T> v) {
    return sign(u / v) > 0;
}

template<typename T = long>
bool inside(vector<Point<T>> &vertices, Point<T> P) {
    int n = vertices.size();
    for (int i = 0; i < n; i++)
        if (left_turn(vertices[(i + 1) % n] - vertices[i], P - vertices[i]))
            return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    while (n--) {
        long xs, ys, xe, ye, xl, yt, xr, yb;
        cin >> xs >> ys >> xe >> ye >> xl >> yt >> xr >> yb;

        if (xl > xr) swap(xl, xr);
        if (yt < yb) swap(yt, yb);

        Point<long> A(xl, yt), B(xr, yt), C(xr, yb), D(xl, yb), E(xs, ys), F(xe, ye);
        vector<Point<long>> vertices = { A, B, C, D };

        if (xl == xr && yt == yb) {
            if (xs == xl && ys == yt) cout << "T\n";
            else if (xe == xl && ye == yt) cout << "T\n";
            else cout << "F\n";
        }
        else if (seg_seg(A, B, E, F)) cout << "T\n";
        else if (seg_seg(B, C, E, F)) cout << "T\n";
        else if (seg_seg(C, D, E, F)) cout << "T\n";
        else if (seg_seg(D, A, E, F)) cout << "T\n";
        else if (inside(vertices, E)) cout << "T\n";
        else if (inside(vertices, F)) cout << "T\n";
        else cout << "F\n";
    }
}