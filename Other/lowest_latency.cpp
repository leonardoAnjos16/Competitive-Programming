#include <bits/stdc++.h>

using namespace std;

#define Vector Point
#define llong long long int
#define ldouble long double

const ldouble INF = 1e18 + 5;

template<typename T>
struct Point {
    T x, y, z;

    Point(): x(0), y(0), z(0) {}
    Point(T x, T y, T z): x(x), y(y), z(z) {}

    Vector<T> operator -(Point<T> other) {
        return Vector<T>(x - other.x, y - other.y, z - other.z);
    }

    T operator *(Point<T> other) {
        return x * other.x + y * other.y + z * other.z;
    }

    bool operator <(Point<T> const &other) const {
        return x < other.x || (x == other.x && y < other.y) || (x == other.x && y == other.y && z < other.z);
    }
};

template<typename T>
ldouble abs(Vector<T> v) {
    return sqrtl(v * v);
}

template<typename T>
ldouble dist(Point<T> P, Point<T> Q) {
    Vector<T> v = Q - P;
    return abs(v);
}

template<typename T>
Point<T> swap_coords(Point<T> P) {
    return Point<T>(P.y, P.x, P.z);
}

template<typename T>
ldouble closest_pair(vector<Point<T>> points) {
    int n = points.size(), k = 0;
    sort(points.begin(), points.end());

    ldouble d = INF;
    set<Point<T>> inv;

    for (int i = 0; i < n; i++) {
        while (k < i && points[k].x < points[i].x - d)
            inv.erase(swap_coords(points[k++]));

        for (auto it = inv.lower_bound(Point<T>(points[i].y - d, points[i].x - d, -INF)); it != inv.end() && it->x <= points[i].y + d; it++)
            d = min(d, dist(points[i], swap_coords(*it)));

        inv.insert(swap_coords(points[i]));
    }

    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int n; cin >> n;

    vector<Point<llong>> planets(n);
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        planets[i] = Point<llong>(x, y, z);
    }

    ldouble ans = closest_pair(planets);
    cout << ans << "\n";
}