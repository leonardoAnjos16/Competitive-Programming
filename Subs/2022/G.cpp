#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define Vector Point

template<typename T>
struct Point {
    T x, y;

    Point(T x = 0, T y = 0): x(x), y(y) {}

    Vector operator -(Point<T> other) {
        return Vector<T>(x - other.x, y - other.y);
    }

    T operator /(Vector<T> other) {
        return x * other.y - y * other.x;
    }

    bool operator ==(Point<T> const &other) const {
        return x == other.x && y == other.y;
    }

    bool operator <(Point<T> const &other) const {
        if (x == other.x)
            return y < other.y;

        return x < other.x;
    }
};

template<typename T>
struct Segment {
    Point<T> P, Q;

    Segment(Point<T> P = Point<T>(), Point<T> Q = Point<T>()) {
        if (Q < P) swap(P, Q);
        this->P = P;
        this->Q = Q;
    }

    bool operator <(Segment<T> const &other) const {
        if (P == other.P)
            return Q < other.Q;

        return P < other.P;
    }
};

vector<llong> darea;
vector<vector<int>> tree;
vector<vector<llong>> memo;

llong min_area(bool can_remove = true, int node = 0, int parent = -1) {
    llong &ans = memo[can_remove][node];
    if (~ans) return ans;

    llong keep = darea[node], remove = 0LL;
    for (int child: tree[node])
        if (child != parent) {
            keep += min_area(true, child, node);
            remove += min_area(false, child, node);
        }

    ans = keep;
    if (can_remove && (int) tree[node].size() == 3)
        ans = min(ans, remove);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    darea.resize(N);
    tree.assign(N, vector<int>());
    map<Segment<llong>, int> triangle;

    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        Point<llong> A(x1, y1), B(x2, y2), C(x3, y3);
        Segment<llong> AB(A, B), AC(A, C), BC(B, C);

        if (triangle.count(AB)) {
            int v = triangle[AB];
            tree[i].push_back(v);
            tree[v].push_back(i);
        }
        
        if (triangle.count(AC)) {
            int v = triangle[AC];
            tree[i].push_back(v);
            tree[v].push_back(i);
        }
        
        if (triangle.count(BC)) {
            int v = triangle[BC];
            tree[i].push_back(v);
            tree[v].push_back(i);
        }

        darea[i] = abs((B - A) / (C - A));
        triangle[AB] = triangle[AC] = triangle[BC] = i;
    }

    memo.assign(2, vector<llong>(N + 5, -1LL));

    llong ans = min_area();
    cout << (ans / 2LL) << "." << (ans & 1LL ? "5" : "0") << "\n";
}