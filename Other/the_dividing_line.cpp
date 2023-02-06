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
        return Vector<T>(x - other.x, y - other.y);
    }

    T operator /(Vector<T> other) {
        return x * other.y - y * other.x;
    }
};

template<typename T>
bool left_turn(Vector<T> u, Vector<T> v) {
    return sign(u / v) > 0;
}

template<typename T>
bool right_turn(Vector<T> u, Vector<T> v) {
    return sign(u / v) < 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<Point<llong>> points(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = Point<llong>(x, y);
    }

    int M; cin >> M;
    while (M--) {
        int X1, Y1, X2, Y2;
        cin >> X1 >> Y1 >> X2 >> Y2;

        Point<llong> P(X1, Y1);
        Point<llong> Q(X2, Y2);
        Vector<llong> u = Q - P;

        vector<int> left, right;
        for (int i = 0; i < N && (left.empty() || right.empty()); i++) {
            Vector<llong> v = points[i] - P;
            if (left_turn(u, v)) left.push_back(i + 1);
            else if (right_turn(u, v)) right.push_back(i + 1);
        }

        if (left.empty() || right.empty()) cout << "0\n";
        else cout << left[0] << " " << right[0] << "\n";
    }
}