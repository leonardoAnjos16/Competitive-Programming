#include <bits/stdc++.h>

using namespace std;

#define ldouble long double
#define Vector Point

const ldouble EPS = 1e-9;
const ldouble INF = 1e9 + 5;

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

struct Line {
    ldouble m, b;

    Line(ldouble m, ldouble b): m(m), b(b) {}

    ldouble get_y(ldouble x) {
        return m * x + b;
    }
};

template<typename T>
ldouble abs(Vector<T> v) {
    return sqrtl(v * v);
}

template<typename T>
Vector<T> get_normal(Point<T> P, Point<T> Q) {
    Vector<T> v = Q - P;
    ldouble len = abs(v);
    return Vector<T>(-v.y / len, v.x / len);
}

ldouble diff(vector<Line> &lower, vector<Line> &upper, ldouble x) {
    ldouble mxy = -INF;
    for (Line &line: lower)
        mxy = max(mxy, line.get_y(x));

    ldouble mny = INF;
    for (Line &line: upper)
        mny = min(mny, line.get_y(x));

    return mny - mxy;
}

bool intersect(vector<Line> &lower, vector<Line> &upper, ldouble l, ldouble r) {
    if (sign(l - r) > 0) return false;

    for (int i = 0; i < 200; i++) {
        ldouble m1 = l + (r - l) / 3.0L;
        ldouble m2 = r - (r - l) / 3.0L;

        ldouble d1 = diff(lower, upper, m1);
        ldouble d2 = diff(lower, upper, m2);

        if (sign(d1 - d2) < 0) l = m1;
        else r = m2;
    }

    return sign(diff(lower, upper, l)) >= 0;
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

    cout << setprecision(8) << fixed;

    int n; cin >> n;

    vector<Point<ldouble>> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i];

    ldouble l = 0.0L, r = INF, ans = 0.0L;
    for (int i = 0; i < 200; i++) {
        ldouble mid = (l + r) / 2.0L;

        vector<Line> lower, upper;
        ldouble lx = -INF, rx = INF;

        for (int j = 0; j < n; j++) {
            Point<ldouble> P = points[j], Q = points[(j + 1) % n];
            Vector<ldouble> normal = get_normal(P, Q);

            P = P + normal * mid;
            Q = Q + normal * mid;

            if (sign(P.x - Q.x) == 0) {
                if (sign(P.y - Q.y) > 0) lx = max(lx, P.x);
                else rx = min(rx, Q.x);
            } else {
                // P.y = m * P.x + b
                // Q.y = m * Q.x + b
                // 2b = P.y + Q.y - m * (P.x + Q.x)

                ldouble m = (Q.y - P.y) / (Q.x - P.x);
                ldouble b = (P.y + Q.y - m * (P.x + Q.x)) / 2.0L;

                if (sign(P.x - Q.x) < 0) lower.emplace_back(m, b);
                else upper.emplace_back(m, b);
            }
        }

        if (!intersect(lower, upper, lx, rx)) r = mid;
        else l = ans = mid;
    }

    cout << ans << "\n";
}