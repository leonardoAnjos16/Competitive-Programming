#include <bits/stdc++.h>

using namespace std;

#define llong long long int
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
};

template<typename T>
bool k_lines(vector<Point<T>> points, int k) {
    if (!k) return points.empty();
    if ((int) points.size() <= k) return true;

    for (int i = 0; i <= k; i++)
        for (int j = i + 1; j <= k; j++) {
            vector<Point<T>> rem;
            for (Point<T> P: points)
                if ((P - points[i]) / (points[j] - points[i]))
                    rem.push_back(P);

            if (k_lines(rem, k - 1)) return true;
        }

    return false;
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

    bool possible = k_lines(points, 3);
    cout << (possible ? "possible" : "impossible") << "\n";
}