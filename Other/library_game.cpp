#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    sort(x.rbegin(), x.rend());

    int k = 0;
    while (k < n && k + 1 <= m / x[k]) k++;

    if (k >= n) cout << "Alessia\n";
    else cout << "Bernardo\n";
    cout.flush();

    priority_queue<tuple<int, int, int>> segments;
    segments.emplace(m, 1, m);

    for (int i = 0; i < n; i++) {
        if (k >= n) {
            auto [size, l, r] = segments.top();
            assert(size >= x[i]);
            segments.pop();

            cout << x[i] << " " << l << "\n";
            cout.flush();

            int b; cin >> b;

            segments.emplace(b - l, l, b - 1);
            segments.emplace(r - b, b + 1, r);
        } else {
            int y, a;
            cin >> y >> a;

            if (y < x[k]) {
                cout << a << "\n";
                cout.flush();
            } else {
                int b = (a + x[k] - 1) / x[k] * x[k];
                cout << b << "\n";
                cout.flush();
            }
        }
    }
}