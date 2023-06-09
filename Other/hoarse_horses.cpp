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
        return x * other.y - other.x * y;
    }
};

void visit(vector<vector<int>> &g, vector<bool> &vis, int v) {
    vis[v] = true;
    for (int u: g[v])
        if (!vis[u])
            visit(g, vis, u);
}

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<pair<Point<llong>, Point<llong>>> fences(n);
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        Point<llong> P(x1, y1), Q(x2, y2);
        fences[i] = make_pair(P, Q);
    }

    int intersections = 0;
    vector<vector<int>> g(n, vector<int>());

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            auto [A, B] = fences[i];
            auto [C, D] = fences[j];

            if (seg_seg(A, B, C, D)) {
                intersections++;
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }

    int components = 0;
    vector<bool> vis(n, false);

    for (int i = 0; i < n; i++)
        if (!vis[i]) {
            components++;
            visit(g, vis, i);
        }

    int ans = components - n + intersections;
    cout << ans << "\n";
}