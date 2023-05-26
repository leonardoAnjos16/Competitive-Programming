#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int x, k;
        cin >> x >> k;

        if (x % k) cout << "1\n" << x << "\n";
        else cout << "2\n" << (x - 1) << " " << "1\n";
    }
}