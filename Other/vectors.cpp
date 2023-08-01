#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define Vector Point

template<typename T>
struct Point {
    T x, y;

    Point(T x = 0, T y = 0): x(x), y(y) {}

    Point<T> operator +(Vector<T> other) {
        return Point<T>(x + other.x, y + other.y);
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
};

template<typename T>
ldouble abs(Vector<T> v) {
    return sqrtl(v * v);
}

template<typename T>
istream& operator >>(istream &cin, Point<T> &v) {
    T x, y;
    cin >> x >> y;
    v = Point<T>(x, y);
    return cin;
}

template<typename T>
ostream& operator <<(ostream &cout, Vector<T> v) {
    cout << v.x << " " << v.y;
    return cout;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    Point<int> A, B, C, D;
    cin >> A >> B >> C >> D;

    Vector<int> u = B - A, v = D - C;

    cout << abs(u) << " " << abs(v) << "\n";
    cout << (u + v) << "\n";

    int dot = u * v, cross = u / v;
    cout << dot << " " << cross << "\n";

    int area = abs(cross) / 2;
    cout << area << (abs(cross) & 1 ? ".5" : "") << "\n";
}