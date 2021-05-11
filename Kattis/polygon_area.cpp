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

const int MAX = 1e3 + 5;

int cross(complex<int> a, complex<int> b) {
    return (conj(a) * b).imag();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(1) << fixed;

    int n;
    while (cin >> n, n) {
        complex<int> vertices[MAX];
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            vertices[i] = { x, y };
        }

        double ans = 0.0;
        for (int i = 0; i < n; i++)
            ans += cross(vertices[i], vertices[(i + 1) % n]) / 2.0;

        cout << (ans < 0 ? "CW" : "CCW");
        cout << " " << abs(ans) << "\n";
    }
}