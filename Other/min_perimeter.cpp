#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define Vector Point

const ldouble EPS = 1e-9;
const ldouble INF = 9e18 + 5;

int sign(ldouble x) {
    return fabsl(x) < EPS ? 0 : (x < 0 ? -1 : 1);
}

template<typename T>
struct Point {
    T x, y;

    Point(): x(0), y(0) {}
    Point(T x, T y): x(x), y(y) {}

    Vector<T> operator -(Point<T> other) {
        return Vector<T>(x - other.x, y - other.y);
    }

    T operator *(Vector<T> other) {
        return x * other.x + y * other.y;
    }

    bool operator <(Point<T> const &other) const {
        if (x == other.x) return y < other.y;
        return x < other.x;
    }
};

template<typename T>
ldouble abs(Vector<T> v) {
    return sqrtl(v * v);
}

void merge(vector<Point<llong>> &left, vector<Point<llong>> &right, vector<Point<llong>> &all) {
    int i = 0, j = 0, k = 0, m = left.size(), n = right.size();
    while (i < m || j < n) {
        if (i >= m) all[k++] = right[j++];
        else if (j >= n) all[k++] = left[i++];
        else if (left[i].y <= right[j].y) all[k++] = left[i++];
        else all[k++] = right[j++];
    }
}

ldouble min_perimeter(vector<Point<llong>> &points) {
    int n = points.size();
    if (n <= 2) {
        if (n == 2 && points[0].y > points[1].y)
            swap(points[0], points[1]);

        return INF;
    }

    vector<Point<llong>> left(points.begin(), points.begin() + n / 2);
    vector<Point<llong>> right(points.begin() + n / 2, points.end());

    llong middle = left.back().x;
    ldouble p = min(min_perimeter(left), min_perimeter(right));
    merge(left, right, points);

    vector<Point<llong>> stripe;
    for (Point<llong> P: points) {
        llong dx = abs(P.x - middle);
        if (sign(dx - p / 2) < 0) stripe.push_back(P);
    }

    for (int i = 0; i < (int) stripe.size(); i++) {
        int idx = i + 1;
        bool done = false;

        while (!done && idx < (int) stripe.size()) {
            llong dy = abs(stripe[idx].y - stripe[i].y);
            if (sign(dy - p) >= 0) done = true;
            else {
                for (int j = i + 1; j < idx; j++) {
                    Vector<llong> u = stripe[j] - stripe[i];
                    Vector<llong> v = stripe[idx] - stripe[i];
                    Vector<llong> w = stripe[idx] - stripe[j];
                    p = min(p, abs(u) + abs(v) + abs(w));
                }

                idx++;
            }
        }
    }

    return p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(10) << fixed;

    int n; cin >> n;

    vector<Point<llong>> points(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = Point<llong>(x, y);
    }

    sort(points.begin(), points.end());

    ldouble ans = min_perimeter(points);
    cout << ans << "\n";
}