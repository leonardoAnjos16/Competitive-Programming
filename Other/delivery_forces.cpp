#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> f(n);
    for (int i = 0; i < n; i++)
        cin >> f[i];

    sort(f.begin(), f.end());

    llong ans = 0LL;
    int l = 0, r = n - 2;

    while (l < r) {
        ans += f[r];
        l++; r -= 2;
    }

    cout << ans << "\n";
}