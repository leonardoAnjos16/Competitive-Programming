#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        long n; cin >> n;
        while (!(n & 1LL))
            n >>= 1LL;

        cout << (n > 1LL ? "YES" : "NO") << "\n";
    }
}