#include <bits/stdc++.h>

using namespace std;

#define ldouble long double

const ldouble EPS = 1e-9;
const ldouble INF = 1e9 + 5;

int sign(ldouble x) {
    return fabsl(x) < EPS ? 0 : x < 0 ? -1 : 1;
}

ldouble pythagoras(ldouble a, ldouble b) {
    return sqrtl((a + b) * (a - b));
}

struct Circle {
    ldouble x, y, r;

    Circle() {}
    Circle(ldouble x, ldouble y, ldouble r): x(x), y(y), r(r) {}

    pair<ldouble, ldouble> get_ys(ldouble x) {
        ldouble dx = x - this->x;
        ldouble dy = pythagoras(r, dx);
        return make_pair(y + dy, y - dy);
    }
};

ldouble diff(vector<Circle> &circles, ldouble x) {
    ldouble mny = INF, mxy = -INF;
    for (Circle &circle: circles) {
        auto [uy, ly] = circle.get_ys(x);
        mny = min(mny, uy);
        mxy = max(mxy, ly);
    }

    return mny - mxy;
}

bool intersect(vector<Circle> &circles) {
    ldouble l = -INF, r = INF;
    for (auto [x, y, rad]: circles) {
        l = max(l, x - rad);
        r = min(r, x + rad);
    }

    if (sign(r - l) < 0) return false;

    for (int i = 0; i < 200; i++) {
        ldouble m1 = l + (r - l) / 3.0L;
        ldouble m2 = r - (r - l) / 3.0L;

        ldouble d1 = diff(circles, m1);
        ldouble d2 = diff(circles, m2);

        if (sign(d1 - d2) < 0) l = m1;
        else r = m2;
    }

    return sign(diff(circles, l)) >= 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    ldouble R, x1, y1, x2, y2;
    cin >> R >> x1 >> y1 >> x2 >> y2;

    ldouble r1 = hypotl(x1, y1);
    ldouble r2 = hypotl(x2, y2);

    ldouble l = 0.0L, r = min({ R, r1, r2 }), ans = -1.0L;
    for (int i = 0; i < 200; i++) {
        ldouble mid = (l + r) / 2.0L;

        vector<Circle> circles;
        circles.emplace_back(0, 0, R - mid);
        circles.emplace_back(x1, y1, r1 - mid);
        circles.emplace_back(x2, y2, r2 - mid);

        if (!intersect(circles)) r = mid;
        else l = ans = mid;
    }

    assert(sign(ans) >= 0);
    cout << ans << "\n";
}