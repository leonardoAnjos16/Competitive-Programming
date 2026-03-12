#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define Vector Point

template<typename T>
struct Point {
    T x, y;

    Point(T x = 0, T y = 0): x(x), y(y) {}

    T operator *(Vector<T> other) const {
        return x * other.x + y * other.y;
    }

    T operator /(Vector<T> other) const {
        return x * other.y - other.x * y;
    }

    bool up() const {
        if (y > 0) return true;
        if (y < 0) return false;
        return x >= 0;
    }

    bool operator <(Point<T> const &other) const {
        if (up() != other.up()) return up();
        return *this / other > 0;
    }
};

template<typename T>
bool above(Vector<T> u, Vector<T> v) {
    if (u / v > 0) return true;
    if (u / v < 0) return false;
    return u * v >= 0;
}

template<typename T>
istream& operator >>(istream &cin, Point<T> &P) {
    T x, y;
    cin >> x >> y;
    P = Point<T>(x, y);
    return cin;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;

        vector<Vector<llong>> points(n);
        for (int i = 0; i < n; i++)
            cin >> points[i];

        sort(points.begin(), points.end());

        int l = 0, r = 0, cnt = 1, ans = INT_MAX;
        while (l < n) {
            while ((r + 1) % n != l && above(points[l], points[(r + 1) % n]))
                r = (r + 1) % n, cnt++;

            ans = min(ans, n - cnt--);
            if (l++ == r) {
                r++;
                cnt = 1;
            }
        }

        cout << ans << "\n";
    }
}