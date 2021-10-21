#include <bits/stdc++.h>

using namespace std;

#define long long long int

int N;
complex<long> A, B;
vector<pair<int, int>> points;
vector<int> memo;

long cross(complex<long> u, complex<long> v) {
    return u.real() * v.imag() - u.imag() * v.real();
}

bool inside(int i, int j) {
    complex<long> C = { points[j].first, points[j].second };
    complex<long> P = { points[i].first, points[i].second };
    if (cross(B - A, C - B) < 0) swap(A, B);

    bool b1 = cross(B - A, P - B) < 0;
    bool b2 = cross(C - B, P - C) < 0;
    bool b3 = cross(A - C, P - A) < 0;

    return b1 == b2 && b2 == b3;
}

int max_points(int last = N) {
    int &ans = memo[last];
    if (~ans) return ans;

    ans = 0;
    for (int i = 0; i < N; i++) {
        if (i == last) continue;
        if (last == N || inside(i, last))
            ans = max(ans, max_points(i) + 1);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int XA, XB;
    cin >> N >> XA >> XB;

    A = { XA, 0 };
    B = { XB, 0 };

    points.resize(N);
    for (int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;
        points[i] = make_pair(X, Y);
    }

    memo.assign(N + 5, -1);

    int ans = max_points();
    cout << ans << "\n";
}