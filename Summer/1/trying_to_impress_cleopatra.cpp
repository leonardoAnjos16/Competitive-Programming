#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define Vector Point

const long double EPS = 1e-9;
const long double PI = acosl(-1.0L);

int sign(long double x) {
    return abs(x) < EPS ? 0 : x > 0 ? 1 : -1;
}

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
};

template<typename T>
long double abs(Vector<T> v) {
    return sqrtl(v * v);
}

template<typename T>
bool right_turn(Vector<T> u, Vector<T> v) {
    return u / v < 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int n; cin >> n;

    vector<Point<llong>> vertices(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vertices[i] = Point<llong>(x, y);
    }

    vector<long double> dists(n);
    Vector<llong> horizontal(1, 0);

    for (int i = 0; i < n; i++)
        dists[i] = abs(vertices[(i + 1) % n] - vertices[i]);

    int end = 0;
    long double ans = 0.0L;

    for (int i = 0; i < n; i++) {
        Vector<llong> horizontal = vertices[(i + 1) % n] - vertices[i];
        while (!right_turn(horizontal, vertices[(end + 1) % n] - vertices[end]) && horizontal * (vertices[(end + 1) % n] - vertices[end]) > 0) {
            ans += dists[end];
            end = (end + 1) % n;
        }

        cout << ans << "\n";

        ans -= dists[i];
        if (end == i) end++;
    }
}