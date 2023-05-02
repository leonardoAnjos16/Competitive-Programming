#include <bits/stdc++.h>

using namespace std;

#define Vector Point
#define llong long long int
#define ldouble long double

const ldouble PI = acosl(-1.0L);

int sign(llong x) {
    return !x ? 0 : (x < 0 ? -1 : 1);
}

template<typename T>
struct Point {
    T x, y;

    Point(): x(x), y(y) {}
    Point(T x, T y): x(x), y(y) {}

    Vector<T> operator -(Point<T> other) {
        return Vector<T>(x - other.x, y - other.y);
    }

    T operator *(Vector<T> other) {
        return x * other.x + y * other.y;
    }

    T operator /(Vector<T> other) {
        return x * other.y - y * other.x;
    }
};

template<typename T>
bool right_turn(Vector<T> u, Vector<T> v) {
    return sign(u / v) < 0;
}

template<typename T>
ldouble abs(Vector<T> v) {
    return sqrtl(v * v);
}

template<typename T>
ldouble angle(Vector<T> u, Vector<T> v) {
    return acosl(u * v / abs(u) / abs(v));
}

template<typename T>
vector<Point<T>> half_hull(vector<Point<T>> &points, int l, int r, int d) {
    vector<Point<T>> hull;
    for (int i = l; i != r; i += d) {
        int size = hull.size();
        while (size > 1 && !right_turn(hull[size - 1] - hull[size - 2], points[i] - hull[size - 2]))
            hull.pop_back(), size--;

        hull.push_back(points[i]);
    }

    return hull;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int n; cin >> n;

    vector<Point<llong>> points(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = Point<llong>(x, y);
    }

    Vector<llong> hor(-1LL, 0LL);
    vector<Point<llong>> hull = half_hull(points, 0, n, 1);

    ldouble ans = 0.0L;
    for (int i = 1; i < (int) hull.size() && hull[i].y > hull[i - 1].y; i++)
        ans = max(ans, angle(hor, hull[i - 1] - hull[i]));

    hor = Vector<llong>(1LL, 0LL);
    for (int i = (int) hull.size() - 2; i >= 0 && hull[i].y > hull[i + 1].y; i++)
        ans = max(ans, angle(hor, hull[i + 1] - hull[i]));

    ans *= 180.0L / PI;
    cout << ans << "\n";
}