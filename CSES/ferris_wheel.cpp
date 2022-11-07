#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    sort(p.begin(), p.end());

    int idx = 0;
    while (idx + 1 < n && p[idx] + p[n - 1] <= x) idx++;

    int rem = idx, r = n - 1, ans = 0;
    while (r > idx) {
        if (p[idx] + p[r] <= x) idx++, r--, ans++;
        else {
            r--;
            ans++;
            if (rem) rem--;
        }
    }

    if (idx == r) rem++;
    ans += (rem + 1) / 2;
    cout << ans << "\n";
}