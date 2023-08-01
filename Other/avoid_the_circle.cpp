#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define Vector Point

const ldouble EPS = 1e-9;

int sign(ldouble x) {
    return fabsl(x) < EPS ? 0 : (x < 0 ? -1 : 1);
}

template<typename T>
struct Point {
    T x, y;

    Point(T x = 0, T y = 0): x(x), y(y) {}

    Vector<T> operator *(T k) {
        return Vector<T>(x * k, y * k);
    }

    Point<T> operator +(Vector<T> v) {
        return Point<T>(x + v.x, y + v.y);
    }

    Vector<T> operator -(Point<T> other) {
        return Vector<T>(x - other.x, y - other.y);
    }

    T operator *(Vector<T> other) {
        return x * other.x + y * other.y;
    }
};

template<typename T>
ldouble abs(Vector<T> v) {
    return sqrtl(v * v);
}

template<typename T>
ldouble angle(Vector<T> u, Vector<T> v) {
    return acosl(u * v / abs(u) / abs(v));
}

template<typename T>
Vector<T> proj(Vector<T> u, Vector<T> v) {
    return v * ((u * v) / (v * v));
}

template<typename T>
Point<T> proj_line(Point<T> P, Point<T> A, Point<T> B) {
    Vector<T> u = P - A, v = B - A;
    return A + proj(u, v);
}

template<typename T>
Vector<ldouble> rotate(Vector<T> v, ldouble theta) {
    return Vector<ldouble>(v.x * cosl(theta) - v.y * sinl(theta), v.x * sinl(theta) + v.y * cosl(theta));
}

template<typename T>
ldouble arc(Point<T> C, T r, Point<T> P, Point<T> Q) {
    ldouble theta = angle(P - C, Q - C);
    return theta * r;
}

template<typename T>
bool between(Point<T> P, Point<T> A, Point<T> B) {
    auto [lx, rx] = minmax(A.x, B.x);
    auto [ly, ry] = minmax(A.y, B.y);
    return sign(lx - P.x) <= 0 && sign(P.x - rx) <= 0 && sign(ly - P.y) <= 0 && sign(P.y - ry) <= 0;
}

template<typename T>
vector<Point<T>> circle_line(Point<T> C, T r, Point<T> A, Point<T> B) {
    Point<T> P = proj_line(C, A, B);
    ldouble dist = abs(P - C);

    vector<Point<T>> intersections;
    if (!sign(dist - r)) intersections.push_back(P);
    else if (sign(dist - r) < 0) {
        Vector<T> v = B - A;
        ldouble t = sqrtl(r * r - dist * dist);

        intersections.push_back(P + v * (t / abs(v)));
        intersections.push_back(P - v * (t / abs(v)));
    }

    return intersections;
}

template<typename T>
vector<Point<T>> circle_seg(Point<T> C, T r, Point<T> A, Point<T> B) {
    vector<Point<T>> intersections = circle_line(C, r, A, B), nintersections;
    for (Point<T> P: intersections)
        if (between(P, A, B))
            nintersections.push_back(P);

    return nintersections;
}

template<typename T>
pair<Point<T>, Point<T>> tangent(Point<T> P, Point<T> C, T r) {
    ldouble theta = asinl(r / abs(C - P));

    Vector<T> u = rotate(C - P, theta);
    u = u * (1.0L / abs(u));

    Vector<T> v = rotate(C - P, -theta);
    v = v * (1.0L / abs(v));

    ldouble d = sqrtl((C - P) * (C - P) - r * r);
    return make_pair(P + u * d, P + v * d);
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

    cout << setprecision(12) << fixed;

    Point<ldouble> A, B;
    cin >> A >> B;

    ldouble R;
    Point<ldouble> C;
    cin >> C >> R;

    if ((int) circle_seg(C, R, A, B).size() <= 1) {
        ldouble ans = abs(B - A);
        cout << ans << "\n";
    } else {
        auto [P1, P2] = tangent(A, C, R);
        auto [Q1, Q2] = tangent(B, C, R);

        ldouble ans = abs(P1 - A) + abs(B - Q1) + arc(C, R, P1, Q1);
        ans = min(ans, abs(P1 - A) + abs(B - Q2) + arc(C, R, P1, Q2));
        ans = min(ans, abs(P2 - A) + abs(B - Q1) + arc(C, R, P2, Q1));
        ans = min(ans, abs(P2 - A) + abs(B - Q2) + arc(C, R, P2, Q2));

        cout << ans << "\n";
    }
}