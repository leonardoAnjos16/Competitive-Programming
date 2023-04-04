#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double

const ldouble EPS = 1e-9;
const ldouble PI = acosl(-1.0L);

int sign(ldouble x) {
    return fabsl(x) < EPS ? 0 : (x < 0 ? -1 : 1);
}

struct Circle {
    ldouble x, y, r, s;

    Circle(ldouble x, ldouble y, ldouble r, ldouble s): x(x), y(y), r(r), s(s) {}

    Circle expand(ldouble t) {
        return Circle(x, y, r + t * s, s);
    }

    ldouble dist(Circle &other) {
        ldouble dx = other.x - x;
        ldouble dy = other.y - y;
        return sqrtl(dx * dx + dy * dy);
    }

    bool intersect(Circle &other) {
        return sign(dist(other) - r - other.r) <= 0;
    }

    ldouble area() {
        return PI * r * r;
    }

    bool operator ==(Circle const &other) const {
        return !sign(x - other.x) && !sign(y - other.y) && !sign(r - other.r) && !sign(s - other.s);
    }
};

Circle merge(vector<Circle> &circles) {
    ldouble x = 0.0L, y = 0.0L, s = 0.0L, A = 0.0L;
    for (Circle circle: circles) {
        x += circle.x;
        y += circle.y;
        s = max(s, circle.s);
        A += circle.area();
    }

    int cnt = circles.size();
    x /= cnt; y /= cnt;

    ldouble r = sqrtl(A / PI);
    return Circle(x, y, r, s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int n; cin >> n;

    vector<Circle> circles;
    for (int i = 0; i < n; i++) {
        int x, y, r, s;
        cin >> x >> y >> r >> s;
        circles.emplace_back(x, y, r, s);
    }

    while (n > 1) {
        ldouble t = 1e18 + 5;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                // sqrt((xj - xi)^2 + (yj - yi)^2) <= ri + t * si + rj + t * sj
                // t * (si + sj) >= sqrt((xj - xi)^2 + (yj - yi)^2) - ri - rj
                // t >= (sqrt((xj - xi)^2 + (yj - yi)^2) - ri - rj) / (si + sj)
                t = min(t, (circles[i].dist(circles[j]) - circles[i].r - circles[j].r) / (circles[i].s + circles[j].s));
            }

        for (int i = 0; i < n; i++)
            circles[i] = circles[i].expand(t);

        bool intersection = true;
        while (intersection) {
            vector<Circle> intersections;
            for (int i = 0; i < n; i++) {
                bool found = false;
                for (int j = 0; j < n && !found; j++)
                    if (i != j && circles[i].intersect(circles[j]))
                        found = true;

                if (found) intersections.push_back(circles[i]);
            }

            if (intersections.empty()) intersection = false;
            else {
                Circle new_circle = merge(intersections);
                for (Circle circle: intersections) {
                    auto it = find(circles.begin(), circles.end(), circle);
                    assert(it != circles.end());
                    circles.erase(it);
                    n--;
                }

                circles.push_back(new_circle);
                n++;
            }
        }
    }

    assert(n == 1);

    auto [x, y, r, s] = circles[0];
    cout << x << " " << y << "\n" << r << "\n";
}