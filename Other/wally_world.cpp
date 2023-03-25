#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define Vector Point

template<typename T>
struct Point {
    T x, y;

    Point(): x(0), y(0) {}
    Point(T x, T y): x(x), y(y) {}

    Vector<T> operator -(Point<T> other) {
        return Point<T>(x - other.x, y - other.y);
    }

    T operator *(Vector<T> other) {
        return x * other.x + y * other.y;
    }

    T operator /(Vector<T> other) {
        return x * other.y - y * other.x;
    }

    long double abs() {
        return sqrtl(*this * *this);
    }
};

int sign(llong x) {
    return !x ? 0 : (x < 0LL ? -1 : 1);
}

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(3) << fixed;

    int x1, y1, x2, y2, t = 1;
    while (cin >> x1 >> y1 >> x2 >> y2, x1 || x2 || y1 || y2) {
        int x3, y3, x4, y4;
        cin >> x3 >> y3 >> x4 >> y4;

        cout << "Case " << t++ << ": ";

        Point<llong> A(x1, y1), B(x2, y2), C(x3, y3), D(x4, y4);
        if (!seg_seg(A, B, C, D)) {
            long double ans = (B - A).abs() / 2.0L;
            cout << ans << "\n";
        } else {
            long double AC = (C - A).abs();
            long double AD = (D - A).abs();
            long double BC = (C - B).abs();
            long double BD = (D - B).abs();
            long double CD = (D - C).abs();

            long double ans = min({ AC + BC, AD + BD, AC + BD + CD, AD + BC + CD }) / 2.0L;
            cout << ans << "\n";
        }
    }
}