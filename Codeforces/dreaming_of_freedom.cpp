#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        if (n == 1) cout << "YES\n";
        else {
            int p = 2;
            while (p * p <= n && (n % p) > 0) p++;

            if (p * p > n) p = n;
            cout << (m < p ? "YES" : "NO") << "\n";
        }
    }
}