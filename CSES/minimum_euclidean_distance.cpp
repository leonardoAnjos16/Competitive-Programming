#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int sign(llong x) {
    return !x ? 0 : (x < 0 ? -1 : 1);
}

template<typename T>
struct Point {
    T x, y;

    Point(): x(0), y(0) {}
    Point(T x, T y): x(x), y(y) {}

    bool operator <(Point<T> const &other) const {
        if (!sign(x - other.x))
            return sign(y - other.y) < 0;

        return sign(x - other.x) < 0;
    }
};

void merge(vector<Point<int>> &left, vector<Point<int>> &right, vector<Point<int>> &all) {
    int i = 0, j = 0, k = 0, m = left.size(), n = right.size();
    while (i < m || j < n) {
        if (i >= m) all[k++] = right[j++];
        else if (j >= n) all[k++] = left[i++];
        else if (left[i].y <= right[j].y) all[k++] = left[i++];
        else all[k++] = right[j++];
    }
}

llong squared_dist(Point<int> P, Point<int> Q) {
    int dx = Q.x - P.x, dy = Q.y - P.y;
    return 1LL * dx * dx + 1LL * dy * dy;
}

llong min_squared_dist(vector<Point<int>> &points) {
    int n = points.size();
    if (n <= 1) return LLONG_MAX;

    vector<Point<int>> left(points.begin(), points.begin() + n / 2);
    vector<Point<int>> right(points.begin() + n / 2, points.end());

    int middle = left.back().x;
    llong d = min(min_squared_dist(left), min_squared_dist(right));
    merge(left, right, points);

    vector<Point<int>> stripe;
    for (Point<int> P: points) {
        int dx = P.x - middle;
        if (1LL * dx * dx < d)
            stripe.push_back(P);
    }

    for (int i = 0; i < (int) stripe.size(); i++) {
        int idx = i + 1;
        bool done = false;

        while (!done && idx < (int) stripe.size()) {
            int dy = stripe[idx].y - stripe[i].y;
            if (1LL * dy * dy >= d) done = true;
            else d = min(d, squared_dist(stripe[i], stripe[idx++]));
        }
    }

    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<Point<int>> points(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = Point<int>(x, y);
    }

    sort(points.begin(), points.end());
    llong ans = min_squared_dist(points);
    cout << ans << "\n";
}