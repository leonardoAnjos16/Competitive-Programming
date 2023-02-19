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

        vector<int> b(n);
        for (int i = 0; i < n; i++)
            cin >> b[i];

        int i = n - 1, j = n - 1, ans = 0;
        while (i >= 0) {
            if (a[i] != b[j]) ans++, i--;
            else i--, j--;
        }

        cout << ans << "\n";
    }
}