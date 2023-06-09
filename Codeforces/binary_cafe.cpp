#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        if (k >= 30) cout << (n + 1) << "\n";
        else cout << min(n + 1, 1 << k) << "\n";
    }
}