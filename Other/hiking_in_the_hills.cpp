#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define Vector Point

template<typename T>
struct Point {
    T x, y, z;

    Point(T x = 0, T y = 0, T z = 0): x(x), y(y), z(z) {}

    Vector<T> operator -(Point<T> other) {
        return Vector<T>(x - other.x, y - other.y);
    }

    bool operator <(Point<T> const &other) const {
        return make_tuple(x, y, z) < make_tuple(other.x, other.y, other.z);
    }

    bool operator ==(Point<T> const &other) const {
        return x == other.x && y == other.y && z == other.z;
    }
};

template<typename T>
T cross(Vector<T> u, Vector<T> v) {
    return u.x * v.y - u.y * v.x;
}

template<typename T>
struct Segment {
    Point<T> A, B;

    Segment(Point<T> A = Point<T>(), Point<T> B = Point<T>()) {
        if (B < A) swap(A, B);
        this->A = A;
        this->B = B;
    }

    bool operator <(Segment<T> const &other) const {
        if (A == other.A) return B < other.B;
        return A < other.A;
    }
};

template<typename T>
struct Triangle {
    Point<T> A, B, C;

    Triangle(Point<T> A = Point<T>(), Point<T> B = Point<T>(), Point<T> C = Point<T>()): A(A), B(B), C(C) {}

    bool inside(Point<T> P) {
        if (P == A || P == B || P == C) return true;

        T cAB = cross(B - A, P - A);
        T cBC = cross(C - B, P - B);
        T cCA = cross(A - C, P - C);

        if (cAB < 0 && cBC < 0 && cCA <= 0) return true;
        if (cAB > 0 && cBC > 0 && cCA >= 0) return true;
        if (cAB < 0 && cBC <= 0 && cCA < 0) return true;
        if (cAB > 0 && cBC >= 0 && cCA > 0) return true;
        if (cAB <= 0 && cBC < 0 && cCA < 0) return true;
        if (cAB >= 0 && cBC > 0 && cCA > 0) return true;

        return false;
    }
};

template<typename T>
int get_triangle(vector<Triangle<T>> &triangles, Point<T> P) {
    for (int i = 0; i < (int) triangles.size(); i++)
        if (triangles[i].inside(P)) return i;

    return -1;
}

template<typename T>
vector<int> get_path(vector<vector<pair<int, Point<T>>>> &g, int s, int t) {
    int n = g.size();

    vector<bool> vis(n, false);
    vector<int> dist(n, INT_MAX);
    vector<int> prev(n, -1);
    dist[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.emplace(0, s);

    while (!heap.empty()) {
        int v = heap.top().second; heap.pop();
        if (vis[v]) continue;
        vis[v] = true;

        for (auto [u, P]: g[v])
            if (!vis[u] && max((T) dist[v], P.z) < dist[u]) {
                prev[u] = v;
                dist[u] = max((T) dist[v], P.z);
                heap.emplace(dist[u], u);
            }
    }

    assert(vis[t]);

    int v = t;
    vector<int> path;

    while (v != -1) {
        path.push_back(v);
        v = prev[v];
    }

    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("hiking.in", "r", stdin);
    freopen("hiking.out", "w", stdout);

    int n; cin >> n;

    vector<Triangle<llong>> triangles(n);
    map<Segment<llong>, vector<int>> segments;

    for (int i = 0; i < n; i++) {
        int x1, y1, z1, x2, y2, z2, x3, y3, z3;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3;

        Point<llong> A(x1, y1, z1), B(x2, y2, z2), C(x3, y3, z3);
        Segment<llong> AB(A, B), BC(B, C), CA(C, A);

        segments[AB].push_back(i);
        segments[BC].push_back(i);
        segments[CA].push_back(i);
        triangles[i] = Triangle(A, B, C);
    }

    int x, y, z;
    cin >> x >> y >> z;

    Point<llong> A(x, y, z);

    cin >> x >> y >> z;

    Point<llong> B(x, y, z);

    vector<vector<pair<int, Point<llong>>>> g(n, vector<pair<int, Point<llong>>>());
    for (auto [segment, indices]: segments) {
        int sz = indices.size();
        if (sz > 1) {
            assert(sz == 2);

            int u = indices[0];
            int v = indices[1];
            Point<llong> P = segment.A.z < segment.B.z ? segment.A : segment.B;

            g[u].emplace_back(v, P);
            g[v].emplace_back(u, P);
        }
    }

    int s = get_triangle(triangles, A);
    int t = get_triangle(triangles, B);

    assert(s != -1);
    assert(t != -1);

    vector<Point<llong>> ans(1, A);
    vector<int> path = get_path(g, s, t);

    for (int i = 1; i < (int) path.size(); i++)
        for (auto [v, P]: g[path[i - 1]])
            if (v == path[i] && !(P == ans.back()))
                ans.push_back(P);

    if (!(B == ans.back()))
        ans.push_back(B);

    int cnt = ans.size();
    cout << cnt << "\n";

    for (auto [x, y, z]: ans)
        cout << x << " " << y << " " << z << "\n";
}