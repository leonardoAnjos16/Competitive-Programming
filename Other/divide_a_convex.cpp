#include <bits/stdc++.h>

using namespace std;

#define ldouble long double
#define Vector Point

const ldouble EPS = 1e-9;

int sign(ldouble x) {
    return fabsl(x) < EPS ? 0 : (x < 0 ? -1 : 1);
}

template<typename T>
struct Point {
    T x, y;

    Point(T x = 0, T y = 0): x(x), y(y) {}

    Point<T> operator +(Vector<T> v) {
        return Point<T>(x + v.x, y + v.y);
    }

    Vector<T> operator -(Point<T> other) {
        return Vector<T>(x - other.x, y - other.y);
    }

    Vector<T> operator *(T k) {
        return Vector<T>(x * k, y * k);
    }

    T operator *(Vector<T> other) const {
        return x * other.x + y * other.y;
    }

    T operator /(Vector<T> other) const {
        return x * other.y - other.x * y;
    }

    bool up() const {
        if (sign(y) > 0) return true;
        if (sign(y) < 0) return false;
        return sign(x) >= 0;
    }

    bool operator <(Vector<T> const &other) const {
        if (up() != other.up()) return up();
        return (!sign(x) && !sign(y)) || sign(*this / other) > 0;
    }
};

template<typename T>
ldouble abs(Vector<T> v) {
    return sqrtl(v * v);
}

template<typename T>
istream& operator >>(istream &cin, Point<T> &P) {
    int x, y;
    cin >> x >> y;
    P = Point<T>(x, y);
    return cin;
}

template<typename T>
ldouble side_length(int n, vector<Point<T>> &vertices, int i) {
    return abs(vertices[(i + 1) % n] - vertices[i]);
}

int which_edge(int n, vector<ldouble> &sides_ps, ldouble dist) {
    int l = 1, r = n, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (sign(sides_ps[mid] - dist) < 0) l = mid + 1;
        else r = mid - 1, ans = mid;
    }

    assert(sign(dist - sides_ps[n]) > 0 || ans != -1);
    return ans;
}

ldouble solve(int n, vector<ldouble> &sides_ps, vector<Point<ldouble>> &vertices, ldouble dist) {
    int edge = which_edge(n, sides_ps, dist);
    ldouble rem_dist = dist - sides_ps[edge - 1];

    Vector<ldouble> v = vertices[edge % n] - vertices[edge - 1];
    Point<ldouble> A = vertices[edge - 1] + v * (rem_dist / abs(v));

    edge = which_edge(n, sides_ps, dist + sides_ps[n] / 2.0L);
    rem_dist = dist + sides_ps[n] / 2.0L - sides_ps[edge - 1];

    v = vertices[edge % n] - vertices[edge - 1];
    Point<ldouble> B = vertices[edge - 1] + v * (rem_dist / abs(v));

    return abs(B - A);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int n; cin >> n;

    vector<Point<ldouble>> vertices(n);
    for (int i = 0; i < n; i++)
        cin >> vertices[i];

    sort(vertices.begin(), vertices.end());

    vector<ldouble> ps(n + 1, 0.0L);
    for (int i = 1; i <= n; i++)
        ps[i] = ps[i - 1] + side_length(n, vertices, i - 1);

    ldouble l = 0.0L, r = ps[n] / 2.0L;
    for (int i = 0; i < 1000; i++) {
        ldouble m1 = l + (r - l) / 3.0L;
        ldouble m2 = r - (r - l) / 3.0L;

        ldouble d1 = solve(n, ps, vertices, m1);
        ldouble d2 = solve(n, ps, vertices, m2);

        if (sign(d1 - d2) < 0) r = m2;
        else l = m1;
    }

    ldouble ans = solve(n, ps, vertices, l);
    cout << ans << "\n";
}