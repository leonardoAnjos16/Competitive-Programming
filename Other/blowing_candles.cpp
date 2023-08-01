#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define Vector Point

template<typename T>
struct Point {
    T x, y;

    Point(T x = 0, T y = 0): x(x), y(y) {}

    template<typename U>
    Vector<U> operator *(U k) {
        return Vector<U>(x * k, y * k);
    }

    template<typename U>
    Point<U> operator +(Vector<U> other) {
        return Point<U>(x + other.x, y + other.y);
    }

    template<typename U>
    Vector<U> operator -(Point<U> other) {
        return Vector<U>(x - other.x, y - other.y);
    }

    T operator *(Vector<T> other) {
        return x * other.x + y * other.y;
    }

    T operator /(Vector<T> other) {
        return x * other.y - other.x * y;
    }

    bool operator <(Point<T> const &other) const {
        if (x == other.x)
            return y < other.y;

        return x < other.x;
    }

    template<typename U>
    operator Point<U>() const {
        return Point<U>(U(x), U(y));
    }
};

template<typename T>
bool left_turn(Vector<T> u, Vector<T> v) {
    return u / v > 0;
}

template<typename T>
vector<Point<T>> half_hull(vector<Point<T>> &points, int l, int r, int d) {
    vector<Point<T>> hull;
    for (int i = l; i != r; i += d) {
        int size = hull.size();
        while (size > 1 && left_turn(hull[size - 1] - hull[size - 2], points[i] - hull[size - 2]))
            hull.pop_back(), size--;

        hull.push_back(points[i]);
    }

    return hull;
}

template<typename T>
vector<Point<T>> convex_hull(vector<Point<T>> &points) {
    int n = points.size();
    sort(points.begin(), points.end());

    vector<Point<T>> hull = half_hull(points, 0, n, 1);
    vector<Point<T>> lower = half_hull(points, n - 1, -1, -1);

    for (int i = 1; i < (int) lower.size() - 1; i++)
        hull.push_back(lower[i]);

    return hull;
}

template<typename T>
int max_dot_product(vector<Point<T>> &hull, Vector<T> v) {
    int n = hull.size();
    if (n < 3) {
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (hull[i] * v > hull[ans] * v)
                ans = i;

        return ans;
    }

    int ans = 0;
    if (hull[1] * v > hull[ans] * v)
        ans = 1;

    for (int i = 0; i < 2; i++) {
        int l = 2, r = n - 1;
        while (l != r) {
            int mid = (l + r + 1) / 2;

            bool check = hull[mid] * v >= hull[mid - 1] * v;
            if (!i) check &= hull[mid] * v >= hull[0] * v;
            else check |= hull[mid - 1] * v < hull[0] * v;

            if (check) l = mid;
            else r = mid - 1;
        }

        if (hull[l] * v > hull[ans] * v)
            ans = l;
    }

    return ans;
}

template<typename T>
ldouble abs(Vector<T> v) {
    return sqrtl(v * v);
}

template<typename T>
Vector<T> proj(Vector<T> u, Vector<T> v) {
    return v * ((u * v) / (v * v));
}

template<typename T, typename U>
Point<T> proj_line(Point<U> P, Point<U> A, Point<U> B) {
    Vector<T> u = P - A, v = B - A;
    return A + proj(u, v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int N, R;
    cin >> N >> R;

    vector<Point<llong>> candles(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        candles[i] = Point<llong>(x, y);
    }

    candles = convex_hull(candles);
    N = candles.size();

    int furthest = 0;
    ldouble ans = 2.0L * R;

    for (int i = 0; i < N; i++) {
        Vector<llong> v = candles[(i + 1) % N] - candles[i];
        v = Vector<llong>(v.y, -v.x);

        int furthest = max_dot_product(candles, v);
        Point<ldouble> P = proj_line<ldouble, int>(candles[furthest], candles[i], candles[(i + 1) % N]);
        ans = min(ans, abs(candles[furthest] - P));
    }

    cout << ans << "\n";
}