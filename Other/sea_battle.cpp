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
bool right_turn(Vector<T> u, Vector<T> v) {
    return u / v < 0;
}

template<typename T>
bool inside(vector<Point<T>> &upper, vector<Point<T>> &lower, Point<T> P) {
    int iu = upper_bound(upper.begin(), upper.end(), P) - upper.begin();
    int il = upper_bound(lower.begin(), lower.end(), P) - lower.begin();

    if (!iu || !il) return false;
    if (iu >= (int) upper.size() && P.x > upper.back().x) return false;
    if (il >= (int) lower.size() && P.x > lower.back().x) return false;

    if (iu >= (int) upper.size()) iu--;
    if (il >= (int) lower.size()) il--;

    if (left_turn(upper[iu] - upper[iu - 1], P - upper[iu - 1])) return false;
    if (left_turn(P - lower[il - 1], lower[il] - lower[il - 1])) return false;

    return true;
}

template<typename T>
pair<vector<Point<T>>, vector<Point<T>>> split(vector<Point<T>> &hull) {
    auto first = min_element(hull.begin(), hull.end());
    auto last = max_element(hull.begin(), hull.end());

    if (first > last) {
        reverse(hull.begin(), hull.end());
        first = min_element(hull.begin(), hull.end());
        last = max_element(hull.begin(), hull.end());
    }

    vector<Point<T>> lower(first, last + 1);
    vector<Point<T>> upper(last, hull.end());

    for (auto it = hull.begin(); it != first; it++)
        upper.push_back(*it);

    upper.push_back(*first);
    reverse(upper.begin(), upper.end());

    bool should_swap = false;
    for (int i = 2; i < (int) lower.size() && !should_swap; i++)
        if (right_turn(lower[i - 1] - lower[i - 2], lower[i] - lower[i - 1]))
            should_swap = true;

    for (int i = 2; i < (int) upper.size() && !should_swap; i++)
        if (left_turn(upper[i - 1] - upper[i - 2], upper[i] - upper[i - 1]))
            should_swap = true;

    if (should_swap) lower.swap(upper);
    return make_pair(upper, lower);
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

    int n, m, k;
    cin >> n >> m >> k;

    vector<Point<llong>> ship(n);
    for (int i = 0; i < n; i++)
        cin >> ship[i];

    int cnt = 0;
    auto [upper, lower] = split(ship);

    while (m--) {
        Point<llong> hit; cin >> hit;
        if (inside(upper, lower, hit)) cnt++;
    }

    cout << (cnt >= k ? "YES" : "NO") << "\n";
}