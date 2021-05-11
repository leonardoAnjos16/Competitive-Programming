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

    int n; cin >> n;

    complex<int> points[MAX];
    for (int i = 0; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = { x, y };
    }

    int ans = 0;
    for (int i = 1; i < n; i++)
        ans += cross(points[i] - points[i - 1], points[i + 1] - points[i]) > 0;

    cout << ans << "\n";
}