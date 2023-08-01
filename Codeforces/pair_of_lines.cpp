#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define Vector Point

template<typename T>
struct Point {
    T x, y;

    Point(T x = 0, T y = 0): x(x), y(y) {}

    Point<T> operator -(Point<T> other) {
        return Point<T>(x - other.x, y - other.y);
    }

    T operator /(Vector<T> other) {
        return x * other.y - other.x * y;
    }
};

template<typename T>
bool one_line(vector<Point<T>> &points) {
    for (int i = 2; i < (int) points.size(); i++)
        if ((points[i] - points[0]) / (points[1] - points[0]))
            return false;

    return true;
}

template<typename T>
bool two_lines(vector<Point<T>> &points, int a, int b) {
    vector<Point<T>> rem;
    for (int i = 0; i < (int) points.size(); i++) {
        if (i == a || i == b) continue;

        if ((points[i] - points[a]) / (points[b] - points[a]))
            rem.push_back(points[i]);
    }

    return one_line(rem);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<Point<llong>> points(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = Point<llong>(x, y);
    }

    if (n <= 2) cout << "YES\n";
    else {
        bool possible = two_lines(points, 0, 1);
        possible |= two_lines(points, 0, 2);
        possible |= two_lines(points, 1, 2);
        cout << (possible ? "YES" : "NO") << "\n";
    }
}