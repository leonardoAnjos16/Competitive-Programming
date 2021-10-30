#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int zeroes = 0;
    map<pair<int, int>, int> cnt;

    for (int i = 0; i < n; i++) {
        // d * ai = -bi
        if (!a[i]) zeroes += !b[i];
        else {
            int g = gcd(abs(a[i]), abs(b[i]));
            pair<int, int> p = make_pair(-b[i] / g, a[i] / g);

            if (a[i] < 0) {
                p.first *= -1;
                p.second *= -1;
            }

            cnt[p]++;
        }
    }

    int ans = 0;
    for (auto [p, c]: cnt)
        ans = max(ans, c);

    ans += zeroes;
    cout << ans << "\n";
}