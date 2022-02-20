#include <bits/stdc++.h>

using namespace std;

bool cmp(complex<long long int> &u, complex<long long int> &v) {
    if (u.real() == v.real())
        return u.imag() < v.imag();
    
    return u.real() < v.real();
}

long long int cross(complex<long long int> u, complex<long long int> v) {
    return u.real() * v.imag() - u.imag() * v.real();
}

vector<complex<long long int>> get_hull(vector<complex<long long int>> &points, int begin, int end) {
    int change = begin <= end ? 1 : -1;

    vector<complex<long long int>> hull;
    hull.push_back(points[begin]);
    begin += change;

    while (begin != end) {
        int slast = (int) hull.size() - 2, last = slast + 1;
        while (slast >= 0 && cross(hull[last] - hull[slast], points[begin] - hull[last]) >= 0)
            slast--, last--, hull.pop_back();

        hull.push_back(points[begin]);
        begin += change;
    }

    return hull;
}

long double area(complex<long long int> &A, complex<long long int> &B, complex<long long int> &C) {
    long double ans = A.real() * (B.imag() - C.imag());
    ans += B.real() * (C.imag() - A.imag());
    ans += C.real() * (A.imag() - B.imag());
    return ans / 2.0L;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int N; cin >> N;

    vector<complex<long long int>> points(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = { x, y };
    }

    sort(points.begin(), points.end(), cmp);
    points.erase(unique(points.begin(), points.end()), points.end());
    int num_points = points.size();

    vector<complex<long long int>> hull = get_hull(points, 0, num_points);
    vector<complex<long long int>> lower = get_hull(points, num_points - 1, -1);

    assert(hull.front() == lower.back());
    assert(hull.back() == lower.front());

    for (int i = 1; i < (int) lower.size() - 1; i++)
        hull.push_back(lower[i]);

    long double ans = 0.0L;
    num_points = hull.size();

    for (int i = 0; i < num_points; i++)
        for (int j = i + 1; j < num_points; j++) {
            int l = i, r = j;
            while (r - l >= 3) {
                int m1 = l + (r - l) / 3;
                int m2 = r - (r - l) / 3;

                long double a1 = area(hull[i], hull[j], hull[m1]);
                long double a2 = area(hull[i], hull[j], hull[m2]);

                if (a1 < a2) l = m1 + 1;
                else r = m2 - 1;
            }

            for (int k = l; k <= r; k++)
                ans = max(ans, area(hull[i], hull[j], hull[k]));
        }

    cout << ans << "\n";
}