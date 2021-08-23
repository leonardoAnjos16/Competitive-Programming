#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v1, v2;
    cin >> v1 >> v2;

    int t, d;
    cin >> t >> d;

    vector<int> v(t);
    v[0] = v1; v[t - 1] = v2;

    int idx = 1;
    while (idx + 1 < t && v2 + (t - idx - 1) * d - v[idx - 1] > 0)
        v[idx] = v[idx - 1] + min(d, v2 + (t - idx - 1) * d - v[idx - 1]), idx++;

    while (idx + 1 < t)
        v[idx] = v[idx - 1] - max(0, v[idx - 1] - v2 - (t - idx - 1) * d), idx++;

    int ans = 0;
    for (int i = 0; i < t; i++)
        ans += v[i];

    cout << ans << "\n";
}