#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.rbegin(), a.rend());

    long long int ans = 0LL;
    for (int i = 0; i < n; i++)
        ans += i * a[i].first + 1;

    cout << ans << "\n";
    for (int i = 0; i < n; i++)
        cout << a[i].second << " ";

    cout << "\n";
}