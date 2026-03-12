#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define Vector Point

int sign(llong x) {
    return !x ? 0 : (x > 0 ? 1 : -1);
}

template<typename T>
struct Point {
    T x, y;

    Point(): x(0), y(0) {}
    Point(T x, T y): x(x), y(y) {}

    T operator *(Vector<T> other) {
        return x * other.x + y * other.y;
    }

    T operator /(Vector<T> other) {
        return x * other.y - y * other.x;
    }

    int quad() const {
        if (sign(x) > 0 && sign(y) >= 0) return 0;
        if (sign(x) <= 0 && sign(y) > 0) return 1;
        if (sign(x) < 0 && sign(y) <= 0) return 2;
        return 3;
    }

    bool operator <(const Point<T> &other) const {
        return quad() == other.quad() ? sign(x * other.y - y * other.x) > 0 : quad() < other.quad();
    }
};

bool operator <(pair<llong, llong> a, pair<llong, llong> b) {
    __int128 num = a.first, den = a.second;
    return num * b.second < den * b.first;
}

bool operator >(pair<llong, llong> a, pair<llong, llong> b) {
    __int128 num = a.first, den = a.second;
    return num * b.second > den * b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<pair<Vector<int>, int>> vectors(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vectors[i] = make_pair(Vector<int>(x, y), i);
    }

    sort(vectors.begin(), vectors.end());

    Vector<int> u = vectors[0].first;
    Vector<int> v = vectors[1].first;

    int dot = u * v;
    llong num = 1LL * dot * dot;
    llong den = 1LL * (u * u) * (v * v);
    pair<llong, llong> co = make_pair(num, den);

    int a = vectors[0].second, b = vectors[1].second;
    for (int i = 1; i < n; i++) {
        u = vectors[i].first;
        v = vectors[(i + 1) % n].first;

        int curr_dot = u * v;
        num = 1LL * curr_dot * curr_dot;
        den = 1LL * (u * u) * (v * v);
        pair<llong, llong> curr_co = make_pair(num, den);

        if (dot >= 0 && curr_dot < 0) continue;
        if (dot >= 0 && curr_co < co) continue;
        if (dot < 0 && curr_dot < 0 && curr_co > co) continue;

        co = curr_co;
        dot = curr_dot;
        a = vectors[i].second;
        b = vectors[(i + 1) % n].second;
    }

    cout << (a + 1) << " " << (b + 1) << "\n";
}