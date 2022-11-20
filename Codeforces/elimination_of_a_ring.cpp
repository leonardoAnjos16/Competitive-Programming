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

        bool alternate = true;
        for (int i = 2; i < n && alternate; i++)
            if (a[i] != a[i - 2]) alternate = false;

        if (!alternate) cout << n << "\n";
        else cout << (n / 2 + 1) << "\n";
    }
}