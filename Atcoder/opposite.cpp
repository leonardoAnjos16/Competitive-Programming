#include <bits/stdc++.h>

using namespace std;

#define long long long int

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

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int N; cin >> N;

    double x0, y0;
    cin >> x0 >> y0;

    double x_half, y_half;
    cin >> x_half >> y_half;

    double cx = (x0 + x_half) / 2.0;
    double cy = (y0 + y_half) / 2.0;

    double angle = 2.0 * M_PI / N;
    complex<double> aux = polar(1.0, angle);

    complex<double> p = { x0, y0 };
    complex<double> c = { cx, cy };
    complex<double> v = p - c;

    complex<double> ans = c + v * aux;
    cout << ans.real() << " " << ans.imag() << "\n";
}