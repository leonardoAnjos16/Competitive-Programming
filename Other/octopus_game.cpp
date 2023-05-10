#include <bits/stdc++.h>

using namespace std;

#define llong long long int

vector<pair<int, llong>> ans;

int sign(llong x) {
    return !x ? 0 : (x < 0 ? -1 : 1);
}

int solve(llong a, llong b, bool ceil = false) {
    if (!a || !b) return 0;

    int t = abs(a) >= abs(b) ? 1 : 2;
    llong k = max(abs(a), abs(b)) / min(abs(a), abs(b));
    if (ceil && k * min(abs(a), abs(b)) < max(abs(a), abs(b))) k++;
    if (sign(a) == sign(b)) k = -k;

    ans.emplace_back(t, k);
    if (abs(a) >= abs(b))
        return solve(a + k * b, b, ceil) + 1;

    return solve(a, b + k * a, ceil) + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    llong a0, b0;
    cin >> a0 >> b0;

    int cnt = solve(a0, b0);
    if (cnt > 50) {
        ans.clear();
        cnt = solve(a0, b0, true);
        assert(cnt <= 50);
    }

    cout << cnt << "\n";
    for (auto [t, k]: ans)
        cout << t << " " << k << "\n";
}