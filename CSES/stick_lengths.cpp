#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    sort(p.begin(), p.end());

    llong ans = 0LL;
    for (int i = 0; i < n; i++)
        ans += abs(p[n / 2] - p[i]);

    cout << ans << "\n";
}