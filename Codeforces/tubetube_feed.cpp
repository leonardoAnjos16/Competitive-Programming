#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q; cin >> q;
    while (q--) {
        int n, t;
        cin >> n >> t;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> b(n);
        for (int i = 0; i < n; i++)
            cin >> b[i];

        int ans = -1;
        for (int i = 0; i < n; i++)
            if (a[i] + i <= t && (ans == -1 || b[i] > b[ans - 1]))
                ans = i + 1;

        cout << ans << "\n";
    }
}