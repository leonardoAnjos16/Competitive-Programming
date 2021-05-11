#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int MAX = 105;

bool comp(complex<long double> &a, complex<long double> &b) {
    return a.real() < b.real();
}

long double dot(complex<long double> &u, complex<long double> &v) {
    return (conj(u) * v).real();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(2) << fixed;

    int C; cin >> C;
    while (C--) {
        int N; cin >> N;

        complex<long double> points[MAX];
        for (int i = 0; i < N; i++) {
            long double x, y;
            cin >> x >> y;
            points[i] = { x, y };
        }

        if (N <= 1) {
            cout << 0.0 << "\n";
            continue;
        }

        sort(points, points + N, comp);

        vi peaks(1, N - 2);
        for (int i = N - 3; i >= 0; i--)
            if (points[i].imag() > points[peaks.back()].imag())
                peaks.pb(i);

        long double ans = abs(points[peaks[0]] - points[peaks[0] + 1]);
        for (int i = 1; i < size(peaks); i++) {
            auto p = points[peaks[i] + 1], q = points[peaks[i - 1]];
            complex<long double> u = points[peaks[i]] - p;

            long double k = (q.imag() - p.imag()) / u.imag();
            complex<long double> inter = p + k * u;
            ans += abs(u) - abs(inter - p);
        }

        cout << ans << "\n";
    }
}