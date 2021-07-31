#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        long X, Y;
        cin >> X >> Y;

        if (__gcd(X, Y) > 1) cout << "0\n";
        else if (__gcd(X + 1, Y) > 1 || __gcd(X, Y + 1) > 1) cout << "1\n";
        else cout << "2\n";
    }
}