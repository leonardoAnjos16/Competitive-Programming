#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        long n; cin >> n;

        if (n % 3 && n % 4) cout << "IMPOSSIBLE\n";
        else if (!(n % 3)) {
            long a = n / 3;
            cout << a << " " << a << " " << a << "\n";
        } else {
            long a = n / 2;
            long b = n / 4;
            cout << a << " " << b << " " << b << "\n";
        }
    }
}