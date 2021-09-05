#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("gcd.in", "r", stdin);

    long g = 0;
    int q; cin >> q;

    while (q--) {
        long l, r;
        cin >> l >> r;

        if (l < r) g = 1;
        else g = __gcd(g, l);

        cout << g << "\n";
    }
}