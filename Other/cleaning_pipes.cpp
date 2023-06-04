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

    Point() {}
    Point(T x, T y): x(x), y(y) {}

    Point<T> operator +(Vector<T> v) {
        return Point<T>(x + v.x, y + v.y);
    }

    Vector<T> operator -(Point<T> other) {
        return Point<T>(x - other.x, y - other.y);
    }

    Vector<T> operator *(T k) {
        return Vector<T>(x * k, y * k);
    }

    T operator /(Vector<T> other) {
        return x * other.y - y * other.x;
    }

    bool operator <(const Point<T> &other) const {
        if (!sign(x - other.x))
            return sign(y - other.y) < 0;

        return sign(x - other.x) < 0;
    }

    bool operator !=(const Point<T> &other) const {
        return sign(x - other.x) || sign(y - other.y);
    }
};

template<typename T>
bool intersect(T a, T b, T c, T d) {
    if (sign(a - b) > 0) swap(a, b);
    if (sign(c - d) > 0) swap(c, d);
    return sign(max(a, c) - min(b, d)) <= 0;
}

template<typename T>
bool seg_seg(Point<T> A, Point<T> B, Point<T> C, Point<T> D) {
    Vector<T> CA = A - C, CB = B - C, CD = D - C;
    if (!sign(CA / CD) && !sign(CB / CD))
        return intersect(A.x, B.x, C.x, D.x) && intersect(A.y, B.y, C.y, D.y);

    Vector<T> AB = B - A, AC = C - A, AD = D - A;
    return sign(AB / AC) != sign(AB / AD) && sign(CA / CD) != sign(CB / CD);
}

bool bicolorable(vector<vector<int>> &g, vector<int> &colors, int v, int c = 0) {
    if (colors[v] == c) return true;
    if (colors[v] != -1) return false;

    colors[v] = c;
    for (int u: g[v])
        if (!bicolorable(g, colors, u, 1 - c))
            return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int w, p;
    cin >> w >> p;

    vector<Point<int>> wells(w);
    for (int i = 0; i < w; i++) {
        int x, y;
        cin >> x >> y;
        wells[i] = Point<int>(x, y);
    }

    vector<pair<Point<int>, Point<int>>> pipes(p);
    for (int i = 0; i < p; i++) {
        int s, x, y;
        cin >> s >> x >> y;

        Point<int> P = wells[s - 1];
        Point<int> Q(x, y);
        pipes[i] = make_pair(P, Q);
    }

    vector<vector<int>> g(p, vector<int>());
    for (int i = 0; i < p; i++)
        for (int j = i + 1; j < p; j++) {
            auto [A, B] = pipes[i];
            auto [C, D] = pipes[j];

            if (seg_seg(A, B, C, D) && A != C) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }

    bool possible = true;
    vector<int> colors(p, -1);

    for (int i = 0; i < p && possible; i++)
        if (colors[i] == -1)
            possible = bicolorable(g, colors, i);

    cout << (possible ? "possible" : "impossible") << "\n";
}