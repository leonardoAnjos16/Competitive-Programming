#include <bits/stdc++.h>

using namespace std;

#define llong long long int

#define BEGIN 0
#define BALLOON 1
#define END 2

const long double EPS = 1e-9;

int sign(long double x) {
    return abs(x) < EPS ? 0 : (x > 0 ? 1 : -1);
}

template<typename T>
struct Point {
    T x, y;

    Point(): x(0), y(0) {}
    Point(T x, T y): x(x), y(y) {}
};

struct Event {
    int x, type, idx;

    Event(int x, int type, int idx): x(x), type(type), idx(idx) {}

    bool operator <(const Event &other) const {
        if (x == other.x)
            return type < other.type;

        return x < other.x;
    }
};

struct Segment {
    int idx;
    Point<llong> P, Q;

    Segment(int idx, Point<llong> P, Point<llong> Q): idx(idx) {
        if (P.x > Q.x) swap(P, Q);
        this->P = P;
        this->Q = Q;
    }

    long double get_y(llong x) const {
        if (P.x == Q.x) return P.y;

        long double m = 1.0L * (Q.y - P.y) / (Q.x - P.x);
        return P.y + m * (x - P.x);
    }

    bool operator <(const Segment &other) const {
        llong x = max(P.x, other.P.x);
        int y1 = get_y(x), y2 = other.get_y(x);

        if (!sign(y1 - y2))
            return idx < other.idx;

        return sign(y1 - y2) < 0;
    }
};

void get_exit(vector<vector<int>> &forest, vector<int> &exit, vector<int> &slast, int node, int idx, int sidx = -1) {
    exit[node] = idx;
    slast[node] = sidx;

    for (int child: forest[node])
        get_exit(forest, exit, slast, child, idx, node == idx ? child : sidx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, C;
    while (cin >> N >> C) {
        vector<Event> events;
        vector<Segment> segments;

        for (int i = 0; i < N; i++) {
            int X1, Y1, X2, Y2;
            cin >> X1 >> Y1 >> X2 >> Y2;

            events.emplace_back(min(X1, X2), BEGIN, i);
            events.emplace_back(max(X1, X2), END, i);

            Point<llong> P(X1, Y1), Q(X2, Y2);
            segments.emplace_back(i, P, Q);
        }

        vector<int> balloons(C);
        for (int i = 0; i < C; i++) {
            cin >> balloons[i];
            events.emplace_back(balloons[i], BALLOON, i);
        }

        sort(events.begin(), events.end());

        set<Segment> active;
        vector<int> parent(N, -1), first(C, -1);

        for (auto [x, type, idx]: events) {
            if (type == BEGIN) {
                active.insert(segments[idx]);
                if (segments[idx].P.y > segments[idx].Q.y) {
                    auto it = active.upper_bound(segments[idx]);
                    if (it != active.end()) parent[idx] = it->idx;
                }
            } else if (type == END) {
                if (segments[idx].P.y < segments[idx].Q.y) {
                    auto it = active.upper_bound(segments[idx]);
                    if (it != active.end()) parent[idx] = it->idx;
                }

                active.erase(segments[idx]);
            } else {
                auto it = active.begin();
                if (it != active.end())
                    first[idx] = it->idx;
            }
        }

        vector<vector<int>> forest(N, vector<int>());
        for (int i = 0; i < N; i++)
            if (parent[i] != -1)
                forest[parent[i]].push_back(i);

        vector<int> exit(N, -1), slast(N);
        for (int i = 0; i < N; i++)
            if (exit[i] == -1)
                get_exit(forest, exit, slast, i, i);

        for (int i = 0; i < C; i++) {
            if (first[i] == -1) cout << balloons[i] << "\n";
            else {
                int last = exit[first[i]];
                if (segments[last].P.y > segments[last].Q.y) cout << segments[last].P.x << "\n";
                else if (segments[last].P.y < segments[last].Q.y) cout << segments[last].Q.x << "\n";
                else if (first[i] == last) cout << balloons[i] << " " << segments[last].P.y << "\n";
                else {
                    int idx = slast[first[i]];
                    assert(idx != -1);

                    int x = segments[idx].P.y > segments[idx].Q.y ? segments[idx].P.x : segments[idx].Q.x;
                    cout << x << " " << segments[last].P.y << "\n";
                }
            }
        }
    }
}