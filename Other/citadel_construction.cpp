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

    bool operator <(const Point<T> &other) const {
        if (!sign(x - other.x))
            return sign(y - other.y) < 0;

        return sign(x - other.x) < 0;
    }
};

template<typename T>
bool right_turn(Vector<T> u, Vector<T> v) {
    return sign(u / v) < 0;
}

template<typename T = llong>
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

template<typename T = llong>
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
T area(Point<T> A, Point<T> B, Point<T> C) {
    return abs((B - A) / (C - A));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;

        vector<Point<int>> locations(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            locations[i] = Point<int>(x, y);
        }

        vector<Point<int>> hull = convex_hull(locations);
        int size = hull.size();

        int ans = 0;
        if (size == 3) ans = area(hull[0], hull[1], hull[2]);
        else {
            for (int i = 0; i < size; i++) {
                int ij = (i + 1) % size, ji = (i + 3) % size;
                for (int j = (i + 2) % size; (j + 1) % size != i; j = (j + 1) % size) {
                    if (j == ji) ji = (ji + 1) % size;
                    int aij = area(hull[i], hull[ij], hull[j]);
                    int aji = area(hull[j], hull[ji], hull[i]);

                    while ((ij + 1) % size != j && area(hull[i], hull[(ij + 1) % size], hull[j]) > aij) {
                        ij = (ij + 1) % size;
                        aij = area(hull[i], hull[ij], hull[j]);
                    }

                    while ((ji + 1) % size != i && area(hull[j], hull[(ji + 1) % size], hull[i]) > aji) {
                        ji = (ji + 1) % size;
                        aji = area(hull[j], hull[ji], hull[i]);
                    }

                    ans = max(ans, aij + aji);
                }
            }
        }

        if (!(ans & 1)) cout << (ans / 2) << "\n";
        else cout << (ans / 2) << ".5\n";
    }
}