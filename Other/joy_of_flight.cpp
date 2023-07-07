#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define Vector Point

template<typename T>
struct Point {
    T x, y;

    Point(T x = 0, T y = 0): x(x), y(y) {}

    Vector<T> operator *(T k) {
        return Vector<T>(k * x, k * y);
    }

    Vector<T> operator -(Point<T> other) {
        return Vector<T>(x - other.x, y - other.y);
    }

    Point<T> operator +(Vector<T> other) {
        return Point<T>(x + other.x, y + other.y);
    }

    T operator *(Vector<T> other) {
        return x * other.x + y * other.y;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("joy.in", "r", stdin);
    freopen("joy.out", "w", stdout);

    cout << setprecision(6) << fixed;

    int Sx, Sy, Fx, Fy;
    cin >> Sx >> Sy >> Fx >> Fy;

    int n, k, vmax;
    cin >> n >> k >> vmax;

    int last_t = 0;
    Vector<llong> last_w;
    vector<Vector<llong>> wind;

    for (int i = 0; i < n; i++) {
        int t, wx, wy;
        cin >> t >> wx >> wy;

        for (int j = last_t; j < t; j++)
            wind.push_back(last_w);

        last_t = t;
        last_w = Vector<llong>(wx, wy);
    }

    for (int i = last_t; i < k; i++)
        wind.push_back(last_w);

    assert((int) wind.size() == k);

    Vector<llong> sum;
    for (int i = 0; i < k; i++)
        sum = sum + wind[i];

    Vector<llong> target = Point<llong>(Fx, Fy) - Point<llong>(Sx, Sy);
    Vector<llong> diff = target - sum;

    if (diff * diff > 1LL * k * k * vmax * vmax) cout << "No\n";
    else {
        cout << "Yes\n";

        Point<ldouble> P(Sx, Sy);
        Vector<ldouble> v = Vector<ldouble>(diff.x, diff.y) * (1.0L / k);

        for (int i = 0; i < k; i++) {
            Vector<ldouble> dir = Vector<ldouble>(wind[i].x, wind[i].y) + v;
            P = P + dir;

            cout << P.x << " " << P.y << "\n";
        }
    }
}