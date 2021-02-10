#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, d; cin >> n >> d;

        int a[MAX];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);
        if (upper_bound(a, a + n, d) - a >= n || a[0] + a[1] <= d)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}