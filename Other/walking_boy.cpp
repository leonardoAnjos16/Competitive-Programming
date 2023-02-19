#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int cnt = 0;
        for (int i = 1; i < n; i++)
            cnt += (a[i] - a[i - 1]) / 120;

        cnt += a[0] / 120;
        cnt += (1440 - a.back()) / 120;

        if (cnt >= 2) cout << "YES\n";
        else cout << "NO\n";
    }
}