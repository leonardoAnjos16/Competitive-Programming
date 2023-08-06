#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define Vector Point

const int INF = 1e9 + 5;
const int BEGIN = 0;
const int QUERY = 1;
const int END = 2;

int sign(llong x) {
    return !x ? 0 : (x < 0 ? -1 : 1);
}

template<typename T>
struct Point {
    T x, y;

    Point(T x = 0, T y = 0): x(x), y(y) {}

    Vector<T> operator -() {
        return Vector<T>(-x, -y);
    }

    Vector<T> operator -(Point<T> other) {
        return Vector<T>(x - other.x, y - other.y);
    }

    T operator *(Vector<T> other) const {
        return x * other.x + y * other.y;
    }

    T operator /(Vector<T> other) const {
        return x * other.y - other.x * y;
    }

    bool up() const {
        if (sign(y) > 0) return true;
        return sign(x) >= 0;
    }

    bool operator <(Vector<T> const &other) const {
        if (up() != other.up()) return up();
        return sign(*this / other) > 0;
    }
};

template<typename T>
bool right_turn(Vector<T> u, Vector<T> v) {
    return u / v < 0;
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

    //! N <= 2

    int N, Q;
    cin >> N >> Q;

    vector<Point<llong>> points(N);
    for (int i = 0; i < N; i++)
        cin >> points[i];

    int concave = 0;
    vector<tuple<Vector<llong>, int, int>> events;

    for (int i = 0; i < N; i++) {
        Vector<llong> u = points[(i + 1) % N] - points[i];
        Vector<llong> v = points[(i + 2) % N] - points[(i + 1) % N];

        if (right_turn(u, v)) {
            u = -u;
            if (u.y < 0 || (u.y == 0 && u.x < 0)) u = -u;
            if (v.y < 0 || (v.y == 0 && v.x < 0)) v = -v;

            concave++;
            if (right_turn(v, u)) {
                events.emplace_back(u, BEGIN, -1);
                events.emplace_back(v, END, -1);
            } else {
                events.emplace_back(u, BEGIN, -1);
                events.emplace_back(Vector<llong>(1, 0), BEGIN, -1);
                events.emplace_back(v, END, -1);
            }
        }
    }

    for (int i = 0; i < Q; i++) {
        Vector<llong> v; cin >> v;
        v = Vector<llong>(-v.y, v.x);
        v = v.y < 0 || (v.y == 0 && v.x < 0) ? -v : v;
        events.emplace_back(v, QUERY, i);
    }

    int open = 0;
    vector<char> ans(Q);
    sort(events.begin(), events.end());

    for (auto [v, type, idx]: events) {
        if (type == BEGIN) open++;
        else if (type == END) open--;
        else if (open >= concave) ans[idx] = 'Y';
        else ans[idx] = 'N';
    }

    for (int i = 0; i < Q; i++)
        cout << ans[i] << "\n";
}