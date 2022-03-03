#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> b(n);
        for (int i = 0; i < n; i++)
            cin >> b[i];

        for (int i = 0; i < n; i++)
            if (a[i] > b[i])
                swap(a[i], b[i]);

        int ans = *max_element(a.begin(), a.end());
        ans *= *max_element(b.begin(), b.end());
        cout << ans << "\n";
    }
}