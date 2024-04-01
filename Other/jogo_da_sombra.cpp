#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define Vector Point

template<typename T>
struct Point {
    T x, y;

    Point(T x = 0, T y = 0): x(x), y(y) {}

    Vector<T> operator -(Point<llong> other) {
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
istream& operator >>(istream &cin, Point<T> &P) {
    T x, y;
    cin >> x >> y;

    P = Point<T>(x, y);
    return cin;
}

template<typename T>
ldouble abs(Vector<T> v) {
    return sqrtl(v * v);
}

template<typename T>
bool left_turn(Vector<T> u, Vector<T> v) {
    return u / v < 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(6) << fixed;

    int N; cin >> N;

    Point<llong> P;
    cin >> P;

    vector<Point<llong>> polygon(N);
    for (int i = 0; i < N; i++)
        cin >> polygon[i];

    ldouble covered = 0.0L, total = 0.0L;
    for (int i = 0; i < N; i++) {
        Point<llong> A = polygon[i], B = polygon[(i + 1) % N];
        total += abs(B - A);

        if (left_turn(P - A, B - A))
            covered += abs(B - A);
    }

    ldouble ans = 100.0L * covered / total;
    cout << ans << "\n";
}