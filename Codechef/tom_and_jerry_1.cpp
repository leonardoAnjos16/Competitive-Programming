#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int a, b, c, d, K;
        cin >> a >> b >> c >> d >> K;

        K -= abs(c - a) + abs(d - b);
        if (K < 0 || K % 2) cout << "NO\n";
        else cout << "YES\n";
    }
}