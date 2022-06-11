#include <bits/stdc++.h>

using namespace std;

#define Vector Point

const long double EPS = 1e-6;

bool zero(long double n) {
    return fabsl(n) <= EPS;
}

bool positive(long double n) {
    return n > EPS;
}

bool negative(long double n) {
    return n < -EPS;
}

struct Point {
    long double x, y;

    Point(): x(0.0L), y(0.0L) {}
    Point(long double x, long double y): x(x), y(y) {}

    Vector operator -() {
        return Vector(-x, -y);
    }

    Point operator +(Vector v) {
        return Point(x + v.x, y + v.y);
    }

    Vector operator -(Point other) {
        return Point(x - other.x, y - other.y);
    }

    Vector operator *(long double k) {
        return Vector(x * k, y * k);
    }

    long double operator ^(Vector &other) {
        return x * other.y - y * other.x;
    }

    bool operator <(const Point &other) const {
        if (zero(x - other.x))
            return negative(y - other.y);

        return negative(x - other.x);
    }
};

struct Line {
    Point P;
    Vector v;

    Line(Point P, Point Q) {
        if (Q < P) swap(P, Q);
        this->P = P;
        v = Q - P;
    }

    pair<Point, bool> intersection(Line &other) {
        long double den = v ^ other.v;
        if (zero(den)) return make_pair(Point(), false);

        long double t = ((other.P - P) ^ other.v) / den;
        return make_pair(P + v * t, true);
    }

    bool contains(Point Q) {
        return zero((Q - P) ^ v);
    }
};

struct Street {
    string name;
    Line line;

    Street(): name(""), line(Point(), Point()) {}
    Street(string name, Line line): name(name), line(line) {}
};

bool right_turn(Vector &u, Vector &v) {
    return negative(u ^ v);
}

bool infinity(vector<vector<pair<Point, int>>> &intersections, int street, int segment, bool going_right) {
    return (!going_right && !segment) || (going_right && segment >= (int) intersections[street].size());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, X, Y; long long int N;
    cin >> R >> N >> X >> Y;

    vector<Street> streets(R);
    for (int i = 0; i < R; i++) {
        string S; cin >> S;

        int X1, Y1, X2, Y2;
        cin >> X1 >> Y1 >> X2 >> Y2;

        Point P(X1, Y1), Q(X2, Y2);
        streets[i] = Street(S, Line(P, Q));
    }

    vector<vector<pair<Point, int>>> intersections(R);
    for (int i = 0; i < R; i++)
        for (int j = i + 1; j < R; j++) {
            auto [P, has_intersection] = streets[i].line.intersection(streets[j].line);
            if (has_intersection) {
                intersections[i].emplace_back(P, j);
                intersections[j].emplace_back(P, i);
            }
        }

    for (int i = 0; i < R; i++)
        sort(intersections[i].begin(), intersections[i].end());

    Point home(X, Y);
    int street = -1, segment = -1;

    for (int i = 0; i < R; i++)
        if (streets[i].line.contains(home)) {
            auto it = upper_bound(intersections[i].begin(), intersections[i].end(), make_pair(home, INT_MAX));
            segment = it - intersections[i].begin();
            street = i;
        }

    assert(street != -1);
    assert(segment != -1);

    vector<vector<bool>> vis(R);
    for (int i = 0; i < R; i++)
        vis[i].assign((int) intersections[i].size() + 1, false);

    vector<int> cycle;
    bool going_right = true;

    while (N && !infinity(intersections, street, segment, going_right) && !vis[street][segment]) {
        cycle.push_back(street);
        vis[street][segment] = true;

        Vector direction = going_right ? streets[street].line.v : -streets[street].line.v;
        auto [P, next_street] = going_right ? intersections[street][segment] : intersections[street][segment - 1];

        Vector other_direction = streets[next_street].line.v;
        going_right = right_turn(direction, other_direction);

        auto it = upper_bound(intersections[next_street].begin(), intersections[next_street].end(), make_pair(P, INT_MAX));
        int next_segment = it - intersections[next_street].begin() - !going_right;

        street = next_street;
        segment = next_segment;
        N--;
    }

    if (!N || infinity(intersections, street, segment, going_right)) cout << streets[street].name << "\n";
    else {
        int idx = 0;
        while (idx < (int) cycle.size() && cycle[idx] != street) idx++;
        assert(idx < (int) cycle.size());

        cycle.erase(cycle.begin(), cycle.begin() + idx);

        int size = cycle.size();
        cout << streets[cycle[N % size]].name;
    }
}