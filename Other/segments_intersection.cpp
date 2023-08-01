#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define Vector Point

int sign(llong x) {
    return !x ? 0 : (x < 0 ? -1 : 1);
}

template<typename T>
struct Point {
    T x, y;

    Point(T x = 0, T y = 0): x(x), y(y) {}

    template<typename U>
    Vector<U> operator *(U k) {
        return Vector<U>(x * k, y * k);
    }

    template<typename U>
    Point<U> operator +(Vector<U> other) {
        return Point<U>(x + other.x, y + other.y);
    }

    Vector<T> operator -(Point<T> other) {
        return Vector<T>(x - other.x, y - other.y);
    }

    T operator /(Vector<T> other) {
        return x * other.y - other.x * y;
    }

    bool operator <(Point<T> const &other) const {
        if (!sign(x - other.x))
            return sign(y - other.y) < 0;

        return sign(x - other.x) < 0;
    }

    bool operator !=(Point<T> const &other) const {
        return sign(x - other.x) || sign(y - other.y);
    }
};

template<typename T>
struct Line {
    Point<T> P;
    Vector<T> v;

    Line(Point<T> P, Point<T> Q) {
        if (Q < P) swap(P, Q);
        this->P = P;
        v = Q - P;
    }

    template<typename U>
    Point<U> intersection(Line<T> other) {
        U den = v / other.v;
        assert(sign(den));

        U t = ((other.P - P) / other.v) / den;
        return P + v * t;
    }
};

template<typename T>
bool intersect(T a, T b, T c, T d) {
    if (sign(a - b) > 0) swap(a, b);
    if (sign(c - d) > 0) swap(c, d);
    return sign(max(a, c) - min(b, d)) <= 0;
}

template<typename T>
bool seg_seg(Point<T> A, Point<T> B, Point<T> C, Point<T> D) {
    Vector<T> CA = A - C, CB = B - C, CD = D - C;
    if (!sign(CA / CD) && !sign(CB / CD))
        return intersect(A.x, B.x, C.x, D.x) && intersect(A.y, B.y, C.y, D.y);

    Vector<T> AB = B - A, AC = C - A, AD = D - A;
    return sign(AB / AC) != sign(AB / AD) && sign(CA / CD) != sign(CB / CD);
}

template<typename T>
istream& operator >>(istream &cin, Point<T> &P) {
    T x, y;
    cin >> x >> y;
    P = Point<T>(x, y);
    return cin;
}

template<typename T>
ostream& operator <<(ostream &cout, Point<T> P) {
    cout << P.x << " " << P.y;
    return cout;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(12) << fixed;

    Point<int> A, B, C, D;
    cin >> A >> B >> C >> D;

    if (!seg_seg(A, B, C, D)) cout << "Empty\n";
    else {
        Line<int> l(A, B), m(C, D);
        if (sign(l.v / m.v)) cout << l.intersection<ldouble>(m) << "\n";
        else {
            Point<int> points[4] = { A, B, C, D };
            sort(points, points + 4);

            cout << points[1] << "\n";
            if (points[2] != points[1])
                cout << points[2] << "\n";
        }
    }
}