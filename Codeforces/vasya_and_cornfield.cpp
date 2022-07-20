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

    Point(): x(0.0L), y(0.0L) {}
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

    T operator ^(Vector<T> other) {
        return x * other.y - y * other.x;
    }
};

template<typename T = long>
bool left_turn(Vector<T> u, Vector<T> v) {
    return sign(u ^ v) > 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    cin >> n >> d;

    Point<int> A(0, d), B(n - d, n), C(n, n - d), D(d, 0);

    int m; cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;

        Point P(x, y);
        if (left_turn(B - A, P - A)) cout << "NO\n";
        else if (left_turn(C - B, P - B)) cout << "NO\n";
        else if (left_turn(D - C, P - C)) cout << "NO\n";
        else if (left_turn(A - D, P - D)) cout << "NO\n";
        else cout << "YES\n";
    }
}