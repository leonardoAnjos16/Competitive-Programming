#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        llong altsum = 0LL;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (i & 1) altsum -= a;
            else altsum += a;
        }

        if (n & 1) cout << "YES\n";
        else if (altsum <= 0LL) cout << "YES\n";
        else cout << "NO\n";
    }
}