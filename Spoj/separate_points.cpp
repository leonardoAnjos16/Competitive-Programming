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

    Point(): x(0), y(0) {}
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

    T operator /(Vector<T> other) {
        return x * other.y - y * other.x;
    }

    bool operator <(const Point<T> &other) const {
        if (!sign(x - other.x))
            return sign(y - other.y) < 0;

        return sign(x - other.x) < 0;
    }
};

template<typename T = long>
bool left_turn(Vector<T> u, Vector<T> v) {
    return sign(u / v) > 0;
}

template<typename T = long>
bool right_turn(Vector<T> u, Vector<T> v) {
    return sign(u / v) < 0;
}

template<typename T = long>
bool intersect(T a, T b, T c, T d) {
    if (sign(a - b) > 0) swap(a, b);
    if (sign(c - d) > 0) swap(c, d);
    return sign(max(a, c) - min(b, d)) <= 0;
}

template<typename T = long>
bool seg_seg(Point<T> A, Point<T> B, Point<T> C, Point<T> D) {
    Vector<T> CA = A - C, CB = B - C, CD = D - C;
    if (!sign(CA / CD) && !sign(CB / CD))
        return intersect(A.x, B.x, C.x, D.x) && intersect(A.y, B.y, C.y, D.y);

    Vector<T> AB = B - A, AC = C - A, AD = D - A;
    return sign(AB / AC) != sign(AB / AD) && sign(CA / CD) != sign(CB / CD);
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

template<typename T = long>
vector<Point<T>> convex_hull(vector<Point<T>> &points) {
    int n = points.size();
    sort(points.begin(), points.end());

    vector<Point<T>> hull = half_hull(points, 0, n, 1);
    vector<Point<T>> lower = half_hull(points, n - 1, -1, -1);

    for (int i = 1; i < (int) lower.size() - 1; i++)
        hull.push_back(lower[i]);

    return hull;
}

template<typename T = long>
bool inside(vector<Point<T>> &vertices, Point<T> P) {
    int n = vertices.size();
    for (int i = 0; i < n; i++)
        if (left_turn(vertices[(i + 1) % n] - vertices[i], P - vertices[i]))
            return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m, n || m) {
        vector<Point<int>> black(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            black[i] = Point<int>(x, y);
        }

        vector<Point<int>> white(m);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            white[i] = Point<int>(x, y);
        }

        if (!n || !m) cout << "YES\n";
        else if (n < 2 && m < 2) cout << "YES\n";
        else if (n < 3 && m < 3) {
            Point<int> A = black[0], B = n == 1 ? A : black[1];
            Point<int> C = white[0], D = m == 1 ? C : white[1];
            cout << (seg_seg(A, B, C, D) ? "NO" : "YES") << "\n";
        }
        else {
            vector<Point<int>> black_hull = convex_hull(black);
            vector<Point<int>> white_hull = convex_hull(white);

            bool possible = true;
            for (auto P: black_hull)
                if (inside(white_hull, P)) {
                    possible = false;
                    break;
                }

            for (auto P: white_hull)
                if (inside(black_hull, P)) {
                    possible = false;
                    break;
                }

            cout << (possible ? "YES" : "NO") << "\n";
        }
    }
}