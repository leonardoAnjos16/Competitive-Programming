#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double

ldouble dist(vector<pair<int, int>> &sources) {
    ldouble v = 0.0L, ans = 0.0L;
    for (auto [a, s]: sources) {
        ans += v * s + 1.0L * a * s * s / 2.0L;
        v += 1.0L * a * s;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(1) << fixed;

    int n; cin >> n;

    vector<pair<int, int>> sources(n);
    for (int i = 0; i < n; i++) {
        int a, s;
        cin >> a >> s;
        sources[i] = make_pair(a, s);
    }

    ldouble ans = -dist(sources);
    sort(sources.rbegin(), sources.rend());
    ans += dist(sources);

    cout << ans << "\n";
}