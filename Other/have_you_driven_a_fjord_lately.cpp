#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define Vector Point

const ldouble EPS = 1e-9;
const ldouble INF = 1e18 + 5;

int sign(ldouble x) {
    return fabsl(x) < EPS ? 0 : (x < 0 ? -1 : 1);
}

template<typename T>
struct Point {
    T x, y;

    Point(): x(0), y(0) {}
    Point(T x, T y): x(x), y(y) {}

    Vector<T> operator -(Point<T> other) {
        return Vector<T>(x - other.x, y - other.y);
    }

    T operator *(Vector<T> other) {
        return x * other.x + y * other.y;
    }
};

template<typename T>
ldouble abs(Vector<T> v) {
    return sqrtl(v * v);
}

template<typename T>
ldouble angle(Vector<T> u, Vector<T> v) {
    return acosl(u * v / abs(u) / abs(v));
}

int n, m;
vector<Point<ldouble>> points;

pair<ldouble, ldouble> bhaskara(ldouble a, ldouble b, ldouble c) {
    ldouble delta = b * b - 4LL * a * c;
    if (sign(delta) < 0) return make_pair(INF, INF);
    return make_pair((-b + sqrtl(delta)) / 2LL / a, (-b - sqrtl(delta)) / 2LL / a);
}

pair<ldouble, ldouble> cosine_law(ldouble a, ldouble c, ldouble theta) {
    // c^2 = a^2 + b^2 - 2ab * cos(theta)
    // b^2 - 2ab * cos(theta) + a^2 - c^2 = 0
    return bhaskara(1LL, -2LL * a * cosl(theta), a * a - c * c);
}

ldouble get_savings(int fjord, int bridge) {
    Vector<ldouble> u = points[fjord] - points[fjord + 1];
    Vector<ldouble> v = points[fjord + 2] - points[fjord + 1];

    ldouble theta = angle(u, v);
    ldouble size = bridge / sinl(theta / 2.0L) / 2.0L;

    if (sign(size - abs(u)) > 0 || sign(size - abs(v)) > 0) {
        auto [b1, b2] = cosine_law(abs(u), bridge, theta);
        auto [b3, b4] = cosine_law(abs(v), bridge, theta);

        ldouble ans = -INF;
        if (sign(b1 - INF) < 0) {
            if (sign(b1) >= 0 && sign(b1 - abs(v)) <= 0) ans = max(ans, abs(u) + b1 - bridge);
            if (sign(b2) >= 0 && sign(b2 - abs(v)) <= 0) ans = max(ans, abs(u) + b2 - bridge);
        }

        if (sign(b3 - INF) < 0) {
            if (sign(b3) >= 0 && sign(b3 - abs(u)) <= 0) ans = max(ans, abs(v) + b3 - bridge);
            if (sign(b4) >= 0 && sign(b4 - abs(u)) <= 0) ans = max(ans, abs(v) + b4 - bridge);
        }

        return ans;
    }

    return 2.0L * size - bridge;
}

void solve(int l, int r, int optl, int optr, vector<ldouble> &last, vector<ldouble> &curr, vector<ldouble> &savings) {
    if (l > r) return;

    int opt = -1;
    ldouble mx = -INF;
    int mid = (l + r) / 2;

    for (int i = optl; i <= min(mid, optr); i++) {
        ldouble aux = last[mid - i] + savings[i];
        if (sign(aux - mx) > 0) {
            opt = i;
            mx = aux;
        }
    }

    curr[mid] = mx;
    solve(l, mid - 1, optl, opt, last, curr, savings);
    solve(mid + 1, r, opt, optr, last, curr, savings);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(2) << fixed;

    int t = 1;
    while (cin >> n >> m, n || m) {
        points.resize(2 * n + 1);
        for (int i = 0; i <= 2 * n; i++) {
            int x, y;
            cin >> x >> y;
            points[i] = Point<ldouble>(x, y);
        }

        vector<ldouble> dp(m + 1, 0.0L);
        for (int i = 0; i < 2 * n; i += 2) {
            vector<ldouble> savings(m + 1, 0.0L);
            for (int j = 1; j <= m; j++)
                savings[j] = get_savings(i, j);

            vector<ldouble> curr(m + 1);
            solve(0, m, 0, m, dp, curr, savings);
            dp = curr;
        }

        int bridge = m;
        while (bridge - 1 >= 0 && !sign(dp[bridge - 1] - dp[bridge])) bridge--;

        cout << "Case " << t++ << ": " << bridge << " meters used saving " << dp[m] << " meters\n";
    }
}