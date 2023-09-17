#include <bits/stdc++.h>

using namespace std;

#define Vector Point

template<typename T>
struct Point {
    T x, y;

    Point(T x = 0, T y = 0): x(x), y(y) {}

    Vector<T> operator -(Point<T> other) {
        return Vector<T>(x - other.x, y - other.y);
    }

    T operator /(Vector<T> other) {
        return x * other.y - other.x * y;
    }

    bool operator <(Point<T> const &other) const {
        if (x == other.x)
            return y < other.y;

        return x < other.x;
    }
};

template<typename T>
bool left_turn(Vector<T> u, Vector<T> v) {
    return u / v > 0;
}

template<typename T>
vector<pair<Point<T>, int>> half_hull(vector<pair<Point<T>, int>> &points, int l, int r, int d) {
    vector<pair<Point<T>, int>> hull;
    for (int i = l; i != r; i += d) {
        int size = hull.size();
        while (size > 1 && left_turn(hull[size - 1].first - hull[size - 2].first, points[i].first - hull[size - 2].first))
            hull.pop_back(), size--;

        hull.push_back(points[i]);
    }

    return hull;
}

template<typename T>
vector<pair<Point<T>, int>> convex_hull(vector<pair<Point<T>, int>> &points) {
    int n = points.size();
    sort(points.begin(), points.end());

    vector<pair<Point<T>, int>> hull = half_hull(points, 0, n, 1);
    vector<pair<Point<T>, int>> lower = half_hull(points, n - 1, -1, -1);

    for (int i = 1; i < (int) lower.size() - 1; i++)
        hull.push_back(lower[i]);

    return hull;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<pair<Point<int>, int>> points(N);
    for (int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;
        points[i] = make_pair(Point<int>(X, Y), i + 1);
    }

    points = convex_hull(points);

    vector<int> ans(points.size());
    for (int i = 0; i < (int) points.size(); i++)
        ans[i] = points[i].second;

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for (int i = 0; i < (int) ans.size(); i++) {
        if (i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}