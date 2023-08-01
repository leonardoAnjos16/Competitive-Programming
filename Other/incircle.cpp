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

    T operator /(Vector<T> other) {
        return x * other.y - other.x * y;
    }

    template<typename U>
    operator Point<U>() const {
        return Point<U>(U(x), U(y));
    }
};

template<typename T>
struct Line {
    Point<T> P;
    Vector<T> v;

    Line(Point<T> P, Vector<T> v): P(P), v(v) {}

    pair<Point<T>, bool> intersection(Line<T> other) {
        T den = v / other.v;
        if (!sign(den)) return make_pair(Point<T>(), false);

        T t = ((other.P - P) / other.v) / den;
        return make_pair(P + v * t, true);
    }
};

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

template<typename T>
ldouble abs(Vector<T> v) {
    return sqrtl(v * v);
}

template<typename T>
bool left_turn(Vector<T> u, Vector<T> v) {
    return u / v > 0;
}

template<typename T>
ldouble angle(Vector<T> u, Vector<T> v) {
    return acosl(u * v / abs(u) / abs(v));
}

template<typename T>
Vector<ldouble> rotate(Vector<T> v, ldouble theta) {
    return Vector<ldouble>(v.x * cosl(theta) - v.y * sinl(theta), v.x * sinl(theta) + v.y * cosl(theta));
}

template<typename T>
Vector<ldouble> bisect(Vector<T> u, Vector<T> v) {
    ldouble theta = angle(u, v);
    return left_turn(u, v) ? rotate(u, theta / 2.0L) : rotate(v, theta / 2.0L);
}

template<typename T>
pair<Point<ldouble>, ldouble> incircle(Point<T> A, Point<T> B, Point<T> C) {
    Vector<T> AB = B - A, BC = C - B, CA = A - C;
    ldouble a = abs(AB), b = abs(BC), c = abs(CA), s = (a + b + c) / 2.0L;
    ldouble r = sqrtl(s - a) * sqrtl(s - b) * sqrtl(s - c) / sqrtl(s);

    Vector<ldouble> u = bisect(AB, C - A);
    Line<ldouble> l(A, u);

    Vector<ldouble> v = bisect(BC, A - B);
    Line<ldouble> m(B, v);

    auto [P, has_intersection] = l.intersection(m);
    assert(has_intersection);
    return make_pair(P, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    Point<int> A, B, C;
    cin >> A >> B >> C;

    auto [P, r] = incircle(A, B, C);
    cout << P << " " << r << "\n";
}