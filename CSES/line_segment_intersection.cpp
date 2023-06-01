#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define Vector Point

int sign(llong x) {
    return !x ? 0 : (x < 0 ? -1 : 1);
}

template<typename T>
struct Point {
    T x, y;

    Point(): x(0), y(0) {}
    Point(T x, T y): x(x), y(y) {}

    Vector<T> operator -(Point<T> other) {
        return Point<T>(x - other.x, y - other.y);
    }

    T operator /(Vector<T> other) {
        return x * other.y - y * other.x;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        Point<llong> A(x1, y1), B(x2, y2), C(x3, y3), D(x4, y4);
        bool intersect = seg_seg(A, B, C, D);

        cout << (intersect ? "YES" : "NO") << "\n";
    }
}